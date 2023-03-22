#define _CRT_SECURE_NO_WARNINGS
#include "workers.h";

int main() {
	worker**w;
	int N = amount();
	allocate_memory(&w, N);
	adding(w);
	higher_education(w, N);
	for (int i = 0; i < N; i++) {
		memory_free(&(w[i]));
	}
}
