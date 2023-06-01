#ifndef _RECEIPT_H
#define _RECEIPT_H
#include <iostream>
#include <string>
#include "products.h"
#include "container.h"
#include "datentime.h"
#include "database.h"
#include "display.h"
using namespace std;

class TReceiptLine {
private:
	int count;
	double sum;
	TProduct* product;
public:
	TReceiptLine();

	bool Scan(TDataBase& data, const string& code, const int _count = 1);
	void AddCount(int _count = 1);
	string GetCode() const { return (*product).GetCode(); }
	string GetName() const { return (*product).GetName(); }
	double GetCost() const { return (*product).GetCost(); }
	int GetCount() const { return count; }
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
	int index;
	string code;	// Èíäèâèäóàëüíûé êîä ÷åêà
	TContainer<TReceiptLine> products;
	TDate date;
	TTime time;
	double sum;

	double money;
	double odd_money;

public:
	TReceipt();

	void Add(const TReceiptLine& product, int _count = 1);
	void Del(int index);
	void Del(const TReceiptLine& product);
	void Change(int ind, int _count);
	void Cart();
	int Count() const;
	
	double GetSum() const { return sum; }
	void SetCode(int _code);

	void Show() const;
	void Payment(TDataBase& data, const double _money);
	void Clear();

	void LastScan();

	void SetIndex(int _index) { _index = index; }
	void SetCLOCK() { date.setCurrentDay(); time.setCurrentTime(); }

	int _find(const TReceiptLine& rl) const { return products._find(rl); }
	int FindCount(const TReceiptLine& rl);

	const TReceipt& operator=(const TReceipt& r);

	TReceiptLine operator[](int ind);
	bool operator==(const TReceipt& r) const;
	friend ostream& operator<<(ostream& out, const TReceipt& r) {
		cout << "×åê #" << r.code << endl;
		cout << r.date << ' ' << r.time << "\n" << endl;
		cout << r.products << endl;
		cout << "Èòîãîâàÿ ñóììà ê îïëàòå: " << r.sum << " ðóá." << endl;
		cout << "Âû îïëàòèëè: " << r.money << " ðóá." << endl;
		cout << "Âàøà ñäà÷à: " << r.odd_money << " ðóá.\n" << endl;
		cout << "ÑÏÀÑÈÁÎ ÇÀ ÏÎÊÓÏÊÓ! ÆÄÅÌ ÂÀÑ ÑÍÎÂÀ!!!" << endl;
	}
};

#endif // !_RECEIPT_H