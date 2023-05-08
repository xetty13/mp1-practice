#pragma once
#ifndef _TAGENCY_H
#define _TAGENCY_H

#include "TService.h"
#include <string>
struct TAgency // Tourist agency
{
    string name;
    int num_services;
    TService* services;

    TAgency(void);
    TAgency(int num_services);//initialisation of TAgency objects
    TAgency(const TAgency& object);//copy object
    ~TAgency();
};

#endif