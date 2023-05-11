#pragma once
#ifndef _TAGENCUBOOK_H
#define _TAGENCYBOOK_H

#include "TAgency.h"
enum class FileExeption { NullPtrFile = -1 };//enumeration for file errors
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
    int counter_euro_agencies();//count euro agencies

    void search_string(ifstream& file);//look for the first occurrence of the string
    void file_reader(ifstream& file);

    TAgencyBook Get_Europe_Countries();//find european countries and create european massive
    const TAgencyBook& operator=(const TAgencyBook& obj);

    friend ostream& operator<<(ostream& stream, const TAgencyBook& obj);//overloading for TAgencyBook
    
};

#endif