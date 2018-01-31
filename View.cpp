#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <map>
#include "View.h"


View::View(int m, int y, int firstDay, int numOfDays)
{
	month = m;
	year = y;
	firstWeekDayOfMonth = firstDay;
	numberOfDays = numOfDays;
}