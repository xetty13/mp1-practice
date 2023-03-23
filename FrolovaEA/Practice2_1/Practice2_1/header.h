#ifndef _HEADER_H
#define _HEADER_H

typedef struct
{
	char* name;
	char* unit;
	double price;
	int number;
} product;

typedef struct
{
	int day;
	int month;
	int year;
} date;

int cntLines(const char* filename);
void allocate_stock(product** shipment, date** data, int number);
void fill_shipment(product* shipment, date* data, int number);
void find_null(product* shipment, date* data, int number);
void free_stock(product** shipment, date** data, int number);

#endif