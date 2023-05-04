#include "Book.h"
#include <iostream>
#include <string>
#include <fstream>
#include <locale.h>
#include <sstream>

#define SECTION "Любой"

string get_path()
{
	string line;

	cout << "Введите название файла" << endl;

	ifstream file;
	file.exceptions(ifstream::badbit | ifstream::failbit);
	int c;
	do
	{
		getline(cin, line);
		try
		{
			file.open(line);
			c = 1;

		}
		catch (const std::exception& ex)
		{
			cout << "Неверно введён файл" << endl;
			c = 0;
		}
	} while (c != 1);
	return line;
}

int TLib::count_books(const string& path) const
{

	string line;
	ifstream file;
	file.open(path);
	int count=0;
	while (file.peek() != EOF)
	{
		getline(file, line);
		count++;
	}
	file.close();
	return count;
}

int TLib:: count_unic() const
{
	int unic = 0;
	for (int i = 0; i < count; i++)
	{
		int flag = 0;
		for (int j = i + 1; j < count; j++)
		{

			if (books[i].Section == books[j].Section)
			{
				flag++;
				break;
			}


		}
		if (flag == 0)
			unic++;
	}
	return unic;
}

void TLib:: create_section()
{

	unic_section = new string[CountUnic];

	int k = 0;

	for (int i = 0; i < count; i++)
	{
		int flag = 0;
		for (int j = i + 1; j < count; j++)
		{

			if (books[i].Section == books[j].Section)
			{
				flag++;
				break;
			}


		}
		if (flag == 0)
		{
			unic_section[k] = books[i].Section;
			k++;
		}
	}
}


TBook::TBook()
{
	this->Couaut=0;
	this->Author=nullptr;
	this->Name="";
	this->Publishing="";
	this->Section="";
	this->Availability=false;
	this->Score=0;
}
TLib::TLib()
{
	this->books = nullptr;
	this->count = 0;
	this->CountUnic = 0;
	this->unic_section = nullptr;
	
}
void TLib::print_unique_sections()
{
	for (int i = 0; i < this->CountUnic; i++)
	{
		cout << (i+1)<<"." << this->unic_section[i] << endl;
	}
	cout << endl << "0- Если хотите выйти"<<endl;
}
TLib::TLib(const TLib& lib)
{
	this->count = lib.count;
	this->books = new TBook[this->count];
	this->CountUnic = lib.CountUnic;
	for (int i = 0; i < this->count; i++) {
		this->books[i] = lib.books[i];
	}
	this->unic_section = new string[this->CountUnic];
	for (int i = 0; i < this->CountUnic; i++) {
		this->unic_section[i] = lib.unic_section[i];
	}
}

TLib TLib:: search_by_section(const string& section_name)
{
	int count_unqie_books = 0;
	for (int i = 0; i < this->count; i++)
	{
		if (section_name == this->books[i].Section)
		{
			count_unqie_books++;
		}
	}
	TLib sectionLibrary;
	sectionLibrary.books = new TBook[count_unqie_books];
	sectionLibrary.unic_section = new string[1];
	sectionLibrary.unic_section[0] = section_name;
	int j = 0;
	for (int i = 0; i < this->count; i++)
	{
		if (section_name == this->books[i].Section)
		{
			sectionLibrary.books[j] = this->books[i];
			j++;
		}
	}
	sectionLibrary.count = count_unqie_books;
	sectionLibrary.CountUnic = 1;
	return sectionLibrary;
}


TLib::TLib(const string& path)
{
	this->count = count_books(path);
	this->books = new TBook[count];
	int i = 0;
	string line;
	string authorNames;
	ifstream file;
	file.open(path);;
	while (i < count)
	{

		getline(file, authorNames, ';');
		getline(file, line, ';');
		books[i].Name = line;
		getline(file, line, ';');
		books[i].Publishing = line;
		getline(file, line, ';');
		books[i].Section = line;
		getline(file, line, ';');
		if (line == "Есть")
			books[i].Availability = true;
		else
			books[i].Availability = false;
		getline(file, line, '\n');
		books[i].Score = atoi(line.c_str());

		int couaut = 0;
		stringstream authorNameStream(authorNames);

		string Name;
		while (getline(authorNameStream, Name, ','))
		{
			couaut++;

		}
		books[i].Couaut = couaut;

		books[i].Author = new string[couaut];
		int j = 0;
		authorNameStream.clear();
		authorNameStream.seekg(0, std::ios::beg);
		while (getline(authorNameStream, Name, ','))
		{
			books[i].Author[j] = Name;
			j++;
		}
		i++;
	}
	
	this->CountUnic = count_unic();
	create_section();
	
	file.close();
	
}


TBook::~TBook()
{
	delete[] this->Author;
}
TLib::~TLib() {

	
	delete[] this->books;
	if (this->unic_section != nullptr)
	{
		delete[] this->unic_section;
	}
}
ostream& operator << (std::ostream& out, TBook& book)
{
	out << "Автор - ";
	for (int j = 0; j < book.Couaut; j++)
	{
		out << book.Author[j] << " ";
	}
	out << " | Название книги - " << book.Name;
	out << "| Издательство - " << book.Publishing;
	out << "| Жанр - " << book.Section;
	if (book.Availability)
	{
		out << "| Наличие - Есть";
	}
	else
	{
		out << "| Наличие - Нет";
	}
	out << "| Оценка - " << book.Score << endl;
	return out;
}
ostream& operator <<(std::ostream& out, TLib& lib)
{
	out << "Имеются следующие книги в нашей библиотеке:  " << endl;
	for (int i = 0; i < lib.count; i++)
	{
		out << lib.books[i] << endl;
	}
	return out;
}
TBook& TBook::operator=(const TBook& book) {
	this->Couaut = book.Couaut;
	this->Author = new string[book.Couaut];
	for (int i = 0; i < book.Couaut; i++)
	{
		this->Author[i] = book.Author[i];
	}
	this->Name = book.Name;
	this->Publishing = book.Publishing;
	this->Section = book.Section;
	this->Availability = book.Availability;
	this->Score = book.Score;

	return *this;
}
TLib& TLib:: operator=(const TLib& lib)
{
	this->count = lib.count;
	this->CountUnic = lib.CountUnic;
	this->books = new TBook[count];
	for (int i = 0; i < count; i++)
	{
		this->books[i] = lib.books[i];
	}
	this->unic_section = new string[CountUnic];
	for (int i = 0; i < CountUnic; i++)
	{
		this->unic_section[i] = lib.unic_section[i];
	}

	return *this;
}

