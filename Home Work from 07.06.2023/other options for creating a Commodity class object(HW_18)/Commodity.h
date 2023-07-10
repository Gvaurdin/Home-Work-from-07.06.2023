#pragma once
#include <iomanip> 
#include <Windows.h>
#include <iostream>
#include <ctime>
#include "Product.h"
#include "Container.h"

using namespace std;

class Commodity : public Product, public Container
{
protected:
	string name_commodity;
	double cost;
public:
	Commodity(Product p, Container c);
	Commodity(string _np, double _cost_p, string _nc, double _cost_c);
	Commodity();
	void Set_Commodity();
	friend ostream& operator << (ostream& os, Commodity com);
};

void func_menu();

