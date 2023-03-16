#ifndef _HEADER_H
#define _HEADER_H

typedef struct
{
	char* name;
	int number;
} product;

int cntLines(const char* filename);
void allocate_stock(product** shipment, int number);
void fill_shipment(product* shipment, int number);
void find_null(product* shipment, int number);
void free_stock(product** shipment, int number);

#endif