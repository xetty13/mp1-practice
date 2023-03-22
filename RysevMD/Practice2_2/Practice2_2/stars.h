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
	std::string name;
	Star* stars;
};

void allocate(Constellation** cns);
void cfree(Constellation** cns);

void cnst_table(Constellation* cns);
void read_data(Constellation* cns);
void print_data(Constellation* cns, int num);
void choice(Constellation* cns);
#endif 


