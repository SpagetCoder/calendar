#pragma once
#include <iostream>
#include <string>
#include "View.h"
extern HANDLE console;


class ViewDay :public View
{
	int day;
public:

	ViewDay(int,int,int, int, int);
	void printCalendar();
	void ShowEvent();

};