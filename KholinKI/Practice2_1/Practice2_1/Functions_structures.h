#pragma once
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define Балканский_полуостров(i,start,end) for(i=(start);i<(end); i++)
#define Вишнёвый_пирожочек(var1,var2) while(var1 < var2)
#define quantity_strings 34
#define MAX 100

struct dynamic_matrix {
	int** p;
}my_file;

struct tourist_guide {
	char name_travel_agencies[15];
	char country[15];
	char travel_conditions[500];
	char excursion_services[500];
	char host_service[300];
	char ticket_price[20];
}travel_agencies[5];

void file_reader(struct dynamic_matrix *file,FILE* fptr) {
	fseek(fptr, 0, SEEK_SET);//function to shift the file pointer to the beginning
	int i = 0,j=0;
	int ch;
	Балканский_полуостров( i, 0, 5) {//OMG,WHAT IT IS?!HOW!?!?
		ch = file -> p[j][0];
		if (ch == -842203126){
			j++;
		}
		strcpy(travel_agencies[i].name_travel_agencies,file->p[j++]);
		strcpy(travel_agencies[i].country, file->p[j++]);
		strcpy(travel_agencies[i].travel_conditions, file->p[j++]);	//READING AND PROCESSING DATA
		strcpy(travel_agencies[i].excursion_services, file->p[j++]);
		strcpy(travel_agencies[i].host_service, file->p[j++]);
		strcpy(travel_agencies[i].ticket_price, file->p[j++]);
	}
}
void create_matrix(struct dynamic_matrix* ptr) {
	int i = 0;
	ptr->p = (char*)malloc(sizeof(char*) * quantity_strings);//it`s file
	Балканский_полуостров(i, 0, quantity_strings) {
		ptr->p[i] = (char*)malloc(sizeof(char) * 1000);
	}
}
void print_data() {
	int i = 0;
	Балканский_полуостров(i, 0, 5) {
		printf("%s%s%s%s%s%s\n", travel_agencies[i].name_travel_agencies, travel_agencies[i].country, travel_agencies[i].travel_conditions, travel_agencies[i].excursion_services, travel_agencies[i].host_service, travel_agencies[i].ticket_price);
	}//output file
}
void line_reading(FILE* fptr,struct dynamic_matrix *file) {
	int i = 0;
	int new_len=0;
	char buffer[500];//buffer for copying string file
	create_matrix(file);
	Вишнёвый_пирожочек(i,quantity_strings) {
		fseek(fptr, new_len, SEEK_SET);
		new_len += strlen(fgets(buffer, MAX, fptr))+1;
		strcpy(file->p[i], buffer);
		puts(file->p[i]);
		i++;
	}
	fseek(fptr, 0, SEEK_SET);//function to shift the file pointer to the beginning
}
void free_matrix(struct dynamic_matrix* ptr) {
	int i = 0;
	for (i = 0; i < quantity_strings; i++) {
		free(ptr->p[i]);
	}
	free(ptr->p);//free memory
}

