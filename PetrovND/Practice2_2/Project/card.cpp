#include <iostream>
#include <fstream>
#include <sstream>
#include "card.h"

string menu() {
	string path;
	do {
		cout << "Enter the file path..." << endl;
		cin >> path;
		ifstream in(path);
		if (!in.is_open()) {
			cout << "ERROR: Could not open file!\n";
		}
		else {
			in.close();
			return path;
		}
	} while (true);
}

int strCount(string path) {
	int count{0};
	string line;
	ifstream in(path);
	while (getline(in, line))
	{
		if (line != "\0") {
			count++;
		}
	}
	in.close();
	return count;
}

int authorsCount(string path, int stringCount) {
	int i = 0, count = 0;
	string line, s;
	ifstream in(path);
	while (getline(in, line))
	{
		if (line == "\0") {
			continue;
		}
		stringstream ss(line);
		while (getline(ss, s, ';')) {
			switch (i) {
			case 0:
				if (count > std::count(s.begin(), s.end(), ',')) {
					break;
				}
				count = std::count(s.begin(), s.end(), ',');
				break;
			case 5:
				i = -1;
				break;
			}
			i++;
		}
	}
	in.close();
	return count+1;
}

cardIndex* alloc(int stringCount, int authorsCount) {
	cardIndex* cards = new cardIndex[stringCount];
	for (int i = 0; i < stringCount; i++) {
		cards[i].authors = new string[authorsCount];
	}
	return cards;
}

void readFile(cardIndex* cards, string path, int stringCount, int authorsCount) {
	int i = 0, j = 0;
	string line,s;
	ifstream in(path);
	string* buff = new string[stringCount];
	while (getline(in, line))
	{
		if (line == "\0") {
			continue;
		}
		stringstream ss(line);
		while (getline(ss, s, ';')) {
			switch (i) {
			case 0:
				buff[j] = s;
				break;
			case 1:
				cards[j].title = s;
				break;
			case 2:
				cards[j].publisher = s;
				break;
			case 3:
				cards[j].section = s;
				break;
			case 4:
				if (s == "Available") {
					cards[j].avb = AVAILABLE;
				}
				else {
					cards[j].avb = UNAVAILABLE;
				}
				break;
			case 5:
				cards[j].evaluation = stof(s);
				i = -1;
				j++;
				break;
			}
			i++;
		}
	}
	for (int i = 0; i < stringCount; i++) {
		int g = 0;
		stringstream ss(buff[i]);
		while (getline(ss, s, ',')) {
			cards[i].authors[g] = s;
			g++;
		}
	}
	in.close();
	delete[] buff;
}

void bookPrint(cardIndex* cards, int authorsCount, int g) {
	cout << "--------------|--------------" << endl;
	cout << cards[g].title << endl;
	cout << "Authors: ";
	for (int i = 0; i < authorsCount; i++)
		cout << cards[g].authors[i];
	cout << "\nPublisher: " << cards[g].publisher << endl;
	cout << "Availability: ";
	if (cards[g].avb == AVAILABLE) {
		cout << "available" << endl;
	}
	else {
		cout << "unavailable" << endl;
	}
	cout << "Evaluation: " << cards[g].evaluation << endl;
}

set <string> booksBySection(cardIndex* cards, int stringCount, int act) {
	set <string> sections;
	for (int i = 0; i < stringCount; i++) {
		sections.insert(cards[i].section);
	}
	for (string s : sections) {
		cout << "\nBooks from " << s << endl;
		for (int j = 0; j < stringCount; j++) {
			if (cards[j].section == s) {
				bookPrint(cards, act, j);
			}
		}
	}
	return sections;
}

void selectBook(cardIndex* cards, set <string> section, int stringCount, int authorsCount) {
	int i, j = 0;
	int userInput; 
	int* indexes = new int[stringCount+1];
	set <string> ::iterator it = section.begin();

	do {
		cout << "\nSelect the library section you are interested in:\n";
		for (i = 0; i < section.size(); i++, it++) {
			cout << i << ")" << " " << *it << endl;
		}
		cin >> userInput;
	} while (userInput > i - 1 || userInput < 0);

	for (i = 0, it = section.begin(); i < section.size(); i++, it++) {
		if (i != userInput) {
			continue;
		}
		for (int p = 0; p < stringCount; p++) {
			if (cards[p].section == *it) {
				cout << j << ")" << " " << cards[p].title << endl;
				indexes[j] = p;
				j++;
			}
		}
	}

	do {
		cout << "\nChoose the book you are interested in:" << endl;
		cin >> userInput;
	} while (j - 1 < userInput || userInput < 0);

	for (i = 0; i < stringCount; i++) {
		if (cards[i].title == cards[indexes[userInput]].title) {
			bookPrint(cards, authorsCount, i);
			break;
		}
	}
	delete[] indexes;
}

void del(int stringCount, cardIndex* cards) {
	for (int i = 0; i < stringCount; i++) {
		delete[] cards[i].authors;
	}
	delete[] cards;
}