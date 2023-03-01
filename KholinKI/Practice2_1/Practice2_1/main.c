#include <stdio.h>
#include "Functions_structures.h"
#include <locale.h>
#include <string.h>
#include <malloc.h>


int main(int argc,char *argv[]) {
	system("chcp 1251");
	setlocale(LC_ALL, "rus");




	struct dynamic_matrix *file = &my_file;//pointer to dynamic_matrix structure
	FILE* fptr;//creating file var



	fptr = fopen("C://TouristAgences.txt", "r");//open the file for reading
	if (fopen == NULL) {
		printf("Ошибка!Файл не найден\n");//check
		exit(-99999999999999);//normal program termination
	}



	line_reading(fptr, file);//count the lengths of the lines in the file
	file_reader(file, fptr);//reading and processing data from a file
	print_data();//file output 
	free_matrix(file);//Washing the pens

	return 0;
}