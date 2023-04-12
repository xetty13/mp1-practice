#include "title.h"

int main() {
	setlocale(LC_ALL, "RU");
	const string adress = "shops.txt";
	int shop_count = count_shops(adress);
	//cout << shop_count << endl;
	Shop* shops = info(shop_count, adress);
	print_str(shops, shop_count);
	int nums = quantity(shops, shop_count);
	//cout << nums<<endl;
	int* arr = array_our(shops, nums,shop_count);
	print_str(shops, nums, arr);
	free_struct(&shops);
	return 0;
}