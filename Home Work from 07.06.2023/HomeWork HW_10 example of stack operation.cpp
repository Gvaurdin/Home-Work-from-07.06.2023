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
	* ����� �������� �������� "isBalanced" ���� �������������� ���������, �������������� ���� 
	* �� ����� �������, ��� � ������ ��������� ������ ����������� ����� , � �� ������ ��������� ���� ������ 
	* �� ������������ ���� �����.
	*/
	

}
/*
* ���������� ������ ����� ��� �������� ��������� ������������� ������ � �������������� ����������
* ������� isBalanced ��������� ������ ��������� � ��������� �������� �� �������� ������. 
���� ����������� ������������� ������, ��� ���������� � ����. 
���� ����������� ������������� ������, �� ���������, ������������� �� ��� ��������� �������� ������ � �����. 
���� ��� ������ ��������������, ������� ���������� true, � ��������� ������ - false.
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
				return false; // ����������� ������ ��� �����������
			}

			char tmp = st.Pop();
			if ((c == ')' && tmp != '(') || (c == ']' && tmp != '[') ||
				(c == '}' && tmp != '{'))
			{
				cout << "The brackets don't match each other\n";
				return false; // ������������� ����� ������
			}
		}
	}
	cout << "Brackets have been placed successfully!\n";
	return st.IsEmpty(); // ��� ������ ��������������, ���� ���� ����
}
