#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <vector>
#include "films.h"

int main()
{
	// get path to file with films
	std::string message = "Enter the path to file : ";
	std::string path = getInput(message);
	std::cout << path << '\n';

	// read file and save info about Films to array
	std::vector<Film> films;
	films = ReadFileWithFilms(path);

	// get films by procuder
	while (true) {
		std::string producer_info = getInput("Enter producer's name and surname separated by a space: ");
		Producer inputProducer = getProducerFromString(producer_info);
		std::cout << inputProducer << '\n';
		std::vector<Film> found_films = getFilmsByProducer(films, inputProducer);

		// print answer
		std::cout << "Count of found films by entered producer = " << found_films.size() << "\n\n";
		for (int i = 0; i < found_films.size(); ++i) {
			std::cout << found_films[i] << '\n';
		}

		// ask to continue
		std::cout << "Do you want to continue? (Y/N) : ";
		std::string choice;
		std::getline(std::cin, choice);
		if (choice == "N" || choice == "n") {
			break;
		}
	}

	return 0;
}