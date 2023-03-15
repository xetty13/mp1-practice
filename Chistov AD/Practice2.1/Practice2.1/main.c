#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "workers.h";

int main() {
	worker* w;
	char* buffer;
	int n = counter();
	int N = amount();
	buffer = readFile(n);
	allocate(&w, N);
	adding(w, buffer);
	higher_education(w, N);
}
