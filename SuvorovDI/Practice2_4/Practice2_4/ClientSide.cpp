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

		bool isCompleted = false;
		while (!isCompleted) {
			int search_result;
			std::cout << "\nPlease, scan new product.\n";
			
			std::string user_input;
			do {
				std::cout << "\n >>> ";
				getline(std::cin, user_input);
				search_result = db.barcode_search(stol(user_input));
				if (search_result == -1) {
					std::cout << "In our store there are not the product with this barcode. Try again\n";
				}
					
			} while (search_result == -1);

			TProduct curr_p = db[search_result].product;
			std::cout << "\n" << curr_p << "\n\n";
					
			// Search such prod in receipt
				
			int idx_prod_in_receipt = curr_rec.Find_product(curr_p);
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

			std::cout << "If you want to complete this receipt and print it - enter '#'.\n";
			std::cout << "If you want to delete last added product - enter '-'.\n";
			std::cout << "If you want to delete certain product - enter its barcode.\n";
			std::cout << "If you want to add new product - enter '+'.\n";

			do {
				std::cout << "\n >>> ";
				getline(std::cin, user_input);
				if (user_input != "#" and user_input != "-" and user_input != "+") {
					std::cout << "Uncorrect input. You should enter '#' or '-' or '+'! Try again\n";
				}
			} while (user_input != "#" and user_input != "-" and user_input != "+");

			if (user_input == "#") {
				isCompleted = true;
			}
			else if (user_input == "-") {
				std::cout << "Last added product was deleted: \n";
				std::cout << curr_p << "\n\n";
				curr_rec.Delete_current_prod();
			}
		}
		
		curr_rec.Get_data_n_time();
		receipts.insert(curr_rec);
		std::cout << receipts.current();
	}
}