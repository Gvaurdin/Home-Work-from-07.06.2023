#include "Ink`s recipes.h"

Paint_Material::Paint_Material()
{
	size_base = 2;
	size_paint_color = 4;
	size_raw_code = 7;
	base = new string[size_base];
	paint_color = new string[size_paint_color];
	solvent = "Solvent";
	base[0] = "White Ink";
	base[1] = "Varnish (base)";
	paint_color[0] = "Cyan";
	paint_color[1] = "Yellow";
	paint_color[2] = "Black";
	paint_color[3] = "Magenta";
	RAW_code = new string[size_raw_code];
	RAW_code[0] = "[001] ";
	RAW_code[1] = "[006] ";
	RAW_code[2] = "[101] ";
	RAW_code[3] = "[301] ";
	RAW_code[4] = "[901] ";
	RAW_code[5] = "[801] ";
	RAW_code[6] = "[RHS] ";

}

Paint_Material::~Paint_Material()
{
	delete[] base;
	delete[] paint_color;
	delete[] RAW_code;
}

Paint_Material::Paint_Material(const Paint_Material& obj)
{
	base = new string[2];
	paint_color = new string[4];
	for (int i = 0; i < size_base; i++)
	{
		base[i] = obj.base[i];
	}
	for (int i = 0; i < size_paint_color; i++)
	{
		paint_color[i] = obj.paint_color[i];
	}
	RAW_code = new string[6];
	for (int i = 0; i < size_raw_code; i++)
	{
		RAW_code[i] = obj.RAW_code[i];
	}
}

Component::Component()
{
	Color_ID = "None";
}

Component::Component(const Component& obj)
{
	Color_ID = obj.Color_ID;
}

string Component::ID_Basic_Varnish()
{
	Color_ID = RAW_code[1] + base[1];
	return Color_ID;
}

string Component::ID_Basic_WHite()
{
	Color_ID = RAW_code[0] + base[0];
	return Color_ID;
}

string Component::ID_Cyan()
{
	Color_ID = RAW_code[2] + paint_color[0];
	return Color_ID;
}

string Component::ID_Yellow()
{
	Color_ID = RAW_code[3] + paint_color[1];
	return Color_ID;
}

string Component::ID_Black()
{
	Color_ID = RAW_code[4] + paint_color[2];
	return Color_ID;
}

string Component::ID_Magenta()
{
	Color_ID = RAW_code[5] + paint_color[3];
	return Color_ID;
}

string Component::ID_Solvent()
{
	Color_ID = RAW_code[6] + solvent;
	return Color_ID;
}

void Component::Print_List_Components()
{
	cout << "List components :\n" <<
		ID_Basic_Varnish() << endl <<
		ID_Basic_WHite() << endl <<
		ID_Cyan() << endl <<
		ID_Yellow() << endl <<
		ID_Black() << endl <<
		ID_Magenta() << endl <<
		ID_Solvent() << endl;
}

ostream& operator<<(ostream& os, Paint_Material& m)
{
	cout << "All paint-materials:\n" <<
		"Bases :\n";
	for (int i = 0; i < m.size_base; i++)
	{
		cout << "[" << i + 1 << "] " <<  m.base[i] << endl;
	}
	cout << "Paint-Colors:\n";
	for (int i = 0; i < m.size_paint_color; i++)
	{
		cout << "[" << i + 1 << "] " << m.paint_color[i] << endl;
	}
	cout << endl;
	return os;
}


ostream& operator << (ostream& os, Recipe& c)
{
	if(c.weight == nullptr || c.components == nullptr)
	{
		cout << "The recipe does not exist or was created with an error!\n";
	}
	else
	{
		cout << "Recipe " << c.paint_recipe_number << " (weight 100kg)\n" <<
			c.components[0] << " : " << c.weight[0] << " kg\n" <<
			c.components[1] << " : " << c.weight[1] << " kg\n" <<
			c.components[2] << " : " << c.weight[2] << " kg\n";
	}
	return os;
}

