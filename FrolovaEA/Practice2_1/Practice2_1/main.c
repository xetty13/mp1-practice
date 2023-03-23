#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "header.h"

int main() {

	int number;
	product* shipment;
	date* data;

	number = cntLines("sklad.txt");

	//	printf("%d\n",number);
	//	_getch();

	allocate_stock(&shipment, &data, number);

	fill_shipment(shipment, data, number);

	find_null(shipment, data, number);

	free_stock(&shipment, &data, number);


	return 0;
}