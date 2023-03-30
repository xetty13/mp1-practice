#define _CRT_SECURE_NO_WARNINGS
#include "workers.h";
using namespace std;

int main() {
	string path = get_Path();
	int N = amount(path);
	worker* w = new worker[N];
	adding(w, path, N);
	higher_education(w, N);
	delete[] w;
}
