#pragma once
#ifndef _PROTOTYPES_H
#define _PROTOTYPES_H

#include <string>

using namespace std;


enum class FileExeption { NullPtrFile = -1 };//enumeration for file errors
struct TService// list of service
{
    string country;
    string travel_conditions;
    string excursion_services;
    string host_service;
    string ticket_price;

    TService(void);
    TService(const TService& obj);
};

struct TAgency // Tourist agency
{
    int num_services;
    string name;
    TService* services;
    TAgency(void);
    TAgency(int num_services);//initialisation of TAgency objects
    TAgency(const TAgency& object);//copy object
    ~TAgency();
};

struct TAgencyBook
{
    TAgency** agencies;
    int count_agencies;//num no european countries
    TAgencyBook(void);
    TAgencyBook(const string& path);//initialising TAgencyBook + call constructor TAgency
    TAgencyBook(const TAgencyBook& object);//copy_object
    ~TAgencyBook();

   void CountAgencies(ifstream& file);
   int* CountTServices(ifstream& file);//count directions
   int* counter_euro_countries();//count euro countries
   int counter_euro_agencies();//count euro agencies

   void search_string(ifstream& file);//look for the first occurrence of the string
   void file_reader(ifstream& file);

   TAgencyBook Get_Europe_Countries();//find european countries and create european massive
   const TAgencyBook& operator=(const TAgencyBook& obj);
};
ostream& operator<<(ostream& stream, const TAgencyBook& obj);//overloading for TAgencyBook
#endif