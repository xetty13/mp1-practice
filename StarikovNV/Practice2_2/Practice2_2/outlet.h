#ifndef _OUTLET_H
#define _OUTLET_H
#include  <string>
#include <vector>
using namespace std;

enum Day {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

struct Time {
    int hour;
    int minute;
    bool operator==(const Time& other) const;
};

struct address {
    string street;
    int house_number;
};

// структура для хранения рабочих дней магазина
struct workingDays {
    vector<Day> days;
    vector<Time> opens;
    vector<Time> closes;
};

// структура для хранения сведений о торговой точке
struct outlet {
    string name;
    address address;
    int phone_number;
    string specialization;
    workingDays working_days;
    friend ostream& operator<<(ostream& os, const outlet& outlet);
};

struct buyerGuide {//хранит все торговые точки
    buyerGuide(const vector<outlet>& o);
    buyerGuide(const string& filename);
    ~buyerGuide();
    vector<outlet> outlets;
    buyerGuide show_24_outlets();
    friend ostream& operator<<(ostream& os, const buyerGuide& bg);
};

string start();
#endif // !_OUTLET_H

