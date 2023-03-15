#ifndef _FILEPROCESSING_H
#define _FILEPROCESSING_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 100
#define MAX_LINE_LEN 5000

typedef enum {
    DNEV,
    VECHER,
    ZAOCH
} EducationalForm;

typedef struct {
    char name[MAX_NAME];
    int n_form;
    EducationalForm* forms;
    int* examScores;
    int* costs;
} Spec_t;

typedef struct {
    char name[MAX_NAME];
    int n_spec;
    Spec_t* specs;
} University_t;

int find_num_univ(FILE* fp);
void fill_univ(FILE* fp, University_t* uns);
void print_all_info(University_t* uns, int c);
void free_memory(University_t* uns, int c);

#endif