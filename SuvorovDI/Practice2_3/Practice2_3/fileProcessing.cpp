#include "fileProcessing.h"

// Default constructors
Univ_database_t::Univ_database_t() {
    count = -1;
    univs = nullptr;
}
University_t::University_t() {
    name = "";
    n_spec = 0;
    specs = nullptr;
}
Spec_t::Spec_t() {
    name = "";
    n_form = 0;
    forms = nullptr;
    examScores = nullptr;
    costs = nullptr;
}

Univ_database_t::Univ_database_t(const std::string& fname) {
    int i = 0;
    std::string line;
    count = try_to_open_file(fname);
    std::ifstream file(fname);
    univs = new University_t[count];

    while (i < count) {
        getline(file, line, ';');
        univs[i].SetName(line);
        getline(file, line, ';');
        univs[i].SetNumSpecs( atoi(line.c_str()) );
        univs[i].SetSpecs(univs[i].GetNum_spec());

        for (int j = 0; j < univs[i].GetNum_spec(); j++) {
            getline(file, line, ';');
            univs[i].GetSpec(j).SetName(line);
            getline(file, line, ';');
            univs[i].GetSpec(j).SetNumForms( atoi(line.c_str()) );
            int num_forms = univs[i].GetSpec(j).GetNum_form();

            univs[i].GetSpec(j).Set_Forms(num_forms);
            univs[i].GetSpec(j).Set_Costs(num_forms);
            univs[i].GetSpec(j).Set_ExamScores(num_forms);

            for (int z = 0; z < num_forms; z++) {
                std::string type_form;
                getline(file, line, ';');
                type_form = line;

                if (type_form == "дневная") {
                    univs[i].GetSpec(j).Set_Form(z, DNEV);
                    getline(file, line, ';');
                    univs[i].GetSpec(j).Set_ExamScore(z, atoi(line.c_str()));
                    getline(file, line, ';');
                    univs[i].GetSpec(j).Set_Cost(z, atoi(line.c_str()));
                }
                if (type_form == "вечерняя") {
                    univs[i].GetSpec(j).Set_Form(z, VECHER);
                    getline(file, line, ';');
                    univs[i].GetSpec(j).Set_ExamScore(z, atoi(line.c_str()));
                    getline(file, line, ';');
                    univs[i].GetSpec(j).Set_Cost(z, atoi(line.c_str()));
                }
                if (type_form == "заочная") {
                    univs[i].GetSpec(j).Set_Form(z, ZAOCH);
                    getline(file, line, ';');
                    univs[i].GetSpec(j).Set_ExamScore(z, atoi(line.c_str()));
                    getline(file, line, ';');
                    univs[i].GetSpec(j).Set_Cost(z, atoi(line.c_str()));
                }
            }
        }
        i++;
        file.get();
    }

    file.close();
}
Univ_database_t::Univ_database_t(int c) {
    count = c;
    univs = new University_t[count];
}

// Copy constructors
Spec_t::Spec_t(const Spec_t& s) {
    name = s.name;
    n_form = s.n_form;
    forms = new EducationalForm[n_form];
    costs = new int[n_form];
    examScores = new int[n_form];

    for (int i = 0; i < n_form; i++) {
        forms[i] = s.forms[i];
        costs[i] = s.costs[i];
        examScores[i] = s.examScores[i];
    }
}
University_t::University_t(const University_t& u) {
    name = u.name;
    n_spec = u.n_spec;
    specs = new Spec_t[n_spec];

    for (int i = 0; i < n_spec; i++) {
        specs[i] = u.specs[i];
    }
}
Univ_database_t::Univ_database_t(const Univ_database_t& ud) {
    count = ud.count;
    univs = new University_t[count];

    for (int i = 0; i < count; i++) {
        univs[i] = ud.univs[i];
    }
}

// Destuctors
Univ_database_t::~Univ_database_t() {
    delete[]univs;
}
University_t::~University_t() {
    delete[]specs;
}
Spec_t::~Spec_t() {
    delete[]forms;
    delete[]examScores;
    delete[]costs;
}

// Overloaded operators
University_t& Univ_database_t::operator[] (const int ind) {
    return univs[ind];
}

std::ostream& operator<<(std::ostream& out, const University_t& un) {
    std::cout << "Информация о ВУЗе " << un.GetName() << ":\n";
    std::cout << "ВУЗ " << un.GetName() << " имеет " << un.GetNum_spec() << " специальностей:\n";

    for (int i = 0; i < un.GetNum_spec(); i++) {
        std::cout << "   " << un.GetSpec(i).GetName() << std::endl;
    }

    return out;
}

std::ostream& operator<<(std::ostream& out, const Spec_t& s) {
    std::cout << "Название специальности: " << s.GetName() << ":\n";
    std::cout << "Количество форм обучения: " << s.GetNum_form() << "\n";

    for (int i = 0; i < s.GetNum_form(); i++) {
        std::string name_form;
        switch (s.Get_Form(i))
        {
        case 0: name_form = "Дневная";
        case 1: name_form = "Вечерняя";
        case 2: name_form = "Заочная";
        }
        std::cout << "   Форма обучения: " << name_form << std::endl;
        std::cout << "   Стоимость: " << s.Get_Cost(i) << std::endl;
        std::cout << "   Проходные баллы: " << s.Get_ExamScore(i) << std::endl;

    }

    return out;
}

