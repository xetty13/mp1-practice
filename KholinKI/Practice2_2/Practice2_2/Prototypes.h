#pragma once
#ifndef _PROTOTYPES_H
#define _PROTOTYPES_H

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
    TAgency(void);
    TAgency(int num_services);//initialisation of TAgency objects
    TAgency(const TAgency& object);//copy object

};

struct TAgencyBook
   
{
    TAgency* agencies;
    int count_agencies;//num no european countries
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
ostream& operator<<(ostream& stream, const TAgency& obj);//overloading for TAgency
#endif