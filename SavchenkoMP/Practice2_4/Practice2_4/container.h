#ifndef _CONTAINER_H
#define _CONTAINER_H
#include <iostream>
#include <string>
using namespace std;

template <typename TELEM>
class TContainer {
private:
	TELEM* elem;	// Массив хранимых элементов
	int size;		// Размер массива
	int count;		// к-во реально хранимых элементов
	int sizestep;

public:
	TContainer(int _size = 5, int _sizestep = 10);
	TContainer(const TContainer& _cnt);
	~TContainer();

	int Count() const;
	int Size() const;
	int Sizestep() const;

	void Add(const TELEM& _elm);
	void Del(int index);

	TELEM& operator[](int index) const;

	bool operator!=(const TContainer& _cnt) const;
	bool operator==(const TContainer& _cnt) const;

	// присваивание контейнеров
	const TContainer& operator=(const TContainer& _cnt);
	// объединение контейнеров
	TContainer operator+(const TContainer& _cnt);
	// пересечение контейнеров
	TContainer operator*(const TContainer& _cnt);
	// разность контейнеров
	TContainer operator-(const TContainer& _cnt);

	friend ostream& operator<<(ostream& out, const TContainer<TELEM>& _elm) {
		for (int i = 0; i < _elm.Count(); i++)
			out << _elm[i] << endl;
		return out;
	}

	void Clear();
	// Выделяет новую память, которую указал пользователь, и меняет размер шага. БЕЗ КОПИРОВАНИЯ ЭЛЕМЕНТОВ
	void ChangeMemorry(int _size, int _sizestep = 10);
	// Выделяет новую память без свободных мест для новых элементов контейнера
	void Compress();

	// Найти индекс элемента. -1 - элемент не найден.
	int _find(const TELEM& _elm) const;	// Найти индекс элемента
protected:
	// Изменить размер массива
	void resize(int dsize = 0);
};


// ========== ОБЪЯВЛЕНИЕ ========== //

template <typename TELEM>
TContainer<TELEM>::TContainer(int _size, int _sizestep) {
	if (_size <= 0) {
		string exp = "cntWRONGMEMCOUNT";
		throw std::out_of_range(exp);
	}
	size = _size;
	sizestep = _sizestep;
	count = 0;
	elem = new TELEM[size];
}
template <typename TELEM>
TContainer<TELEM>::TContainer(const TContainer& _cnt) {
	size = _cnt.size;
	count = _cnt.count;
	elem = new TELEM[size];
}
template <typename TELEM>
TContainer<TELEM>::~TContainer() {
	if (size > 0) {
		delete[] elem;
		elem = 0;
		count = 0;
		size = 0;
	}
}

template <typename TELEM>
int TContainer<TELEM>::Count() const { return count; }
template <typename TELEM>
int TContainer<TELEM>::Size() const { return size; }
template <typename TELEM>
int TContainer<TELEM>::Sizestep() const { return sizestep; }

template <typename TELEM>
void TContainer<TELEM>::Add(const TELEM& _elm) {
	if (_find(_elm) == -1) {
		if (size == count)
			resize();
		elem[count++] = _elm;
	}
}
template <typename TELEM>
void TContainer<TELEM>::Del(int index) {
	if (index > -1 && index < count)
		for (int i = index; i < count - 1; i++)
			elem[i] = elem[i + 1];
	count--;
}

template <typename TELEM>
TELEM& TContainer<TELEM>::operator[](int index) const {
	if (index < 0 || index >= count) {
		string exp = "cntINDOUTOFRANGE";
		throw std::out_of_range(exp);
	}
	return elem[index];
}

template <typename TELEM>
bool TContainer<TELEM>::operator!=(const TContainer& _cnt) const {
	if (this == &_cnt) return false;
	if (size == _cnt.size && count == _cnt.count && sizestep == _cnt.sizestep)
		for (int i = 0; i < count; i++)
			if (elem[i] == _cnt.elem[i]) return false;
	return true;
}
template <typename TELEM>
bool TContainer<TELEM>::operator==(const TContainer& _cnt) const {
	if (this == &_cnt) return true;
	return !((*this) != _cnt);
}

// присваивание контейнеров
template <typename TELEM>
const TContainer<TELEM>& TContainer<TELEM>::operator=(const TContainer& _cnt) {
	if ((*this) != _cnt) {
		delete[] elem;;
		size = _cnt.size;
		count = _cnt.count;
		sizestep = _cnt.sizestep;
		elem = new TELEM[size];
		for (int i = 0; i < count; i++)
			elem[i] = _cnt.elem[i];
	}
	return *this;
}
// объединение контейнеров
template <typename TELEM>
TContainer<TELEM> TContainer<TELEM>::operator+(const TContainer& _cnt) {
	int i;
	TContainer<TELEM> tmp(count + _cnt.count + sizestep);
	for (i = 0; i < count; i++)
		tmp.elem[i] = elem[i];
	tmp.count = count;
	for (i = 0; i < _cnt.count; i++)
		tmp.Add(_cnt.elem[i]);
	return tmp;
}
// пересечение контейнеров
template <typename TELEM>
TContainer<TELEM> TContainer<TELEM>::operator*(const TContainer& _cnt) {
	int i;
	int ss = count;
	if (ss < _cnt.count) ss = _cnt.count;
	TContainer<TELEM> tmp(ss + sizestep);
	tmp.count = 0;
	for (i = 0; i < count; i++)
		if (_cnt._find(elem[i]) != -1) tmp.elem[tmp.count++] =
			elem[i];
	return tmp;
}
// разность контейнеров
template <typename TELEM>
TContainer<TELEM> TContainer<TELEM>::operator-(const TContainer& _cnt) {
	int i;
	TContainer<TELEM> tmp(count + sizestep);
	tmp.count = 0;
	for (i = 0; i < count; i++)
		if (_cnt._find(elem[i]) == -1) tmp.elem[tmp.count++] =
			elem[i];
	return tmp;
}

template <typename TELEM>
void TContainer<TELEM>::Clear() {
	while (count) {
		Del(count - 1);
	}
}

// Выделяет новую память, которую указал пользователь, и меняет размер шага. БЕЗ КОПИРОВАНИЯ ЭЛЕМЕНТОВ
template <typename TELEM>
void TContainer<TELEM>::ChangeMemorry(int _size, int _sizestep) {  // (int _size, int _sizestep = 10)
	if (size > 0) {
		delete[] elem;
		size = _size;
		sizestep = _sizestep;
		count = 0;
		elem = new TELEM[size];
	}
}
// Выделяет новую память без свободных мест для новых элементов контейнера
template <typename TELEM>
void TContainer<TELEM>::Compress() {
	int dsize = count - size;
	if (dsize)
		resize(dsize);
}

// Найти индекс элемента. -1 - элемент не найден.
template <typename TELEM>
int TContainer<TELEM>::_find(const TELEM& _elm) const {
	int nom = -1;
	int i = 0;
	while (i < count && nom == -1)
		if (elem[i] == _elm) nom = i; else i++;
	return nom;
}

template <typename TELEM>
void TContainer<TELEM>::resize(int dsize) {  // (int dsize = 0)
	if (dsize == 0) dsize = sizestep;
	size += dsize;
	TELEM* tmp = new TELEM[size];
	for (int i = 0; i < count; i++)
		tmp[i] = elem[i];
	delete[] elem;
	elem = tmp;
}
#endif // !_CONTAINER_H