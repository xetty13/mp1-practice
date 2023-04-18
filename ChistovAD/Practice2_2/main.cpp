#define _CRT_SECURE_NO_WARNINGS
#include "workers.h";
using namespace std;

int main() {
	string path = get_path();
	labor labor_exchange(path);
	labor_exchange.higher_education(path);
	return 0;
}
