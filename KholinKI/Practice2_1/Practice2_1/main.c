#include <stdio.h>
#include "Functions_structures.h"
#include <locale.h>
#include <string.h>
#include <malloc.h>

char euro_zone[20][15] = {//list of eurozone countries
	"Austria\n",
	"Belgium\n",
	"Cyprus\n",
	"Estonia\n",
	"Finland\n",
	"France\n",
	"Germany\n",
	"Greece\n",
	"Ireland\n",
	"Italy\n",
	"Latvia\n",
	"Lithuania\n",
	"Luxembourg\n",
	"Malta\n",
	"Netherlands\n",
	"Portugal\n",
	"Slovakia\n",
	"Slovenia\n",
	"Croatia\n"
};

int main(int argc,char *argv[]) {
	system("chcp 1251");
	setlocale(LC_ALL, "rus");


	FILE* fptr;//creating file var


	fptr = fopen("C://TouristAgences.txt", "r");//open the file for reading
	if (fopen == NULL) {
		printf("Ошибка!Файл не найден\n");//check
		exit(-99999999999999);//normal program termination
	}
	int i = 0;

	TAgency* agencies;
	allocate_struct();
	free_memory();

	char* p_ezone[20];//massive pointers
	for (i = 0; i < 20; i++) {
		p_ezone[i] = &euro_zone[i][0];//get adresses strings of list
	}

/*	pointer = file_reader(fptr, &pointer);//process reading file and filling into structure
	output_data_file(fptr, &pointer, p_ezone);//the choice of eurozone countries
	free_memory(&pointer);//wash my pens*/
	return 0;
}