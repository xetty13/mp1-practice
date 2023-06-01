#ifndef _RECEIPT_H
#define _RECEIPT_H

#include <string>
#include "Container.h"

struct TProduct 
{
	int code;
	string name;
	float price;

	bool operator==(const TProduct&) const;
	friend ostream& operator<<(ostream&, const TProduct&);
};

struct TInfoProduct 
{
	TProduct product;
	int count;

	bool operator==(const TInfoProduct&) const;
	friend ostream& operator<<(ostream&, const TInfoProduct&);
};

class TProductsDatabase 
{
private:
	TContainer<TInfoProduct> products;

	void get_correct_file_name(const string& fname) const;
	bool check_file_name(const string& fname) const;
public:
	TProductsDatabase(const string& filename);
	TInfoProduct& operator[](int ind);
	
	int barcode_search(const int barcode);
	int Get_num_prods() const;

	void Updating_remove(const TProduct& prod);
	void Updating_add(const TProduct& prod);
	friend ostream& operator<<(ostream&, const TProductsDatabase&);
	// operator <<
};

class TReceiptLine 
{
private:
	TProduct product;
	int count;
	double summ;
public:
	TReceiptLine();
	TReceiptLine(TProduct& product, int count, double sum_price);
	TReceiptLine(const TReceiptLine&);

	const TReceiptLine& operator= (const TReceiptLine&);
	bool operator==(const TReceiptLine&) const;
	friend ostream& operator<<(ostream& out, const TReceiptLine& rec_line);

	const TProduct& Get_product() const;
	int Get_count() const;
	double Get_sum_cost() const;

	void Set_count(int);
	void Set_sum_cost(double);

};

struct TDate 
{
	int day;
	int month;
	int year;

	TDate();
};

struct TTime 
{
	int hour;
	int minute;
	int second;

	TTime();
};

class TReceipt 
{
private:
	static long code;
	TDate date;
	TTime time;
	TContainer<TReceiptLine> products;

	static void Code_increase();
public:
	TReceipt();
	TReceipt(const TReceipt&);
	int Find_product(const long) const;
	int Get_num_products() const;
	void Add_new_prod(const TReceiptLine&);
	double Get_total_sum() const;
	void SetTime();
	void Delete_prod(const int ind);
	void Delete(TProductsDatabase& db);
	void Add(TProductsDatabase& db, int search);
	TReceiptLine& operator[](int);
	friend ostream& operator<<(ostream& out, TReceipt& rec);
	const TReceipt& operator= (const TReceipt&);
};


#endif
