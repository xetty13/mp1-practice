#include <iostream>
#include "Header.h"

int main() {
	try {
		TContainer<int> c(3);
		int s = 123;
		c.insert(s);
		c.insert(34);
		c.insert(12);
		c.insert(1);
		c.print_elements();
		std::cout << "\n";

		c.remove(1);
		c.print_elements();
		std::cout << "\n";
		std::cout << c[1] << "\n";
		std::cout << c.next() << "\n";
		std::cout << c.next() << "\n";
	}
	catch (std::exception& err) {
		std::cout << err.what();
	}


	return 0;
}