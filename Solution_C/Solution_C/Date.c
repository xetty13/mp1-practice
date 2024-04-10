#include "Date.h"
void read_date(const FILE* f, Date* d)
{
    fscanf(f, "%d.%d.%d", &d->day, &d->month, &d->year);
}