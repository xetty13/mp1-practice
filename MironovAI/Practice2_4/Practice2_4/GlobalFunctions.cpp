#include "Header.h"
#include <iostream>
#include <fstream>
using namespace std;

int PathError()
{
	std::cout << "This file isn`t exist. Be sure, that u writed a correct path with type *.<type>" << endl;
	return 1;
}
string input_path()
{
	string path; std::cout << "Input a path: \n "; cin >> path;
	ifstream file(path);
	if (!file) {
		throw PathError();
	}
	return path;
}
double operator+(int& f, Cart s) {
	double tmp = f;
	tmp += s.get_cost();
	return tmp;
}
void user()
{

	NewContainer<Base> base;
	NewContainer<Base>::read(input_path(), base);
	Receipt q;
	q.set_num(1);
	//Base* e = base.get_elements();
	std::cout << "Hi. Lets start.\n\nThis is all our products:\n ";  cout << base << endl;

	while (true) {


		std::cout << "Choose what do u wanna do " << endl;
		std::cout << "Input 0 :kill the programm 1: add some products 2: remove some products 3: output receipt(cart) 4: print all products " << endl;

		int user, f = 1; cin >> user;

		if (user == 0) {
			f = 0;
			std::cout << "Have a nice day! " << endl;
			break;
		}
		if (user == 1) {

			f = 0;
			std::cout << "Which one do u wanna add ? Pls input code of product" << endl;
			string product;  cin >> product;
			int count = 0, ucount;

			// if we dont have the product
			if (base.find(product) == nullptr)
			{
				std::cout << "Sorry, we dont have this product now" << endl;
				continue;
			}

			//now we know, that we have this product "pr" 
			Base pr = *base.find(product);
			count = pr.get_count();
			cout << "\nYour product:      " << pr.get_product() << endl;

			std::cout << "\nInput a count of products between 0 and " << count << endl;
			cin >> ucount;
			//changing count in the base
			if (ucount < 0 || ucount > count) {
				std::cout << "Wrong count. Try again" << endl;
				continue;
			}
			if (ucount == 0) continue;
			base[base.find_id(pr)].set_count(pr.get_count() - ucount);

			//add
			if (q.find(pr) != nullptr)
				q.add(*q.find(pr), ucount);
			else {
				q.add(pr.get_product(), ucount);

			}
			cout << "\nDone! \n\n" << endl;
		}
		if (user == 2) {

			f = 0;
			q.print_cart();
			if (q.empty())
			{
				cout << "Nothing in the cart. Add something!\n" << endl;
				continue;
			}
			std::cout << "Which one do u wanna remove ? Pls input code of product" << endl;
			string product;  cin >> product;
			int ucount;

			//find element in the cart
			Cart* tmp = q.find(product);
			if (tmp == nullptr) {
				std::cout << "Sorry, we dont have this product in the cart " << endl;
				continue;
			}


			//user count 
			std::cout << "Input a count of products between 0 and " << tmp->get_count() << endl;
			cin >> ucount;
			if (ucount < 0 || ucount > tmp->get_count()) {
				std::cout << "Wrong count. Try again" << endl;
				continue;
			}

			// add deleted from the cart elements to the base
			int index = base.find_id(product);
			if (index >= 0 && index < base.len())
			{
				base[index] += ucount;
			}

			//remove 
			q.remove(*tmp, ucount);
			cout << "\nDone!" << endl;
			q.print_cart();

		}
		if (user == 3)
		{
			f = 0;
			if (q.empty())
			{
				cout << "Nothing in the cart. Add something.\n" << endl;
				continue;
			}
			cout << "Time of receipt formation: " << endl;
			q.pdata();
			q.print_cart();
			cout << "Total cost: " << q.sum() << endl;
		}
		if (user == 4)
		{
			cout << " " << base;
			f = 0;
		}
		if (f) cout << "Input Date is wrong. Try again. " << endl;
	}
	string filename; cin >> filename;
	dump_data_base(base, filename);
	std::cout << "Have a nice day! " << endl;

}

template <typename Type>
void dump_data_base(const NewContainer<Type>& base, const string& filename)
{
	std::ofstream file(filename);
	if (file.is_open())
	{
		file << base << endl;
		file << "DONE!!!" << endl;
	}
	file.close();
}
