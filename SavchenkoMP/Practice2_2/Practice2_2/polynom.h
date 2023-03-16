#ifndef _POLYNOM_H
#define _POLYNOM_H

#include <fstream> 

struct TPolynom {
	int degree;
	float* coeff;

	TPolynom(void);				// По умолчанию
	TPolynom(const TPolynom& p);// Копирование
	TPolynom(int _degree);		// Инициализатор (Преобразование типа?)
	TPolynom(int _degree, float _coeff); // Инициализатор, все coeff = _coeff
	~TPolynom(void);			// Деконструктор

	bool operator==(const TPolynom& p) const;
	bool operator!=(const TPolynom& p) const;
	TPolynom& operator=(const TPolynom& p);

	TPolynom operator+(const TPolynom& p);
	TPolynom operator-(const TPolynom& p);
	TPolynom operator*(const TPolynom& p);
	float operator()(float _x);

	//!!! WIP !!!
	TPolynom& operator+=(const TPolynom& p);
	TPolynom& operator-=(const TPolynom& p);
	TPolynom& operator*=(const TPolynom& p);

	void Fill_hand();		// Заполнение от руки
	void Show();
	void Copy(const TPolynom& p);


	TPolynom Add(const TPolynom& p1, const TPolynom& p2);
	TPolynom Minus(const TPolynom& p1, const TPolynom& p2);
	TPolynom Multi(const TPolynom& p1, const TPolynom& p2);
	TPolynom Diff(const TPolynom& p);

	TPolynom& AddEq(const TPolynom& p);
	TPolynom& MinusEq(const TPolynom& p);
	TPolynom& MultiEq(const TPolynom& p);
	TPolynom& DiffEq();

	float Value(float x);

	void Rebuffer(int newDegree);
	void Rebuffer();
	void Resize(int newDegree);
	void _coeffcopy(float* c1, float* c2);
};

void read_file(TPolynom** p, int& n);

float power(float x, int n);
int max_d(int a, int b);
int min_d(int a, int b);

#endif