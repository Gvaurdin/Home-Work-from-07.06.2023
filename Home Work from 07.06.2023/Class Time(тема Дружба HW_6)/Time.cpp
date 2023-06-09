#include "Time.h"

Time::Time()
{
	HH = 0;
	MM = 0;
	SS = 0;
}

Time::Time(int HH,int MM,int SS)
{
	this->HH = HH;
	this->MM = MM;
	this->SS = SS;
}

Time::~Time()
{
}

ostream& operator<<(ostream& os, Time &t)
{
	cout << setw(2) << setfill('0') << t.HH << " : " <<
		setw(2) << setfill('0') << t.MM << " : " <<
		setw(2) << setfill('0') << t.SS << endl;
	// setfill, setw - functions library iomanip
	return os;
}

istream& operator>>(istream& is, Time &t)
{
	cout << "Enter to hours : ";
	cin >> t.HH;
	while (t.HH < 0 || t.HH > 23)
	{
		cout << "Input error\n" <<
			"Enter to hours again : ";
		cin >> t.HH;
	}
	cout << "Enter to minutes : ";
	cin >> t.MM;
	while (t.MM < 0 || t.MM > 59)
	{
		cout << "Input error\n" <<
			"Enter to minutes again : ";
		cin >> t.MM;
	}
	cout << "Enter to seconds : ";
	cin >> t.SS;
	while (t.SS < 0 || t.SS > 59)
	{
		cout << "Input error\n" <<
			"Enter to seconds again : ";
		cin >> t.SS;
	}
	return is;

}

void StopWatch(Time t)
{
	t = Time();
	cout << "Press any key to start the stopwatch." <<
		"To stop the stopwatch, press any key again.\n";
	system("pause");
	while (!_kbhit())
	{
		system("cls");
		t.SS++;
		if (t.SS > 59)
		{
			t.MM++;
			t.SS = 0;
		}

		if (t.MM > 59)
		{
			t.HH++;
			t.SS = 0;
			t.MM = 0;
		}
		if (t.HH > 23)
		{
			t.HH = 0;
			t.SS = 0;
			t.MM = 0;
		}
		cout << "\n\n\t\t Stopwatch ON : " << t;
		Sleep(800);
	}
}

void Timer(Time t)
{
	cout << "\n\tSet the timer time\n";
	cin >> t;
	system("cls");
	cout << "Press any key to start the timer." <<
		"To stop the timer, press any key again.\n";
	system("pause");
	while (!_kbhit())
	{
		system("cls");
		t.SS--;
		if (t.SS < 1 && t.MM > 0)
		{
			t.MM--;
			t.SS = 59;
		}

		if (t.MM < 1 && t.HH > 0)
		{
			t.HH--;
			t.SS = 59;
			t.MM = 59;
		}
		if (t.HH == 0 && t.MM == 0 &&
			t.SS == 0)
		{
			cout << '\a' << "Stop timer\n";
			cout << t;
			break;
		}
		cout << "\n\n\t\t Timer ON : " << t;
		Sleep(800);
	}
}
