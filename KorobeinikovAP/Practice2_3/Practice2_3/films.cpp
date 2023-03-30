#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "films.h"
using namespace std;


std::string getInput(const std::string& message) {
	std::string input;
	std::cout << message;
	std::getline(std::cin, input);
	return input;
}

Producer getProducerFromFile(std::ifstream& file) {
	std::string name;
	std::string surname;

	getline(file, name, ' ');
	getline(file, surname);

	Producer p = { name, surname };
	return p;
}

Producer getProducerFromString(std::string& producer_str) {
	std::string name;
	std::string surname;

	int ptr = producer_str.find(' ');
	if (ptr == -1) {
		std::cout << "Uncorrect format of producer string!";
	}
	else {
		name = producer_str.substr(0, ptr);
		surname = producer_str.substr(ptr + 1);
	}

	Producer p = { name, surname };
	return p;
}

Film ReadFilmEntity(std::ifstream& file) {
	std::string film_name;
	std::getline(file, film_name);

	// create Producer from string
	std::string producer;
	//getline(file, producer);
	Producer p = getProducerFromFile(file);

	std::string country;
	std::getline(file, country);

	std::string film_year_s;
	std::getline(file, film_year_s);
	int film_year = stoi(film_year_s);

	std::string film_budget_s;
	std::getline(file, film_budget_s);
	int film_budget = stoi(film_budget_s);

	std::string film_fees_s;
	std::getline(file, film_fees_s);
	int film_fees = stoi(film_fees_s);

	Film new_film = { film_name, p, country, film_year, film_budget, film_fees };
	return new_film;
}


std::vector<Film> ReadFileWithFilms(const std::string& file_path) {
	std::ifstream file;
	file.open(file_path);
	if (!file.is_open()) {
		printf("\nRead file error.\n");
	}
	std::vector<Film> films;

	// we assume that the file contains information about at least one film
	std::string tmp;
	while (!file.eof()) {
		Film current_film = ReadFilmEntity(file);
		films.push_back(current_film);
		std::getline(file, tmp);
	}
	file.close();
	return films;
}

std::vector<Film> getFilmsByProducer(const std::vector<Film>& all_films, const Producer& creator) {
	std::cout << "Search films with producer : " << creator << "\n";
	std::vector<Film> needed_films;

	for (int i = 0; i < all_films.size(); ++i) {
		Producer  creat = all_films[i].getCreator();
		if (creat == creator) {
			needed_films.push_back(all_films[i]);
		}
	}

	return needed_films;
}

std::istream& operator>>(std::istream& input_stream, Producer& p) {
	input_stream >> p.Name >> p.Surname;
	return input_stream;
}

std::ostream& operator<<(std::ostream& output_stream, const Producer& p) {
	output_stream << p.Name << " " << p.Surname;

	return output_stream;
}

bool Producer::operator==(const Producer& p) const {
	if (Name == p.Name && Surname == p.Surname) {
		return true;
	}

	return false;
}

std::istream& operator>>(std::istream& input_stream, Film& film) {
	input_stream >> film.film_name;
	input_stream >> film.creator;
	input_stream >> film.country;
	input_stream >> film.year >> film.budget >> film.fees;
	return input_stream;
}

std::ostream& operator<<(std::ostream& output_stream, const Film& film) {
	output_stream << "Film name: " << film.film_name << '\n';
	output_stream << "Producer Name - Surname: " << film.creator << '\n';
	output_stream << "Country: " << film.country << '\n';
	output_stream << "Year: " << film.year << '\n';
	output_stream << "Budget: " << film.budget << '\n';
	output_stream << "Fees: " << film.fees << '\n';

	return output_stream;
}

Producer::Producer(const std::string& name, const std::string& surname) {
	this->Name = name;
	this->Surname = surname;
}

Film::Film(const std::string& film_name, const Producer& creator, const std::string& country, int year, int budget, int fees) {
	this->film_name = film_name;
	this->creator = creator;
	this->country = country;
	this->year = year;
	this->budget = budget;
	this->fees = fees;
}

Producer::Producer() {
	Name = "";
	Surname = "";
}

Producer Film::getCreator() const {
	return creator;
}

const Producer& Producer:: operator = (const Producer& p) {
	Name = p.Name;
	Surname = p.Surname;
	return *this;
}