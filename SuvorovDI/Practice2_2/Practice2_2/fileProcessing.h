#ifndef _FILEPROCESSING_H
#define _FILEPROCESSING_H
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

enum EducationalForm {
    DNEV,
    VECHER,
    ZAOCH
};

struct Spec_t {
    std::string name;
    int n_form;
    EducationalForm* forms;
    int* examScores;
    int* costs;
    ~Spec_t();
};

struct University_t {
    std::string name;
    int n_spec;
    Spec_t* specs;
    ~University_t();
};

struct Univ_database_t {
    University_t* univs;
    Univ_database_t(std::string fname, int c);
    ~Univ_database_t();
    University_t& operator[] (const int ind);
};

int find_num_univ(std::string fname);
void print_all_info(University_t* uns, int c);
int try_to_open_file(std::string& fname);
std::ostream& operator << (std::ostream& out, University_t& un);

#endif