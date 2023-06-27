#include "Template_arr_functions.h"

void func_Menu()
{
	bool p = true;
	do
	{
		char choise{}; int size{};
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
		cout << "\tEnter size array :";
		cin >> size;
		while (size < 2 || size > 50)
		{
			cout << "\t\t Error input\n" <<
				"Enter size again : ";
			cin >> size;
		}
		switch (choise)
		{
		case '1':
		{
			int* arr_int{};
			func_build(arr_int, size);
			func_init(arr_int, size);
			func_Menu_Array(arr_int, size);
		}
		break;
		case '2':
		{
			float* arr_float{};
			func_build(arr_float, size);
			func_init(arr_float, size);
			func_Menu_Array(arr_float, size);
		}
		break;
		case '3':
		{
			char* arr_char{};
			func_build(arr_char, size);
			func_init(arr_char, size);
			func_Menu_Array(arr_char, size);
		}
		break;
		default:
			break;
		}
		cout << "Continue ? 1 - Yes , 0 - No\n";
		cin >> p;
	} while (p);
}
