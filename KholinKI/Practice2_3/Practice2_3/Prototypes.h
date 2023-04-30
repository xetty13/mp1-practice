#pragma once
#ifndef _PROTOTYPES_H
#define _PROTOTYPES_H

#include <string>

using namespace std;

class TService// list of service
{
private:
    string country;
    string travel_conditions;
    string excursion_services;
    string host_service;
    string ticket_price;
public:
    TService(void);
    string get_country() { return country; }
    string get_travel_conditions() { return travel_conditions; }
    string get_excursion_services() { return excursion_services; }
    string get_host_service() { return host_service; }
    string get_ticket_price() { return ticket_price; }

    void set_service(TService& object, ifstream& file);//file version
    void set_service(const TService& object);//no file version
};

class TAgency // Tourist agency
{
    friend ostream& operator<<(ostream& stream, const TAgency& obj);//overloading for TAgency
private:
    int num_services;
    TService* services;
    string name;
public:

    TAgency(void);
    TAgency(int num_services);//initialisation of TAgency objects
    TAgency(const TAgency& object);//copy object
    ~TAgency();
    string get_name() { return name; }
    int get_num_services() { return num_services; }
    TService*& get_TService() { return services; }
   

    void set_name(string name_) { name = name_; }
    void set_num_services(int argument) { num_services = argument; }
};

class TAgencyBook
{
private:
    TAgency** agencies;
    int count_agencies;//num no european countries
public:
    TAgencyBook(void);
    TAgencyBook(const string& path);//initialising TAgencyBook + call constructor TAgency
    TAgencyBook(const TAgencyBook& object);//copy_object
    ~TAgencyBook();

    void CountAgencies(ifstream& file);
    int* CountTServices(ifstream& file);//count directions
    int* counter_euro_countries();//count euro countries

    void search_string(ifstream& file);//look for the first occurrence of the string
    void file_reader(ifstream& file);
    void show_all_data();//all data
    void output_data_EZONES();//output european massive!:)

    void create(TAgencyBook& object);//find european countries and create european massive


};

#endif