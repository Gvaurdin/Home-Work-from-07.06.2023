#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <iomanip> 
using namespace std;

class QueuePriority;
class List;
struct Element;
class Printer_Program
{
	string owner;
	int number_print_pages;
	int priority;
	int time_SS;
	int time_MM;
public:
	friend QueuePriority;
	friend Element;
	Printer_Program();
	Printer_Program(string name, int priority);
	~Printer_Program() { ; }
	void chek_time();
	friend ostream& operator << (ostream& os, Printer_Program& p);
	friend void create_Users(Printer_Program& a, Printer_Program& t, Printer_Program& u);
};

class QueuePriority
{
	Printer_Program* Wait;
	int* Pri;
	int MaxQueueLength;
	int QueueLength;
	int time_queue = 0;
public:
	friend Printer_Program;
	QueuePriority(int m);
	~QueuePriority();
	QueuePriority(QueuePriority& obj);
	void Add(Printer_Program p, int c);
	Printer_Program Extract();
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int GetCount();
	void Show();
	friend ostream& operator << (ostream& os, QueuePriority& p);
	void create_Print(Printer_Program print);
	int Get_Length() { return QueueLength; }
};

struct Element
{
	Printer_Program data;
	Element* Next;
};

class List
{
	Element* Head;
	Element* Tail;
	int Count;
public:
	friend Printer_Program;
	List();
	~List();
	void Add(Printer_Program data);
	void Del();
	void DelAll();
	void Print();
	int GetCount();
	friend ostream& operator << (ostream& os, List& p);
};


void Table_template();

void func_menu();
