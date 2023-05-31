#ifndef _CLIENTSIDE_H
#define _CLIENTSIDE_H

#include "Header.h"

void work_with_client(TProductsDatabase& db);

bool isDigit(const std::string& s);

void create_updating_db(TProductsDatabase& db);


#endif