#pragma once
#ifndef _TAGENCY_H
#define _TAGENCY_H

#include "TService.h"

class TAgency // Tourist agency
{
private:
    int num_services;
    TService* services;
public:
    string name;//очень часто использую

    TService* get_services() { return services; }
    int get_num_services() { return num_services; }


    TAgency(void);
    TAgency(int num_services);//initialisation of TAgency objects
    TAgency(const TAgency& object);//copy object
    ~TAgency();
};

#endif