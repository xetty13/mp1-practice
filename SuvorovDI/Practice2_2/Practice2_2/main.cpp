#include "fileProcessing.h"
#include "userSide.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string fname;
	int count_univ = -1;

	count_univ = try_to_open_file(fname);
	Univ_database_t unsdata(fname, count_univ);

	working_with_user(unsdata, count_univ);

	return 0;
}