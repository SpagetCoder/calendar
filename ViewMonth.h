#pragma once
#include <iostream>
#include <string>
#include "View.h"
extern HANDLE console;


using namespace std;

class ViewMonth :public View
{
public:

	ViewMonth(int,int,int, int);

	void printCalendar();

	void ShowEvent();

};
