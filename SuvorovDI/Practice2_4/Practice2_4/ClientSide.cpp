#include "ClientSide.h"

void create_updating_db(TProductsDatabase& db) {
	std::remove("DB.csv");
	std::ofstream file("DB.csv");

	for (int i = 0; i < db.Get_num_prods(); i++) {
		file << db[i].product.code << ";";
		file << db[i].product.name << ";";
		file << db[i].product.cost << ";";
		file << db[i].count << ";";
		file << "\n";
	}
	file.close();
}

std::string get_first_input() {
	std::string input_action;

	do {
		std::cout << "If you want to create new receipt - enter '1'\n";
		std::cout << "If you want to complete - enter '0'\n >>>  ";

		getline(std::cin, input_action);
		if (input_action != "1" and input_action != "0") {
			std::cout << "Uncorrect input. Try again\n";
		}
	} while (input_action != "1" and input_action != "0");

	return input_action;
}

std::string get_receipt_action() {
	std::string user_input;

	do {
		getline(std::cin, user_input);
		if (user_input != "#" and user_input != "-" and user_input != "+") {
			std::cout << "Uncorrect input! Try again following the input instructions\n  >>> ";
		}
	} while (user_input != "#" and user_input != "-" and user_input != "+");

	return user_input;
}

void Add_new_receipt(TContainer<TReceipt>& receipts, TReceipt& rec) {
	if (rec.Get_num_products() == 0) {
		std::cout << "You have completed the purhase, BUT you haven't added any products! So the reciept hasn't created\n";
	}
	else {
		rec.Get_data_n_time();
		receipts.insert(rec);
		std::cout << receipts.current();
	}
}

void work_with_client(TProductsDatabase& db) {
	std::cout << "\nWelcome!\n";

	TContainer<TReceipt> receipts;

	while (1) {
		std::string input_action = get_first_input();

		if (input_action == "0") {
			break;
		}

		TReceipt curr_rec;

		bool receiptCompleted = false;
		while (!receiptCompleted) {
			std::cout << "If you want to scan new product - enter '+'.\n";
			std::cout << "If you want to complete this receipt and print it - enter '#'.\n";
			std::cout << "If you want to delete some product - enter '-'.\n  >>> ";

			std::string user_input = get_receipt_action();

			if (user_input == "#") {
				receiptCompleted = true;
			}
			else if (user_input == "-") {
				curr_rec.Delete(db);
			}
			else if (user_input == "+") {
				curr_rec.Add(db);
			}
		}
		
		Add_new_receipt(receipts, curr_rec);
	}
	create_updating_db(db);
}