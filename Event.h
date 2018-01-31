#pragma once
#include <iostream>
#include <string>
extern HANDLE console;

using namespace std;

class Event
{
protected:
	int day, month, year, hour, minutes;
	string reminder;

public:

	Event(int,int,int,int,int,string);

};
