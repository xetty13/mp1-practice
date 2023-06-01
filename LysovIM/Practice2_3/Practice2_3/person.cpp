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

string Person::getName() const { return Name; }
string Person::getSurname() const { return Surname; }

int PersonsList::person_count(const string& path) const
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

PersonsList::PersonsList(const string& path)
{
    count = person_count(path);
    persons = new Person[count];
    ifstream file(path);
    if (file.is_open())
    {
        string line;
        int index = 0;
        while (getline(file, line))
        {
            string Surname, Name, Middle_name, Nation;
            address address;
            date date;
            gender Gender;
            int Height, Weight;
            long long phone_number;
            stringstream ss(line);
            string token;

            getline(ss, token, ';'); // Фамилия
            Surname = token;

            getline(ss, token, ';'); // Имя
            Name = token;

            getline(ss, token, ';'); // Отчество
            Middle_name = token;

            getline(ss, token, ';'); // Пол
            Gender = (token == "M") ? male : female;

            getline(ss, token, ';'); // Национальность
            Nation = token;

            getline(ss, token, ';'); // Дата рождения
            stringstream date_ss(token);
            getline(date_ss, token, '.'); // День
            date.day = stoi(token);
            getline(date_ss, token, '.'); // Месяц
            date.mounth = stoi(token);
            getline(date_ss, token, '.'); // Год
            date.year = stoi(token);

            getline(ss, token, ';'); // Рост
            Height = stof(token);

            getline(ss, token, ';'); // Вес
            Weight = stof(token);

            getline(ss, token, ';'); // Телефонный номер
            phone_number = stoll(token);

            getline(ss, token, ';'); // Почтовый индекс
            address.postal_code = stoi(token);

            getline(ss, token, ';'); // Страна
            address.Country = token;

            getline(ss, token, ';'); // Область
            address.Region = token;

            getline(ss, token, ';'); // Район
            address.Area = token;

            getline(ss, token, ';'); // Город
            address.City = token;

            getline(ss, token, ';'); // Улица
            address.Street = token;

            getline(ss, token, ';'); // Номер дома
            address.House = stoi(token);

            getline(ss, token, ';'); // Номер квартиры
            address.Apart = stoi(token);

            Person p(Surname, Name, Middle_name, Gender, Nation, date, Height, Weight, phone_number, address);
            persons[index] = p;
            index++;
        }

        file.close();
    }
}

void PersonsList::surname_sort() 
{
    Person* temp = new Person;
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (persons[j].getSurname() != persons[i].getSurname())
            {
                if (persons[j].getSurname() < persons[i].getSurname())
                {
                    *temp = persons[i];
                    persons[i] = persons[j];
                    persons[j] = *temp;
                }
            }
            else
            {
                if (persons[j].getName() < persons[i].getName())
                {
                    *temp = persons[i];
                    persons[i] = persons[j];
                    persons[j] = *temp;
                }
            }
        }
    }
}

PersonsList::~PersonsList() {
    delete[] persons;
}

Person::Person(const string& surname, const string& name, const string& middle_name, gender gender,
    const string& nation, const date& birth_date, float height, float weight,
    long long phone_number, const address& address)
    : Surname(surname), Name(name), Middle_name(middle_name), Gender(gender), Nation(nation),
    date_(birth_date), Height(height), Weight(weight), phone_number(phone_number), address_(address)
{
}
Person::Person() {}

ostream& operator<<(ostream& out, const Person& p) {
    string gender[]{ "male", "female" };
    out << "===========================================" << endl;
    out << "FIO: " << p.Surname << " " << p.Name << " " << p.Middle_name << endl;
    out << "Gender: " << gender[p.Gender] << endl;
    out << "Nation: " << p.Nation << endl;
    out << "Date: " << p.date_.day << "." << p.date_.mounth << "." << p.date_.year << endl;
    out << "Height: " << p.Height << endl;
    out << "Weight: " << p.Weight << endl;
    out << "Phone number: " << p.phone_number << endl;
    out << "Postal code: " << p.address_.postal_code << endl;
    out << "Country: " << p.address_.Country << endl;
    out << "Region: " << p.address_.Region << endl;
    out << "Address: city: " << p.address_.City << endl;
    out << "Area: " << p.address_.Area << endl;
    out << "Street: " << p.address_.Street << endl;
    out << "House: " << p.address_.House << endl;
    out << "Apartament: " << p.address_.Apart << endl;
    return out;
}
ostream& operator<<(ostream& out, const PersonsList& pl) {
    for (int i = 0; i < pl.count; i++) {
        out << pl.persons[i];
    }
    return out;
}