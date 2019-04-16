#include <iostream>
#include"Date.h"
#include"Time.h"
#include"ToDoList.h"
#include"TaskTypes.h"
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
	char buff[50]; // буфер промежуточного хранения считываемого из файла текста
	ifstream fin("List.txt"); // открыли файл для чтения

	fin >> buff; // считали первое слово из файла
	cout << buff << endl; // напечатали это слово

	fin.getline(buff, 50); // считали строку из файла
	fin.close(); // закрываем файл
	cout << buff << endl; // напечатали эту строку

	return 0;
}