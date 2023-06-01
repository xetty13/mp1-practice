#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdio.h>

const int STEP = 10;

class TProductsDatabase;
class TReceipt;
class TReceiptLine;

template <typename T>
class TContainer {
private:
	int size;
	int max_size;
	int step;
	int current_index;
	T* elements;

	void realloc();
public:
	TContainer();
	TContainer(int, int);
	TContainer(const TContainer<T>& c);
	~TContainer();

	T& operator[] (int);
	const T& operator[] (int) const;
	const TContainer& operator=(const TContainer& c);
	friend std::ostream& operator<<(std::ostream& out, const TContainer<T>& c) {
		for (int i = 0; i < c.size; i++) {
			out << c.elements[i];
		}
		return out;
	}

	int Get_size() const;

	void insert(const T&);
	void insert_forward(const T&);
	void insert_back(const T&);

	void remove(const int);
	void remove(const T&);
	void remove_forward();
	void remove_back();

	int find_elem(const T&);

	void reset();

	T& next();
	T& previous();
	T& current();
	bool IsEnded();
};

struct TProduct {
	long code;
	std::string name;
	double cost;

	bool operator==(const TProduct&) const;
	friend std::ostream& operator<<(std::ostream&, const TProduct&);
};

struct TInfoProduct {
	TProduct product;
	int count;

	bool operator==(const TInfoProduct&) const;
};

class TReceiptLine {
private:
	TProduct product;
	int count;
	double sum_cost;
public:
	TReceiptLine();
	TReceiptLine(TProduct&, int, double);
	TReceiptLine(const TReceiptLine&);

	const TReceiptLine& operator= (const TReceiptLine&);
	bool operator==(const TReceiptLine&) const;
	friend std::ostream& operator<<(std::ostream& out, const TReceiptLine& rec_line);

	const TProduct& Get_product() const;
	int Get_count() const;
	double Get_sum_cost() const;

	void Set_count(int);
	void Set_sum_cost(double);

};

struct TDate {
	int day;
	int month;
	int year;

	TDate();
};

struct TTime {
	int hour;
	int minute;
	int second;

	TTime();
};

class TReceipt {
private:
	static long code;
	TDate date;
	TTime time;
	TContainer<TReceiptLine> products;

	static void Code_increase();
	int get_barcode_delete(TProductsDatabase& db);
	int get_barcode_add(TProductsDatabase& db);
public:
	TReceipt();
	TReceipt(const TReceipt&);

	TReceiptLine& operator[](int);
	friend std::ostream& operator<<(std::ostream& out, TReceipt& rec);
	const TReceipt& operator= (const TReceipt&);

	int Find_product(const long) const;
	int Get_num_products() const;
	void Add_new_prod(const TReceiptLine&);
	double Get_total_sum() const;
	void Get_data_n_time();
	void Delete_prod(const int ind);
	void Delete(TProductsDatabase& db);
	void Add(TProductsDatabase& db);
};

class TProductsDatabase {
private:
	TContainer<TInfoProduct> productsInStock;

	void get_correct_file_name(const std::string& fname) const;
	bool check_file_name(const std::string& fname) const;
public:
	TProductsDatabase(const std::string& filename);

	TInfoProduct& operator[](int);

	int barcode_search(const long barcode);
	int Get_num_prods() const;
	void Updating_data_remove(const TProduct& prod);
	void Updating_data_add(const TProduct& prod);
	void create_updating_db();
};

// T_CONTAINER:
// Constructors&destructors
template <typename T>
TContainer<T>::TContainer() {
	size = 0;
	max_size = 0;
	step = STEP;
	current_index = -1;
	elements = nullptr;
}

template <typename T>
TContainer<T>::TContainer(int max_size, int step_value) {
	size = 0;
	current_index = -1;
	step = step_value;
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
	if (elements != nullptr) {
		delete[] elements;
	}
}

// overloading
template <typename T>
const TContainer<T>& TContainer<T>::operator=(const TContainer<T>& c) {
	if (this == &c)
		return (*this);

	size = c.size;
	max_size = c.max_size;
	step = c.step;
	current_index = c.current_index;
	if (elements) {
		delete[] elements;
	}
	elements = new T[max_size];

	for (int i = 0; i < size; i++) {
		elements[i] = c.elements[i];
	}
	
	return (*this);
}

template <typename T>
const T& TContainer<T>::operator[] (int ind) const {
	if (ind >= max_size || ind < 0)
		throw "Index out of range";
	return elements[ind];
}

template <typename T>
T& TContainer<T>::operator[] (int ind) {
	if (ind >= max_size || ind < 0)
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
	current_index = size;
	size++;
}

template <typename T>
void TContainer<T>::insert_forward(const T& elem) {
	if (size == max_size) {
		realloc();
	}
	T* tmp = new T[max_size];

	int i;
	for (i = 0; i <= current_index; i++) {
		tmp[i] = elements[i];
	}
	tmp[i] = elem;
	for (; i < size; i++) {
		tmp[i + 1] = elements[i];
	}
	delete[] elements;
	elements = tmp;
	current_index++;
	size++;
}

template <typename T>
void TContainer<T>::insert_back(const T& elem) {
	if (size == max_size) {
		realloc();
	}
	T* tmp = new T[max_size];

	int i;
	for (i = 0; i < current_index; i++) {
		tmp[i] = elements[i];
	}
	tmp[i] = elem;
	for (; i < size; i++) {
		tmp[i + 1] = elements[i];
	}
	delete[] elements;
	elements = tmp;
	size++;
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
void TContainer<T>::remove(const int ind) {
	if (ind < 0 or ind >= size)
		throw "Incorrect index";

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
void TContainer<T>::remove(const T& elem) {
	int index = find_elem(elem);

	if (index == -1)
		return;

	this->remove(index);
}

template <typename T>
void TContainer<T>::remove_forward() {
	this->remove(current_index + 1);
}

template <typename T>
void TContainer<T>::remove_back() {
	this->remove(current_index - 1);
}

template <typename T>
void TContainer<T>::reset() {
	current_index = 0;
}

template <typename T>
int TContainer<T>::find_elem(const T& elem) {
	for (int i = 0; i < size; i++) {
		if (elements[i] == elem) {
			return i;
		}
	}
	return -1;
}

template <typename T>
T& TContainer<T>::next() {
	if (current_index == -1)
		throw std::exception("Conteiner is Empty! Isert some element in it");
	if (current_index >= size - 1)
		throw std::exception("Index out of range");
	current_index++;
	return elements[current_index];
}

template <typename T>
T& TContainer<T>::previous() {
	if (current_index == -1)
		throw std::exception("Conteiner is Empty! Isert some element in it");
	if (current_index < 1)
		throw std::exception("Index out of range");
	current_index--;
	return elements[current_index];
}

template <typename T>
T& TContainer<T>::current() {
	if (current_index == -1)
		throw std::exception("Conteiner is Empty! Isert some element in it");
	return elements[current_index];
}

template <typename T>
bool TContainer<T>::IsEnded() {
	return current_index == (size - 1);
}

template <typename T>
int TContainer<T>::Get_size() const {
	return size;
}

#endif