#pragma once
#ifndef _TSERVICE_H
#define _TSERVICE_H

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
#endif