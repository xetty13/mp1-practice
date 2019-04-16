#pragma once
class Time
{
private:
	unsigned h;
	unsigned m;
public:
	Time();
	Time(unsigned h, unsigned m);
	~Time();
	void PrintTime();
};
