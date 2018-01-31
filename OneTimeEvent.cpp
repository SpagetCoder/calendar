#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <map>
#include "OneTimeEvent.h"


OneTimeEvent::OneTimeEvent(int d, int m, int y, int h, int min, string r) :Event(d, m, y, h, min, r) {}

void OneTimeEvent::Create()
{
	fstream dates;
	string reminder2 = to_string(hour) + ":" + to_string(minutes) + " " + reminder;
	int randomnumber = Randomize();

	dates.open("onedayevent.txt", ios::out | ios::app);
	dates << day << "/" << month << "/" << year << "/" << randomnumber << "-" << reminder2 << endl;

	fstream file;
	file.open("onedayhelper.txt", ios::out | ios::app);
	file << "|" << randomnumber << "|" << day << "/" << month << "/" << year << "/" << "-" << reminder2 << endl;
	file.close();

	dates.close();
}

void OneTimeEvent::Delete(int number)
{
	fstream dates;
	string line;
	string ID;
	string remindertext;

	dates.open("onedayevent.txt", ios::in);

	map<string, string> m;

	while (dates.eof() != 1)
	{
		getline(dates, line, '-');
		ID = line;

		getline(dates, line, '\n');
		remindertext = "-" + line;

		m.insert(pair<string, string>(ID, remindertext));
	}

	dates.close();

	string t = to_string(day) + "/" + to_string(month) + "/" + to_string(year) + "/" + to_string(number);
	m.erase(t);

	dates.open("onedayevent.txt", ios::out);

	map<string, string>::iterator iter = m.end();

	do
	{
		iter--;
		dates << iter->first << iter->second << endl;
	} while (iter != m.begin());

	dates.close();

	dates.open("onedayhelper.txt", ios::in);

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

	string tt = "|" + to_string(number) + "|" + to_string(day) + "/" + to_string(month) + "/" + to_string(year) + "/";
	n.erase(tt);

	dates.open("onedayhelper.txt", ios::out);

	map<string, string>::iterator iterr = n.end();

	do
	{
		iterr--;
		dates << iterr->first << iterr->second << endl;
	} while (iterr != n.begin());

	dates.close();

}