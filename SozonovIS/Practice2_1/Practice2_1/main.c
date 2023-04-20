#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>
#include "header.h"

int main(){
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	int n;
	TSchool **sc;

	n = counting();
	allocation(&sc, n);
	read_file(sc);
	print_file(sc, n);
	sorting(sc, n);
	printf("\n");
	printf("\n");
	print_file(sc, n);

	release(&sc, n);

	return 0;
}