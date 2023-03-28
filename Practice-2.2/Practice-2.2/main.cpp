#define _CRT_SECURE_NO_WARNINGS
#include "workers.h";

int main() {
	worker** w;
	int N = amount();
	allocate_workers(&w, N);
	adding(w);
	higher_education(w, N);
	free_workers(&w, N);
}