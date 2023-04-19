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
	Constellation(std::string Cname, int n);
	~Constellation();
	int count;
	std::string name;
	Star* stars;
};
struct Constellation_library {
	Constellation_library(int n);
	~Constellation_library();
	Constellation** cns;
	int count;
};

std::ostream& operator<< (std::ostream& out, const Constellation* cns);

void cnst_table(Constellation_library* cns, int count);
void read_data(Constellation_library*& lib, int& cnt);
void choice(Constellation_library* cns, int count);
#endif 


