#include "Template_arr_functions.h"

void func_Menu()
{
	bool p = true;
	do
	{
		char choise{}; int row{}, col{};
		cout << "\n\t\t\tArray editor\n" <<
			"\tWhat type of element array do you want to create?\n" <<
			"\tChange : " << "1 - array int, 2 - array double, 3 - array char \n" <<
			"\t\t\tYour choice : ";
		cin >> choise;
		while (choise != '1' && choise != '2' && choise != '3')
		{
			cout << "\t\tError input\n" <<
				"\t\t\tEnter choise again : ";
			cin >> choise;
		}
		cout << "\tEnter number rows array :";
		cin >> row;
		while (row < 2 || row > 10)
		{
			cout << "\t\t Error input\n" <<
				"Enter size again : ";
			cin >> row;
		}
		cout << "\tEnter number columns array :";
		cin >> col;
		while (col < 2 || col > 20)
		{
			cout << "\t\t Error input\n" <<
				"Enter size again : ";
			cin >> col;
		}
		switch (choise)
		{
		case '1':
		{
			int** arr_int{};
			func_build(arr_int,row,col);
			func_init(arr_int, row, col);
			func_Menu_Array(arr_int,row, col);
			func_delete(arr_int,row);
		}
		break;
		case '2':
		{
			float** arr_float{};
			func_build(arr_float, row, col);
			func_init(arr_float, row, col);
			func_Menu_Array(arr_float, row, col);
			func_delete(arr_float, row);
		}
		break;
		case '3':
		{
			char** arr_char{};
			func_build(arr_char, row, col);
			func_init(arr_char, row, col);
			func_Menu_Array(arr_char, row, col);
			func_delete(arr_char,row);
		}
		break;
		default:
			break;
		}
		cout << "Continue ? 1 - Yes , 0 - No\n";
		cin >> p;
	} while (p);
}
