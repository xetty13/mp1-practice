#ifndef _FILEPROCESSING_H
#define _FILEPROCESSING_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 100

typedef struct {
    char name[MAX_NAME];
    int n_form;
    int form_info[3][2];
} Spec_t;

typedef struct {
    char name[MAX_NAME];
    int n_spec;
    Spec_t* specs;
} University_t;

int find_num_univ(FILE* fp);
void alloc_univ(FILE* fp, University_t** uns);
void print_all_info(University_t** uns, int c);
void free_memory(University_t** uns, int c);

#endif