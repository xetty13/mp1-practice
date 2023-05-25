#include "person.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

string getPath()
{
    string path;
    while (true) {
        cout << "Enter the name of your file:" << endl;
        getline(cin, path);
        ifstream file(path);
        if (file.good()) {
            file.close();
            return path;
        }
        cout << "ERROR:The file isn`t open\n" << endl;
    }
}

int persons_list::person_count(const string& path)
{
    int count = 0;
    string line;
    ifstream file(path);
    while (getline(file, line)) {
        if (!line.empty()) {
            count++;
        }
    }
    file.close();
    return count;
}

persons_list::persons_list(const string& path) {
    this->count = person_count(path);
    this->persons = new person[count];
    ifstream file(path);
    if (file.is_open())
    {
        string line;
        int index = 0;
        while (getline(file, line))
        {
            stringstream ss(line);
            string token;

            getline(ss, token, ';'); // Фамилия
            persons[index].Surname = token;

            getline(ss, token, ';'); // Имя
            persons[index].Name = token;

            getline(ss, token, ';'); // Отчество
            persons[index].Middle_name = token;

            getline(ss, token, ';'); // Пол
            persons[index].Gender = (token == "M") ? male : female;

            getline(ss, token, ';'); // Национальность
            persons[index].Nation = token;

            getline(ss, token, ';'); // Дата рождения
            stringstream date_ss(token);
            getline(date_ss, token, '.'); // День
            persons[index].date.day = stoi(token);
            getline(date_ss, token, '.'); // Месяц
            persons[index].date.mounth = stoi(token);
            getline(date_ss, token, '.'); // Год
            persons[index].date.year = stoi(token);

            getline(ss, token, ';'); // Рост
            persons[index].Height = stof(token);

            getline(ss, token, ';'); // Вес
            persons[index].Weight = stof(token);

            getline(ss, token, ';'); // Телефонный номер
            persons[index].phone_number = stoll(token);

            getline(ss, token, ';'); // Почтовый индекс
            persons[index].address.postal_code = stoi(token);

            getline(ss, token, ';'); // Страна
            persons[index].address.Country = token;

            getline(ss, token, ';'); // Область
            persons[index].address.Region = token;

            getline(ss, token, ';'); // Район
            persons[index].address.Area = token;

            getline(ss, token, ';'); // Город
            persons[index].address.City = token;

            getline(ss, token, ';'); // Улица
            persons[index].address.Street = token;

            getline(ss, token, ';'); // Номер дома
            persons[index].address.House = stoi(token);

            getline(ss, token, ';'); // Номер квартиры
            persons[index].address.Apart = stoi(token);

            index++;
        }

        file.close();
    }
}

persons_list::~persons_list() {
    delete[] persons;
}

void persons_list::surname_sort()
{
    person* temp = new person;
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (persons[j].Surname != persons[i].Surname)
            {
                if (persons[j].Surname < persons[i].Surname)
                {
                    *temp = persons[i];
                    persons[i] = persons[j];
                    persons[j] = *temp;
                }
            }
            else
            {
                if (persons[j].Name < persons[i].Name)
                {
                    *temp = persons[i];
                    persons[i] = persons[j];
                    persons[j] = *temp;
                }
            }
        }
    }
}

void menu(const persons_list& ps) {
    int flag_sorted_list;
    do {
        cout << "\nHow to output a sorted array?\n1. From A to Z\n2. From Z to A\nEnter a number: ";
        cin >> flag_sorted_list;
        if ((flag_sorted_list == 1) || (flag_sorted_list == 2)) {

            if (flag_sorted_list == 1)
            {
                cout << "\n";
                for (int i = 0; i < ps.count; i++)
                    cout << ps.persons[i];
            }
            if (flag_sorted_list == 2)
            {
                cout << "\n";
                for (int i = ps.count - 1; i >= 0; i--)
                    cout << ps.persons[i];
            }
        }
        else cout << "ERROR: Enter values from the list to display a sorted list" << endl;

    } while ((flag_sorted_list <= 0) || (flag_sorted_list > 2));
}

ostream& operator<<(ostream& out, const person& p) {
    string gender[]{ "male", "female" };
    out << "===========================================" << endl;
    out << "FIO: " << p.Surname << " " << p.Name << " " << p.Middle_name << endl;
    out << "Gender: " << gender[p.Gender] << endl;
    out << "Nation: " << p.Nation << endl;
    out << "Date: " << p.date.day << "." << p.date.mounth << "." << p.date.year << endl;
    out << "Height: " << p.Height << endl;
    out << "Weight: " << p.Weight << endl;
    out << "Phone number: " << p.phone_number << endl;
    out << "Postal code: " << p.address.postal_code << endl;
    out << "Country: " << p.address.Country << endl;
    out << "Region: " << p.address.Region << endl;
    out << "Address: city: " << p.address.City << endl;
    out << "Area: " << p.address.Area << endl;
    out << "Street: " << p.address.Street << endl;
    out << "House: " << p.address.House << endl;
    out << "Apartament: " << p.address.Apart << endl;
    return out;
}

ostream& operator<<(ostream& out, const persons_list& pl) {
    for (int i = 0; i < pl.count; i++) {
        out << pl.persons[i];
    }
    return out;
}