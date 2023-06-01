#include <iostream>
#include "Header.h"
#include "ClientSide.h"

int main() {
	std::string file_name;
	TProductsDatabase database(file_name);

	work_with_client(database);

	return 0;
}