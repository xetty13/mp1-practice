#ifndef _RECEIPT_H
#define _RECEIPT_H
#include <iostream>
#include <string>
#include "products.h"
#include "container.h"
#include "datentime.h"
#include "database.h"
using namespace std;

class TReceiptLine {
private:
	int count = 0;
	double sum = 0;
	TProduct* product;
public:
	bool Scan(TDataBase& data, const string& code, const int _count = 1);
	void AddCount(int _count = 1);
	string GetCode() const { return (*product).GetCode(); }
	string GetName() const { return (*product).GetName(); }
	double GetCost() const { return (*product).GetCost(); }
	double GetSum() const { return sum; }

	bool operator==(const TReceiptLine& rl);
	const TReceiptLine& operator=(const TReceiptLine& rl);

	friend ostream& operator<<(ostream& out, const TReceiptLine& rl) {
		out << *(rl.product) << "*" << rl.count << " =" << rl.sum;
		return out;
	}
};

class TReceipt {
private:
	int index = 0;
	TContainer<TReceiptLine> products;
	TDate date;
	TTime time;
	double sum = 0;

	double money = 0;
	double odd_money = 0;

public:
	void Add(const TReceiptLine& product, int _count = 1);
	void Del(int index);
	void Del(const TReceiptLine& product);
	void Change(int ind, int _count);
	void Cart();
	int Count() const;
	
	void SetSum();
	double GetSum() { return sum; }

	void Show() const;
	void Payment(double money);
	void Clear();

	void Next();
	void Now();
	void Prev();

	void SetIndex(int _index) { _index = index; }
	void SetDate() { date.setCurrentDay(); }
	void SetTime() { time.setCurrentTime(); }

	int _find(const TReceiptLine& rl) { return products._find(rl); }

	const TReceipt& operator=(const TReceipt& r);

	TReceiptLine operator[](int ind);
	bool operator==(const TReceipt& r) { return false; }
	friend ostream& operator<<(ostream& out, const TReceipt& r) {
		cout << r.date << ' ' << r.time << "\n" << endl;
		cout << r.products << endl;
		cout << "Èòîãîâàÿ ñóììà ê îïëàòå: " << r.sum << " ðóá." << endl;
		cout << "Âû îïëàòèëè: " << r.money << " ðóá." << endl;
		cout << "Âàøà ñäà÷à: " << r.odd_money << " ðóá.\n" << endl;
		cout << "ÑÏÀÑÈÁÎ ÇÀ ÏÎÊÓÏÊÓ! ÆÄÅÌ ÂÀÑ ÑÍÎÂÎ!!!" << endl;
	}

	int DEBUGIndex() { return index; }
	int DEBUGSize() { return products.Size(); }
};
#endif // !_RECEIPT_H