void func_menu()
{
	char menu{};
	bool flag = false;
	while (flag == false)
	{
		system("cls");
		cout << "\t\t\t\tFigure editor\n" <<
			"\t\t\Enter 1 to show list ink materials\n" <<
			"\t\tEnter 2 to show list components\n" <<
			"\t\tEnter 3 to create and show recipe\n" <<
			"\t\tEnter 4 to exit the editor\n\n" <<
			"\t\t\tEnter a command to select an action : ";
		cin >> menu;
		while (menu != '1' && menu != '2' &&
			menu != '3' && menu != '4')
		{
			cout << "\t\tError input\n" <<
				"\t\t\tEnter choise again : ";
			cin >> menu;
		}
		switch (menu)
		{
		case '1':
		{
			system("cls");
			Paint_Material ink_material;
			cout << ink_material;
			system("pause");
		}
		break;
		case '2':
		{
			system("cls");
			Component component;
			component.Print_List_Components();
			system("pause");
		}
		break;
		case '3':
		{
			system("cls");
			Recipe recipe;
			char choise{};
			cout << "Enter 1 to create color Cyan\n" <<
				"Enter 2 to create color Yellow\n" <<
				"Enter 3 to create color Black\n" <<
				"Enter 4 to create color Magenta\n" <<
				"Enter 5 to exit\n" <<
				"Select an operation : ";
			cin >> choise;
			while (choise != '1' && choise != '2' &&
				choise != '3' && choise != '4' &&
				choise != '5')
			{
				cout << "\t\tError input\n" <<
					"\t\t\tEnter choise again : ";
				cin >> choise;
			}
			switch (choise)
			{
			case '1':
			{
				system("cls");
				recipe.Set_Recipe_Cyan();
				Sleep(1000);
				system("cls");
				cout << recipe;
				system("pause");
			}
			break;
			case '2':
			{
				system("cls");
				recipe.Set_Recipe_Yellow();
				Sleep(1000);
				system("cls");
				cout << recipe;
				system("pause");
			}
			break;
			case '3':
			{
				system("cls");
				recipe.Set_Recipe_Black();
				Sleep(1000);
				system("cls");
				cout << recipe;
				system("pause");
			}
			break;
			case '4':
			{
				system("cls");
				recipe.Set_Recipe_Magenta();
				Sleep(1000);
				system("cls");
				cout << recipe;
				system("pause");
			}
			break;
			case '5':
			{
				system("cls");
				Sleep(1000);
				cout << "Exit program......\n";
			}
			break;
			}
		}
		break;
		case '4':
		{
			system("cls");
			cout << "\t\tThe program exits\n";
			flag = true;
		}
		break;
		default:
		{
			cout << "\t\tMistake. Wrong command\n";
			system("pause");
		}
		break;
		}
	}
}

Recipe::Recipe()
{
	paint_recipe_number = "none";
	components = nullptr;
	weight = nullptr;
	number_components = 0;
	check_count = 0;
}

Recipe::~Recipe()
{
	delete[] weight;
	delete[] components;
}

Recipe::Recipe(const Recipe& obj)
{
	number_components = obj.number_components;
	check_count = obj.check_count;
	paint_recipe_number = obj.paint_recipe_number;
	weight = new int[number_components];
	components = new string[number_components];
	for (int i = 0; i < number_components; i++)
	{
		weight[i] = obj.weight[i];
		components[i] = obj.components[i];
	}
}

void Recipe::Set_Recipe_Cyan()
{
	paint_recipe_number = " Cyan - 1020001";
	number_components = 3;
	weight = new int[number_components];
	components = new string[number_components];
	components[0] = ID_Solvent();
	weight[0] = 40;
	check_count++;
	components[1] = ID_Basic_Varnish();
	weight[1] = 35;
	check_count++;
	components[2] = ID_Cyan();
	weight[2] = 25;
	check_count++;
	int sum_weight{};
	for (int i = 0; i < number_components; i++)
	{
		sum_weight += weight[i];
	}
	if (sum_weight != 100 || check_count != 3)
	{
		cout << "Critical error when creating a paint recipe!\n";
		return;
	}
	else {
		check_count = 0;
		cout << "The recipe has been successfully created!\n";
	}
}

void Recipe::Set_Recipe_Yellow()
{
	paint_recipe_number = " Yellow - 3020001";
	number_components = 3;
	weight = new int[number_components];
	components = new string[number_components];
	components[0] = ID_Solvent();
	weight[0] = 35;
	check_count++;
	components[1] = ID_Basic_Varnish();
	weight[1] = 40;
	check_count++;
	components[2] = ID_Yellow();
	weight[2] = 25;
	check_count++;
	int sum_weight{};
	for (int i = 0; i < number_components; i++)
	{
		sum_weight += weight[i];
	}
	if (sum_weight != 100 || check_count != 3)
	{
		cout << "Critical error when creating a paint recipe!\n";
		return;
	}
	else {
		check_count = 0;
		cout << "The recipe has been successfully created!\n";
	}
}

void Recipe::Set_Recipe_Black()
{
	paint_recipe_number = "Black - 9020001";
	number_components = 3;
	weight = new int[number_components];
	components = new string[number_components];
	components[0] = ID_Solvent();
	weight[0] = 40;
	check_count++;
	components[1] = ID_Basic_Varnish();
	weight[1] = 30;
	check_count++;
	components[2] = ID_Black();
	weight[2] = 30;
	check_count++;
	int sum_weight{};
	for (int i = 0; i < number_components; i++)
	{
		sum_weight += weight[i];
	}
	if (sum_weight != 100 || check_count != 3)
	{
		cout << "Critical error when creating a paint recipe!\n";
		return;
	}
	else {
		check_count = 0;
		cout << "The recipe has been successfully created!\n";
	}
}

void Recipe::Set_Recipe_Magenta()
{
	paint_recipe_number = "Magenta - 8020001";
	number_components = 3;
	weight = new int[number_components];
	components = new string[number_components];
	components[0] = ID_Solvent();
	weight[0] = 40;
	check_count++;
	components[1] = ID_Basic_Varnish();
	weight[1] = 40;
	check_count++;
	components[2] = ID_Magenta();
	weight[2] = 20;
	check_count++;
	int sum_weight{};
	for (int i = 0; i < number_components; i++)
	{
		sum_weight += weight[i];
	}
	if (sum_weight != 100 || check_count != 3)
	{
		cout << "Critical error when creating a paint recipe!\n";
		return;
	}
	else {
		check_count = 0;
		cout << "The recipe has been successfully created!\n";
	}
}
