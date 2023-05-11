#include "receipt.h"

int main() {//C:\Users\nikit\Desktop\1.txt
	string path = start();
	dataBase data(path);
	Receipt receipt;
	menu(data, receipt);
	return 0;
}