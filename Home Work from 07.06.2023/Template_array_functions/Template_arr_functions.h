#include <iostream>
#include <time.h>
#include <Windows.h>
#include <iomanip> 
using namespace std;

template <typename T> void  func_build(T**& array, int row, int col);
template <typename T> void  func_init(T** array, int row, int col);
template <typename T> void  func_show(T** array, int row, int col);
template <typename T> void  func_delete(T** array,int row);
void func_Menu();

template<typename T>
void func_build(T**& array, int row, int col)
{
	array= new T*[row];
	for (int i = 0; i < row; i++)
	{
		array[i] = new T[col];
	}
}

template<typename T>
void func_init(T** array, int row, int col)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; j++)
		{
			array[i][j] = rand() % 25 + 65 + rand() % 100 / 100.0;
		}
	}
}

template<typename T>
void func_show(T** array, int row, int col)
{
	if (array != nullptr)
	{
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; j++)
			{
				cout << array[i][j] << "  ";
			}
			cout << endl;
		}
	}
}

template<typename T>
void func_delete(T** array,int row)
{
	if (array != nullptr)
	{
		for (int i = 0; i < row; i++) {
			delete array[i];
		}
		delete[] array;
		array = NULL;
	}
}

template<typename T>
int* func_max(T** &array, int row, int col)
{
	if (array != nullptr)
	{
		int max = INT_MIN;
		int* i_max = new int[2];
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (array[i][j] > max)
				{
					max = array[i][j];
					i_max[0] = i;
					i_max[1] = j;
				}
			}
		}
		return i_max;
	}
}

template<typename T>
int* func_min(T** array, int row, int col)
{
	if (array != nullptr)
	{
		int min = INT_MAX;
		int* i_min = new int[2];
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (array[i][j] < min)
				{
					min = array[i][j];
					i_min[0] = i;
					i_min[1] = j;
				}
			}
		}
		return i_min;
	}
}

template<typename T>
T func_avg(T** array, int row, int col)
{
	if (array != nullptr)
	{
		T sum{};
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; ++j)
			{
				sum += array[i][j];
			}
		}
		return sum / (row * col);
	}
}

template<typename T>
void func_sort(T** array, int row, int col)
{
	if (array != nullptr)
	{
		for (int k = 0; k < row; k++)
		{
			for (int r = 0; r < col; r++)
			{
				for (int i = 0; i < row; i++)
				{

					for (int j = 0; j < col; j++)
					{

						if (array[i][j] > array[k][r])
						{
							swap(array[i][j],array[k][r]);
						}
					}
				}
			}
		}
	}
}

template<typename T>
void func_Menu_Array(T** array, int row, int col)
{
	char num{}; bool flag = true;
	if (array != nullptr)
	{
		do
		{
			system("cls");
			cout << "Your custom array :\n";
			func_show(array,row,col);
			cout << "\n====================\n";
			cout << setw(20) << "Array Menu\n" <<
				setw(10) << "Enter 1 -  to sorting your array\n" <<
				setw(10) << "Enter 2 - to show MAX, MIN, AVG elements your array \n" <<
				setw(10) << "Enter 3 - exit the Array menu\n" <<
				setw(15) << "Enter to command : ";
			cin >> num;
			while (num != '1' && num != '2' && num != '3' && num != '4')
			{
				cout << setw(15) << "Error\n" <<
					setw(15) << "Try again : ";
				cin >> num;
			}
			switch (num)
			{
			case '1':
			{
				system("cls");
				cout << "We sorting your array....\n";
				func_sort(array,row,col);
				Sleep(1000);
				system("cls");
				cout << "Your array successfully sorted\n";
				Sleep(1000);
			}
				break;
			case '2':
			{
				system("cls");
				cout << "Your custom array :\n";
				func_show(array,row,col);
				int* max = new int[2];
				int* min = new int[2];
				max = func_max(array, row, col);
				min = func_min(array, row, col);
				T avg = func_avg(array,row,col);
				cout << "MAX element = " << "[ROW " << max[0] + 1 << "]" <<
					"[COL " << max[1] + 1 << "] : " << array[max[0]][max[1]] << endl;
				cout << "MIN element = " << "[ROW " << min[0] + 1 << "]" <<
					"[COL " << min[1] + 1 << "] : " << array[min[0]][min[1]] << endl;
				cout << "AVG element = " << avg << endl;
				delete[] max;
				delete[] min;
				system("pause");
			}
				break;
			case '3':
			{
				system("cls");
				system("cls");
				cout << "\t\tThe array menu exits\n";
				system("pause");
				flag = false;
			}
				break;
			default:
				system("cls");
				cout << "Error!!!\n";
				break;
			}
		} while (flag);
	}
}
