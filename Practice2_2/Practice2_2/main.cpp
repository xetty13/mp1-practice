#include "title.h"
void main() {
	const string adress = "shops.txt";
	int shop_count = count_shops(adress);
	List list = info(shop_count, adress);
		cout << list;
	int quantity = our_quantity(list.shop, shop_count);
	cout << "\nOur shops: " << endl;
	List our = correct_shop(list.shop, shop_count, quantity);
		cout << our ;
	free_str(&list, list.count);
	free_str(&our, our.count);
}
