#include "helpers.h"
#include "ViewDay.h"
#include "ViewMonth.h"
#include "ViewWeek.h"
#include "OneTimeEvent.h"
#include "PeriodicEvent.h"
#include "LongEvent.h"
#include <vector>


//function will return current day
int CurrDay()
{
	time_t t;
	struct tm * now;

	time(&t);
	now = localtime(&t);

	return now->tm_mday;
}

//function will return current year
int CurrYear()
{
	time_t t;
	struct tm * now;

	time(&t);
	now = localtime(&t);

	return now->tm_year;
}

//function will return current month
int CurrMonth()
{
	time_t t;
	struct tm * now;

	time(&t);
	now = localtime(&t);

	return now->tm_mon;
}

//function will return total number of days
int  getNumberOfDays(int month, int year)
{
	//leap year condition, if month is 2
	if (month == 2)
	{
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
			return 29;
		else
			return 28;
	}
	//months which has 31 days
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
		|| month == 10 || month == 12)
		return 31;
	else
		return 30;
}

//function will randomize number from 1 to 1000
int Randomize()
{
	int w;
	srand(time(NULL));
	w = rand() % 999;

	return w;
}

// function checks ending day of week
int CheckEndDay(int firstWeekDayOfMonth, int numberOfDays, int number)
{
	int value = 1;
	int w, d;
	int tempBreak = 1;
	int numberOfWeek = 1;

	for (w = 0; w<firstWeekDayOfMonth; w++)
	{
		tempBreak++;
	}

	for (d = 1; d <= numberOfDays; d++)
	{
		if (numberOfWeek == number)
		{
			value = d;
		}

		if (tempBreak >= 7)
		{
			tempBreak = 0;
			numberOfWeek++;
		}
		tempBreak++;
	}

	return value;
}

// function checks starting day of the week
int CheckStartingDay(int firstWeekDayOfMonth, int numberOfDays, int number)
{
	int value = 1;
	int w, d;
	int tempBreak = 1;
	int numberOfWeek = 1;

	for (w = 0; w<firstWeekDayOfMonth; w++)
	{
		tempBreak++;
	}

	for (d = 1; d <= numberOfDays; d++)
	{
		if (numberOfWeek == number)
		{
			value = d;
			break;
		}

		if (tempBreak >= 7)
		{
			tempBreak = 0;
			numberOfWeek++;
		}
		tempBreak++;
	}

	return value;
}

// function checks how many weeks in month
int HowManyWeeks(int firstWeekDayOfMonth, int numberOfDays)
{
	int w, d;
	int tempBreak = 1;
	int numberOfWeek = 1;

	for (w = 1; w<firstWeekDayOfMonth; w++)
	{
		tempBreak++;
	}

	for (d = 1; d <= numberOfDays; d++)
	{
		if (tempBreak >= 7)
		{
			tempBreak = 0;
			numberOfWeek++;
		}
		tempBreak++;
	}

	return numberOfWeek;
}

