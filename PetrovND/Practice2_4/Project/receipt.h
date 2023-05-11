#ifndef _RECEIPT_H
#define _RECEIPT_H
using namespace std;
#include <vector>
#include <tuple>
#include <string>

template <typename T> class Container {
public:
	Container() :
		step(5), size(0), capacity(0), currentIndex(0), elements(new T[0]) {}
	Container(int capacity, int step = 5) :
		capacity(capacity), step(step), elements(new T[capacity]), size(0), currentIndex(0) {}
	~Container() {
		delete[] elements;
		elements = nullptr;
	}

	void add(const T& element) {
		if (size == capacity) {
			resize();
		}
		elements[size] = element;
		size++;
	}
	void remove(const T& element) {
		int i;
		for (i = 0; i < size; i++) {
			if (elements[i] == element)
				break;
		}
		for (i; i < size - 1; i++) {
			elements[i] = elements[i + 1];
		}
		size--;
	}
	void remove(int index) {
		if (index >= size || index < 0) { return; }
		for (int i = index; i < size - 1; i++) {
			elements[i] = elements[i + 1];
		}
		size--;
	}
	int getSize() const { return size; }
	T& operator[](int index) { return elements[index]; }

	bool isEnd() {
		return currentIndex == size - 1;
	}
	void next() {
		if (isEnd() || size == 0)
			return;
		currentIndex++;
	}
	void prev() {
		if (currentIndex == 0)
			return;
		currentIndex--;
	}
	T getCurrent() {
		if (size == 0)
			return -1;
		return elements[currentIndex];
	}
	void resetIndex() {
		currentIndex = 0;
	}
	void reset() {
		delete[] elements;
		elements = new T[0];
		size = 0;
		capacity = 0;
		currentIndex = 0;
	}
private:
	T* elements;
	int currentIndex;
	int size;
	int capacity;
	int step;
	void resize() {
		T* newElements = new T[capacity + step];
		for (int i = 0; i < size; i++) {
			newElements[i] = elements[i];
		}
		delete[] elements;
		elements = newElements;
		capacity += step;
	}
};

class Product {
public:
	Product(int code, const string& name, double price);
	Product();
	int getCode();
	float getPrice();
	string getName();
private:
	int code;
	string name;
	float price;
};

struct dataBase {
public:
	Product searchProductByCode();
	dataBase(const string& path);
	vector<tuple<Product, int>> data;
};

struct Time {
	int hour;
	int minute;
};

struct date {
	int day;
	int mounth;
	int year;
};

class ReceiptLine {
public:
	ReceiptLine();
	ReceiptLine(Product product, int count);
	Product& getProduct();
	int getCount();
	float getSumm();
	void setCount(int count);
	void setSumm(int summ);
private:
	Product product;
	int count;
	float summ;
};

class Receipt {
public:
	Receipt();
	friend ostream& operator<<(ostream& os, Receipt& receipt);
	void addItem(Product& product, dataBase& data);
	void removeItem(Product& product);
	double getTotal();
	void reset();
private:
	void setTime();
	Time time_;
	date date;
	Container<ReceiptLine> pr;
};

string start();
void menu(dataBase& data, Receipt& receipt);
#endif // !_RECEIPT_H
