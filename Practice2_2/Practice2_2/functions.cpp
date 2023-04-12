#include "title.h"
int count_shops(const string adress) {
	ifstream base(adress);
	
	string line;
	int lines = 0;
	if (base.is_open()) {
		cout << "File opened successfully!\n";
		while (!base.eof()) {
			getline(base, line);
			lines++;
		}
	}
	else {
		cout << "Error opening file";
		exit(1);
	}
	base.close();
	return lines;
}
//void malloc_struct(Shop** shop, int length) {
//	*shop = new Shop[length];
//}
Shop* info(int& n,const string adress) {
	ifstream file(adress);
	Shop* shop = new Shop[n];
	for (int i = 0; i < n; i++)
	{
		file >> shop[i].name >> shop[i].adress >> shop[i].phone_number >> shop[i].specialization >> shop[i].opening_hours >> shop[i].opening_days >> shop[i].form_of_ownership;
	}
	file.close();
	return shop;
}
void print_str(Shop* shop, int n) {
	for (int i = 0; i < n; i++) {
		shop[i].print_struct();
	}
}
void print_str(Shop* shop, int n,int* arr) {
	cout << "\nПодходящие нам магазины: " << endl;
	for (int i = 0; i < n; i++) {
		shop[arr[i]].print_struct();
	}
}
void free_struct(Shop** shop) {
	delete[] *shop;
}
int quantity(Shop* shop, int records) {
	int count = 0;
	const string str1 = "Products";
	const string str2 = "AllDay";
	for (int i = 0; i < records; i++) {
		if(((shop[i].specialization.compare(str1))==0) && ((shop[i].opening_hours.compare(str2))==0))
			count++;
	}
	return count;
}
int* array_our(Shop* shop, int nums, int records) {
	int* arr = new int[nums];
	const string str1 = "Products";
	const string str2 = "AllDay";
	int j = 0;
	while (j < nums) {
		for (int i = 0; i < records; i++) {
			if (((shop[i].specialization.compare(str1)) == 0) && ((shop[i].opening_hours.compare(str2)) == 0)) {
				arr[j] = i;
				j++;
			}
		}
	}
	return arr;
}