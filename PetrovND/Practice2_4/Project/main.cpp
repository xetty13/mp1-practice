#include "receipt.h"
#include "container.h"
#include "interface.h"

int main() {//C:\Users\nikit\Desktop\1.txt
	string path = start();
	dataBase data(path);
	Container<Receipt> receipts;
	menu(data, receipts);
	return 0;
}