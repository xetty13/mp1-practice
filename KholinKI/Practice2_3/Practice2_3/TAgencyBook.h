#pragma once
#ifndef _TAGENCUBOOK_H
#define _TAGENCYBOOK_H

#include "TAgency.h"

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