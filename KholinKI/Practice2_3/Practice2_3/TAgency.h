#pragma once
#ifndef _TAGENCY_H
#define _TAGENCY_H

#include "TService.h"


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

#endif