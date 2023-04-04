#pragma once
#ifndef _prototypes_
#define _prototypes_
#include <fstream>
#include <iostream>

using namespace std;

ifstream create_file();
int CountAgencies(ifstream& file);
int* CountTServices(ifstream& file);
#endif