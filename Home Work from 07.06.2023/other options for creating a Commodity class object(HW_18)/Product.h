#pragma once
#include <iomanip> 
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

class Product
{
protected:
	string name_product;
	double cost;
public:
	Product() { name_product = "empty"; cost = 0; }
	Product(string _np, double _cost);
	void Set_Product(string np, double _cost);
	string Get_Name_Product() { return name_product; }
	int Get_Cost_Product() { return cost; }
};

