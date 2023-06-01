#include <iostream>
#include "Container.h"
#include "Client.h"

using namespace std;

int main()
{
	string file_name;
	TProductsDatabase database(file_name);
	cout << database;
	work_with_client(database);
	return 0;

}