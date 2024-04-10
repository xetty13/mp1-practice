#include "Gender.h"
void read_gend(const FILE* f, Gender* g)
{
    g->gender = (char*)malloc(sizeof(char) * Buffer);
    fscanf(f, "%s", g->gender);
}