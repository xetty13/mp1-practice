#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

const int step_value = 10;

template <typename T>
class TContainer {
private:
	int size;
	int max_size;
	int step = step_value;
	int current_index;
	T* elements;

	void realloc();
public:
	TContainer();
	TContainer(int);
	TContainer(const TContainer<T>&);
	~TContainer();
	T& operator[] (int);

	void insert(const T&);
	void remove(int);
	void print_elements();
	void reset();
	T& next();
	T& previous();
};

// Database clasess
class TInfoProduct {
private:
	long code;
	std::string name;
	double cost;
	int count;
public:
	TInfoProduct();
	const TInfoProduct& operator= (const TInfoProduct&);

	void SetCode(const long);
	void SetName(const std::string&);
	void SetCost(const double);
	void SetCount(const int);

	long GetCode() const;
	std::string GetName() const;
	double GetCost() const;
	int GetCount() const;
};

std::ostream& operator<<(std::ostream& out, const TInfoProduct& s);

class TProductsDatabase {
private:
	TContainer<TInfoProduct>* productsInStock;
public:
	TProductsDatabase(const std::string& filename);

	int try_to_open_file(const std::string& fname) const;
	int find_num_univ(const std::string& fname) const;
	void print();
};

// Receipt clasess
class TProduct {
private:
	long code;
	std::string name;
	double cost;
public:
	TProduct();
};

class TReceiptLine {
private:
	TProduct product;
	int count;
	double sum_cost;
public:
	TReceiptLine();
	const TReceiptLine& operator= (const TReceiptLine&);
};

class TDate {
private:
	int day;
	int month;
	int year;
};

class TTime {
private:
	int hour;
	int minute;
	int second;
};

class TReceipt {
private:
	long code;
	/*TDate date;
	TTime time;*/
	TContainer<TReceiptLine>* products;
public:
	TReceipt();
	TReceipt(int msize);
};


// T_CONTAINER:
// Constructors&destructors
template <typename T>
TContainer<T>::TContainer() {
	size = -1;
	max_size = -1;
	current_index = -1;
	elements = nullptr;
}

template <typename T>
TContainer<T>::TContainer(int max_size) {
	size = 0;
	current_index = 0;
	this->max_size = max_size;
	elements = new T[max_size];
}

template <typename T>
TContainer<T>::TContainer(const TContainer<T>& c) {
	size = c.size;
	step = c.step;
	current_index = c.current_index;
	max_size = c.max_size;
	elements = new T[max_size];

	for (int i = 0; i < size; i++) {
		elements[i] = c.elements[i];
	}
}

template <typename T>
TContainer<T>::~TContainer() {
	delete[] elements;
}

// overloading
template <typename T>
T& TContainer<T>::operator[] (int ind) {
	if (ind >= max_size or ind < 0)
		throw "Index out of range";
	current_index = ind;
	return elements[ind];
}

// methods
template <typename T>
void TContainer<T>::insert(const T& elem) {
	if (size == max_size) {
		realloc();
	}
	elements[size] = elem;
	size++;
}

template <typename T>
void TContainer<T>::print_elements() {
	for (int i = 0; i < size; i++) {
		std::cout << elements[i] << std::endl;
	}
}

template <typename T>
void TContainer<T>::realloc() {
	max_size = max_size + step;
	T* tmp = new T[max_size];
	for (int i = 0; i < size; i++) {
		tmp[i] = elements[i];
	}
	delete[] elements;
	elements = tmp;
}

template <typename T>
void TContainer<T>::remove(int ind) {
	T* tmp = new T[max_size];
	for (int i = 0; i < ind; i++) {
		tmp[i] = elements[i];
	}
	for (int i = ind; i < size - 1; i++) {
		tmp[i] = elements[i + 1];
	}
	delete[] elements;
	elements = tmp;
	size--;
}

template <typename T>
void TContainer<T>::reset() {
	current_index = 0;
}

template <typename T>
T& TContainer<T>::next() {
	if ((current_index + 1) >= size)
		throw std::exception("Index out of range");
	current_index++;
	return elements[current_index];
}

template <typename T>
T& TContainer<T>::previous() {
	if ((current_index - 1) < 0)
		throw std::exception("Index out of range");
	current_index--;
	return elements[current_index];
}

#endif