#include <iostream>
#include <time.h>
#include <Windows.h>
#include <iomanip> 
using namespace std;

template <typename T> void  func_build(T*& array, int size);
template <typename T> void  func_init(T* array, int size);
template <typename T> void  func_show(T* array, int size);
template <typename T> void  func_delete(T* array);
void func_Menu();

template<typename T>
void func_build(T*& array, int size)
{
	array = new T[size];
}

template<typename T>
void func_init(T* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		array[i] = rand() % 25 + 65 + rand() % 100 / 100.0;
	}
}

template<typename T>
void func_show(T* array, int size)
{
	if (array != nullptr)
	{
		for (int i = 0; i < size; ++i)
		{
			cout << "[" << i + 1 << "] : " << array[i] << "  ";
		}
		cout << endl;
	}
}

template<typename T>
void func_delete(T* array)
{
	delete[] array;
	array = NULL;
}

template<typename T>
int func_max(T* array, int size)
{
	if (array != nullptr)
	{
		T max = INT_MIN, i_max = 0;
		for (int i = 0; i < size; ++i)
		{
			if (array[i] > max)
			{
				max = array[i];
				i_max = i;
			}
		}
		return i_max;
	}
}

template<typename T>
int func_min(T* array, int size)
{
	if (array != nullptr)
	{
		T min = INT_MIN, i_min = 0;
		for (int i = 0; i < size; ++i)
		{
			if (array[i] < min)
			{
				min = array[i];
				i_min = i;
			}
		}
		return i_min;
	}
}

template<typename T>
T func_avg(T* array, int size)
{
	if (array != nullptr)
	{
		T sum{};
		for (int i = 0; i < size; ++i)
		{
			sum += array[i];
		}
		return sum / size;
	}
}

template<typename T>
void func_sort(T* array, int size)
{
	if (array != nullptr)
	{
		int min = 0;
		for (int i = 0; i < size - 1; ++i)
		{
			min = i;
			for (int j = i + 1; j < size; ++j)
			{
				if (array[j] < array[min])
				{
					min = j;
				}
			}
			if (min != i)
			{
				swap(array[i], array[min]);
			}
		}
	}
}

template<typename T>
void func_Menu_Array(T* array, int size)
{
	char num{}; bool flag = true;
	if (array != nullptr)
	{
		do
		{
			system("cls");
			cout << "Your custom array :\n";
			func_show(array, size);
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
				func_sort(array, size);
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
				func_show(array, size);
				int max = func_max(array, size);
				int min = func_min(array, size);
				T avg = func_avg(array, size);
				cout << "MAX element = " << "[" << max + 1 << "] : " <<
					array[max] << endl;
				cout << "MIN element = " << "[" << min + 1 << "] : " <<
					array[min] << endl;
				cout << "AVG element = " << avg << endl;
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
