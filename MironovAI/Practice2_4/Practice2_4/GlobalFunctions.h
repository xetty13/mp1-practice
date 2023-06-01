#ifndef _GLOBALFUNCTIONS_H_
#define _GLOBALFUNCTIONS_H_

#include <iostream>
#include <fstream>
using namespace std;

int PathError();
string input_path();
void user();

template<typename Type>
void dump_data_base(const NewContainer<Type>& base, const string& filename);


#endif  