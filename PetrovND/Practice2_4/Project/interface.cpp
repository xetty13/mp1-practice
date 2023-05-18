#include "interface.h"
#include "container.h"
#include "receipt.h"
#include <iostream>
#include <fstream>

string start() {
	string path;
	while (true) {
		cout << "Enter the file path..." << endl;
		getline(cin, path);
		ifstream file(path);
		if (file.good()) {
			file.close();
			return path;
		}
		cout << "ERROR: Could not open file!\n" << endl;
	}
}

string getDebugPath() {
	string path;
	while (true) {
		cout << "Enter path to debug file..." << endl;
		getline(cin, path);
		ifstream file(path);
		if (file.good()) {
			file.close();
			return path;
		}
	}
}

void menu(dataBase& data, Container<Receipt>& receipts) {
	int i = 0;
	while (true) {
		Receipt currentReceipt(i);
		bool exit = false;
		while (!exit) {
			cout << "Menu:\n";
			cout << "1. Add item\n";
			cout << "2. Remove item\n";
			cout << "3. Counting summ\n";
			cout << "4. New receipt\n";
			cout << "5. Exit\n";

			int choice;
			cout << "Enter menu's point: ";
			cin >> choice;

			switch (choice) {
			case 1: {
				Product* product = data.searchProductByCode();
				currentReceipt.addItem(product, data);
				cout << currentReceipt << endl;
				break;
			}
			case 2: {
				Product* product = data.searchProductByCode();
				currentReceipt.removeItem(product);
				cout << currentReceipt << endl;
				break;
			}
			case 3: {
				cout << currentReceipt;
				cout << "Total cost: " << currentReceipt.getTotal() << endl;
				break;
			}
			case 4: {
				receipts.add(currentReceipt);
				exit = true;
				cout << "New receipt...\n";
				i++;
				currentReceipt.dataUpdate(data);
				break;
			}
			case 5: {
				receipts.add(currentReceipt);
				currentReceipt.dataUpdate(data);
				cout << "Exit.\n";
				string debugPath = getDebugPath();
				data.writeData(debugPath);
				return;
			}

			}
		}
	}
}