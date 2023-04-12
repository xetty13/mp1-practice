#pragma once
#ifndef _actionh_
#define _actionh_

#include <string>

using namespace std;

#define STRLEN 10

void output();

typedef struct team {
	string Name;
	string City;
	int Games;
	int Points;
	int Players;
} Steam;

typedef struct teamarray {
	Steam* teams;
	size_t length;
} Steamarray;

#endif