#pragma once
#include <iostream>
#include <string>
#include "Event.h"
#include  "helpers.h"
extern HANDLE console;

class PeriodicEvent :public Event
{

public:
	PeriodicEvent(int,int,int,int,int,string);

	void Create();
	void CreateMonthly();
	void Delete(int number);

};