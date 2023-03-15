#define _CRT_SECURE_NO_WARNINGS
#include "workers.h";

int main() {
	worker* w;
	int N = amount();
	allocate(&w, N);
	adding(w);
	higher_education(w, N);
}
