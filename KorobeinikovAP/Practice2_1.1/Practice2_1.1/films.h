#ifndef FILM_H

#define FILM_H
#include <string>
typedef struct Producer {
	char* Name;
	char* Surname;
} Producer;

typedef struct Film {
	char* film_name;
	Producer creator;
	char* country;
	int year;
	int budget;
	int fees;
} Film;


char* read_string(FILE* stream);

char* getInput(char* message);

Producer getProducerFromString(char* str);

Film ReadFilmEntity(FILE* file);

Film* ReadFileWithFilms(char* file_path, int* number_of_films);

int compareProducers(const Producer* x, const Producer* y);

Film* getFilmsByProducer(Film* all_films, int count_all_films, Producer creator, int* needed_count);

void PrintFilm(Film film);


#endif