void Interface()
{
	SetConsoleTextAttribute(console, 3); //red color
	cout << endl;
	cout << "\t\t\t     \xDB\xDB\xDB\xDB  \xDB\xDB\xDB\xDB  \xDB   \xDB\xDB\xDB  \xDB   \xDB  \xDB\xDB\xDB   \xDB\xDB\xDB\xDB  \xDB\xDB\xDB\xDB" << endl;
	cout << "\t\t\t     \xDB     \xDB  \xDB  \xDB   \xDB    \xDB\xDB  \xDB  \xDB  \xDB  \xDB  \xDB  \xDB  \xDB" << endl;
	cout << "\t\t\t     \xDB     \xDB  \xDB  \xDB   \xDB\xDB\xDB  \xDB \xDB \xDB  \xDB  \xDB  \xDB  \xDB  \xDB  \xDB" << endl;
	cout << "\t\t\t     \xDB     \xDB\xDB\xDB\xDB  \xDB   \xDB    \xDB  \xDB\xDB  \xDB  \xDB  \xDB\xDB\xDB\xDB  \xDB\xDB\xDB" << endl;
	cout << "\t\t\t     \xDB\xDB\xDB\xDB  \xDB  \xDB  \xDB\xDB  \xDB\xDB\xDB  \xDB   \xDB  \xDB\xDB\xDB   \xDB  \xDB  \xDB  \xDB" << endl << endl;

	SetConsoleTextAttribute(console, 15); //white color
	cout << "\t\t\t=====================================================" << endl;
	cout << "\t\t\t\t\t1 Add event" << endl;
	cout << "\t\t\t\t\t2 Add periodic event" << endl;
	cout << "\t\t\t\t\t3 Add long event" << endl;
	cout << "\t\t\t\t\t4 Delete one day event" << endl;
	cout << "\t\t\t\t\t5 Delete periodic event" << endl;
	cout << "\t\t\t\t\t6 Delete long event" << endl;
	cout << "\t\t\t\t\t7 Show calendar (day)" << endl;
	cout << "\t\t\t\t\t8 Show calendar (week)" << endl;
	cout << "\t\t\t\t\t9 Show calendar (month)" << endl;
	cout << "\t\t\t\t	 (Esc) Exit" << endl;
	cout << "\t\t\t=====================================================" << endl;
	cout << endl << endl;
	SetConsoleTextAttribute(console, 15);
}

//function will return first day of the week
int Firstday(int month, int year)
{
	tm tFirst = { 0, 0, 0, 1, month, year };
	time_t time_temp = mktime(&tFirst);
	struct tm * firstTime = localtime(&time_temp);

	return firstTime->tm_wday;
}

//function will return number of days in month
int AskDay(int month, int year)
{
	int day;
	int numberOfDays = getNumberOfDays(month, year);

	cout << "Please give me a day" << endl;
	cin >> day;

	while (day < 1 || day > numberOfDays)
	{
		cout << "Please chose correct number of day" << endl;
		cin.clear();
		cin.sync();
		cin.ignore(1000, '\n');
		cin >> day;
	}

	return day;
}

//function asks user about year
int AskYear()
{
	int year;
	cin >> year;

	while (year < 1971 || year > 2100)
	{
		cout << "Wrong year" << endl;
		cin.clear();
		cin.sync();
		cin.ignore(1000, '\n');
		cin >> year;
	}

	return year;
}

//function asks user about hour
int AskHour()
{
	int hour;

	cout << "Please give me hour" << endl;
	cin >> hour;

	while (hour < 0 || hour > 23)
	{
		cout << "wrong number of hours" << endl;
		cin.clear();
		cin.sync();
		cin.ignore(1000, '\n');
		cin >> hour;
	}

	return hour;
}

//function asks user about minutes
int AskMinutes()
{
	int minutes;
	cout << "Please give me minutes" << endl;
	cin >> minutes;

	while (minutes < 0 || minutes > 59)
	{
		cout << "wrong numer of minutes" << endl;
		cin.clear();
		cin.sync();
		cin.ignore(1000, '\n');
		cin >> minutes;
	}

	return minutes;
}

//function asks user about month
int AskMonth()
{
	int month;

	cout << "Please give me month" << endl;
	cin >> month;

	while (month < 1 || month > 12)
	{
		cout << "Please choose correct number of month" << endl;
		cin.clear();
		cin.sync();
		cin.ignore(1000, '\n');
		cin >> month;
	}

	return month;
}

//function asks user about week
int AskWeek(int month, int year)
{
	int week;
	int firstDayOfTheWeek = Firstday(month, year);
	int numberOfDays = getNumberOfDays(month + 1, year);
	int howmany = HowManyWeeks(firstDayOfTheWeek, numberOfDays);

	cout << "Please give me week" << endl;
	cin >> week;

	while (week < 1 || week > howmany)
	{
		cout << "Please choose correct number of week" << endl;
		cin.clear();
		cin.sync();
		cin.ignore(1000, '\n');
		cin >> week;
	}

	return week;
}

