#ifndef FILM_H

#define FILM_H
#include <string>
#include <fstream>
#include <vector>

class Producer {
private:
	std::string Name;
	std::string Surname;
public:
	Producer();
	Producer(const std::string& name, const std::string& surname);
	friend std::istream& operator>>(std::istream& input_stream, Producer& p);
	friend std::ostream& operator<<(std::ostream& output_stream, const Producer& p);
	bool operator==(const Producer& p) const;
	const Producer& operator= (const Producer& p);
};

class Film {
private:
	std::string film_name;
	Producer creator;
	std::string country;
	int year;
	int budget;
	int fees;
public:
	Film(const std::string& film_name, const Producer& creator, const std::string& country, int year, int budget, int fees);
	friend std::istream& operator>>(std::istream& input_stream, Film& p);
	friend std::ostream& operator<<(std::ostream& output_stream, const Film& p);
	Producer getCreator() const;
};


std::string getInput(const std::string& message);

Producer getProducerFromFile(std::ifstream& file);
Producer getProducerFromString(std::string& producer_str);

Film ReadFilmEntity(std::ifstream& file);

std::vector<Film> ReadFileWithFilms(const std::string& file_path);

std::vector<Film> getFilmsByProducer(const std::vector<Film>& all_films, const Producer& creator);

#endif