#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <map>
#include "ViewWeek.h"
#include "helpers.h"

ViewWeek::ViewWeek(int m, int y, int firstDay, int numOfDays, int n)
	:View(m, y, firstDay, numOfDays)
{
	number = n;
}

void ViewWeek::printCalendar()
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
	int numberOfWeek = 1;

	for (w = 0; w<firstWeekDayOfMonth; w++)
	{
		cout << "       ";
		tempBreak++;
	}

	for (d = 1; d <= numberOfDays; d++)
	{
		if (numberOfWeek == number)
			SetConsoleTextAttribute(console, 3); //blue color

		if (d == currday && month == currM && year == currY)
			SetConsoleTextAttribute(console, 5); //red color

		cout << d << "     ";
		SetConsoleTextAttribute(console, 15); //white color

		if (d<10)
			cout << " ";
		if (tempBreak >= 7)
		{
			cout << endl;
			tempBreak = 0;
			numberOfWeek++;
		}
		tempBreak++;
	}
	cout << endl << endl << "Press n to move to the previous week, press m to move to the next week" << endl;
}

void ViewWeek::ShowEvent()
{
	fstream dates;
	string line;
	string ID;
	string reminder;
	int startingDay = CheckStartingDay(firstWeekDayOfMonth, numberOfDays, number);
	int endDay = CheckEndDay(firstWeekDayOfMonth, numberOfDays, number);

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



	for (int d = startingDay; d <= endDay; d++)
	{
		for (int los = 0; los < 1000; los++)
		{
			string t = to_string(d) + "/" + to_string(month + 1) + "/" + to_string(year + 1900) + "/" + to_string(los);

			auto range = m.equal_range(t);
			auto i = range.first;

			for (i; i != range.second; ++i)
			{
				cout << d << "/" << month + 1 << "/" << year + 1900 << " " << i->second << endl;
			}

		}

	}

	dates.close();
}