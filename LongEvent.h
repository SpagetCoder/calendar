#pragma once
#include <iostream>
#include <string>
#include "Event.h"
#include  "helpers.h"
extern HANDLE console;

using namespace std;

class LongEvent :public Event
{
	int to_which_day;
	int to_which_month;
	int to_which_year;

public:
	LongEvent(int, int, int, int , int , string , int , int , int );

	void Create();
	void Delete(int number);


};
