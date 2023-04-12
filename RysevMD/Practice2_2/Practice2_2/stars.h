#ifndef _Star
#define _Star

struct Star {
	std::string name;
	float dist;
	float magnitude;
	float deg;
	float min;
	float sec;
};

struct Constellation {
	int count;
	std::string name;
	Star* stars;
};

void allocate(Constellation*& cns, int cnt);
void allocate(Star*& st, int cnt);
void cfree(Constellation*& cns);

void cnst_table(Constellation* cns, int count);
void read_data(Constellation*& cns, int& cnt);
void print_data(Constellation* cns, int num);
void choice(Constellation* cns, int count);
#endif 


