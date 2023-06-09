#pragma once
#include <iostream>
#include <iomanip> 
#include <Windows.h>
#include <conio.h>

using namespace std;

class Time
{
	int HH, MM, SS;
public:
	Time();
	Time(int HH,int MM,int SS);
	~Time();
	friend ostream& operator << (ostream& os, Time &t);
	friend istream& operator >> (istream& is, Time &t);
	friend void StopWatch(Time t);
	friend void Timer(Time t);
};



