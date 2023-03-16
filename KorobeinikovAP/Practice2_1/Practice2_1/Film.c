#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Film.h"


char* read_string(FILE* stream)
{
	int buffer_size = 8;
	int buffer_size_divizer = 1;
	int offset = 0;
	int additional_length;

	char* buffer = (char*)malloc(sizeof(char) * buffer_size);
	if (buffer == NULL) {
		return NULL;
	}
	buffer[0] = '\0';

	// read string while not face with '\n'
	while (1) {
		// read string to buffer with current offset
		if (fgets(buffer + offset, buffer_size / buffer_size_divizer, stream) == NULL) {
			free(buffer); // free allocated memory
			return NULL;
		}
		else {
			additional_length = strlen(buffer + offset);
			if (buffer[offset + additional_length - 1] != '\n') {
				// increase buffer_size by 2 times
				buffer_size *= 2;
				// realloc new memory
				buffer = (char*)realloc(buffer, sizeof(char) * buffer_size);
				// update offset to number of read elements
				offset += additional_length;
				buffer_size_divizer = 2;
			}
			else {
				buffer[offset + additional_length - 1] = '\0';
				break;
			}
		}
	}
	return buffer;
}



char* getInput(char* message) {
	char* input;
	while (1) {
		printf(message);
		input = read_string(stdin);
		if (input != NULL)
			break;
	}
	return input;
}


Producer getProducerFromString(char* str) {
	char* current_part;
	Producer p;

	current_part = strtok(str, " ");
	if (current_part == NULL) {
		printf("Incorrect format of producer name and surname, please type info use pattern: 'Name Surname' ");
	}
	char* name = current_part;
	char* surname = strtok(NULL, " ");

	p.Name = name;
	p.Surname = surname;
	return p;
}


Film ReadFilmEntity(FILE* file) {
	char* film_name = read_string(file);

	// create Producer from string
	char* producer = read_string(file);
	Producer p = getProducerFromString(producer);

	char* country = read_string(file);
	int film_year = atoi(read_string(file));
	int film_budget = atoi(read_string(file));
	int film_fees = atoi(read_string(file));

	Film new_film = { film_name, p, country, film_year, film_budget, film_fees };
	return new_film;
}


Film* ReadFileWithFilms(char* file_path, int* number_of_films) {
	FILE* file = fopen(file_path, "r");
	if (file == NULL) {
		printf("\nRead file error.\n");
	}
	Film* films = (Film*)malloc(sizeof(Film));
	*number_of_films = 1;

	// we assume that the file contains information about at least one film
	while (1) {
		Film current_film = ReadFilmEntity(file);
		films[*number_of_films - 1] = current_film;
		if (read_string(file) == NULL) {
			break;
		}
		else {
			films = (Film*)realloc(films, (*number_of_films + 1) * sizeof(Film));
			*number_of_films += 1;
		}
	}
	fclose(file);
	return films;
}

int compareProducers(const Producer* x, const Producer* y) {
	if ((strcmp(x->Name, y->Name) == 0) && (strcmp(x->Surname, y->Surname) == 0)) {
		return 1;
	}
	return 0;
}

Film* getFilmsByProducer(Film* all_films, int count_all_films, Producer creator, int* needed_count) {
	printf("Search films with producer : %s %s ...\n\n", creator.Name, creator.Surname);
	Film* needed_films = (Film*)malloc(sizeof(Film));
	int count = 0;
	for (int i = 0; i < count_all_films; ++i) {
		if (compareProducers(&all_films[i].creator, &creator)) {
			needed_films[count] = all_films[i];
			++count;
			needed_films = (Film*)realloc(needed_films, (count + 1) * sizeof(Film));
		}
	}

	*needed_count = count;
	return needed_films;
}

void PrintFilm(Film film) {
	printf("Film name: %s\n", film.film_name);
	printf("Producer Name - Surname: %s %s\n", film.creator.Name, film.creator.Surname);
	printf("Country: %s\n", film.country);
	printf("Year: %d\n", film.year);
	printf("Budget: %d\n", film.budget);
	printf("Fees: %d\n\n", film.fees);
}

