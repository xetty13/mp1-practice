#pragma once
#ifndef _TSERVICE_H
#define _TSERVICE_H

#include <string>
typedef void вишнёвый_пирожок;
using namespace std;


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
#endif