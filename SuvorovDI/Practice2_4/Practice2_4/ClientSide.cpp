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

bool isDigit(const std::string& s) {
	for (int i = 0; i < s.size(); i++) {
		if (std::isdigit(s[i]) == 0)
			return false;
	}
	return true;
}

void work_with_client(TProductsDatabase& db) {
	std::cout << "\nWelcome!\n";

	TContainer<TReceipt> receipts;

	while (1) {
		std::string input_action;

		do {
			std::cout << "If you want to create new receipt - enter '1'\n";
			std::cout << "If you want to complete - enter '0'\n >>>  ";

			getline(std::cin, input_action);
			if (input_action != "1" and input_action != "0") {
				std::cout << "Uncorrect input. Try again\n";
			}
		} while (input_action != "1" and input_action != "0");

		if (input_action == "0") {
			break;
		}

		TReceipt curr_rec;

		bool receiptCompleted = false;
		while (!receiptCompleted) {
			std::cout << "If you want to scan new product - enter '+'.\n";
			std::cout << "If you want to complete this receipt and print it - enter '#'.\n";
			std::cout << "If you want to delete some product - enter '-'.\n  >>> ";

			std::string user_input;
			do {
				getline(std::cin, user_input);
				if (user_input != "#" and user_input != "-" and user_input != "+") {
					std::cout << "Uncorrect input! Try again following the input instructions\n  >>> ";
				}
			} while (user_input != "#" and user_input != "-" and user_input != "+");

			if (user_input == "#") {
				receiptCompleted = true;
			}
			else if (user_input == "-") {
				if (curr_rec.Get_num_products() == 0) {
					std::cout << "The receipt is empty, there is nothing to delete!\n"; \
				}
				else {
					std::cout << "Enter product barcode that you want to delete:\n\n  --- ";

					std::string barcode;

					int search_result = 0;
					bool isAvaliable = true;
					getline(std::cin, barcode);
					if (isDigit(barcode)) {
						search_result = curr_rec.Find_product(stol(barcode));
						if (search_result == -1) {
							std::cout << "You did not add a product with this barcode to the receipt. Try again\n\n  --- ";
						}
						else if (db[search_result].count == 0) {
							isAvaliable = false;
						}
					}
					if (!isDigit(barcode)) {
						std::cout << "Barcodes consists only of digits! Try again\n\n  --- ";
					}
					if (!isAvaliable) {
						std::cout << "Unfortunately, the product is out of stock. Take something else.\n\n  >>> ";
					}

					if (search_result != -1 and isDigit(barcode) and isAvaliable) {
						db.Updating_data_add(curr_rec[search_result].Get_product(), curr_rec[search_result].Get_count());
						curr_rec.Delete_prod(search_result);
					}
				}
			}
			else if (user_input == "+") {
				std::cout << "Enter barcode you want to add\n\n  >>> ";

				int search_result = 0;
				bool isAvaliable = true;

				std::string barcode;
				getline(std::cin, barcode);
				if (isDigit(barcode)) {
					search_result = db.barcode_search(stol(barcode));
					if (search_result == -1) {
						std::cout << "In our store there are not the product with this barcode. Try again!\n  >>> ";
					}
					else if (db[search_result].count == 0) {
						isAvaliable = false;
					}
				}
				if (!isDigit(barcode)) {
					std::cout << "Barcodes consists only of digits! Try again!\n\n  >>> ";
				}
				if (!isAvaliable) {
					std::cout << "Unfortunately, the product is out of stock. Take something else.\n\n  >>> ";
				}
					
				if (search_result != -1 and isDigit(barcode) and isAvaliable) {

					TProduct curr_p = db[search_result].product;
					std::cout << "\n" << curr_p << "\n";

					// Search such prod in receipt

					int idx_prod_in_receipt = curr_rec.Find_product(curr_p.code);
					if (idx_prod_in_receipt != -1) {
						(curr_rec[idx_prod_in_receipt]).Set_count(
							(curr_rec[idx_prod_in_receipt]).Get_count() + 1
						);

						(curr_rec[idx_prod_in_receipt]).Set_sum_cost(
							(curr_rec[idx_prod_in_receipt]).Get_sum_cost() + curr_p.cost
						);
					}
					else {
						TReceiptLine curr_rec_line(curr_p, 1, curr_p.cost);
						curr_rec.Add_new_prod(curr_rec_line);
					}

					db.Updating_data_remove(curr_p);
				}
			}
		}
		
		if (curr_rec.Get_num_products() == 0) {
			std::cout << "You have completed the purhase, BUT you haven't added any products! So the reciept hasn't created\n";
		}
		else {
			curr_rec.Get_data_n_time();
			receipts.insert(curr_rec);
			std::cout << receipts.current();
		}
	}
	create_updating_db(db);
}