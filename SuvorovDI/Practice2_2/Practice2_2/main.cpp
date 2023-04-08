#include "fileProcessing.h"
#include "userSide.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string fname;
	int count_univ = -1;
	University_t* uns;

	count_univ = try_to_open_file(fname);

	uns = fill_univ(fname, count_univ);
	/*print_all_info(uns, count_univ);*/

	working_with_user(uns, count_univ);

	free_memory(uns, count_univ);

	return 0;
}