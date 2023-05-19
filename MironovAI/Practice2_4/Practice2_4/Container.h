#ifndef _Container_H_
#define _Container_H_

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


static int IndexError() {
	cout << "Wrong Index" << endl;
	return -1;
}


//Container
template <typename Type>
class NewConteiner
{
private:
	int size;
	Type* elements;
	int max_size;
	int step;
	int position;
 void realloc() {
		max_size += step;
		if (elements == nullptr)
		{
			elements = new Type[max_size];
			position = 0;
			size = 0;
			return;
		}
		if (max_size == 0) return;
		Type* tmp = new Type[max_size];
		for (int i = 0; i < size; i++) {
			tmp[i] = elements[i];
		}
		delete[] elements;
		elements = new Type[max_size];
		for (int i = 0; i < size; i++) {
			elements[i] = tmp[i];
		}
		position = size;
		delete[] tmp;
	}
public:
	//constructors
	NewConteiner() {
		size = 0;
		max_size = 0;
		step = 10;
		position = -1;
		elements = nullptr;
	}
	// Lengh of the nelements must be equal new_size
	NewConteiner(const int& new_size, const Type*& nelements, int nstep = 10) {
		if (max_size < new_size + 1) {
			realloc();
		}
		size = new_size;
		for (int i = 0; i < size; i++) {
			elements[i] = nelements[i];
		}
		step = nstep;
		position = size;
	}

	NewConteiner(const NewConteiner<Type>& container) {
		size = container.size;
		if (container.max_size != 0) {
			if (max_size < container.size) {
				realloc();
			}
			elements = new Type[container.max_size];
		}

		for (int i = 0; i < container.size; i++)
		{
			elements[i] = container.elements[i];
		}
		max_size = container.max_size;
		position = container.position;
		step = container.step;
	}
	//destructor
	virtual ~NewConteiner() {
		if (elements != nullptr) delete[] elements;
	}

	//overloaded operations	
	friend ifstream& operator>>(ifstream& buf, NewConteiner<Type>& Date) {
		{
			buf >> Date.size;
			for (int i = 0; i < Date.size; i++) {
				if (Date.size+1 >= Date.max_size) Date.realloc();
				buf >> Date.elements[i];
				Date.next();
			}
			return buf;
		}
	}
	
	friend istream& operator>>(istream& buf, NewConteiner<Type>& Date) {
		{
			buf >> Date.size;
			for (int i = 0; i < Date.size; i++) {
				if (Date.size == Date.max_size) Date.realloc();
				buf >> Date.elements[i];
				Date.next();
			}
			return buf;
		}
	}
	
	friend ostream& operator<<(ostream& buf, const NewConteiner<Type>& Date) {
		for (int i = 0; i < Date.size; i++) {
			buf << Date.elements[i] << " ";
		}
		buf << endl;
		return buf;
	}
	Type& operator[](const int& index) const
	{
		if (index < 0 && index >= size) {
			throw IndexError();
		}
		return elements[index];
	}
	bool operator==(const NewConteiner<Type>& container) const {
		if (size != container.size || max_size != container.max_size || step != container.step) return false;
		for (int i = 0; i < size; i++) {
			if (elements[i] != container.elements[i]) return false;
		}
		return true;
	}
	bool operator!=(const NewConteiner<Type>& container) const {
		return !(*this == container);
	}

	const NewConteiner<Type>& operator=(const NewConteiner<Type>& container) {
		if (*this == container)  return *this;
		
		if (max_size < container.size)
		{
			int tmp = step;
			step = max(container.max_size - max_size + 1, step);
			realloc();
			step = tmp;
		}
		size = container.size;
		max_size = container.max_size;
		for (int i = 0; i < size; i++) {
			elements[i] = container.elements[i];
		}
		position = container.position;
		step = container.step;
		return *this;
	}

	//getters
	Type* get_elements() const {
		return elements;
	}
	//setters
	void set_step(const int& nstep) { step = nstep; }

	void push(const Type& value, const int& index)
	{
		if (index < 0 && index >= size)
		{
			throw IndexError;
		}
		if (size + 1 >= max_size) realloc();
		
		for (int i = size - 2; i >= index; i--)
		{
			elements[i + 1] = elements[i];
		}

		elements[index] = value;

		position = size+1;
		size++;
	}
	void push_back(const Type& value)
	{
		if (size + 1 >= max_size) realloc();
		elements[position] = value;
		position = size + 1;
		size++;
	}
	/*
	void push_front(const Type& value)
	{
		if (index < 0 && index >= size)
		{
			cout << "Wrong index" << endl;
			return;
		}
		if (size + 1 >= max_size) realloc();

		for (int i = size, i >= 0; i--)
		{
			elements[i + 1] = elemnts[i];
		}
		elements[0] = value;

		position = size + 1;
		size++;
	}
	*/
	void pop_id(const int& index) {
		if (index < 0 && index >= size)
		{
			throw IndexError;
		}
		
		if (size == 1) {
			elements = nullptr;
			return;
		}

		for (int i = index; i - 2 < size; i++)
		{
			elements[i] = elements[i+1];
		}

		position = size - 1;
		size--;
	}
	void pop_value(const Type& value) {

		int k = find_id(value);
		if (k != -1) pop_id(k);
		throw IndexError;
	}
	/*
	void pop_back() 
	{ 
		pop_id(size - 1);
	}
	void pop_front() {
		pop_id(0); 
	}
	*/
	int len() const {
		return size;
	}
	template<typename Type1>
	Type* find(const Type1& element) const {

		for (int i = 0; i < size; i++) {
			if (element == elements[i]) return &elements[i];
		}
		return nullptr;
	}
	template<typename Type1>
	int find_id(const Type1& element) const {
		for (int i = 0; i < size; i++) {
			if (element == elements[i]) return i;
		}
		return -1;
	}
	static void read(const string& path,NewConteiner<Type>& Date)
	{
		ifstream file(path);
		int count; file >> count;
		if (Date.size + count + 1 >= Date.max_size) Date.realloc();
 		for (int i = 0; i < count; i++) { file >> Date[i]; }
		Date.size = count;
		file.close();
	}
	//Movements 

	void next() {
		if (position + 1 < max_size && position != -1) position++;
	}
	void back() { 
		if (position > 0)  position--;
	}
	void reset() {
		position = 0;
	}
	bool is_end() const { 
		return (position + 1  == max_size) ? true : false;
	}



};


#endif