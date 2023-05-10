#include "title.h"
void main() {
	const string adress = "shops.txt";
	int shop_count = count_shops(adress);
	Shop* shops = info(shop_count, adress);
	for (int i = 0; i < shop_count; i++) {
		cout << shops[i];
	}
	int quantity = our_quantity(shops, shop_count);
	cout << "\nOur shops: " << endl;
	Shop* shop = correct_shop(shops, shop_count, quantity);
	for (int i = 0; i < quantity; i++) {
		cout << shop[i] ;
	}
	free_str(shops, shop_count);
	free_str(shop, quantity);
}
