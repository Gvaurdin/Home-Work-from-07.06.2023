#pragma once
#include <iomanip> 
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;


class Paint_Material
{
	int size_raw_code, size_base, size_paint_color;
protected:
	string* base;
	string* paint_color;
	string* RAW_code;
	string solvent;
public:
	Paint_Material();
	~Paint_Material();
	Paint_Material(const Paint_Material& obj);
	friend ostream& operator << (ostream& os, Paint_Material& m);
};

class Component : public Paint_Material
{
	string Color_ID;
protected:
	string ID_Basic_Varnish();
	string ID_Basic_WHite();
	string ID_Cyan();
	string ID_Yellow();
	string ID_Black();
	string ID_Magenta();
	string ID_Solvent();
public:
	Component();
	Component(const Component& obj);
	~Component() { ; }
	void Print_List_Components();

};

class Recipe : protected Component
{
	int* weight;
	int number_components, check_count;
	string paint_recipe_number;
	string* components;
public:
	Recipe();
	~Recipe();
	Recipe(const Recipe& obj);
	void Set_Recipe_Cyan();
	void Set_Recipe_Yellow();
	void Set_Recipe_Black();
	void Set_Recipe_Magenta();
	friend ostream& operator << (ostream& os, Recipe& c);
};

void func_menu();

