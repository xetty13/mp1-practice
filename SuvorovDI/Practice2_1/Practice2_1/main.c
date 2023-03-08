#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "fileProcessing.h"

int main() {
    setlocale(LC_ALL, "Russian");

    // file data
    FILE* fp;
    char fname[] = "VUZ.csv";
    fp = fopen(fname, "r");
    int c_univ;
    University_t* uns;

    if (fp == NULL)
    {
        printf("No such file");
        return 1;
    }

    // counting the number of univercity
    c_univ = find_num_univ(fp);

    // replace file pointer to start of file
    rewind(fp);

    uns = (University_t*)malloc(sizeof(University_t) * c_univ);

    // allocating all array of university structs
    alloc_univ(fp, &uns);

    print_all_info(&uns, c_univ);



    free_memory(&uns, c_univ);

    fclose(fp);

    return 0;
}