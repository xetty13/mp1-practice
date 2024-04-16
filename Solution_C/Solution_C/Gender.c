#include "Person.h"
#include <string.h>
void read_gend(const FILE* f, Gender *g)
{
    char tmp[10];
    fscanf(f, "%s", tmp);
    if (strcmp(tmp, "Male") == 0)
    {
        *g = 0;
    }
    if (strcmp(tmp, "Female") == 0)
    {
        *g = 1;
    }
}