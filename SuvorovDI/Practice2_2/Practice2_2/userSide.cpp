#include "userSide.h"
#include "fileProcessing.h"

std::string switch_form(EducationalForm form) {
    std::string name_form;
    switch (form) {
    case DNEV:
        name_form = "Дневная";
        break;
    case VECHER:
        name_form = "Вечерняя";
        break;
    case ZAOCH:
        name_form = "Заочная";
        break;
    }
    return name_form;
}

std::string main_entering_mode() {
    std::string in;
    getline(std::cin, in);
    while ((in != "1") && (in != "2") && (in != "0")) {
        std::cout << "Не корректный ввод, попробуйте ещё раз, следуйте инструкциям!\n";
        getline(std::cin, in);
    }
    return in;
}

std::string entering_mode() {
    std::string in;
    getline(std::cin, in);
    while ((in != "1") && (in != "2")) {
        std::cout << "Не корректный ввод, попробуйте ещё раз, следуйте инструкциям!\n";
        getline(std::cin, in);
    }
    return in;
}

// University info:

void about_univercity(Univ_database_t& unsdata) {
    std::string in;
    University_t curr_univ;
    int univ_ind;
    std::cout << "Выберите интересующую вас информацию:\n";
    std::cout << "Всё о конкретном ВУЗе - введите 1;\nСпециальность с минимальным баллом в конкретном ВУЗе - введите 2;\n";
    in = entering_mode();

    if (in == "1") {
        int cost, score, code;
        std::string name;
        std::cout << "Вы выбрали 'Всё о конкретном ВУЗе'\nВведите название вуза:\n";
        
        do {
            getline(std::cin, name);
            code = unsdata.SearchVUZ(name, curr_univ);
            if (code == -1)
                std::cout << "ВУЗа с таким названием нет в базе, попробуйте ещё раз\n";
        } while (code == -1);
        cost = curr_univ.ComputeAverageCost();
        score = curr_univ.ComputeAverageScore();

        std::cout << curr_univ;
        std::cout << "Средний балл для поступления по ВУЗу: " << score << "\n";
        std::cout << "Средняя стоимость обучения по ВУЗу : " << cost << "\n\n";
    }
    else if (in == "2") {
        std::string name;
        Spec_t s;
        int code;
        std::cout << "вы выбрали 'специальность с минимальным баллом в конкретном вузе'\nвведите название вуза:\n";
        do {
            getline(std::cin, name);
            code = unsdata.SearchVUZ(name, curr_univ);
            if (code == -1)
                std::cout << "ВУЗа с таким названием нет в базе, попробуйте ещё раз\n";
        } while (code == -1);

        int min_score;
        std::string name_form, spec_name;
        curr_univ.SearchMinScoreSpeciality(spec_name, min_score, name_form);
        std::cout << "Минимальный балл для поступления в ВУЗе " << curr_univ.name << ": " << min_score << "\n";
        std::cout << "Это специальность:  " << spec_name << ", Форма обучения: " << name_form << std::endl;
    }
}

// Specialty at a university:
int check_existing_spec(Univ_database_t& unsdata, std::string name_spec) {
    for (int i = 0; i < unsdata.count; i++) {
        for (int j = 0; j < unsdata[i].n_spec; j++) {
            if (unsdata[i].specs[j].name == name_spec) {
                return 1;
            }
        }
    }
    return 0;
}

void getting_spec(Univ_database_t& unsdata, std::string& name_spec) {
    getline(std::cin, name_spec);
    while (!check_existing_spec(unsdata, name_spec)) {
        std::cout << "Такой специальности не нашлось ни у одного ВУЗа из нашей базы, попробуйте ещё раз\n";
        getline(std::cin, name_spec);
    }
}

