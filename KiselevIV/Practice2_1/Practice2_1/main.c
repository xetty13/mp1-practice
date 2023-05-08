#define _CRT_SECURE_NO_WARNINGS
#include "banki.h"

int main() {
	//char* path = "C:\\Users\\abobi\\OneDrive\\Рабочий стол\\banki2.txt";
	char* path = getfile();//C:\Users\abobi\banki2.txt
	int stringcount= strcount(path);

	bankstruct** banki = allocbanki(stringcount);
	workfile(banki, path, stringcount);

	int sumvkl = 0;
	int your_month = 0;
	char your_type[15];
	data_input(&sumvkl, &your_month, &your_type);

	chooseall(sumvkl, your_month, banki,stringcount, &your_type);
	freebanki(banki, stringcount);
	return 0;
}