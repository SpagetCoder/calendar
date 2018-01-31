#pragma once
#include <iostream>
#include <string>
#include "helpers.h"
extern HANDLE console;

using namespace std;

class View
{
protected:
	int firstWeekDayOfMonth, numberOfDays, month, year;
	int currM = CurrMonth();
	int currday = CurrDay();
	int currY = CurrYear();

	string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	string  weekDays[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

public:
	View(int,int,int, int);
};