int AskNumber()
{
	int number;
	cin >> number;
	while (number < 0 || number > 1000)
	{
		cout << "Please chose correct number (range from 0-1000)" << endl;
		cin.clear();
		cin.sync();
		cin.ignore(1000, '\n');
		cin >> number;
	}

	return number;
}

void PrintPrieviousNextWeek(int month, int year, int firstWeekDayOfMonth, int numberOfDays, int week)
{
	system("cls");
	ViewWeek a(month, year, firstWeekDayOfMonth, numberOfDays, week);
	a.printCalendar();
	a.ShowEvent();
}

//function is used to print week
void Pweek()
{
	cout << "Please me year beetween 1971-2100" << endl;

	if (_getch() == 27)
		Menu();

	int year = AskYear() - 1900;
	int month = AskMonth() - 1;
	int week = AskWeek(month, year);
	int numberOfDays = getNumberOfDays(month + 1, year);
	int firstWeekDayOfMonth = Firstday(month, year);

	int firstDayOfTheWeek = Firstday(month, year);

	ViewWeek a(month, year, firstWeekDayOfMonth, numberOfDays, week);
	a.printCalendar();
	a.ShowEvent();

	while (true)
	{
		switch (_getch())
		{
		case 'n': // previos week
			week = week - 1;

			if (week == 0)
			{
				month = month - 1;
				firstDayOfTheWeek = Firstday(month, year);
				numberOfDays = getNumberOfDays(month + 1, year);
				week = HowManyWeeks(firstDayOfTheWeek, numberOfDays);

				if (month == -1)
				{
					month = 11;
					year = year - 1;
					firstDayOfTheWeek = Firstday(month, year);
					numberOfDays = getNumberOfDays(month + 1, year);
					week = HowManyWeeks(firstDayOfTheWeek, numberOfDays);
				}

			}

			numberOfDays = getNumberOfDays(month + 1, year);
			firstWeekDayOfMonth = Firstday(month, year);
			PrintPrieviousNextWeek(month, year, firstWeekDayOfMonth, numberOfDays, week);
			break;
		case 'm': // next week
			week = week + 1;

			numberOfDays = getNumberOfDays(month + 1, year);

			if (week == HowManyWeeks(firstDayOfTheWeek, numberOfDays) + 1)
			{
				month = month + 1;
				week = 1;
				firstDayOfTheWeek = Firstday(month, year);
				numberOfDays = getNumberOfDays(month + 1, year);
			}

			if (month == 12)
			{
				month = 0;
				year = year + 1;
				firstDayOfTheWeek = Firstday(month, year);
				numberOfDays = getNumberOfDays(month + 1, year);
				week = 1;
			}

			firstWeekDayOfMonth = Firstday(month, year);
			PrintPrieviousNextWeek(month, year, firstWeekDayOfMonth, numberOfDays, week);

			break;
		case 27: // exit to menu
			Menu();
		}
	}

}

void PrintPrieviousNextMonth(int month, int year, int firstWeekDayOfMonth, int numberOfDays)
{
	system("cls");
	ViewMonth a(month, year, firstWeekDayOfMonth, numberOfDays);
	a.printCalendar();
	a.ShowEvent();
}

//function is used to print month
void Pmonth()
{
	cout << "Please me year beetween 1971-2100" << endl;

	if (_getch() == 27)
		Menu();

	int year = AskYear() - 1900;
	int month = AskMonth() - 1;
	int numberOfDays = getNumberOfDays(month + 1, year);
	int firstWeekDayOfMonth = Firstday(month, year);

	ViewMonth a(month, year, firstWeekDayOfMonth, numberOfDays);
	a.printCalendar();
	a.ShowEvent();

	while (true)
	{
		switch (_getch())
		{
		case 'n': // previos month
			month--;

			if (month == -1)
			{
				month = 11;
				year--;
			}

			numberOfDays = getNumberOfDays(month + 1, year);
			firstWeekDayOfMonth = Firstday(month, year);
			PrintPrieviousNextMonth(month, year, firstWeekDayOfMonth, numberOfDays);
			break;
		case 'm': // next month
			month++;

			if (month == 12)
			{
				month = 0;
				year++;
			}

			numberOfDays = getNumberOfDays(month + 1, year);
			firstWeekDayOfMonth = Firstday(month, year);
			PrintPrieviousNextMonth(month, year, firstWeekDayOfMonth, numberOfDays);
			break;
		case 27: // exit to menu
			Menu();
		}
	}

}

