#include <iostream>
#include "Header.h"
#include "ClientSide.h"

int main() {
	std::string file_name;
	TProductsDatabase database(file_name);

	database.print();

	work_with_client(database);

	return 0;
}