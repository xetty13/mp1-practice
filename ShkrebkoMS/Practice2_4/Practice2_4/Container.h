#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
using namespace std;

template <typename T>
class TContainer
{
private:
	T* elements;
	int max_size;
	int size;
	int step;
	int current_index;
	void realloc();
public:
	TContainer();
	TContainer(int max_size, int step);
	TContainer(const TContainer<T>& container);
	~TContainer();
	int getSize() const;
	T& operator [] (int index);
	const T& operator [] (int index) const;
	void insert(const T& element);
	void insertBefore(const T& element);
	void insertAfter(const T& element);
	int find(const T& element) const;
	void remove(const T& element);
	void remove(int index);
	void reset();
	friend std::ostream& operator<<(std::ostream& out, const TContainer<T>& c) {
		for (int i = 0; i < c.size; i++) {
			out << c.elements[i] << std::endl;
		}
		return out;
	}
	T& next();
	T& prev();
	T& current();
	bool IsEnded() const;
	
	const TContainer<T>& operator=(const TContainer<T>& other);
};
template <typename T>
int TContainer<T>::getSize() const
{
	return size;
}
template <typename T>
TContainer<T>::TContainer()
{
	elements = nullptr;
	max_size = 0;
	size = 0;
	current_index = -1;
	step = 5;
}

template <typename T>
TContainer<T>::TContainer(int max_size, int step)
{
	size = 0;
	this->step = step;
	current_index = -1;
	this->max_size = max_size;
	elements = new T[max_size];
}
template <typename T>
TContainer<T>::TContainer(const TContainer<T>& container)
{
	size = container.size;
	current_index = container.current_index;
	max_size = container.max_size;
	elements = new T[max_size];
	for (int i = 0; i < size; i++)
	{
		elements[i] = container.elements[i];
	}
}
template <typename T>
TContainer<T>::~TContainer()
{
	if (elements != nullptr) 
	{
		delete[] elements;
	}
}
template <typename T>
const T& TContainer<T>:: operator [] (int index) const
{
	if((index >= size) || (index < 0))
		throw exception("Index out of range");
	return elements[index];
}
template <typename T>
T& TContainer<T>::operator[](int index)
{
	if ((index >= size) || (index < 0))
		throw exception("Index out of range");
	current_index = index;
	return elements[index];
}
template <typename T>
void TContainer<T>::realloc()
{
	max_size += step;
	T* tmp = new T[max_size];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = elements[i];
	}
	delete[] elements;
	elements = tmp;
}
template <typename T>
void TContainer<T>::insert(const T& element)
{
	if (max_size == size)
		realloc();
	elements[size] = element;
	current_index = size;
	size++;
}

template <typename T>
void  TContainer<T>::insertBefore(const T& element)
{
	if (size == max_size) {
		realloc();
	}
	T* tmp = new T[max_size];

	int i;
	for (i = 0; i <= current_index; i++) {
		tmp[i] = elements[i];
	}
	tmp[i] = element;
	for (; i < size; i++) {
		tmp[i + 1] = elements[i];
	}
	delete[] elements;
	elements = tmp;
	current_index++;
	size++;
}
template <typename T>
void  TContainer<T>::insertAfter(const T& element)
{
	if (size == max_size) {
		realloc();
	}
	T* tmp = new T[max_size];

	int i;
	for (i = 0; i < current_index; i++) {
		tmp[i] = elements[i];
	}
	tmp[i] = element;
	for (; i < size; i++) {
		tmp[i + 1] = elements[i];
	}
	delete[] elements;
	elements = tmp;
	size++;
}
template <typename T>
int TContainer<T>::find(const T& element) const
{
	for (int i = 0; i < size; i++)
	{
		if (elements[i] == element) 
		
		{
			return i;
		}
	}
	return -1;
}
template <typename T>
void  TContainer<T>::remove(const T& element)
{
	int i;
	for ( i = 0; i < size; i++)
	{
		if (elements[i] == element)
			break;
	}
	for (i; i < size - 1; i++)
	{
		elements[i] = elements[i + 1];
	}
	size--;
}
template <typename T>
void  TContainer<T>::remove(int index)
{
	if ((index < 0) || (index > size))
		return;
	for (int i=index; i < size - 1; i++)
	{
		elements[i] = elements[i + 1];
	}
	size--;
}
template <typename T>
void  TContainer<T>::reset()
{
	current_index = 0;
}
template <typename T>
T&  TContainer<T>::next()
{
	if (current_index + 1 == size)
		throw exception("Index out of range");
	current_index++;
	return elements[current_index];
}
template <typename T>
T& TContainer<T>::prev()
{
	if (current_index - 1 <= 0)
		throw exception("Index out of range");
	current_index--;
	return elements[current_index];
}
template <typename T>
T& TContainer<T>::current()
{
	if (current_index == -1)
		throw std::exception("Conteiner is Empty! Isert some element in it");
	return elements[current_index];
}
template <typename T>
bool TContainer<T>::IsEnded() const
{
	return current_index == size - 1;
}
template <typename T>
const TContainer<T>& TContainer<T>::operator=(const TContainer<T>& container)
{
	if (this != &container)
	{
		delete[] elements;
		current_index = container.current_index;
		size = container.size;
		max_size = container.max_size;
		step = container.step;
		elements = new T[container.max_size];
		for (int i = 0; i < size; i++) 
		{
			elements[i] = container.elements[i];
		}
	}
	return *this;
}
#endif