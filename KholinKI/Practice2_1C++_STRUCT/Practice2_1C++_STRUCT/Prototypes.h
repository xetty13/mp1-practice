#ifndef _PROTOTYPES_H
#define _PROTOTYPES_H

#include <fstream>
#include <string>

using namespace std;

struct TService// list of service
{
    string country;
    string travel_conditions;
    string excursion_services;
    string host_service;
    string ticket_price;
};

struct TAgency // Tourist agency
{
    int num_services;
    string name;
    TService* services;
    TAgency();
    TAgency(int num_services);//инициализация объектов TAgency
    TAgency(const TAgency& object);//копирование объекта
    ~TAgency();
};

struct TAgencyBook
{
    TAgency* agencies;
    int count;//количество европейских стран
    TAgencyBook(int count);
    TAgencyBook(const string path);//ifstream& file here и через методы чтения далее проводим.
    TAgencyBook(const TAgencyBook& object);//копирование объекта
    ~TAgencyBook();

    void CountAgencies(ifstream& fptr); //count agencies
    int* CountTServices(ifstream& file);//count directions
    void file_reader(ifstream& file);
    void search_string(ifstream& file);
    
    void allocate_TAgency(TAgency& object, int count_services);//allocating guide list... (constructor initialising)
    
    void show_all_data();//all data

    int* counter_euro_countries();//count euro countries
    TAgencyBook find_euro_countries();//find european countries and create european massive
    void output_data_EZONES();//output european massive!:)
    
};
ostream& operator<<(ostream& stream, const TAgency& obj);
#endif