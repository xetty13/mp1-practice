#include "ClientSide.h"

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
			std::cout << "If you want to scan new product - enter its barcode.\n";
			std::cout << "If you want to complete this receipt and print it - enter '#'.\n";
			std::cout << "If you want to delete some product - enter '-'.\n  >>> ";

			std::string user_input;
			do {
				getline(std::cin, user_input);
				if (user_input != "#" and user_input != "-" and user_input.size() != 5) {
					std::cout << "Uncorrect input. Remind that in our store barcodes have 5 characters! Try again\n  >>> ";
				}
			} while (user_input != "#" and user_input != "-" and user_input.size() != 5);

			if (user_input == "#") {
				receiptCompleted = true;
			}
			else if (user_input == "-") {
				if (curr_rec.Get_num_products() == 0) {
					std::cout << "The receipt is empty, there is nothing to delete!\n"; \
				}
				else {
					std::cout << "Enter product barcode that you want to delete:\n\n  --- ";
					int search_result;
					std::string barcode;
					do {
						getline(std::cin, barcode);
						search_result = curr_rec.Find_product(stol(barcode));
						if (search_result == -1) {
							std::cout << "You did not add a product with this barcode to the receipt. Try again\n\n  --- ";
						}

					} while (search_result == -1);
					curr_rec.Delete_prod(search_result);
				}
			}
			else {
				int search_result;
				do {
					search_result = db.barcode_search(stol(user_input));
					if (search_result == -1) {
						std::cout << "In our store there are not the product with this barcode. Try again\n  >>> ";
						getline(std::cin, user_input);
					}

				} while (search_result == -1);

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
}