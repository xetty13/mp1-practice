#pragma once
#ifndef _PROTOTYPES_H
#define _PROTOTYPES_H

#include <string>

using namespace std;

class TService// list of service
    //добавить private
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

    
};

class TAgency // Tourist agency
{
    friend ostream& operator<<(ostream& stream, const TAgency& obj);//overloading for TAgency
//добавить private
private:
    int num_services;
    string name;
public:
    TService* services;//?????
    TAgency(void);
    TAgency(int num_services);//initialisation of TAgency objects
    TAgency(const TAgency& object);//copy object
    //сюда деструктор
    string get_name() { return name; }
   
    int get_num_services() { return num_services; }

    void set_num_services(int argument) { num_services = argument; }
};

class TAgencyBook
//добавить private
{
private:
    TAgency* agencies;
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