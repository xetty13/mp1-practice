#include "Client.h"
#include <fstream>
#include <sstream>
void create_updating_db(TProductsDatabase& db) 
{

	ofstream ofc;
	ofc.open("basenew.txt",ios::out|ios::trunc);
	for (int i = 0; i < db.Get_num_prods(); i++) {
		ofc << db[i].product.code << ";";
		ofc << db[i].product.name << ";";
		ofc << db[i].product.price << ";";
		ofc << db[i].count << ";";
		ofc << "\n";
	}
	ofc.close();
}
string get_action(string action)
{

	do
	{
		cout << "Enter '1' for create new receipt " << endl;
		cout << "Enter '0' to complete " << endl;

		getline(cin, action);
		if ((action) != "1" && (action != "0"))
		{
			cout << "Uncorrect input." << endl;
		}
	} while (action != "1" && action != "0");
	return action;
}
int get_barcode_to_add(TProductsDatabase& db, string user_input)
{
	int search;
	bool available;
	do
	{
		available = true;
		search = db.barcode_search(stol(user_input));
		if (search == -1)
		{
			cout << "No the product with this barcode" << endl;
			getline(cin, user_input);
		}
		if (db[search].count == 0)
		{
			available = false;
			cout << "Product is out. Add another " << endl;
			getline(cin, user_input);
		}

	} while (search == -1 || !available);
	return search;
}
void work_with_client(TProductsDatabase& db) 
{
	TContainer<TReceipt> receipts;
	while (1) {
		string action;

		action = get_action(action);

		if (action == "0")
		{
			break;
		}

		TReceipt curr_receipt;
		bool f = false;
		while (!f) 
		{
			string user_input;
			cout << "Enter barcode."<<endl;
			cout << "Enter '#' to complete this receipt and print it " << endl;
			cout << "Enter '-' to delete some product " << endl;
			getline(cin, user_input);

			if (user_input == "#") 
			{
				f = true;
			}
			else if (user_input == "-") 
			{
				curr_receipt.Delete(db);
			}
			else 
			{
				int search = get_barcode_to_add(db, user_input);
				curr_receipt.Add(db, search);
			}
		}
		if (curr_receipt.Get_num_products() == 0) 
		{
			cout << "You haven't added any products. The reciept hasn't created\n";
		}
		else 
		{
			curr_receipt.SetTime();
			receipts.insert(curr_receipt);
			cout << receipts.current();
		}
	}
	create_updating_db(db);
}