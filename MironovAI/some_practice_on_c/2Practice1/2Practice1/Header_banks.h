#ifndef _Header_bankh_
#define _Header_bankh_
#define MAX_NAME 30

typedef struct {
	char* name;
	int period;
	float conditions;
} Deposit;
typedef struct {
	char* name;
	char* ownership;
	int count;
	Deposit* deposits;
} BanksData;
typedef struct {
	int id1;
	int id2;
	float profit;
} pair;

void input_path(char* path);
int read(BanksData** data);
void print_data(BanksData* data, int n);
void freedata(BanksData** data, int n);
void input_user_data(int* user_year, float* user_money);

pair comparing(BanksData* data, int n, int user_year, int user_money);

#endif

