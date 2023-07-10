#pragma once
#include <iomanip> 
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

class Container
{
protected:
	string name_container;
	double cost;
public:
	Container() { name_container = "empty"; cost = 0; }
	Container(string _nc, double _cost);
	Container(const Container& obj);
	void Set_Container(string nc, double cost);
	string Get_Name_Container() { return name_container; }
	int Get_Cost_Container() { return cost; }
};

