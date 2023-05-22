#ifndef _DATENTIME_H
#define _DATENTIME_H
#include <iostream>
#include <chrono>
#include <iomanip> // setfill(), setw()
using namespace std;

struct TDate {
	int d = 0;
	int m = 0;
	int y = 0;
	
	TDate() {
		setCurrentDay();
	}
	void setCurrentDay() {
		auto now = chrono::system_clock::now();
		auto now_time_t = chrono::system_clock::to_time_t(now);
		auto now_tm = *localtime(&now_time_t);
		y = now_tm.tm_year + 1900;
		m = now_tm.tm_mon + 1;
		d = now_tm.tm_mday;
	}
	void Print() {
		cout << setfill('0') << setw(2) << d << '.' << setfill('0') << setw(2) << m << '.' << y;
	}
	friend ostream& operator<<(ostream& out, const TDate& date) {	// Âûâîäèò äàòó ÑÅÉ×ÀÑ
		//date.setCurrentDay();
		out << setfill('0') << setw(2) << date.d << '.' << setfill('0') << setw(2) << date.m << '.' << date.y;
		return out;
	}
	const TDate& operator=(const TDate& date) {
		if (this == &date) return (*this);
		d = date.d;
		m = date.m;
		y = date.y;
		return *this;
	}
};

struct TTime {
	int h = 0;
	int m = 0;
	int s = 0;

	TTime() {
		setCurrentTime();
	}
	void setCurrentTime() {
		auto now = chrono::system_clock::now();
		auto now_time_t = chrono::system_clock::to_time_t(now);
		auto now_tm = *localtime(&now_time_t);
		h = now_tm.tm_hour;
		m = now_tm.tm_min;
		s = now_tm.tm_sec;
	}
	void Print() {
		cout << setfill('0') << setw(2) << h << ':' << setfill('0') << setw(2) << m << ':' << setfill('0') << setw(2) << s;
	}
	friend ostream& operator<<(ostream& out, const TTime& time) {	// Âûâîäèò âðåìÿ ÑÅÉ×ÀÑ
		//time.setCurrentTime();
		out << setfill('0') << setw(2) << time.h << ':' << setfill('0') << setw(2) << time.m << ':' << setfill('0') << setw(2) << time.s;
		return out;
	}
	const TTime& operator=(const TTime& time) {
		if (this == &time) return (*this);
		h = time.h;
		m = time.m;
		s = time.s;
		return *this;
	}
};

#endif // !_DATENTIME_H