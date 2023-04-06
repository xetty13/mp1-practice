#include <stdio.h>
#include "Functions_structures.c"
/*Tourist Guide.The guide contains a list of travel agenciesand the services they offer
(country, city or itinerary of the cruise, accommodation and travel conditions, excursions, host service, price of the trip).
Provide a list of travel agencies offering tours to Eurozone countries.
*/

int main(int argc,char *argv[]) {
	FILE* fptr;//creating file var
	int num_agencies;
	TAgency** my_list_agencies;//create massive pointers

	fptr = fopen("C://TouristAgences.txt", "r");//open the file for reading
	if (fopen == NULL) {
		printf("Error!File not found\n");//check
		exit(-99999999999999);//normal program termination
	}

	num_agencies = file_reader(fptr, &my_list_agencies);//reading data on file
	output_data_EZONES(fptr, my_list_agencies, num_agencies);

	fclose(fptr);
	free_memory(my_list_agencies,fptr);//wash hands

	return 0;
}