void PrintPrieviousNextDay(int month, int year, int firstWeekDayOfMonth, int numberOfDays, int day)
{
	system("cls");
	ViewDay a(month, year, firstWeekDayOfMonth, numberOfDays, day);
	a.printCalendar();
	a.ShowEvent();
}

//function is used to print day
void Pday()
{
	cout << "Please me year beetween 1971-2100" << endl;

	if (_getch() == 27)
		Menu();

	int year = AskYear() - 1900;
	int month = AskMonth() - 1;
	int day = AskDay(month + 1, year);
	int numberOfDays = getNumberOfDays(month + 1, year);
	int firstWeekDayOfMonth = Firstday(month, year);

	ViewDay a(month, year, firstWeekDayOfMonth, numberOfDays, day);
	a.printCalendar();
	a.ShowEvent();

	while (true)
	{
		switch (_getch())
		{
		case 'n': // previos day
			day--;

			if (day == 0)
			{
				month--;
				day = numberOfDays = getNumberOfDays(month + 1, year);

				if (month == -1)
				{
					month = 11;
					year--;
					day = numberOfDays = getNumberOfDays(month + 1, year);
				}
			}

			firstWeekDayOfMonth = Firstday(month, year);
			PrintPrieviousNextDay(month, year, firstWeekDayOfMonth, numberOfDays, day);
			break;
		case 'm': // next month
			day++;

			if (day > getNumberOfDays(month + 1, year))
			{
				month++;
				day = 1;

				if (month == 12)
				{
					month = 0;
					year++;
					day = 1;
				}
			}
			numberOfDays = getNumberOfDays(month + 1, year);
			firstWeekDayOfMonth = Firstday(month, year);
			PrintPrieviousNextDay(month, year, firstWeekDayOfMonth, numberOfDays, day);
			break;
		case 27: // exit to menu
			Menu();
		}
	}

}

void CreateEventDay()
{
	cout << "Give me year beetween 1971-2100" << endl;

	if (_getch() == 27)
		Menu();

	int year = AskYear();
	int month = AskMonth();
	int day = AskDay(month, year);
	int hour = AskHour();
	int minutes = AskMinutes();
	string tekst;

	cout << "Please give me reminder" << endl;
	cin.ignore();
	getline(cin, tekst);

	OneTimeEvent a(day, month, year, hour, minutes, tekst);
	a.Create();

	cout << "Event added"<< endl;
	cout << "Press any key to continue";
	_getch();

}

void DeleteOneDayEvent()
{
	fstream file;
	file.open("onedayhelper.txt", ios::in);

	if (file.good() == true)
	{
		string line;
		int counter = 0;

		cout << "One day events" << endl;
		while (file.eof() != 1)
		{
			do
			{
				getline(file, line, '\n');
			} while (line == "-");

			cout << line << endl;

			if (line.length() != 0)
			{
				counter++;
			}
				
		}

		file.close();

		int year;
		int month;
		int day;

		if (counter != 0)
		{
			cout << "Please type number (located before date) of event you want to delete" << endl;

			if (_getch() == 27)
				Menu();

			int number = AskNumber();

			vector<int> numbers;
			vector<int>::iterator givennumber;

			file.open("onedayhelper.txt", ios::in);

			while (file.eof() != 1)
			{
				getline(file, line, '|');
				numbers.push_back(atoi(line.c_str()));
			}

			givennumber = find(numbers.begin(), numbers.end(), number);

			file.close();

			while (givennumber == numbers.end())
			{
				cout << "wrong number" << endl;
				number = AskNumber();
				givennumber = find(numbers.begin(), numbers.end(), number);
			}

			int number2 = number;

			file.open("onedayhelper.txt", ios::in);

			while (file.eof() != 1)
			{
				getline(file, line, '|');

				if (line == to_string(number))
				{
					getline(file, line, '/');
					day = atoi(line.c_str());

					getline(file, line, '/');
					month = atoi(line.c_str());

					getline(file, line, '-');
					year = atoi(line.c_str());

					OneTimeEvent a(day, month, year, 0, 0, "none");
					a.Delete(number2);
					break;
				}

			}

			file.close();
			cout << "Event deleted" << endl;
			cout << "Press any key to continue";
		}

		else
		{
			cout << "No events" << endl;
			cout << "Press any key to continue";
		}
			
		
	}

	else
	{
		cout << "No events" << endl;
		cout << "Press any key to continue";
	}


}

