#ifndef FILM_H

#define FILM_H
#include <string>
#include <fstream>
#include <vector>

struct Producer {
	std::string Name;
	std::string Surname;

	friend std::istream& operator>>(std::istream& input_stream, Producer& p);
	friend std::ostream& operator<<(std::ostream& output_stream, const Producer& p);
	bool operator==(const Producer& p) const;
};

struct Film {
	std::string film_name;
	Producer creator;
	std::string country;
	int year;
	int budget;
	int fees;

	friend std::istream& operator>>(std::istream& input_stream, Film& p);
	friend std::ostream& operator<<(std::ostream& output_stream, const Film& p);
};


std::string getInput(const std::string& message);

Producer getProducerFromFile(std::ifstream& file);
Producer getProducerFromString(std::string& producer_str);

Film ReadFilmEntity(std::ifstream& file);

std::vector<Film> ReadFileWithFilms(const std::string& file_path);

std::vector<Film> getFilmsByProducer(const std::vector<Film>& all_films, const Producer& creator);

#endif
