#ifndef _HEADER_H
#define _HEADER_H

using namespace std;

class date {
private:
	int day;
	int month;
	int year;
public:
	void create_data(string str);
	void givedata(int* daydest, int* monthdest, int* yeardest);
	const date& operator= (const date& e);
};

class pasport {
private:
	int series;
	int number;
	string auth;
	string reg;
	date issue;
	date birth;
public:
	bool isElderly();
	void create_data(string* str);
	string givedate();
	const pasport& operator= (const pasport& e);
};

class employee {
private:
	pasport pspt;
	string name;
	string edu;
	string spec;
	string unit;
	string appnt;
	date dateofappnt;
	date lastdate;
public:
	void create_data(string str);
	string givename();
	pasport givepasport();
	const employee& operator= (const employee& e);
};

class lib {
private:
	int emp_amount;
	employee* empls;
public:
	lib(int n);
	lib(const lib& l);
	lib(const string& filename);
	~lib();

	employee& operator[](int ind);
	friend ostream& operator<<(ostream& out, const lib& l) {
		for (int i = 0; i < l.emp_amount; i++) {
			out << l.empls[i].givename() << " - " << l.empls[i].givepasport().givedate() << endl;
		}
		return out;
	}

	lib output();
};

string get_string(ifstream& file);

#endif //!_HEADER_H