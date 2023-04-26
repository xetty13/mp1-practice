#ifndef _Star
#define _Star

struct Star {
	std::string name;
	float dist;
	float magnitude;
	float deg;
	float min;
	float sec;
	Star& operator=(const Star& obj);
};

class Constellation {
	public:
		Constellation(std::string Cname, int n);
		Constellation() { count = 0; name = ""; stars = nullptr; };
		~Constellation();
		int getCount() const { return count; }
		std::string getName() { return name; }
		friend std::ostream& operator<< (std::ostream& out, const Constellation* cns);
		friend std::istream& operator>> (std::istream& in, const Constellation* cns);
		Constellation& operator=(const Constellation& obj);
	private:
		int count;
		std::string name;
		Star* stars;
};
class Constellation_library {
	public:
		Constellation_library(std::string& path);
		~Constellation_library();
		int getCount() const { return count; }
		Constellation* getCns(int n) const { return &cns[n]; }
	private:
		Constellation* cns;
		int count;
};

std::string read_path();
void cnst_table(Constellation_library* lib, int count);
void choice(Constellation_library* lib, int count);
#endif
