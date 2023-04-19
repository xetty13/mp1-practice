#include "fileProcessing.h"

Univ_database_t::Univ_database_t(const std::string fname, const int c) {
    int i = 0;
    std::string line;
    std::ifstream file(fname);
    univs = new University_t[c];

    while (i < c) {
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

                if (type_form == "дневна€") {
                    univs[i].specs[j].forms[z] = DNEV;
                    getline(file, line, ';');
                    univs[i].specs[j].examScores[z] = atoi(line.c_str());
                    getline(file, line, ';');
                    univs[i].specs[j].costs[z] = atoi(line.c_str());
                }
                if (type_form == "вечерн€€") {
                    univs[i].specs[j].forms[z] = VECHER;
                    getline(file, line, ';');
                    univs[i].specs[j].examScores[z] = atoi(line.c_str());
                    getline(file, line, ';');
                    univs[i].specs[j].costs[z] = atoi(line.c_str());
                }
                if (type_form == "заочна€") {
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
    delete univs;
}
University_t::~University_t() {
    delete specs;
}
Spec_t::~Spec_t() {
    delete forms;
    delete examScores;
    delete costs;
}

University_t& Univ_database_t::operator[] (const int ind) {
    return univs[ind];
}

std::ostream& operator << (std::ostream& out, const University_t& un) {
    int i, j, sum_costs = 0, sum_examRes = 0, count = 0;
    std::cout << "»нформаци€ о ¬”«е " << un.name << ":\n";
    std::cout << "¬”« " << un.name << " имеет " << un.n_spec << " специальностей:\n";

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

    std::cout << "—редний балл дл€ поступлени€ по ¬”«у: " << double(sum_examRes) / count << std::endl;
    std::cout << "—редн€€ стоимость обучени€ по ¬”«у : " << double(sum_costs) / count << "\n\n";
    return out;
}

int find_num_univ(const std::string fname) {
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

//University_t* fill_univ(std::string fname, int c) {
//    int i = 0;
//    std::string line;
//    std::ifstream file(fname);
//    University_t* uns = new University_t[c];
//
//    while (i < c) {
//        getline(file, uns[i].name, ';');
//        getline(file, line, ';');
//        uns[i].n_spec = atoi(line.c_str());
//        uns[i].specs = new Spec_t[uns[i].n_spec];
//
//        for (int j = 0; j < uns[i].n_spec; j++) {
//            getline(file, uns[i].specs[j].name, ';');
//            getline(file, line, ';');
//            uns[i].specs[j].n_form = atoi(line.c_str());
//
//            uns[i].specs[j].forms = new EducationalForm[uns[i].specs[j].n_form];
//            uns[i].specs[j].costs = new int[uns[i].specs[j].n_form];
//            uns[i].specs[j].examScores = new int[uns[i].specs[j].n_form];
//
//            for (int z = 0; z < uns[i].specs[j].n_form; z++) {
//                std::string type_form;
//                getline(file, line, ';');
//                type_form = line;
//
//                if (type_form == "дневна€") {
//                    uns[i].specs[j].forms[z] = DNEV;
//                    getline(file, line, ';');
//                    uns[i].specs[j].examScores[z] = atoi(line.c_str());
//                    getline(file, line, ';');
//                    uns[i].specs[j].costs[z] = atoi(line.c_str());
//                }
//                if (type_form == "вечерн€€") {
//                    uns[i].specs[j].forms[z] = VECHER;
//                    getline(file, line, ';');
//                    uns[i].specs[j].examScores[z] = atoi(line.c_str());
//                    getline(file, line, ';');
//                    uns[i].specs[j].costs[z] = atoi(line.c_str());
//                }
//                if (type_form == "заочна€") {
//                    uns[i].specs[j].forms[z] = ZAOCH;
//                    getline(file, line, ';');
//                    uns[i].specs[j].examScores[z] = atoi(line.c_str());
//                    getline(file, line, ';');
//                    uns[i].specs[j].costs[z] = atoi(line.c_str());
//                }
//            }
//        }
//        i++;
//        file.get();
//    }
//
//    file.close();
//    return uns;
//}

void print_all_info(University_t* uns, int c) {
    for (int i = 0; i < c; i++) {
        std::cout << uns[i].name << "   " << uns[i].n_spec << " специальностей:\n";
         
        for (int j = 0; j < uns[i].n_spec; j++) {
            std::cout << "   " << uns[i].specs[j].name << "  " << uns[i].specs[j].n_form << " форм обучени€:\n";

            for (int z = 0; z < uns[i].specs[j].n_form; z++) {
                std::cout << "      " << uns[i].specs[j].examScores[z] << "  " << uns[i].specs[j].costs[z] << "\n";
            }
        }
    }
}

int try_to_open_file(std::string& fname) {
    int c = -1;
    while (c == -1) {
        try {
            getline(std::cin, fname);
            c = find_num_univ(fname);
        }
        catch (int err) {
            std::cout << "“акого файла нет" << std::endl;
        }
    }
    return c;
}