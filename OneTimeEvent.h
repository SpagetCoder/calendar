#pragma once
#include <iostream>
#include <string>
#include "Event.h"
#include  "helpers.h"
extern HANDLE console;

using namespace std;

class OneTimeEvent :public Event
{
	int number;

public:
	OneTimeEvent(int, int, int, int, int, string);

	void Create();
	void Delete(int);
	
};
