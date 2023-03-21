#include <stdio.h>
#include "Functions_structures.h"
#include <locale.h>
#include <string.h>
#include <malloc.h>

/*Tourist Guide.The guide contains a list of travel agenciesand the services they offer
(country, city or itinerary of the cruise, accommodation and travel conditions, excursions, host service, price of the trip).
Provide a list of travel agencies offering tours to Eurozone countries.
*/

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
		printf("Error!File not found\n");//check
		exit(-99999999999999);//normal program termination
	}
	int i = 0;
	TAgency** my_list_agencies;//create massive pointers
	file_reader(fptr, &my_list_agencies);//reading data on file
	//output_all_data(fptr, my_list_agencies);//all data
	char* p_ezone[20];//massive pointers
	for (i = 0; i < 20; i++) {
		p_ezone[i] = &euro_zone[i][0];//get adresses strings of list
	}
	output_data_EZONES(fptr, my_list_agencies, p_ezone);
	free_memory(my_list_agencies);//wash hands
	return 0;
}