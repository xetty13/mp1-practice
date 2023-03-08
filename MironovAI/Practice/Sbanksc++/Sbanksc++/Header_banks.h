#ifndef _Header_bankh_
#define _Header_bankh_
#define MAX_NAME 30
using namespace std;

struct Deposit {
	string name;
	int period;
	float conditions;
	//default contructor and destructor
};
struct BanksData {
	string name;
	string ownership;
	int count;
	vector<Deposit> deposits;
		
	//Constructor
	BanksData(){
		name = "";
		ownership = "";
		count = -1;
		deposits.resize(0);
	}
	//Destructor
	~BanksData()
	{
		deposits.resize(0);
	}

	



};
struct triple {
	int id1;
	int id2;
	float profit;
	//default constuctor and destructor
};

int read(BanksData** data, int *n, char* path);

void input_path(char* path);
void print_data(BanksData* data, int n);
void input_user_data(int* user_year, float* user_money);

triple comparing(BanksData* data, int n, int user_year, int user_money);

#endif
