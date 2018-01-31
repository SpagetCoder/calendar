#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <map>
#include "ViewDay.h"
#include "helpers.h"

ViewDay::ViewDay(int m, int y, int firstDay, int numOfDays, int givenday)
	:View(m, y, firstDay, numOfDays)
{
	day = givenday;
}

void ViewDay::printCalendar()
{
	system("cls");

	cout << "\t\t" << months[month] << "  " << year + 1900 << "\n\n";
	int w, d;
	for (w = 0; w < 7; w++)
	{
		cout << weekDays[w] << "    ";
	}
	cout << "\n-------------------------------------------------\n";
	cout << "\n";
	int tempBreak = 1;

	for (w = 0; w<firstWeekDayOfMonth; w++)
	{
		cout << "       ";
		tempBreak++;
	}
	for (d = 1; d <= numberOfDays; d++)
	{
		if (d == day)
			SetConsoleTextAttribute(console, 3); //blue color
		if (d == currday && month == currM && year == currY)
			SetConsoleTextAttribute(console, 5); //red color
		cout << d << "     ";
		SetConsoleTextAttribute(console, 15); //white color

		if (d<10)
			cout << " ";
		if (tempBreak >= 7)
		{
			cout << "\n";
			tempBreak = 0;
		}
		tempBreak++;
	}
	cout << endl << endl << "Press n to move to the previous day, press m to move to the next day" << endl;
}

void ViewDay::ShowEvent()
{
	fstream dates;
	string line;
	string ID;
	string reminder;

	multimap<string, string> m;

	dates.open("onedayevent.txt", ios::in);

	if (dates.good() == true)
	{
		while (dates.eof() != 1)
		{
			getline(dates, line, '-');
			ID = line;

			getline(dates, line, '\n');
			reminder = line;

			m.insert(pair<string, string>(ID, reminder));
		}

		dates.close();
	}

	dates.open("longevent.txt", ios::in);

	if (dates.good() == true)
	{
		while (dates.eof() != 1)
		{
			getline(dates, line, '-');
			ID = line;

			getline(dates, line, '\n');
			reminder = line;

			m.insert(pair<string, string>(ID, reminder));
		}

		dates.close();
	}


	dates.open("periodicY.txt", ios::in);

	if (dates.good() == true)
	{
		while (dates.eof() != 1)
		{
			getline(dates, line, '-');
			ID = line;

			getline(dates, line, '\n');
			reminder = line;

			m.insert(pair<string, string>(ID, reminder));
		}

		dates.close();
	}


	for (int unique_number = 0; unique_number < 1000; unique_number++)
	{
		string t = to_string(day) + "/" + to_string(month + 1) + "/" + to_string(year + 1900) + "/" + to_string(unique_number);

		auto range = m.equal_range(t);
		auto i = range.first;

		for (i; i != range.second; ++i)
		{
			cout << i->second << endl;
		}

	}

}