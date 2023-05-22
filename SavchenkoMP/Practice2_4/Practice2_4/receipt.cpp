#include <iostream>
#include <string>
#include "products.h"
#include "receipt.h"
#include "database.h"
using namespace std;

bool TReceiptLine::Scan(TDataBase& data, const string& code, const int _count) {
	int ind = data.Check(code);
	if (ind == -1) {
		cout << "Неправильный штрихкод. Побробуйте отсканировать другой." << endl;
		return false;
	}

	product = data.GetProduct(ind);
	count = _count;
	sum = (*product).GetCost() * count;
	return true;
}

bool TReceiptLine::operator==(const TReceiptLine& rl) {
	if (product == rl.product) return true;
	return false;
}
const TReceiptLine& TReceiptLine::operator=(const TReceiptLine& rl) {
	if (this == &rl) return (*this);
	product = rl.product;
	count = rl.count;
	sum = rl.sum;
	return (*this);
}

void TReceiptLine::AddCount(int _count) {
	if (_count > 0) {
		count += _count;
		sum += (*product).GetCost()* _count;
	}
}


// =====================================================================
// TReceipt

void TReceipt::Add(const TReceiptLine& product, int _count) {
	int i = products._find(product);
	if (i == -1) {
		products.Add(product);
		index = products.Count() - 1;
		sum += products[products.Count() - 1].GetSum();
	}
	else {
		products[i].AddCount(_count);
		index = i;
		sum += product.GetCost() * _count;
	}
}
void TReceipt::Del(int _index) {
	sum -= products[_index].GetSum();
	products.Del(_index);
	index--;
	if (index < 0) index = 0;
	if (index > products.Count()) index = products.Count();
}
void TReceipt::Del(const TReceiptLine& product) {
	int ind = products._find(product);
	sum -= products[ind].GetSum();
	products.Del(ind);
	index--;
	if (index < 0) index = 0;
	if (index > products.Count()) index = products.Count();
}
void TReceipt::Change(int ind, int _count) {
	products[ind].AddCount(_count);
}
void TReceipt::Cart() {
	cout << "Ваша корзина:" << endl;
	for (int i = 0; i < products.Count(); i++)
		cout << i+1 << ". " << products[i] << endl;
}
int TReceipt::Count() const{
	return products.Count();
}

void TReceipt::Show() const { // Показывает данные чека на мониторе
	cout << products[index] << endl;
}
void TReceipt::Payment(double _money) { // Печатает чек, т.е. заканчивается работа с данным покупателем
	for (int i = 0; i < products.Count(); i++) {
		sum += products[i].GetSum();
	}
	if (_money >= sum) {
		money = _money;
		odd_money = money - sum;
	}
	else {
		string exp = "Не достаточно денег.";
		throw exp;
	}

	cout << date << ' ' << time << endl;
	cout << products << endl;
	cout << "Итоговая сумма к оплате: " << sum << " руб." << endl;
	cout << "Вы оплатили: " << money << " руб." << endl;
	cout << "Ваша сдача: " << odd_money << " руб.\n" << endl;
	cout << "СПАСИБО ЗА ПОКУПКУ! ЖДЕМ ВАС СНОВО!!!" << endl;
}
void TReceipt::Clear() {
	products.Clear();
	index = 0;
	sum = 0;
}

void TReceipt::Next() {	// Показывает следующий продукт
	index++;
	if (index > products.Count())
		index = 0;
	cout << products[index] << endl;
}
void TReceipt::Now() {	// Показывает продукт, который сейчас выбран
	if (Count()) cout << products[index] << endl;
}
void TReceipt::Prev() {	// Показывает предыдущий продукт.
	index--;
	if (index == -1)
		index = products.Count();
	cout << products[index] << endl;
}

const TReceipt& TReceipt::operator=(const TReceipt& r) {
	if (this == &r) return (*this);
	index = r.index;
	products = r.products;
	date = r.date;
	time = r.time;
	sum = sum;

	money = money;
	odd_money = odd_money;
	return *this;
}

TReceiptLine TReceipt::operator[](int ind) {
	return products[ind];
}

void TReceipt::SetSum() {
	for (int i = 0; i < products.Count(); i++)
		sum += products[i].GetSum();
}