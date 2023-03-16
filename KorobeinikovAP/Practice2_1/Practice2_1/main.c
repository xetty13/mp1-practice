#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Film.h"

int main()
{
	// get path to file with films
	char* path = getInput("Enter the path to file : ");
	puts(path);

	// read file and save info about Films to array
	int count_of_films;
	Film* films = ReadFileWithFilms(path, &count_of_films);

	// get films by procuder
	char* producer_info = getInput("Enter producer's name and surname separated by a space: ");
	int count_of_found_films = 0;
	Film* found_films = getFilmsByProducer(films, count_of_films, getProducerFromString(producer_info), &count_of_found_films);

	// print answer
	printf("Count of found films by entered producer = %d\n\n", count_of_found_films);
	for (int i = 0; i < count_of_found_films; ++i) {
		PrintFilm(found_films[i]);
	}
	return 0;
}
