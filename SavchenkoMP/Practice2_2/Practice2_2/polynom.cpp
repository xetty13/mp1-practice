#include <iostream>
#include <fstream> 
#include "polynom.h"
using namespace std;

TPolynom::TPolynom(void) {  // По умолчанию
	degree = 0;
	coeff = new float[degree + 1];
	for (int i = degree; i >= 0; i--)
		coeff[i] = 0;
}
TPolynom::TPolynom(const TPolynom& p) { // Копирование
	degree = p.degree;
	coeff = new float[degree + 1];
	for (int i = degree; i >= 0; i--)
		coeff[i] = p.coeff[i];
}
TPolynom::TPolynom(int _degree) { // Преобразование типа
	degree = _degree;
	coeff = new float[degree + 1];
	for (int i = degree; i >= 0; i--)
		coeff[i] = 0;
}
TPolynom::TPolynom(int _degree, float _coeff) { // Инициализатор, все coeff = _coeff
	degree = _degree;
	coeff = new float[degree + 1];
	for (int i = degree; i >= 0; i--)
		coeff[i] = _coeff;
}
TPolynom::~TPolynom(void) { // Деконструктор
	if (degree + 1)
		delete[] coeff;
	degree = 0;
}


bool TPolynom::operator==(const TPolynom& p) const {
	if (degree != p.degree) return false;
	for (int i = degree; i >= 0; i--)
		if (coeff[i] != p.coeff[i])
			return false;
	return true;
}
bool TPolynom::operator!=(const TPolynom& p) const {
	return !(*this == p);
}
TPolynom& TPolynom::operator=(const TPolynom& p) {
	if (this != &p) {
		if (degree != p.degree) {
			delete[] coeff;
			degree = p.degree;
			coeff = new float[degree + 1];
		}
		for (int i = degree; i >= 0; i--)
			coeff[i] = p.coeff[i];
	}

	return (*this);
}

TPolynom TPolynom::operator+(const TPolynom& p) {
	TPolynom res;
	res.Add(*this, p);
	return res;
}
TPolynom TPolynom::operator-(const TPolynom& p) {
	TPolynom res;
	res.Minus(*this, p);
	return res;
}
TPolynom TPolynom::operator*(const TPolynom& p) {
	TPolynom res;
	res.Multi(*this, p);
	return res;
}
float TPolynom::operator()(float _x) {
	return Value(_x);
}

TPolynom& TPolynom::operator+=(const TPolynom& p) {
	return AddEq(p);
}
TPolynom& TPolynom::operator-=(const TPolynom& p) {
	return MinusEq(p);
}
TPolynom& TPolynom::operator*=(const TPolynom& p) {
	return MultiEq(p);
}

void read_file(TPolynom** p, int& n) {
	/*
	Чтение происходит из файла "data.txt"
	-В первой строке - количество полиномов
	-В второй строке перечисленны степени каждого полинома
	-В последующих строках перечисленны коэффициенты полиномов

	!!!Предполагается, что введенные данные верны!!!
	*/

	int dgr;
	ifstream file;

	file.open("data.txt");
	if (!file.is_open())
		throw "Файл данных не открыт";

	file >> n;
	*p = new TPolynom[n];
	for (int i = 0; i < n; i++) {
		file >> dgr;
		(*p)[i].Rebuffer(dgr);
	}
	for (int i = 0; i < n; i++) {
		for (int j = (*p)[i].degree; j >= 0; j--)
			file >> (*p)[i].coeff[j];
		if (!(*p)[i].coeff[(*p)[i].degree])
			(*p)[i].Rebuffer();
	}

	file.close();
}


void TPolynom::Fill_hand() {
	for (int i = degree; i >= 0; i--) {
		cout << "x^" << i << " = ";
		cin >> coeff[i];
	}
	cout << endl;
}
void TPolynom::Show() {
	cout << coeff[degree];
	if (!coeff[degree]) {
		cout << "x^0" << endl;
		return;
	}

	cout << "x^" << degree << " ";
	for (int i = degree - 1; i >= 0; i--) {
		if (coeff[i] > 0)
			cout << "+ " << coeff[i] << "x^" << i << " ";
		else if (coeff[i] < 0)
			cout << "- " << -coeff[i] << "x^" << i << " ";
	}
	cout << endl;
}
void TPolynom::Copy(const TPolynom& p) {
	this->Rebuffer(p.degree);
	for (int i = degree; i >= 0; i--)
		coeff[i] = p.coeff[i];
}


