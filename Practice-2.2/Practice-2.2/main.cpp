#define _CRT_SECURE_NO_WARNINGS
#include "workers.h";
using namespace std;

int main() {
	string path = GetFilePath();
	int N = amount(path);
	worker* w = new worker[N];
	//adding(w, path, N);
	//higher_education(w, N);
	//delete[] w;
	return 0;
}
