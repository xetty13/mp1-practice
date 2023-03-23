#ifndef _Header_bankh_
#define _Header_bankh_
#define MAX_PATH 100 // Max path length 
#define MAX_NAME 20  // Max name of banks length
using namespace std;



struct triple {
	int id1;
	int id2;
	float profit;
	//default constuctor and destructor
};

struct Deposit {
	string name;
	int period;
	float conditions;
	//default contructor axnd destructor
};
struct BanksData {
	string name;
	string ownership;
	int count;
	int user_year;
	float user_money;
	vector<Deposit> deposits;
	pair<int, float> best_suggestion;

	//Constructor
	BanksData() {
		name = "";
		ownership = "";
		count = -1;
		user_money = -1;
		user_year = -1;
		best_suggestion.first = -1;
		best_suggestion.second = -1;
		deposits.resize(0);
	}
	//Destructor
	~BanksData()
	{
		deposits.resize(0);
	}
	pair<int, float> best_deposit(int user_year, float user_money);
	bool operator>(BanksData sd) {
		if (best_suggestion.second > sd.best_suggestion.second) return true;
		return false;
	}
	bool operator<(BanksData sd) {
		if (best_suggestion.second < sd.best_suggestion.second) return true;
		return false;
	}
};


int read(BanksData*& data, int* n, const string& path);

void input_path(string& path);
void print_data(BanksData* data, int n);
void input_user_data(int* user_year, float* user_money);

triple comparing(BanksData* data, int user_year, float user_money, int n);
#endif