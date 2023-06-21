#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;


class Stack
{
	enum { EMPTY = -1, FULL = 20 };
	char st[FULL + 1];
	int top;
public:
	Stack();
	void Push(char c);
	char Pop();
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int GetCount();
	friend bool isBalanced(const string& example, Stack st);
};
Stack::Stack()
{
	top = EMPTY;
}

void Stack::Clear()
{

	top = EMPTY;
}
bool Stack::IsEmpty()
{

	return top == EMPTY;
}
bool Stack::IsFull()
{

	return top == FULL;
}
int Stack::GetCount()
{

	return top + 1;
}
void Stack::Push(char c)
{

	if (!IsFull())
		st[++top] = c;
}
char Stack::Pop()
{

	if (!IsEmpty())
		return st[top--];
	else return 0;
}
int main()
{
	srand(time(0));
	Stack ST;
	string example_1 = "(((10 + 5)) * 6)";
	string example_2 = "[(8 + 7) * 4]";
	cout << example_1 << endl;
	isBalanced(example_1, ST);
	cout << "\n========================================\n";
	cout << example_2 << endl;
	isBalanced(example_2, ST);
	/*
	* После проверки функцией "isBalanced" двух арифметических выражений, представленных выше 
	* мы можем увидеть, что в первом выражении скобки проставлены верно , а во втором выражении типы скобок 
	* не соотвествуют друг другу.
	*/
	

}
/*
* Применение работы стека для проверки правильно проставленных скобок в арифметических выражениях
* Функция isBalanced принимает строку выражения и выполняет итерацию по символам строки. 
Если встречается открывающаяся скобка, она помещается в стек. 
Если встречается закрывающаяся скобка, мы проверяем, соответствует ли она последней открытой скобке в стеке. 
Если все скобки сбалансированы, функция возвращает true, в противном случае - false.
*/
bool isBalanced(const string& example, Stack st)
{
	for (char c : example)
	{
		if (c == '(' || c == '[' || c == '{')
		{
			st.Push(c);
		}
		else if (c == ')' || c == ']' || c == '}')
		{
			if (st.IsEmpty())
			{
				cout << "Closing bracket without opening\n";
				return false; // закрывающая скобка без открывающей
			}

			char tmp = st.Pop();
			if ((c == ')' && tmp != '(') || (c == ']' && tmp != '[') ||
				(c == '}' && tmp != '{'))
			{
				cout << "The brackets don't match each other\n";
				return false; // несоответсвие типов скобок
			}
		}
	}
	cout << "Brackets have been placed successfully!\n";
	return st.IsEmpty(); // все скобки сбалансированы, если стек пуст
}
