#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <map>
#include "LongEvent.h"

LongEvent::LongEvent(int d, int m, int y, int h, int min, string r, int d2, int m2, int y2)
	:Event(d, m, y, h, min, r)
{
	to_which_day = d2;
	to_which_month = m2;
	to_which_year = y2;
}

void LongEvent::Create()
{
	fstream dates;
	dates.open("longevent.txt", ios::out | ios::app);
	int i = year;
	int j = month;
	int k = day;
	int randomnumber = Randomize();
	string reminder2 = to_string(hour) + ":" + to_string(minutes) + " " + reminder;

	fstream file;
	file.open("longdayhelper.txt", ios::out | ios::app);

	file << "|" << randomnumber << "|" << day << "/" << month << "/" << year << "-" << to_which_day << "/" << to_which_month << "/" << to_which_year << "-" << reminder2 << endl;

	file.close();

	for (i; i <= to_which_year; i++)
	{
		if (i != to_which_year)
		{
			for (j; j <= 12; j++)
			{
				int nday = getNumberOfDays(j, i);
				for (k; k <= nday; k++) // printing correct nuber of days

					dates << k << "/" << j << "/" << i << "/" << randomnumber << "-" << reminder2 << endl;

				k = 1;
			}
			j = 1;
		}

		else
		{

			for (j; j <= to_which_month; j++)
			{
				if (j != to_which_month)
				{
					int nday = getNumberOfDays(j, i);
					for (k; k <= nday; k++) // printing correct nuber of days

						dates << k << "/" << j << "/" << i << "/" << randomnumber << "-" << reminder2 << endl;

					k = 1;
				}

				else
				{
					for (k; k <= to_which_day; k++) // printing correct nuber of days

						dates << k << "/" << j << "/" << i << "/" << randomnumber << "-" << reminder2 << endl;
				}

			}

		}
	}

	dates.close();
}

void LongEvent::Delete(int number)
{
	fstream dates;
	string line;
	string ID;
	string remindertext;

	dates.open("longevent.txt", ios::in);

	map<string, string> m;

	while (dates.eof() != 1)
	{
		getline(dates, line, '-');
		ID = line;

		getline(dates, line, '\n');
		remindertext = line;

		m.insert(pair<string, string>(ID, "-" + remindertext));
	}

	dates.close();

	int d = day;
	int j = month;
	int i = year;

	for (i; i <= to_which_year; i++)
	{
		if (i != to_which_year)
		{
			for (j; j <= 12; j++)
			{
				int nday = getNumberOfDays(j, i);
				for (d; d <= nday; d++)
				{
					string t = to_string(d) + "/" + to_string(j) + "/" + to_string(i) + "/" + to_string(number);
					m.erase(t);
				}

				d = 1;
			}
			j = 1;
		}

		else
		{

			for (j; j <= to_which_month; j++)
			{
				if (j != to_which_month)
				{
					int nday = getNumberOfDays(j, i);
					for (d; d <= nday; d++)
					{
						string t = to_string(d) + "/" + to_string(j) + "/" + to_string(i) + "/" + to_string(number);
						m.erase(t);
					}

					d = 1;
				}

				else
				{
					for (d; d <= to_which_day; d++) // printing correct nuber of days
					{
						string t = to_string(d) + "/" + to_string(j) + "/" + to_string(i) + "/" + to_string(number);
						m.erase(t);
					}

				}

			}

		}

	}

	dates.open("longevent.txt", ios::out);

	map<string, string>::iterator iter = m.end();

	do
	{
		iter--;
		dates << iter->first << iter->second << endl;
	} while (iter != m.begin());

	dates.close();


	dates.open("longdayhelper.txt", ios::in);

	map<string, string> n;

	string ID2;

	while (dates.eof() != 1)
	{
		getline(dates, line, '-');
		ID = line;

		getline(dates, line, '-');
		ID2 = line;

		getline(dates, line, '\n');
		remindertext = line;

		n.insert(pair<string, string>(ID + "-" + ID2, "-" + remindertext));
	}

	dates.close();

	string t = "|" + to_string(number) + "|" + to_string(day) + "/" + to_string(month) + "/" + to_string(year) + "-" + to_string(to_which_day) + "/" + to_string(to_which_month) + "/" + to_string(to_which_year);
	n.erase(t);

	dates.open("longdayhelper.txt", ios::out);

	map<string, string>::iterator iterr = n.end();

	do
	{
		iterr--;
		dates << iterr->first << iterr->second << endl;
	} while (iterr != n.begin());

	dates.close();

}
