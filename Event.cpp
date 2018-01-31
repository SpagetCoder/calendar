#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <map>
#include "Event.h"


Event::Event(int d, int m, int y, int h, int min, string r)
{
	day = d;
	month = m;
	year = y;
	hour = h;
	minutes = min;
	reminder = r;
}