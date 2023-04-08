#include "fileProcessing.h"

int find_num_univ(std::string fname) {
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

University_t* fill_univ(std::string fname, int c) {
    int i = 0;
    std::string line;
    std::ifstream file(fname);
    University_t* uns = new University_t[c];

    while (i < c) {
        getline(file, uns[i].name, ';');
        getline(file, line, ';');
        uns[i].n_spec = atoi(line.c_str());
        uns[i].specs = new Spec_t[uns[i].n_spec];

        for (int j = 0; j < uns[i].n_spec; j++) {
            getline(file, uns[i].specs[j].name, ';');
            getline(file, line, ';');
            uns[i].specs[j].n_form = atoi(line.c_str());

            uns[i].specs[j].forms = new EducationalForm[uns[i].specs[j].n_form];
            uns[i].specs[j].costs = new int[uns[i].specs[j].n_form];
            uns[i].specs[j].examScores = new int[uns[i].specs[j].n_form];

            for (int z = 0; z < uns[i].specs[j].n_form; z++) {
                std::string type_form;
                getline(file, line, ';');
                type_form = line;

                if (type_form == "дневная") {
                    uns[i].specs[j].forms[z] = DNEV;
                    getline(file, line, ';');
                    uns[i].specs[j].examScores[z] = atoi(line.c_str());
                    getline(file, line, ';');
                    uns[i].specs[j].costs[z] = atoi(line.c_str());
                }
                if (type_form == "вечерняя") {
                    uns[i].specs[j].forms[z] = VECHER;
                    getline(file, line, ';');
                    uns[i].specs[j].examScores[z] = atoi(line.c_str());
                    getline(file, line, ';');
                    uns[i].specs[j].costs[z] = atoi(line.c_str());
                }
                if (type_form == "заочная") {
                    uns[i].specs[j].forms[z] = ZAOCH;
                    getline(file, line, ';');
                    uns[i].specs[j].examScores[z] = atoi(line.c_str());
                    getline(file, line, ';');
                    uns[i].specs[j].costs[z] = atoi(line.c_str());
                }
            }
        }
        i++;
        file.get();
    }

    file.close();
    return uns;
}

void print_all_info(University_t* uns, int c) {
    for (int i = 0; i < c; i++) {
        std::cout << uns[i].name << "   " << uns[i].n_spec << " специальностей:\n";
         
        for (int j = 0; j < uns[i].n_spec; j++) {
            std::cout << "   " << uns[i].specs[j].name << "  " << uns[i].specs[j].n_form << " форм обучения:\n";

            for (int z = 0; z < uns[i].specs[j].n_form; z++) {
                std::cout << "      " << uns[i].specs[j].examScores[z] << "  " << uns[i].specs[j].costs[z] << "\n";
            }
        }
    }
}

void free_memory(University_t* uns, int c) {
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < uns[i].n_spec; j++) {
            delete[] uns[i].specs[j].forms;
            delete[] uns[i].specs[j].examScores;
            delete[] uns[i].specs[j].costs;
        }
        delete[] uns[i].specs;
    }
    delete[] uns;
}

int try_to_open_file(std::string& fname) {
    int c = -1;
    while (c == -1) {
        try {
            getline(std::cin, fname);
            c = find_num_univ(fname);
        }
        catch (int err) {
            std::cout << "Такого файла нет" << std::endl;
        }
    }
    return c;
}