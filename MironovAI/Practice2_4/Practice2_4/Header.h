#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//functions
int PathError();
int IndexError(int index, int size);

string input_path();
template<typename Type>
void print_all_products(Type*& products, int size)
{
	cout << "Products: \n " << endl;
	for (int i = 0; i < size; i++) {
		cout << products[i] << endl;
	}
}
void user();


template <typename T1>
struct Base {
	T1 product;
	int count;
	Base() { count = 0;  }
	friend ifstream& operator>>(ifstream& buf,Base<T1>& data) {
		buf >> data.product >> data.count;
		return buf;
	}
	friend ostream& operator<<(ostream& buf, const Base<T1>& data) {
		buf << data.product << data.count << endl;
		return buf;
	}
	friend istream& operator>>(istream& buf, Base<T1>& data) {
		buf >> data.product >> data.count;
		return buf;
	}
	bool operator == (string& str) { return product == str; }
};

template <typename T1>
struct Cart {
	T1 product;
	int count;
	double cost;
	Cart()
	{
		count = 0;
		cost = 0;

	}
	Cart(T1 pr, int ncount, int ncost = 0) {
		product = pr;
		count = ncount;
		cost = ncost;
	}
	friend ifstream& operator>>(ifstream& buf, Cart<T1>& data) {
		buf >> data.product >> data.count >> data.cost;
		return buf;
	}
	friend ostream& operator<<(ostream& buf, const Cart<T1>& data) {
		buf << data.product << data.count << endl;
		return buf;
	}
	friend istream& operator>>(istream& buf, Cart<T1>& data) {
		buf >> data.product >> data.count >> data.cost;
		return buf;
	}
	//bool operator != (Product tmp) { return (product != tmp.product); }
	bool operator == (Cart<T1> tmp) { return (product == tmp.product); }
	bool operator == (Base<T1> tmp) { return (product == tmp.product); }
	bool operator != (Cart<T1> tmp) { return !(product == tmp.product); }
	bool operator == (string& tmp) {
		return product == tmp;
	}
	bool operator <= (int ncount) { return count <= ncount; }
	Cart<T1>& operator = (Cart<T1> tmp) {
		product = tmp.product;
		count = tmp.count;
		cost = tmp.cost;
		return *this;
	}
	Cart<T1>& operator += (int ncount)
	{
		count += ncount;
		return *this;
	}
	Cart<T1>& operator -= (int ncount) {
		count -= ncount;
		return *this;
	}
	

};
//Data
struct Data
{
	//int year, month, day, hour, min, sec;
	struct tm* timeinfo;
	void now();
};


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
	NewConteiner<Type>(const int new_size, const Type* nelements, const int nmax_size = 0, const int nstep = 100) {
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
	NewConteiner<Type>(NewConteiner<Type>& container) {
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
	friend ostream& operator<<(ostream& buf,const NewConteiner<Type>& data) {
		for (int i = 0; i < data.size; i++) {
			buf << data.elements[i] << " ";
		}
		buf << endl;
		return buf;
	}
	Type& operator[](int index) 
	{
		if (index < 0 && index >= size) {
			throw IndexError(index, size);
		}
		return elements[index];
	}
	bool operator==(const NewConteiner<Type>& container) {
		if (size != container.size || max_size != container.max_size || step != container.step) return false;
		for (int i = 0; i < size; i++) {
			if (elements[i] != container.elements[i]) return false;
		}
		return true;
	}
	bool operator!=(const NewConteiner<Type>& container) { 
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
	Type*& get_elements() {
		return elements;
	}
	//setters
	void set_step(int nstep) { step = nstep; }

	Type& find(string code) {
		Type tmp;
	
		if (code == "") return tmp;
		for (int i = 0; i < size; i++) {
			if (elements[i] == code) return elements[i];
		}
		return tmp;
	}

	//funtions
	/*
	void resize(const int new_max_size = -1, const int new_step = -1) //new_step must be greater than 0
	{
		if (new_max_size >= 0) max_size = new_max_size;
		if (new_step > 0) step = new_step;
	}
	*/
	void push(const Type& value, const int& index = position+1)
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
			tmp[i+1] = elements[i];
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
	void pop_back() { pop_id(size - 1); }
	void pop_front() { pop_id(0); }
	int len() { return size; }
	int find(Type& element) {
		for (int i = 0; i < size; i++) {
			if (element == elements[i]) return i; 
		}
		return -1;
	}
	static void read(string path, NewConteiner<Type>& data)
	{
		ifstream file(path);
		int count; file >> count;
		Type* tmp = new Type[count];
		for (int i = 0; i < count; i++) { file >> tmp[i]; }
		NewConteiner<Type> tmp2(count, tmp); 
		data = tmp2;
		delete[] tmp;
		file.close();
		
		
	}
	//Movements 
	void next(const int& step = 1) { position += step; }
	void reset() { position = 0; }
	bool is_end() { (size == max_size) ? true : false; }



};
//Product
class Product
{
private:
	string code, name;
	double cost;

public:
	//constructors
	Product();
	Product(const string& ncode, const string& nname, const double& ncost);
	Product(const Product& new_product);
	Product(Product& new_product);
	//destructor
	~Product();
	
	//overloaded operations
	friend ifstream& operator>>(ifstream& buf, Product& data);
	friend istream& operator>>(istream& buf, Product& data);
	friend ostream& operator<<(ostream& buf, const Product& data);
	Product& operator=(const Product& new_product);
	bool operator==(string& str);
	bool operator==(Product& prod);
	//getters
	string get_name();
	string get_code();
	double get_cost();
};

//Receipt
template<typename Type>
class Receipt
{
private:
	int num;
	int size;
	Data data;
	NewConteiner<Type> cart;

public:
	//constructors
	Receipt<Type>() { num = 0; size = 0; data.timeinfo = NULL;  }
	/*
	Receipt<Type>(int nnum, int nsize, Type*& nproducts)
	{
		num = nnum;
		size = nsize;
		cart = NewConteiner<Type>(size, nproducts);
	}
	*/
	Receipt(const Receipt<Type>& receipt)
	{
		num = receipt.num;
		size = receipt.size;
		data = receipt.data;
		cart = NewConteiner<Type>(receipt.cart);
	}

	//destrictor
	virtual ~Receipt() {}

	//overloaded operations
	friend istream& operator>>(istream& buf, Receipt<Type>& data)
	{
		buf >> data.num >> data.size >> data.cart;
		return buf;
	}
	friend ostream& operator<<(ostream& buf, Receipt<Type>& data)
	{
		buf << "\nNumber of a receipt: " << data.num << endl;
		buf << "Data: " << endl;
		data.data.now();
		buf << "Products: \n";
		for (int i = 0; i < data.size; i++) {
			buf << data.cart[i];
		}
		buf << endl;
		return buf;
	}
	Receipt<Type>& operator=(const Receipt<Type>& receipt) 
	{
		num = receipt.num;
		size = receipt.size;
		data = receipt.data;
		cart = receipt.cart;
		return *this;
	}
	
	//functions
	void add(Cart<Product> product, int& count)
	{
		for (int i = 0; i < size; i++) {
			if (cart[i] == product) {
				cart[i] += count;
				return;
			}
		}
		size += 1;
		cart.push_back(product);
	}
	void add(Product product, int& count)
	{
		Cart<Product> tmp(product, count, product.get_cost());
		add(tmp, count);
	}

	void remove(Type& product, int& count)
	{
		for (int i = 0; i < size; i++) {
			if (cart[i] == product) {
				if (cart[i] <= count) { cart.pop_id(i); }
				else { cart[i] -= count; }
			}
		}
	}
	int sum()
	{
		int sum = 0;
		for (int i = 0; i < size; i++) {
			sum = sum + cart[i].cost*cart[i].count;
		}
		return sum;
	}
	void print_cart() { 
		if (!size) cout << "Nothing in the cart. Add something!" << endl;
		cout << "Your products:: " << endl;
		for (int i = 0; i < size; i++)
			cout << cart << endl;
	}
	void pdata() { data.now(); }
	void set_num(int q) { (q > 0) ? num = q : num = 1; }

	Cart<Product>& find(Base<Product>& product)
	{
		Cart<Product> tmp;
		for (int i = 0; i < size; i++)
		{
			if (cart[i] == product)
				return cart[i];
		}
		return tmp;
	}
	Cart<Product>& find(string& product)
	{
		Cart<Product> tmp;
		for (int i = 0; i < size; i++)
		{
			if (cart[i] == product)
				return cart[i];
		}
		return tmp;
	}

	int len()
	{
		return size;
	}
};

#endif

//constructors

