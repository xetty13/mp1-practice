#ifndef _HEADER_H
#define _HEADER_H

using namespace std;

struct date {
	int day;
	int month;
	int year;
	date();
	date(const string& str);
	const date& operator= (const date& e);
	friend ostream& operator<<(ostream& out, const date& d) {
		out << d.day << "." << d.month << ".19" << d.year;
		return out;
	};
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
	pasport();
	pasport(const string* str);
	bool isElderly() const;
	const pasport& operator= (const pasport& e);
	friend ostream& operator<<(ostream& out, const pasport& p) {
		out << p.birth;
		return out;
	};
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
	employee();
	employee(const string& str);
	pasport givepasport(); 
	const employee& operator= (const employee& e);
	friend ostream& operator<<(ostream& out, const employee& e) {
		out << e.name << " - " << e.pspt;
		return out;
	};
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
			out << l.empls[i] << endl;
		}
		return out;
	}

	lib output() const;
};

string get_string(ifstream& file);

#endif //!_HEADER_H