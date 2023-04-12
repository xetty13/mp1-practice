#define STRLEN 10

#include "action.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;


int new_initializing(Steamarray* phonebook) {
	if (phonebook->teams != nullptr) {
		//SPhone* copy = phonebook->phones;
		if (phonebook->teams == new Steam[100]) {
			phonebook->length = 100;
		}
		else
		{
			cout << "You have too many contacts" << endl;
			return 0;
		}
	}
	else
	{
		if (!(phonebook->teams == new Steam[100])) {
			cout << "Something went wrong" << endl;
			return 0;
		}
		phonebook->length = 100;
	}
	return 1;
}

void My_scan(Steamarray* book) {
	string filename;
	cout << "Enter file path: ";
	cin >> filename;
	ifstream f(filename);
	if (!f) {
		cout << "I can not open " << filename;
		return;
	}
	int length;
	f >> length;
	book->length = length;
	book->teams = new Steam[length];
	for (int i = 0; i < length; i++) {
		string name, city;
		int games, points, players;
		f >> name;
		f >> city;
		f >> games >> points >> players;
//		f.ignore();
		book->teams[i].Name = name;
		book->teams[i].City = city;
		book->teams[i].Games = games;
		book->teams[i].Points = points;
		book->teams[i].Players = players;
	}
	f.close();
}


void output() {
	Steamarray book;
	book.teams = NULL;
	book.length = 0;
	My_scan(&book);
	size_t best_id = 0;
	if (book.teams != NULL) {
		for (size_t i = 1; i < book.length; i++)
		{
			if (book.teams[best_id].Points < book.teams[i].Points)
				best_id = i;
		}
		cout << book.teams[best_id].Name << endl << book.teams[best_id].City <<
			endl <<book.teams[best_id].Games << endl << book.teams[best_id].Players
			<< endl << book.teams[best_id].Points;
	}
}