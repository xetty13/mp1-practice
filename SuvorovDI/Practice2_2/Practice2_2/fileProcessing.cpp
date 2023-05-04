#include "fileProcessing.h"

University_t::University_t(std::string name_u, int spec_count, Spec_t* specialties) {
    name = name_u;
    n_spec = spec_count;
    specs = new Spec_t[spec_count];
    for (int i = 0; i < n_spec; i++) {
        specs[i] = specialties[i];
    }
}

Univ_database_t Univ_database_t::SearchBySpeciality(const std::string& name) {
    int c = 0;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < univs[i].n_spec; j++) {
            if (univs[i].specs[j].name == name) {
                c++;
            }
        }
    }
    Univ_database_t univ_with_such_specs(c);

    int k = 0;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < univs[i].n_spec; j++) {
            if (univs[i].specs[j].name == name) {
                University_t u(univs[i].name, 1, &univs[i].specs[j]);
                univ_with_such_specs[k] = u;
                k++;
            }
        }
    }
    return univ_with_such_specs;
}

Univ_database_t::Univ_database_t(const std::string& fname) {
    int i = 0;
    std::string line;
    count = try_to_open_file(fname);
    std::ifstream file(fname);
    univs = new University_t[count];

    while (i < count) {
        getline(file, univs[i].name, ';');
        getline(file, line, ';');
        univs[i].n_spec = atoi(line.c_str());
        univs[i].specs = new Spec_t[univs[i].n_spec];

        for (int j = 0; j < univs[i].n_spec; j++) {
            getline(file, univs[i].specs[j].name, ';');
            getline(file, line, ';');
            univs[i].specs[j].n_form = atoi(line.c_str());

            univs[i].specs[j].forms = new EducationalForm[univs[i].specs[j].n_form];
            univs[i].specs[j].costs = new int[univs[i].specs[j].n_form];
            univs[i].specs[j].examScores = new int[univs[i].specs[j].n_form];

            for (int z = 0; z < univs[i].specs[j].n_form; z++) {
                std::string type_form;
                getline(file, line, ';');
                type_form = line;

                if (type_form == "дневная") {
                    univs[i].specs[j].forms[z] = DNEV;
                    getline(file, line, ';');
                    univs[i].specs[j].examScores[z] = atoi(line.c_str());
                    getline(file, line, ';');
                    univs[i].specs[j].costs[z] = atoi(line.c_str());
                }
                if (type_form == "вечерняя") {
                    univs[i].specs[j].forms[z] = VECHER;
                    getline(file, line, ';');
                    univs[i].specs[j].examScores[z] = atoi(line.c_str());
                    getline(file, line, ';');
                    univs[i].specs[j].costs[z] = atoi(line.c_str());
                }
                if (type_form == "заочная") {
                    univs[i].specs[j].forms[z] = ZAOCH;
                    getline(file, line, ';');
                    univs[i].specs[j].examScores[z] = atoi(line.c_str());
                    getline(file, line, ';');
                    univs[i].specs[j].costs[z] = atoi(line.c_str());
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
Univ_database_t::Univ_database_t() {
    count = -1;
    univs = nullptr;
}

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

University_t& Univ_database_t::operator[] (const int ind) {
    return univs[ind];
}

std::ostream& operator<<(std::ostream& out, const University_t& un) {
    std::cout << "Информация о ВУЗе " << un.name << ":\n";
    std::cout << "ВУЗ " << un.name << " имеет " << un.n_spec << " специальностей:\n";

    for (int i = 0; i < un.n_spec; i++) {
        std::cout << "   " << un.specs[i].name << std::endl;
    }

    return out;
}

std::ostream& operator<<(std::ostream& out, const Spec_t& s) {
    std::cout << "Название специальности: " << s.name << ":\n";
    std::cout << "Колличество форм обучения: " << s.n_form << "\n";

    for (int i = 0; i < s.n_form; i++) {
        std::string name_form;
        switch (s.forms[i])
        {
        case 0: name_form = "Дневная";
        case 1: name_form = "Вечерняя";
        case 2: name_form = "Заочная";
        }
        std::cout << "   Форма обучения: " << name_form << std::endl;
        std::cout << "   Стоимость: " << s.costs[i] << std::endl;
        std::cout << "   Проходные баллы: " << s.examScores[i] << std::endl;

    }

    return out;
}

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
        catch (int err) {
            std::cout << "Такого файла нет" << std::endl;
        }
    }
    return c;
}

Spec_t::Spec_t() {
    name = "";
    n_form = 0;
    forms = nullptr;
    examScores = nullptr;
    costs = nullptr;
}

University_t::University_t() {
    name = "";
    n_spec = 0;
    specs = nullptr;
}

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

int Univ_database_t::SearchVUZ(const std::string& name, University_t& u) const {
    for (int i = 0; i < count; i++) {
        if (univs[i].name == name) {
            u = univs[i];
            return 1;
        }
    }
    return -1;
}

float University_t::ComputeAverageScore() const {
    float sum_examRes = 0, count = 0;
    for (int i = 0; i < n_spec; i++) {
        for (int j = 0; j < specs[i].n_form; j++) {
            sum_examRes += specs[i].examScores[j];
            count++;
        }
    }
    return sum_examRes / count;
}

float University_t::ComputeAverageCost() const {
    float sum_costs = 0, count = 0;
    for (int i = 0; i < n_spec; i++) {
        for (int j = 0; j < specs[i].n_form; j++) {
            sum_costs += specs[i].costs[j];
            count++;
        }
    }
    return sum_costs / count;
}

University_t& University_t::operator=(const University_t& u) {
    if (this != &u) {
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

void University_t::SearchMinScoreSpeciality(std::string& spec_name, int& score, std::string& form) {
    int min = 1000;
    EducationalForm edForm;
    std::string name_form, name_spec;
    
    for (int i = 0; i < n_spec; i++) {
        for (int j = 0; j < specs[i].n_form; j++) {
            if (specs[i].examScores[j] < min) {
                min = specs[i].examScores[j];
                edForm = specs[i].forms[j];
                name_spec = specs[i].name;
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
        for (int j = 0; j < univs[i].n_spec; j++) {
            if (univs[i].specs[j].name == name)
                c_spec++;
        }
    }
    specs = new Spec_t[c_spec];
    names_univ = new std::string[c_spec];
    int k = 0;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < univs[i].n_spec; j++) {
            if (univs[i].specs[j].name == name) {
                specs[k] = univs[i].specs[j];
                names_univ[k] = univs[i].name;
                k++;
            }
        }
    }
    return c_spec;
}