void print_all_about_spec(Spec_t* spec_arr, int c, std::string* names_univs) {
    std::string name_form;
    EducationalForm edForm;
    std::cout << "Специальность " << spec_arr[0].name << " присутствует в следующем перечне ВУЗов:\n";

    for (int i = 0; i < c; i++) {
        std::cout << names_univs[i] << ":\n";
        std::cout << "  В этом ВУЗе по этой специальности представлено " << spec_arr[i].n_form << " форм:\n";
        for (int z = 0; z < spec_arr[i].n_form; z++) {
            edForm = spec_arr[i].forms[z];
            name_form = switch_form(edForm);
            std::cout << "    " << name_form << "::проходные баллы : " << spec_arr[i].examScores[z];
            std::cout << "; стоимость обучения : " << spec_arr[i].costs[z] << " \n";
        }
    }
}

void print_min_score_for_spec(Spec_t* spec_arr, int c, std::string* names_univs) {
    int min = 1000;
    std::string name_form, name_univ;
    EducationalForm edForm;

    for (int i = 0; i < c; i++) {
        for (int z = 0; z < spec_arr[i].n_form; z++) {
            if (spec_arr[i].examScores[z] < min) {
                min = spec_arr[i].examScores[z];
                edForm = spec_arr[i].forms[z];
                name_form = switch_form(edForm);
                name_univ = names_univs[i];
            }
        }
    }

    std::cout << "По указанной специальности минимальный проходной балл по ВУЗам НН составляет: " << min << ". ВУЗ: ";
    std::cout << name_univ << ", форма обучения: " << name_form << std::endl;
}

int get_specs(Univ_database_t& unsdata, std::string name_spec, Spec_t** specs, std::string** names_univs) {
    int count = 0;
    for (int i = 0; i < unsdata.count; i++) {
        for (int j = 0; j < unsdata[i].n_spec; j++) {
            if (unsdata[i].specs[j].name == name_spec) {
                count++;
            }
        }
    }
    *specs = new Spec_t[count];
    *names_univs = new std::string[count];
    int ind = 0;
    for (int i = 0; i < unsdata.count; i++) {
        for (int j = 0; j < unsdata[i].n_spec; j++) {
            if (unsdata[i].specs[j].name == name_spec) {
                *specs[ind] = unsdata[i].specs[j];
                *names_univs[ind] = unsdata[i].name;
                ind++;
            }
        }
    }
    return count;
}

void about_spec(Univ_database_t& unsdata) {
    std::string in;
    int count_such_specs;
    Spec_t* specs;
    std::string* names_univ;
    std::cout << "Выберите интересующую вас информацию:\n";
    std::cout << "Всё о специальности - введите 1;\nМинимальный балл по специальности среди вузов - введите 2;\n";
    in = entering_mode();

    /*if (in == "1") {
        printf("Вы выбрали 'Всё о специальности'\nВведите название специальности:\n");
        getting_spec(unsdata, c, in);
        int count_such_specs = get_specs(unsdata, c, in, &specs, &names_univ);
        print_all_about_spec(specs, count_such_specs, names_univ);
    }
    else if (in == "2")
    {
        printf("Вы выбрали 'Минимальный балл по специальности среди вузов'\nВведите название специальности:\n");
        getting_spec(unsdata, c, in);
        int count_such_specs = get_specs(unsdata, c, in, &specs, &names_univ);
        print_min_score_for_spec(specs, count_such_specs, names_univ);
    }*/
}

void working_with_user(Univ_database_t& unsdata) {
    int end = 1;
    std::cout << "Что бы вы хотели узнать?\n";
    while (end) {
        std::string in;

        std::cout << "Если интересует информация о конкретном ВУЗе - нажмите 1, если о конкретной специальности - 2;\n";
        std::cout << "Если же узнали всю необходимую информацию и хотите завершить сессию - нажмите 0;\n\n";
        in = main_entering_mode();

        if (in == "1") {
            about_univercity(unsdata);
        }
        else if (in == "2") {
            about_spec(unsdata);

        }
        else if (in == "0") {
            std::cout << "Спасибо, что выбрали нас, до скорых встреч!\n";
            end = 0;
        }
        std::cout << "\n";
    }
}