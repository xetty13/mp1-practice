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

    std::string GetName() const;
    int GetNum_form() const;
    EducationalForm Get_Form(int ind) const;
    int Get_ExamScore(int ind) const;
    int Get_Cost(int ind) const;

    void SetName(const std::string name_s);
    void SetNumForms(const int n);
    void Set_Form(const int ind, EducationalForm form);
    void Set_Cost(const int ind, int cost);
    void Set_ExamScore(const int ind, int score);

    void Set_Forms(const int num);
    void Set_Costs(const int num);
    void Set_ExamScores(const int num);

    Spec_t& operator=(const Spec_t&);
};

class University_t {
private:
    std::string name;
    int n_spec;
    Spec_t* specs;

public:
    University_t();
    University_t(const University_t&);
    ~University_t();
    University_t& operator=(const University_t&);

    std::string GetName() const;
    int GetNum_spec() const;
    Spec_t& GetSpec(int ind) const;

    void SetName(const std::string name_u);
    void SetNumSpecs(const int n);
    void SetSpecs(const int num);

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

    int SearchVUZ(const std::string& name, University_t& u) const;
    int SearchSpecialties(const std::string& name, Spec_t*& specs, std::string*& names_univ) const;
    
};

std::ostream& operator<<(std::ostream& out, const University_t& un);
std::ostream& operator<<(std::ostream& out, const Spec_t& sp);

#endif