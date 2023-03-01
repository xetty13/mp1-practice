#ifndef _Header_bankh_
#define _Header_bankh_

typedef struct {
	char* name;
	char* ownership;
	int count;
	int* periods;
	float* conditions;
	
} BanksData;
typedef struct {
	int id1;
	int id2;
	float profit;
} pair;

void input_path(char* path);
void read(FILE* file, BanksData* data, int n);
void print_data(BanksData* data, int n);
void freedata(BanksData** data, int n);
void input_user_data(int* user_year, float* user_money);

pair comparing(BanksData* data, int n, int user_year, int user_money);

#endif