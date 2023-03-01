#ifndef _prototypes_h
#define _prototypes_h

void create_matrix(struct dynamic_matrix *ptr);
void line_reading(FILE* fptr);
void free_matrix(struct dynamic_matrix* ptr);
void file_reader(struct dynamic_matrix* lens_of_strings, FILE* fptr);
void print_data();

#endif