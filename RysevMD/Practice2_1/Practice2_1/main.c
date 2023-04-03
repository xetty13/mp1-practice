#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stars.h"


int main() {
	system("chcp 1251");

	Constellation* constellations;
	int cns_count;

	read_data(&constellations, &cns_count);
	cnst_table(constellations, cns_count);
	choice(constellations, cns_count);
	
	return 0;
}