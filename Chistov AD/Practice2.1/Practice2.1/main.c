#define _CRT_SECURE_NO_WARNINGS
#include "workers.h";

int main() {
	worker**w;
	char* path = get_Path();
	int N = amount(path);
	allocate_workers(&w, N);
	adding(w,path);
	higher_education(w, N);
	free_workers(&w, N);
}
