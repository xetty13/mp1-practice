#include "fileProcessing.h"

Univ_database_t::Univ_database_t(const std::string& fname) {
    int i = 0;
    std::string line;
    std::ifstream file(fname);
    count = find_num_univ(fname);
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

Univ_database_t::~Univ_database_t() {
    delete []univs;
}
University_t::~University_t() {
    delete []specs;
}
Spec_t::~Spec_t() {
    delete []forms;
    delete []examScores;
    delete []costs;
}

University_t& Univ_database_t::operator[] (const int ind) {
    return univs[ind];
}

std::ostream& operator<<(std::ostream& out, const University_t& un) {
    int i, j, sum_costs = 0, sum_examRes = 0, count = 0;
    std::cout << "Информация о ВУЗе " << un.name << ":\n";
    std::cout << "ВУЗ " << un.name << " имеет " << un.n_spec << " специальностей:\n";

    for (i = 0; i < un.n_spec; i++) {
        std::cout << "   " << un.specs[i].name << std::endl;
    }

    for (i = 0; i < un.n_spec; i++) {
        for (j = 0; j < un.specs[i].n_form; j++) {
            sum_costs += un.specs[i].costs[j];
            sum_examRes += un.specs[i].examScores[j];
            count++;
        }
    }

    std::cout << "Средний балл для поступления по ВУЗу: " << double(sum_examRes) / count << std::endl;
    std::cout << "Средняя стоимость обучения по ВУЗу : " << double(sum_costs) / count << "\n\n";
    return out;
}

int Univ_database_t::find_num_univ(const std::string& fname) {
    std::string line;
    int c = 0;

    std::ifstream file(fname);
    
    if (file.fail())
        throw -1;

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