#ifndef _CONTAINER_H_ 
#define _CONTAINER_H_ 

#include <iostream> 
#include "Exception.h" 

using namespace std;

template <typename T, int maxsize>
class Container
{
	T* arr;
	int n;

public:
	Container();
	Container(T*, int);
	Container(const Container &x);
	~Container();
	bool isFull()const;
	bool isEmpty()const;
	int Find(T a)const;
	void Add(T a);
	void Delete(T a);
	void Delete1(int);
	T& operator[](int);
	const T& operator[](int) const;
	friend std::ostream& operator << (std::ostream & o, const Container& x)
	{
		for (int i = 0; i < x.n; i++)
		{
			cout « x[i] « " ";
		}
		return o;
	}
};

template <typename T, int maxsize>
Container <T, maxsize>::Container()
{
	n = 0;
	arr = new T[maxsize];
};

template <typename T, int maxsize>
Container <T, maxsize>::Container(const Container <T, maxsize> &c)
{
	n = c.n;
	arr = new T[n];
	for (int i = 0; i < n; i++)
		arr[i] = c.arr[i];
};

template <typename T, int maxsize>
Container <T, maxsize>::Container(T* arr1, int x)
{
	n = x;
	arr = new T[maxsize];
	for (int i = 0; i < n; i++)
		arr[i] = arr1[i];
};

template <typename T, int maxsize>
Container <T, maxsize>::~Container()
{
	n = 0;
	delete[] arr;
};

template <typename T, int maxsize>
bool Container <T, maxsize>::isFull() const
{
	return n == maxsize;
};

template <typename T, int maxsize>
bool Container <T, maxsize>::isEmpty() const
{
	return n == 0;
};

template <typename T, int maxsize>
int Container <T, maxsize>::Find(T a) const
{

	for (int i = 0; i < n; i++)
		if (arr[i] == a)
			return i;
	return -1;
};

template <typename T, int maxsize>
void Container <T, maxsize>::Add(T a)
{
	if (isFull())
	{
		throw Exception("Your container is full");
	}
	arr[n] = a;
	n++;
};

template <typename T, int maxsize>
void Container <T, maxsize>::Delete1(int idx)
{
	if (isEmpty())
	{
		throw Exception("Your container is empty");
	}
	arr[idx] = arr[n - 1];
	n--;
};

template <typename T, int maxsize>
void Container <T, maxsize>::Delete(T a)
{
	Delete1(Find(a));
}

template<typename T, int maxsize>
T& Container<T, maxsize>::operator[](int i)
{
	if (i > maxsize)
	{
		throw Exception("Array bounds");
	}
	return arr[i];
};

template<typename T, int maxsize>
const T& Container<T, maxsize>::operator[](int i) const
{
	if (i > maxsize)
	{
		throw Exception("Array bounds");
	}
	return arr[i];
};

//Специализация 
template <typename T, int maxsize>
class Container <T*, maxsize>
{
	T** arr;
	int n;

public:
	Container();
	Container(T**, int);
	Container(const Container <T*, maxsize> &x);
	~Container();
	bool isFull()const;
	bool isEmpty()const;
	int Find(T* a)const;
	void Add(T* a);
	void Delete(T* a);
	void Delete1(int);
	T& operator[](int);
	const T& operator[](int) const;

	friend std::ostream& operator << (std::ostream & o, const Container& x)
	{
		for (int i = 0; i < x.n; i++)
		{
			cout « x[i] « " ";
		}
		return o;
	}
};

template <typename T, int maxsize>
Container <T*, maxsize>::Container()
{
	n = 0;
	arr = new T*[maxsize];
};

template <typename T, int maxsize>
Container <T*, maxsize>::Container(T** arr1, int x)
{
	n = x;
	arr = new T*[maxsize];
	for (int i = 0; i < n; i++)
		arr[i] = new T(*(arr1[i]));
};

template <typename T, int maxsize>
Container <T*, maxsize>::Container(const Container <T*, maxsize> &c)
{
	n = c.n;
	arr = new T*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new T(*(c.arr[i]));
};

template <typename T, int maxsize>
Container <T*, maxsize>::~Container()
{
	n = 0;
	delete[] arr;
};

template <typename T, int maxsize>
bool Container <T*, maxsize>::isFull() const
{
	return n == maxsize;
};

template <typename T, int maxsize>
bool Container <T*, maxsize>::isEmpty() const
{
	return n == 0;
};

template <typename T, int maxsize>
int Container <T*, maxsize>::Find(T* a) const
{
	for (int i = 0; i < n; i++)
		if (arr[i] == a)
			return i;
	return -1;
};

template <typename T, int maxsize>

void Container <T*, maxsize>::Add(T* a)
{
	if (isFull())
	{
		throw Exception("Your container is full");
	}
	arr[n] = a;
	n++;
};

template <typename T, int maxsize>
void Container <T*, maxsize>::Delete1(int idx)
{
	if (isEmpty())
	{
		throw Exception("Your container is empty");
	}
	arr[idx] = arr[n - 1];
	n--;
};

template <typename T, int maxsize>
void Container <T*, maxsize>::Delete(T* a)
{
	Delete1(Find(a));
}

template<typename T, int maxsize>
T& Container<T*, maxsize>::operator[](int i)
{
	if (i > maxsize)
	{
		throw Exception("Array bounds");
	}
	return *arr[i];
};

template<typename T, int maxsize>
const T& Container<T*, maxsize>::operator[](int i) const
{
	if (i > maxsize)
	{
		throw Exception("Array bounds");
	}
	return *arr[i];
};

#endif