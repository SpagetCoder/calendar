#pragma once
#include <iostream>
#include <string>
#include "View.h"
extern HANDLE console;

class ViewWeek :public View
{
	int number;

public:

	ViewWeek(int,int,int,int,int);
	void printCalendar();
	void ShowEvent();

};