void DeletePeriodicEvent()
{
	fstream file;
	file.open("periodichelper.txt", ios::in);

	if (file.good() == true)
	{
		string line;
		int counter = 0;

		cout << "Periodic events" << endl;
		while (file.eof() != 1)
		{
			do
			{
				getline(file, line, '\n');
			} while (line == "-");

			cout << line << endl;

			if (line.length() != 0)
			{
				counter++;
			}
		}

		file.close();

		int year;
		int month;
		int day;

		if (counter != 0)
		{
			cout << "Please type number (located before date) of event you want to delete" << endl;

			if (_getch() == 27)
				Menu();

			int number = AskNumber();

			vector<int> numbers;
			vector<int>::iterator givennumber;

			file.open("periodichelper.txt", ios::in);

			while (file.eof() != 1)
			{
				getline(file, line, '|');
				numbers.push_back(atoi(line.c_str()));
			}

			givennumber = find(numbers.begin(), numbers.end(), number);

			file.close();

			while (givennumber == numbers.end())
			{
				cout << "wrong number" << endl;
				number = AskNumber();
				givennumber = find(numbers.begin(), numbers.end(), number);
			}

			int number2 = number;

			file.open("periodichelper.txt", ios::in);

			while (file.eof() != 1)
			{
				getline(file, line, '|');

				if (line == to_string(number))
				{
					getline(file, line, '/');
					day = atoi(line.c_str());

					getline(file, line, '/');
					month = atoi(line.c_str());

					getline(file, line, '/');
					year = atoi(line.c_str());

					PeriodicEvent a(day, month, year, 0, 0, "none");
					a.Delete(number2);
					break;
				}

			}

			file.close();
			cout << "Event deleted" << endl;
			cout << "Press any key to continue";
		}
		else
		{
			cout << "No events" << endl;
			cout << "Press any key to continue";
		}

	}
	else
	{
		cout << "No events" << endl;
		cout << "Press any key to continue";
	}

}

