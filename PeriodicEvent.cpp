#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <map>
#include "PeriodicEvent.h"
	
PeriodicEvent::PeriodicEvent(int d, int m, int y, int h, int min, string r)
		:Event(d, m, y, h, min, r) {}


	void PeriodicEvent::Create()
	{
		fstream dates;
		int randomnumber = Randomize();
		string reminder2 = to_string(hour) + ":" + to_string(minutes) + " " + reminder;
		dates.open("periodicY.txt", ios::out | ios::app);

		for (int i = year; i <= 2100; i++)
			dates << day << "/" << month << "/" << i << "/" << randomnumber << "-" << reminder2 << endl;

		dates.close();

		dates.open("periodichelper.txt", ios::out | ios::app);
		dates << "|" << randomnumber << "|" << day << "/" << month << "/" << year << "/" << "-" << reminder2 << endl;
		dates.close();

	}

	void PeriodicEvent::CreateMonthly()
	{
		int randomnumber = Randomize();
		int j = month;
		fstream dates;
		string reminder2 = to_string(hour) + ":" + to_string(minutes) + " " + reminder;
		dates.open("periodicM.txt", ios::out | ios::app);

		for (int i = year; i <= 2100; i++)
		{
			for (j; j <= 12; j++)
				dates << day << "/" << j << "/" << i << "/" << randomnumber << "-" << reminder2 << endl;

			j = 1;

		}

		dates.close();
	}

	void PeriodicEvent::Delete(int number)
	{
		fstream dates;
		string line;
		string ID;
		string remindertext;
		int j = month;

		dates.open("periodicY.txt", ios::in);

		multimap<string, string> m;

		while (dates.eof() != 1)
		{
			getline(dates, line, '-');
			ID = line;

			getline(dates, line, '\n');
			remindertext = line;

			m.insert(pair<string, string>(ID, "-" + remindertext));
		}

		dates.close();

		for (int i = year; i <= 2100; i++)
		{
			for (j; j <= 12; j++)
			{
				string t = to_string(day) + "/" + to_string(j) + "/" + to_string(i) + "/" + to_string(number);
				m.erase(t);
			}

			j = 1;
		}

		dates.open("periodicY.txt", ios::out);

		multimap<string, string>::iterator iter = m.end();

		do
		{
			iter--;
			dates << iter->first << iter->second << endl;
		} while (iter != m.begin());

		dates.close();


		dates.open("periodichelper.txt", ios::in);

		map<string, string> n;

		while (dates.eof() != 1)
		{
			getline(dates, line, '-');
			ID = line;

			getline(dates, line, '\n');
			remindertext = line;

			n.insert(pair<string, string>(ID, "-" + remindertext));
		}

		dates.close();

		string t = "|" + to_string(number) + "|" + to_string(day) + "/" + to_string(month) + "/" + to_string(year) + "/";
		n.erase(t);

		dates.open("periodichelper.txt", ios::out);

		map<string, string>::iterator iterr = n.end();

		do
		{
			iterr--;
			dates << iterr->first << iterr->second << endl;
		} while (iterr != n.begin());

		dates.close();
	}