TPolynom TPolynom::Add(const TPolynom& p1, const TPolynom& p2) {
	this->Rebuffer(max_d(p1.degree, p2.degree));

	if (p1.degree >= p2.degree) {
		for (int i = p1.degree; i >= 0; i--)
			coeff[i] = p1.coeff[i];
		for (int i = p2.degree; i >= 0; i--)
			coeff[i] += p2.coeff[i];
	}
	else {
		for (int i = p2.degree; i >= 0; i--)
			coeff[i] = p2.coeff[i];
		for (int i = p1.degree; i >= 0; i--)
			coeff[i] += p1.coeff[i];
	}
	if (coeff[degree] == 0)
		this->Rebuffer();
	return *this;
}
TPolynom TPolynom::Minus(const TPolynom& from, const TPolynom& substract) {
	this->Rebuffer(max_d(from.degree, substract.degree));
	for (int i = degree; i >= 0; i--)
		coeff[i] = 0.f;

	for (int i = from.degree; i >= 0; i--)
		coeff[i] = from.coeff[i];
	for (int i = substract.degree; i >= 0; i--)
		coeff[i] -= substract.coeff[i];

	if (coeff[degree] == 0)
		this->Rebuffer();
	return *this;
}
TPolynom TPolynom::Multi(const TPolynom& p1, const TPolynom& p2) {
	this->Rebuffer(p1.degree + p2.degree);

	for (int i = p1.degree; i >= 0; i--)
		for (int j = p2.degree; j >= 0; j--)
			coeff[i + j] += p1.coeff[i] * p2.coeff[j];

	return *this;
}
TPolynom TPolynom::Diff(const TPolynom& p) {
	this->Rebuffer(0);

	if (p.degree) {
		this->Rebuffer(p.degree - 1);
		for (int i = p.degree - 1; i >= 0; i--)
			coeff[i] = p.coeff[i + 1] * (i + 1);
	}

	return *this;
}


TPolynom& TPolynom::AddEq(const TPolynom& p) {
	if (p.degree > degree)
		this->Resize(p.degree);

	for (int i = p.degree; i >= 0; i--)
		coeff[i] += p.coeff[i];

	if (coeff[degree] == 0)
		this->Rebuffer();
	return *this;
}
TPolynom& TPolynom::MinusEq(const TPolynom& p) {
	if (p.degree > degree)
		this->Resize(p.degree);

	for (int i = p.degree; i >= 0; i--)
		coeff[i] -= p.coeff[i];

	if (coeff[degree] == 0)
		this->Rebuffer();
	return *this;
}
TPolynom& TPolynom::MultiEq(const TPolynom& p) {
	int tmp_d = degree + p.degree;
	TPolynom tmp(tmp_d);

	for (int i = degree; i >= 0; i--)
		for (int j = p.degree; j >= 0; j--)
			tmp.coeff[i + j] += coeff[i] * p.coeff[j];

	this->Rebuffer(tmp_d);
	for (int i = tmp_d; i >= 0; i--)
		coeff[i] = tmp.coeff[i];

	return *this;
}
TPolynom& TPolynom::DiffEq() {
	int tmp_d = degree - 1;
	TPolynom tmp(tmp_d);

	if (degree == 0)
		return *this;
	else {
		for (int i = tmp_d; i >= 0; i--)
			tmp.coeff[i] = coeff[i + 1] * (i + 1);
	}

	this->Rebuffer(tmp_d);
	for (int i = tmp_d; i >= 0; i--)
		coeff[i] = tmp.coeff[i];

	return *this;
}



float TPolynom::Value(float _x) {
	float res = 0.0f, x = 1.0f;
	for (int i = degree; i >= 0; i--) {
		res += coeff[i] * x;
		x *= _x;
	}
	return res;
}



void TPolynom::Rebuffer(int newDegree) { // Изменяет кол-во коэф-ов и зануляет их
	if (degree + 1)
		delete[] coeff;
	degree = newDegree;
	coeff = new float[degree + 1];
	for (int i = degree; i >= 0; i--)
		coeff[i] = 0.f;
}
void TPolynom::Rebuffer() { // Проверяет, есть ли у высоких степеней коэф 0. Если да, то уменьшается степень с копированием коэф-ов


	int tmp_dgr = degree;
	for (int i = degree; i >= 0; i--)
		if (coeff[i]) {
			tmp_dgr = i;
			break;
		}

	if (tmp_dgr != degree) {
		float* tmp = new float[degree + 1];
		_coeffcopy(tmp, coeff);

		if (degree + 1)
			delete[] coeff;
		degree = tmp_dgr;
		coeff = new float[degree + 1];
		for (int i = tmp_dgr; i >= 0; i--)
			coeff[i] = tmp[i];

		delete[] tmp;
	}
}
void TPolynom::Resize(int newDegree) {
	int tmp_degree = degree;
	float* tmp = new float[tmp_degree];
	_coeffcopy(tmp, coeff);

	if (degree + 1)
		delete[] coeff;
	degree = newDegree;
	coeff = new float[degree + 1];
	for (int i = degree; i > tmp_degree; i--)
		coeff[i] = 0.f;
	for (int i = tmp_degree; i >= 0; i--)
		coeff[i] = tmp[i];
	delete[] tmp;
}
void TPolynom::_coeffcopy(float* copy, float* from) {
	for (int i = degree; i >= 0; i--)
		copy[i] = from[i];
}

float power(float x, int n) {
	float res = 1.f;
	for (int i = 0; i < n; i++)
		res *= x;
	return res;
}
int max_d(int a, int b) {
	return (a > b) ? a : b;
}
int min_d(int a, int b) {
	return (a < b) ? a : b;
}