void DeleteLongEvent()
{
	fstream file;
	file.open("longdayhelper.txt", ios::in);

	if (file.good() == true)
	{
	
		string line;
		int counter = 0;

		cout << "Long events" << endl;
		while (file.eof() != 1)
		{
			do
			{
				getline(file, line, '\n');
			} while (line == "--");

			cout << line << endl;

			if (line.length() != 0)
			{
				counter++;
			}

		}

		file.close();

		int year;
		int month;
		int day;
		int to_which_year;
		int to_which_month;
		int to_which_day;


		if (counter != 0)
		{
			cout << "Please type number (located before date) of event you want to delete" << endl;

			if (_getch() == 27)
				Menu();

			int number = AskNumber();

			vector<int> numbers;
			vector<int>::iterator givennumber;

			file.open("longdayhelper.txt", ios::in);

			while (file.eof() != 1)
			{
				getline(file, line, '|');
				numbers.push_back(atoi(line.c_str()));
			}

			givennumber = find(numbers.begin(), numbers.end(), number);

			file.close();

			while (givennumber == numbers.end())
			{
				cout << "wrong number" << endl;
				number = AskNumber();
				givennumber = find(numbers.begin(), numbers.end(), number);
			}

			int number2 = number;

			file.open("longdayhelper.txt", ios::in);

			while (file.eof() != 1)
			{
				getline(file, line, '|');

				if (line == to_string(number))
				{
					getline(file, line, '/');
					day = atoi(line.c_str());

					getline(file, line, '/');
					month = atoi(line.c_str());

					getline(file, line, '-');
					year = atoi(line.c_str());

					getline(file, line, '/');
					to_which_day = atoi(line.c_str());

					getline(file, line, '/');
					to_which_month = atoi(line.c_str());

					getline(file, line, '/');
					to_which_year = atoi(line.c_str());

					LongEvent a(day, month, year, 0, 0, "none", to_which_day, to_which_month, to_which_year);
					a.Delete(number2);
					cout << "Event deleted" << endl;
					break;
				}

			}

			file.close();
			cout << "Press any key to continue";

		}

		else
		{
			cout << "No events" << endl;
			cout << "Press any key to continue";
		}

	}

	else
	{
		cout << "No events" << endl;
		cout << "Press any key to continue";
	}
		

}

void CreatePeriodicEvent()
{
	cout << "Give me year beetween 1971-2100" << endl;

	if (_getch() == 27)
		Menu();

	int year = AskYear();
	int month = AskMonth();
	int day = AskDay(month, year);
	int hour = AskHour();
	int minutes = AskMinutes();
	string tekst;

	cout << "Please give me reminder" << endl;
	cin.ignore();
	getline(cin, tekst);

	PeriodicEvent a(day, month, year, hour, minutes, tekst);
	a.Create();

	cout << "Event added" << endl;
	cout << "Press any key to continue";
	_getch();

}

void CreateLongEvent()
{
	cout << "Please me year beetween 1971-2100" << endl;

	if (_getch() == 27)
		Menu();

	int year = AskYear();
	int month = AskMonth();
	int day = AskDay(month, year);
	int hour = AskHour();
	int minutes = AskMinutes();

	cout << "Please give me to which year you want create an event" << endl;
	int to_which_year = AskYear();

	while (to_which_year < year)
	{
		cout << "Year cannot be less then " << year << endl;
		to_which_year = AskYear();
	}

	int to_which_month = AskMonth();

	while (to_which_month < month)
	{
		cout << "Wrong month" << endl;
		to_which_month = AskMonth();
	}

	int to_which_day = AskDay(to_which_month, to_which_year);

	while (to_which_day < day)
	{
		cout << "Wrong day" << endl;
		to_which_day = AskDay(to_which_month, to_which_year);
	}


	string tekst;
	cout << "Give me reminder" << endl;
	cin.ignore();
	getline(cin, tekst);

	LongEvent a(day, month, year, hour, minutes, tekst, to_which_day, to_which_month, to_which_year);
	a.Create();

	cout << "Event added" << endl;
	cout << "Press any key to continue";
	_getch();

}

void Menu()
{
	char decision;

	while (true)
	{
		system("cls");
		Interface();

		decision = _getch();
		cout << endl;

		switch (decision)
		{
		case '1':
			system("cls");
			CreateEventDay();
			break;
		case '2':
			system("cls");
			CreatePeriodicEvent();
			break;
		case '3':
			system("cls");
			CreateLongEvent();
			break;
		case '4':
			system("cls");
			DeleteOneDayEvent();
			_getch();
			break;
		case '5':
			system("cls");
			DeletePeriodicEvent();
			_getch();
			break;
		case '6':
			system("cls");
			DeleteLongEvent();
			_getch();
			break;
		case '7':
			system("cls");
			Pday();
			break;
		case '8':
			system("cls");
			Pweek();
		case '9':
			system("cls");
			Pmonth();
		case 27:
			exit(0);
		default:
			cout << "wrong key";
			_getch();
			break;
		}
	}

}