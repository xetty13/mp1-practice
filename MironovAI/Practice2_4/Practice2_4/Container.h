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
		position = 0;
		elements = new Type[1];
	}
	// Lengh of the nelements must be equal new_size
	NewConteiner<Type>(int new_size, Type* nelements, int nmax_size = 0, int nstep = 100) {
		max_size = nstep + new_size;
		size = new_size;
		elements = new Type[max_size];
		for (int i = 0; i < size; i++) {
			elements[i] = nelements[i];
		}
		step = nstep;
		position = size;
	}

	NewConteiner<Type>(const NewConteiner<Type>& container) {
		size = container.size;
		if (container.max_size == 0) elements = new Type[1];
		else elements = new Type[container.max_size];
		elements = container.elements;
		max_size = container.max_size;
		position = container.position;
		step = container.step;
	}
	//destructor
	virtual ~NewConteiner<Type>() {
		delete[] elements;
	}

	//overloaded operations	
	friend ifstream& operator>>(ifstream& buf, NewConteiner<Type>& data) {
		{

			for (int i = 0; i < data.size; i++) {
				if (data.size == data.max_size) realloc();
				buf >> data.elements[i];
				data.next();
			}
			return buf;
		}
	}
	friend istream& operator>>(istream& buf, NewConteiner<Type>& data) {
		{

			for (int i = 0; i < data.size; i++) {
				if (data.size == data.max_size) data.realloc();
				buf >> data.elements[i];
				data.next();
			}
			return buf;
		}
	}
	friend ostream& operator<<(ostream& buf, const NewConteiner<Type>& data) {
		for (int i = 0; i < data.size; i++) {
			buf << data.elements[i] << " ";
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
		if (size != container.size || max_size != container.max_size || step != container.step) return true;
		for (int i = 0; i < size; i++) {
			if (elements[i] != container.elements[i]) return true;
		}
		return true;
	}

	NewConteiner<Type>& operator=(const NewConteiner<Type>& container) {

		delete[] elements;
		size = container.size;
		max_size = container.max_size;
		step = container.step;
		elements = new Type[max_size];
		for (int i = 0; i < max_size; i++) {
			elements[i] = container.elements[i];
		}
		position = container.position;
		return *this;
	}

	//getters
	Type* get_elements() const {
		return elements;
	}
	//setters
	void set_step(const int& nstep) { step = nstep; }
	void push(const Type& value, const int& index = position + 1)
	{
		if (index < 0 && index >= size) {
			cout << "Wrong index" << endl;
			return;
		}
		if (size == max_size) realloc();
		Type* tmp = new Type[max_size];
		for (int i = 0; i < index; i++) {
			tmp[i] = elements[i];
		}
		tmp[index] = value;
		for (int i = index; i < size; i++) {
			tmp[i + 1] = elements[i];
		}
		for (int i = 0; i < size + 1; i++) {
			elements[i] = tmp[i];
		}
		position = size + 1;
		size++;
		delete[] tmp;
	}
	void push_back(const Type& value)
	{
		if (size == max_size) realloc();
		Type* tmp = new Type[max_size];
		for (int i = 0; i < size; i++) {
			tmp[i] = elements[i];
		}
		tmp[size] = value;
		for (int i = 0; i < size + 1; i++) {
			elements[i] = tmp[i];
		}
		delete[] tmp;
		position = size + 1;
		size++;
	}
	void push_front(const Type& value)
	{
		if (size == max_size) realloc();
		Type* tmp = new Type[max_size];
		tmp[0] = value;
		for (int i = 0; i < size; i++) {
			tmp[i + 1] = elements[i];
		}

		for (int i = 0; i < size + 1; i++) {
			elements[i] = tmp[i];
		}
		delete[] tmp;
		position = size + 1;
		size = size + 1;
	}
	void pop_id(const int& index) {
		if (index < 0 && index >= size) {
			cout << "Wrong index" << endl;
			return;
		}
		Type* tmp = new Type[size - 1];
		for (int i = 0; i < index; i++) {
			tmp[i] = elements[i];
		}
		for (int i = index; i < size - 1; i++) tmp[i] = elements[i + 1];
		size -= 1;
		position -= 1;
		delete[] elements; elements = new Type[size];
		for (int i = 0; i < size; i++) {
			elements[i] = tmp[i];
		}
		delete[] tmp;
	}
	void pop_value(const Type& value) {
		for (int i = 0; i < size; i++) {
			if (elements[i] == value) {
				pop_id(i);
				return;
			}
		}
	}
	void pop_back() 
	{ 
		pop_id(size - 1);
	}
	void pop_front() {
		pop_id(0); 
	}
	int len() const {
		return size;
	}

	Type& find(const Type& element) const {
		Type tmp;
		for (int i = 0; i < size; i++) {
			if (element == elements[i]) return elements[i];
		}
		return tmp;
	}
	static void read(const string& path,NewConteiner<Type>& data)
	{
		ifstream file(path);
		int count; file >> count;
		Type* tmp = new Type[count];
		for (int i = 0; i < count; i++) { file >> tmp[i]; }
		//NewConteiner<Type> tmp2(count, tmp, count+100, 100);
		data = NewConteiner<Type>::NewConteiner(count,tmp,count+100,100);
		delete[] tmp;
		//delete &tmp2;
		file.close();
	}
	//Movements 
	void next() {
		if (position+1 < max_size) position++;
	}
	void back() { 
		if (position > 0)  position--;
	}
	void reset() {
		position = 0;
	}
	bool is_end() const { 
		(size == max_size) ? true : false;
	}



};


#endif