University_t& University_t::operator=(const University_t& u) {
    if (this != &u) {
        if (specs)
            delete[] specs;

        name = u.name;
        n_spec = u.n_spec;

        specs = new Spec_t[n_spec];

        for (int i = 0; i < n_spec; i++) {
            specs[i] = u.specs[i];
        }
    }
    return *this;
}

Spec_t& Spec_t::operator=(const Spec_t& s) {
    if (this != &s) {
        if (forms)
            delete[] forms;
        if (costs)
            delete[] costs;
        if (examScores)
            delete[] examScores;

        name = s.name;
        n_form = s.n_form;
        forms = new EducationalForm[n_form];
        costs = new int[n_form];
        examScores = new int[n_form];

        for (int i = 0; i < n_form; i++) {
            forms[i] = s.forms[i];
            costs[i] = s.costs[i];
            examScores[i] = s.examScores[i];
        }
    }
    return *this;
}

// Accessors, mutators
std::string University_t::GetName() const {
    return name;
}
int University_t::GetNum_spec() const {
    return n_spec;
}
Spec_t& University_t::GetSpec(int ind) const {
    return specs[ind];
}

std::string Spec_t::GetName() const {
    return name;
}
int Spec_t::GetNum_form() const {
    return n_form;
}
EducationalForm Spec_t::Get_Form(int ind) const {
    return forms[ind];
}
int Spec_t::Get_ExamScore(int ind) const {
    return examScores[ind];
}
int Spec_t::Get_Cost(int ind) const {
    return costs[ind];
}

void University_t::SetName(const std::string name_u) {
    name = name_u;
}
void University_t::SetNumSpecs(const int n) {
    n_spec = n;
}
void University_t::SetSpecs(const int num) {
    specs = new Spec_t[num];
}

void Spec_t::SetName(const std::string name_s) {
    name = name_s;
}
void Spec_t::SetNumForms(const int n) {
    n_form = n;
}
void Spec_t::Set_Form(const int ind, EducationalForm form) {
    forms[ind] = form;
}
void Spec_t::Set_Cost(const int ind, int cost) {
    costs[ind] = cost;
}
void Spec_t::Set_ExamScore(const int ind, int score) {
    examScores[ind] = score;
}

void Spec_t::Set_Forms(const int num) {
    forms = new EducationalForm[num];
}
void Spec_t::Set_Costs(const int num) {
    costs = new int[num];
}
void Spec_t::Set_ExamScores(const int num) {
    examScores = new int[num];
}

// Methods
int Univ_database_t::find_num_univ(const std::string& fname) const {
    std::string line;
    int c = 0;

    std::ifstream file(fname);

    if (file.fail())
        throw - 1;

    while (getline(file, line)) {
        c++;
    }

    file.close();
    return c;
}

int Univ_database_t::try_to_open_file(const std::string& fname) {
    int c = -1;
    while (c == -1) {
        try {
            getline(std::cin, const_cast<std::string&>(fname));
            c = find_num_univ(fname);
        }
        catch (...) {
            std::cout << "Такого файла нет" << std::endl;
        }
    }
    return c;
}

int Univ_database_t::SearchVUZ(const std::string& name, University_t& u) const {
    for (int i = 0; i < count; i++) {
        if (univs[i].GetName() == name) {
            u = univs[i];
            return 1;
        }
    }
    return -1;
}

float University_t::ComputeAverageScore() const {
    float sum_examRes = 0, count = 0;
    for (int i = 0; i < n_spec; i++) {
        for (int j = 0; j < specs[i].GetNum_form(); j++) {
            sum_examRes += specs[i].Get_ExamScore(j);
            count++;
        }
    }
    return sum_examRes / count;
}

float University_t::ComputeAverageCost() const {
    float sum_costs = 0, count = 0;
    for (int i = 0; i < n_spec; i++) {
        for (int j = 0; j < specs[i].GetNum_form(); j++) {
            sum_costs += specs[i].Get_ExamScore(j);
            count++;
        }
    }
    return sum_costs / count;
}

void University_t::SearchMinScoreSpeciality(std::string& spec_name, int& score, std::string& form) {
    int min = 1000;
    EducationalForm edForm;
    std::string name_form, name_spec;

    for (int i = 0; i < n_spec; i++) {
        for (int j = 0; j < specs[i].GetNum_form(); j++) {
            if (specs[i].Get_ExamScore(j) < min) {
                min = specs[i].Get_ExamScore(j);
                edForm = specs[i].Get_Form(j);
                name_spec = specs[i].GetName();
            }
        }
    }
    switch (edForm)
    {
    case 0: name_form = "Дневная";
    case 1: name_form = "Вечерняя";
    case 2: name_form = "Заочная";
    }

    score = min;
    form = name_form;
    spec_name = name_spec;
}

int Univ_database_t::SearchSpecialties(const std::string& name, Spec_t*& specs, std::string*& names_univ) const {
    int c_spec = 0;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < univs[i].GetNum_spec(); j++) {
            if (univs[i].GetSpec(j).GetName() == name)
                c_spec++;
        }
    }
    specs = new Spec_t[c_spec];
    names_univ = new std::string[c_spec];
    int k = 0;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < univs[i].GetNum_spec(); j++) {
            if (univs[i].GetSpec(j).GetName() == name) {
                specs[k] = univs[i].GetSpec(j);
                names_univ[k] = univs[i].GetName();
                k++;
            }
        }
    }
    return c_spec;
}