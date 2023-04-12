#include "Book.h"
#include <iostream>
#include <string>
#include <fstream>
#include <locale.h>
#include <sstream>

int count_books(string& str)
{

	string line;

	cout <<"Введите название файла"<<endl;

	ifstream file;
	file.exceptions(ifstream::badbit | ifstream::failbit);
	int c;
	do
	{
		getline(cin, str);
		try
		{
			file.open(str);
			c = 1;

		}
		catch (const std::exception& ex)
		{
			cout << "Неверно введён файл" << endl;
			c = 0;
		}
	} while (c != 1);
	
	int count = 0;
	while (file.peek() != EOF)
	{
		getline(file, line);
		count++;
	}
	file.close();
	return count;
}


TBook* read(string str, TBook* book,int count)

{
	int i = 0;
	string line;

	string authorNames;
	ifstream file;
	file.open(str);;
	while (i <count)
	{

		getline(file, authorNames, ';');

		getline(file, line, ';');
		book[i].Name = line;
		getline(file, line, ';');
		book[i].Publishing = line;
		getline(file, line, ';');
		book[i].Section=line;
		getline(file, line, ';');
		if (line == "Есть")
			book[i].Availability = true;
		else
			book[i].Availability = false;
		getline(file, line, '\n');
		book[i].Score = atoi(line.c_str());

		
		int couaut = 0;
		stringstream authorNameStream(authorNames);

		string Name;
		while (getline(authorNameStream, Name, ','))
		{
			couaut++;
			
		}
		book[i].Couaut = couaut;

		book[i].Author = new string[couaut];
		int j = 0;
		authorNameStream.clear();
		authorNameStream.seekg(0, std::ios::beg);
		while (getline(authorNameStream, Name, ','))
		{
			book[i].Author[j] = Name;
			j++;
			
		}
		
		i++;
	}
	file.close();
	return book;
}


int count_unic(TBook* book, int count)
{
	int unic = 0;
	for (int i = 0; i < count; i++)
	{
		int flag = 0;
		for (int j = i + 1; j < count; j++)
		{

			if (book[i].Section == book[j].Section)
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
string* create_section(TBook* book, int unic, int count)
{
	
	string* unic_section = new string[unic];

	int k = 0;
	
	for (int i = 0; i < count; i++)
	{
		int flag = 0;
		for (int j = i + 1; j < count; j++)
		{

			if (book[i].Section == book[j].Section)
			{
				flag++;
				break;
			}


		}
		if (flag == 0)
		{
			unic_section[k] = book[i].Section;
			k++;
		}
	}
	return unic_section;
}
void print_book(TBook* book, int count)
{
	

	cout<<"Имеются следующие книги в нашей библиотеке:"<<endl;
	for (int i = 0; i < count; i++)
	{
		cout<<(i + 1)<< ". Автор - ";
		for (int j = 0; j < book[i].Couaut; j++)
		{
			cout<< book[i].Author[j]<<" ";
		}
		cout << " | Название книги - " << book[i].Name;
		cout<< "| Издательство - "<< book[i].Publishing;
		cout<< "| Жанр - "<< book[i].Section;
		if (book->Availability)
		{
			cout<<"| Наличие - Есть";
		}
		else
		{
			cout<<"| Наличие - Нет";
		}
		cout<< "| Оценка - "<< book[i].Score<<endl;
	}
}

void print_section(TBook* book, int count, string word)
{
	
	for (int i = 0; i < count; i++)
	{
		if (book[i].Section == word )
		{
			cout << (i + 1) << ". Автор - ";
			for (int j = 0; j < book[i].Couaut; j++)
			{
				cout << book[i].Author[j] << " ";
			}
			cout << " | Название книги - " << book[i].Name;
			cout << "| Издательство - " << book[i].Publishing;
			cout << "| Жанр - " << book[i].Section;
			if (book->Availability)
			{
				cout << "| Наличие - Есть";
			}
			else
			{
				cout << "| Наличие - Нет";
			}
			cout << "| Оценка - " << book[i].Score << endl;
		}

	}

}
void print_choose_book(TBook* lib, int count, int unic, string* unic_section)
{
	int a;
	string word;
	do
	{
		cout<<endl<<"Какой жанр вы хотите увидеть ? "<<endl;
		for (int i = 0; i < unic; i++)
		{
			cout<< i + 1<< " - "<< unic_section[i]<<endl;
		}
		cout<<"Если хотите выйти, введите 0"<<endl;

		cin>>a;



		if ((a > 0) && (a <= unic))
		{
			print_section(lib, count, unic_section[a - 1]);
		}
	} while (a != 0);
}


void free_mas(TBook* book, int count)
{

	for (int i = 0; i < count; i++)
	{
		delete[] book[i].Author;
	}
	delete[] book;
}
