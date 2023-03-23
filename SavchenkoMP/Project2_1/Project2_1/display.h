#include "polynom.h"

#ifndef _DISPLAY_H
#define _DISPLAY_H

void choose();
void answer(int* ans);
void retry(int* ans);

void print_p(TPolynom** p, int n);
void index(int* ind, int n);
void print_2p(TPolynom* p1, TPolynom* p2, int* ind);


#endif // !_DISPLAY_H