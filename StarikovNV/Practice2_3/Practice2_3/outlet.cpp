#include <iostream>
#include <fstream>
#include <sstream>
#include "outlet.h"

ostream& operator<<(ostream& os, const outlet& outlet) {//перегрузка вывода для оюъекта struct outlet
    const char* dayNames[] = { "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };
    os << "Name: " << outlet.name << endl;
    os << "Address: " << outlet.address_.street << ", " << outlet.address_.house_number << endl;
    os << "Phone Number: " << outlet.phone_number << endl;
    os << "Specialization: " << outlet.specialization << endl;
    os << "Working Days: " << endl;
    for (int i = 0; i < outlet.working_days.days.size(); i++) {
        os << dayNames[outlet.working_days.days[i]] << ": " << outlet.working_days.opens[i].hour << ":" <<
            outlet.working_days.opens[i].minute << " - " << outlet.working_days.closes[i].hour << ":" << outlet.working_days.closes[i].minute << endl;
    }
    os << endl;
    return os;
}

ostream& operator<<(ostream& os, const buyerGuide& bg) {//перегрузка вывода для buyerGuide
    for (auto& o : bg.outlets) {
        cout << o;
    }

    return os;
}

bool Time::operator==(const Time& other) const {//перегрузка оператора сравнения
    return hour == other.hour && minute == other.minute;
}

workingDays* outlet::getWD() { return &working_days; }

string start() {//запрашивает у пользователя путь к файлу до тех пор, пока не будет введён путь к существующему файлу
    string path;
    while (true) {
        cout << "Enter the file path..." << endl;
        getline(cin, path);
        ifstream file(path);
        if (file.good()) {
            file.close();
            return path;
        }
        cout << "ERROR: Could not open file!\n" << endl;
    }
}

outlet::outlet(string name, address address, int number, string specialization, workingDays wd) :
    name(name), address_(address), phone_number(number), specialization(specialization), working_days(wd) {}

outlet::~outlet() {
    working_days.closes.clear();
    working_days.opens.clear();
    working_days.days.clear();
}

buyerGuide::buyerGuide(const vector<outlet>& o) {//конструктор с параметром
    outlets = o;
}

buyerGuide::buyerGuide(const string& path) {
    ifstream infile(path);
    string line;
    while (getline(infile, line)) {
        istringstream iss(line);
        string name, street, specialization, phone_number, house_number;
        getline(iss, name, ',');//-----------------------------------|
        getline(iss, street, ',');//
        getline(iss, house_number, ',');// просто считываем данные
        getline(iss, phone_number, ',');//                           
        getline(iss, specialization, ',');//-------------------------|
        string day_time;
        workingDays wd;
        while (getline(iss, day_time, ',')) {//работаем с днями
            istringstream dt(day_time);
            string day, opens, closes;
            getline(dt, day, ':');
            Day currentDay;
            if (day == "Monday")
                currentDay = Monday;
            else if (day == "Tuesday")
                currentDay = Tuesday;
            else if (day == "Wednesday")
                currentDay = Wednesday;
            else if (day == "Thursday")
                currentDay = Thursday;
            else if (day == "Friday")
                currentDay = Friday;
            else if (day == "Saturday")
                currentDay = Saturday;
            else if (day == "Sunday")
                currentDay = Sunday;
            getline(dt, opens, '-');
            getline(dt, closes, '-');
            wd.days.push_back(currentDay);
            wd.opens.push_back({ stoi(opens.substr(0, 2)), stoi(opens.substr(3, 2)) });
            wd.closes.push_back({ stoi(closes.substr(0, 2)), stoi(closes.substr(3, 2)) });
        }
        outlet o = { name, {street, stoi(house_number)}, stoi(phone_number), specialization, wd };//создаём объект "магазин"
        outlets.push_back(o);//запихиваем заполненный объект в вектор
    }
    infile.close();
}

buyerGuide::~buyerGuide() {//деструктор, просто удаляет содержимое векторов(по сути это бесполезно, но лучше чем ничего)
    outlets.clear();
}

buyerGuide buyerGuide::show_24_outlets() {//показывает магазины работающие 24/7
    vector<outlet> all_time_shops;
    cout << "24-Hour Retail Outlets:\n" << endl;
    for (auto& outlet : outlets) {//проходимся по всем торговым точкам
        for (int i = 0; i < outlet.getWD()->days.size(); i++) {
            if (outlet.getWD()->opens[i] == outlet.getWD()->closes[i]) {
                all_time_shops.push_back(outlet);
                break;
            }
        }
    }
    buyerGuide bg(all_time_shops);
    return bg;
}