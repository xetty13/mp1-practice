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
	TContainer(int _size = 5, int _sizestep = 10) {
		size = _size;
		sizestep = _sizestep;
		count = 0;
		elem = new TELEM[size];
	}
	TContainer(const TContainer& _cnt) {
		size = _cnt.size;
		count = _cnt.count;
		elem = new TELEM[size];
	}
	~TContainer() {
		if (size > 0) {
			delete[] elem;
			elem = 0;
			count = 0;
			size = 0;
		}
	}

	const int& Count() const { return count; }
	int& Count() { return count; }
	const int& Size() const { return size; }
	int& Size() { return size; }
	const int& Sizestep() const { return sizestep; }

	void Add(const TELEM& _elm) {
		if (_find(_elm) == -1) {
			if (size == count)
				resize();
			elem[count++] = _elm;
		}
	}
	void Del(int index) {
		if (index > -1 && index < count)
			for (int i = index; i < count - 1; i++)
				elem[i] = elem[i + 1];
		count--;
	}
	TELEM& operator[](int index) {
		if (index < 0 || index >= count) {
			string exp = "cntINDOUTOFRANGE";
			throw exp;
		}
		return elem[index];
	}
	const TELEM& operator[](int index) const {
		if (index < 0 || index >= count) {
			string exp = "cntINDOUTOFRANGE";
			throw exp;
		}
		return elem[index];
	}

	friend ostream& operator<<(ostream& out, const TContainer<TELEM>& _elm) {
		for (int i = 0; i < _elm.Count(); i++)
			out << _elm[i] << endl;
		return out;
	}

	void Clear() {
		while (count) {
			Del(count - 1);
		}
	}

	void ChangeMemorry(int _size, int _sizestep = 10) { // Выделяет новую, которую указал пользователь и меняет размер шага
		if (size > 0) {
			delete[] elem;
			size = _size;
			sizestep = _sizestep;
			count = 0;
			elem = new TELEM[size];
		}
	}
	void Compress() { // Выделяет новую память без свободных мест для новых элементов контейнера
		int dsize = count - size;
		if (dsize)
			resize(dsize);
	}

	int _find(const TELEM& _elm) const { // Найти индекс элемента
		int nom = -1;
		int i = 0;
		while (i < count && nom == -1)
			if (elem[i] == _elm) nom = i; else i++;
		return nom;
	}

private:
	void resize(int dsize = 0) { // Изменить размер массива
		if (dsize == 0) dsize = sizestep;
		size += dsize;
		TELEM* tmp = new TELEM[size];
		for (int i = 0; i < count; i++)
			tmp[i] = elem[i];
		delete[] elem;
		elem = tmp;
	}
};


#endif // !_CONTAINER_H