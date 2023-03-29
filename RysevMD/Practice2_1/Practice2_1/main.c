#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stars.h"


int main() {
	system("chcp 1251");

	Ñonstellation* constellations;

	read_data(&constellations);
	cnst_table(constellations);
	choice(constellations);
	
	return 0;
}