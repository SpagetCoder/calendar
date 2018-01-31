#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <map>
extern HANDLE console;


using namespace std;

//function will return current day
int CurrDay();

//function will return current year
int CurrYear();

//function will return current month
int CurrMonth();

//function will return total number of days
int  getNumberOfDays(int month, int year);

//function will randomize number from 1 to 1000
int Randomize();

// function checks ending day of week
int CheckEndDay(int firstWeekDayOfMonth, int numberOfDays, int number);

// function checks starting day of the week
int CheckStartingDay(int firstWeekDayOfMonth, int numberOfDays, int number);

// function checks how many week are in month
int HowManyWeeks(int firstWeekDayOfMonth, int numberOfDays);

void Interface();

//function will return first day of the week
int Firstday(int month, int year);

//function will return number of days in month
int AskDay(int month, int year);

int AskYear();

int AskHour();

int AskMinutes();

int AskMonth();

int AskWeek(int month, int year);

int AskNumber();

void PrintPrieviousNextWeek(int month, int year, int firstWeekDayOfMonth, int numberOfDays, int week);

void Pweek();

void PrintPrieviousNextMonth(int month, int year, int firstWeekDayOfMonth, int numberOfDays);

void Pmonth();

void PrintPrieviousNextDay(int month, int year, int firstWeekDayOfMonth, int numberOfDays, int day);

void Pday();

void CreateEventDay();

void DeleteOneDayEvent();

void DeletePeriodicEvent();

void DeleteLongEvent();

void CreatePeriodicEvent();

void CreateLongEvent();

void Menu();
