#ifndef _WORKERS_H
#define _WORKERS_H
#include <string>
using namespace std;

class worker {
private:
	string  id;
	string  profession;
	string  education;
	string  last_job;
	string  rsn_dismiss;
	string  family_status;
	int  contact_info;
public:
	worker();
	worker(const string  id,const string  profession,const string  education,const string  last_job,const string  rsn_dismiss,const string  family_status,int  contact_info);
	friend ostream& operator<<(ostream& out, const worker& w);
	void adding(string _id, string _profession, string _education, string last_job, string _rsn_dismiss, string  _family_status, int contact_info);
	string get_education();
};

class labor {
private:
	worker* w;
	int n;
	int amount(const string& path);
public:
	labor(const string& path);
	float higher_education();
	~labor();
};

string get_path();
#endif 



