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
    Spec_t();
    Spec_t(const Spec_t&);
    ~Spec_t();
    Spec_t& operator=(const Spec_t&);
};

struct University_t {
    std::string name;
    int n_spec;
    Spec_t* specs;

    University_t();
    University_t(const University_t&);
    ~University_t();
    University_t& operator=(const University_t&);

    void SearchMinScoreSpeciality(std::string& spec_name, int& score, std::string& form);
    float ComputeAverageScore() const;
    float ComputeAverageCost() const;
};

struct Univ_database_t {
    int count;
    University_t* univs;

    Univ_database_t(int count);
    Univ_database_t(const std::string& fname);
    Univ_database_t(const Univ_database_t&);
    ~Univ_database_t();

    Univ_database_t SearchBySpeciality(const std::string& name);
    University_t& operator[] (const int ind);

    int SearchVUZ(const std::string& name, University_t& u) const;
    int find_num_univ(const std::string& fname);
    int try_to_open_file(const std::string& fname);
};

std::ostream& operator<<(std::ostream& out, const University_t& un);
std::ostream& operator<<(std::ostream& out, const Spec_t& un);

#endif