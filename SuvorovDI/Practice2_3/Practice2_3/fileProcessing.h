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

class Spec_t {
private:
    std::string name;
    int n_form;
    EducationalForm* forms;
    int* examScores;
    int* costs;

public:
    Spec_t();
    Spec_t(const Spec_t&);
    ~Spec_t();
    Spec_t& operator=(const Spec_t&);
};

class University_t {
private:
    std::string name;
    int n_spec;
    Spec_t* specs;

public:
    University_t();
    University_t(std::string name_u, int spec_count, Spec_t* specialties);
    University_t(const University_t&);
    ~University_t();
    University_t& operator=(const University_t&);

    void SearchMinScoreSpeciality(std::string& spec_name, int& score, std::string& form);
    float ComputeAverageScore() const;
    float ComputeAverageCost() const;
};

class Univ_database_t {
private:
    int count;
    University_t* univs;

    int find_num_univ(const std::string& fname) const;
    int try_to_open_file(const std::string& fname);

public:
    Univ_database_t();
    Univ_database_t(int count);
    Univ_database_t(const std::string& fname);
    Univ_database_t(const Univ_database_t&);
    ~Univ_database_t();
    University_t& operator[] (const int ind);

    Univ_database_t SearchBySpeciality(const std::string& name);
    int SearchVUZ(const std::string& name, University_t& u) const;
    int SearchSpecialties(const std::string& name, Spec_t*& specs, std::string*& names_univ) const;
    
};

std::ostream& operator<<(std::ostream& out, const University_t& un);
std::ostream& operator<<(std::ostream& out, const Spec_t& sp);

#endif