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
    // конструктор копирования и т.д.
    ~Spec_t();
};

struct University_t {
    std::string name;
    int n_spec;
    Spec_t* specs;

    Spec_t SearchMinScoreSpeciality();
    float ComputeAverageScore() const;
    float ComputeAverageCost() const;
    ~University_t();
};

struct Univ_database_t {
    University_t* univs;
    int count;
    
    Univ_database_t(int count);
    Univ_database_t(const std::string& fname);
    Univ_database_t(const Univ_database_t&);
    ~Univ_database_t();

    University_t SearchVUZInfo(const std::string& name) const;
    Univ_database_t SearchBySpeciality(const std::string& name);
    University_t& operator[] (const int ind);

    int find_num_univ(const std::string& fname);
    int try_to_open_file(const std::string& fname);
};

std::ostream& operator<<(std::ostream& out, const University_t& un);

#endif