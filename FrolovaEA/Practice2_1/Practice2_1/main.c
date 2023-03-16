#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "header.h"

int main() {

	int number;
	product* shipment;

	number = cntLines("sklad.txt");

	//	printf("%d\n",number);
	//	_getch();

	allocate_stock(&shipment, number);

	fill_shipment(shipment, number);

	find_null(shipment, number);

	free_stock(&shipment, number);


	return 0;
}