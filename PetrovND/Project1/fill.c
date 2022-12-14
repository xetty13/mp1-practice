#include "fill.h"

void add(unsigned long* copy, int* index, unsigned long* size, int count) {
    for (int i = 0; i < count; i++) {
        copy[i] = size[i];
        index[i] = i;
    }
}