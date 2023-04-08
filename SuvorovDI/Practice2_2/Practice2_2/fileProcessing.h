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
};

struct University_t {
    std::string name;
    int n_spec;
    Spec_t* specs;
};

int find_num_univ(std::string fname);
University_t* fill_univ(std::string fname, int c);
void print_all_info(University_t* uns, int c);
void free_memory(University_t* uns, int c);
int try_to_open_file(std::string& fname);

#endif