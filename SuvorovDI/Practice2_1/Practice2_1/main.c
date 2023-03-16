#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "fileProcessing.h"
#include "userSide.h"

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);

    char fname[] = "VUZ.csv";
    int c_univ;
    University_t* uns;

    // counting the number of univercity
    c_univ = find_num_univ(fname);

    // allocating all array of university structs
    uns = fill_univ(fname, c_univ);

    working_with_user(uns, c_univ);

    free_memory(uns, c_univ);
    
    return 0;
}