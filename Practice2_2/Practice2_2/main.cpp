#include "title.h"
void main() {
	const string adress = "shops.txt";
	List list(adress);
		cout << list;
		cout << "Our shops: " << endl;
		List our;
		our.correct_base(list);
		cout << our;

}
