#include "Printer_Program.h"

Printer_Program::Printer_Program()
{
	owner = "User";
	number_print_pages = 0;
	priority = 0;
	time_SS = number_print_pages * 2;
	time_MM = 0;
}


Printer_Program::Printer_Program(string name, int priority)
{
	this->owner = name;
	this->number_print_pages = rand() % 20 + 1;
	this->priority = priority;
	this->time_SS = number_print_pages * 2;
	this->time_MM = 0;
	this->chek_time();
}

void Printer_Program::chek_time()
{
	if (this->time_SS > 59)
	{
		this->time_MM = this->time_SS / 60;
		this->time_SS = this->time_SS % 60;
	}
}



void QueuePriority::Show() {
	for (int i = 0; i < QueueLength; i++)
	{
		cout << i +1 << Wait[i] << "\n";
	}
	cout << "\n-----------------------------------\n";
}

void QueuePriority::create_Print(Printer_Program print)
{
	this->Add(print, print.priority);
}

QueuePriority::~QueuePriority()
{
	delete[]Wait;
	delete[]Pri;
}
QueuePriority::QueuePriority(QueuePriority& obj)
{
	obj.MaxQueueLength = MaxQueueLength;
	obj.Wait = new Printer_Program[MaxQueueLength];
	obj.Wait = Wait;
	obj.Pri = new int[MaxQueueLength];
	obj.Pri = Pri;
	obj.QueueLength = QueueLength;

}
QueuePriority::QueuePriority(int m)
{
	MaxQueueLength = m;
	Wait = new Printer_Program[MaxQueueLength];
	Pri = new int[MaxQueueLength];
	QueueLength = 0;
}
void QueuePriority::Clear()
{
	QueueLength = 0;
}
bool QueuePriority::IsEmpty()
{
	return QueueLength == 0;
}
bool QueuePriority::IsFull()
{
	return QueueLength == MaxQueueLength;
}
int QueuePriority::GetCount()
{
	return QueueLength;
}
void QueuePriority::Add(Printer_Program p, int c)
{

	if (!IsFull()) {
		Wait[QueueLength] = p;
		Pri[QueueLength] = c;
		QueueLength++;
	}
}

Printer_Program QueuePriority::Extract()
{

	if (!IsEmpty())
	{
		int max_pri = Pri[0];
		int pos_max_pri = 0;
		for (int i = 1; i < QueueLength; i++)
			if (max_pri < Pri[i])
			{
				max_pri = Pri[i];
				pos_max_pri = i;
			}
		Printer_Program temp1 = Wait[pos_max_pri];
		int temp2 = Pri[pos_max_pri];
		for (int i = pos_max_pri; i < QueueLength - 1; i++)
		{
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}
		QueueLength--;
		this->time_queue += temp1.time_SS;
		temp1.time_SS = this->time_queue;
		temp1.chek_time();
		return temp1;
	}
	else cout << "Error\n";
}

ostream& operator << (ostream& os, Printer_Program& p)
{
	cout << (char)186 << left << setw(14) << p.owner << (char)186 <<
		left << setw(13) << p.number_print_pages << (char)186 <<
		p.time_MM <<
		left << setw(5) << " min. " << left << setw(2) << p.time_SS <<
		" sec." << (char)186 << right << setw(9) << p.priority << (char)186;
	return os;
}

void create_Users(Printer_Program& a, Printer_Program& t, Printer_Program& u)
{
	a = Printer_Program("Admin", 3);
	t = Printer_Program("Teacher", 2);
	u = Printer_Program("User", 1);
}

ostream& operator<<(ostream& os, QueuePriority& p)
{
	
	Table_template();
	for (int i = 0; i < p.QueueLength; i++)
	{
		cout << char(186) << left << setw(13) << i + 1 <<
		p.Wait[i] << "\n";
		for (int j = 0; j < 69; j++)
		{
			if (i == p.QueueLength - 1)
			{
				if (j == 14 || j == 29 ||
					j == 43 || j == 58) cout << (char)202;
				else if (j == 0) cout << (char)200;
				else if (j == 68) cout << (char)188;
				else cout << (char)205;
			}
			else if (j == 0) cout << (char)204;
			else if (j == 68) cout << (char)185;
			else if (j == 14 || j == 29 ||
				j == 43 || j == 58) cout << (char)206;
			else cout << (char)205;
		}
		cout << endl;
	}
	return os;
}

ostream& operator<<(ostream& os, List& p)
{
	Element* temp = p.Head;
	int i = 1, count = 0, min = 5;
	char action{};
	cout << "Press the enter key to show next 5 requests print\n" <<
		"Press ESC key to exit\n";
	Table_template();
	while (temp != 0)
	{
		if (action == 27) break;
		while (count < min)
		{
			if (temp == 0) break;
			cout << char(186) << left << setw(13) << i <<
				temp->data << "\n";
			for (int j = 0; j < 69; ++j)
			{
				if (j == 0) cout << (char)204;
				else if (j == 68) cout << (char)185;
				else if (j == 14 || j == 29 ||
					j == 43 || j == 58) cout << (char)206;
				else cout << (char)205;
			}
			++i;
			++count;
			cout << endl;
			temp = temp->Next;
		}
		if (temp != 0)
		{
			action = _getch();
			if (action == 13) {
				min += 5;
				Sleep(200);
			}
			else if (action != 27 && action != 13)
			{
				system("cls");
				cout << "Error!!!!!\n";
				break;
			}
		}
		else break;
	}
	return os;
}

void Table_template()
{
	cout << (char)186 << " Number queue" << setw(1) << (char)186  << " Request owner" <<
		(char)186 << " Number pages" << (char)186 << " Print time" <<
		setw(4) << (char)186 << " Priority"  << (char)186 << endl;
		for (int i = 0; i < 65; i++)
		{
			if (i == 0) cout << (char)204;
			else if (i == 64) cout << (char)185;
			 else cout << (char)205;
			if (i == 13 || i == 27 ||
				i == 40 || i == 54) cout << (char)206;
		}
	cout << endl;
}

void func_menu()
{
	bool flag = true; char num = 0;
	Printer_Program admin, teacher, user;
	create_Users(admin, teacher, user);
	QueuePriority q(30); List l, l2;
	for (int i = 0, j = 1; i < 14; ++i)
	{
		j = rand() % 14+1;
		if (j % 2 == 0)
		{
			q.create_Print(admin);
			l2.Add(admin);
		}
		else if (j % 3 == 0)
		{
			q.create_Print(teacher);
			l2.Add(teacher);
		}
		else
		{
			q.create_Print(user);
			l2.Add(user);
		}
	}
	
	for (int i = 0; i < 14; i++)
	{
		l.Add(q.Extract());
	}
	do
	{
		system("cls");
		cout << setw(20) << "Printer Menu\n" <<
			setw(10) << "Enter 1 -  show a list of print requests\n" <<
			setw(10) << "Enter 2 - show the print queue list \n" <<
			setw(10) << "Enter 3 - exit the program\n" <<
			setw(15) << "Enter to command : ";
		cin >> num;
		while (num != '1' && num != '2' && num != '3')
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
			cout << l2;
			system("pause");
		}
		break;
		case '2':
		{
			system("cls");
			cout << l;
			system("pause");
		}
		break;
		case '3':
		{
			system("cls");
			cout << "\t\tThe program exits\n";
			system("pause");
			flag = false;
		}
		break;
		default:
			system("cls");
			cout << "Error!!!\n";
			break;
		}
	} while (flag == true);
}


List::List()
{
	Head = Tail = NULL;
	Count = 0;
}
List::~List()
{
	DelAll();
}
int List::GetCount()
{
	return Count;
}
void List::Add(Printer_Program data)
{
	Element* temp = new Element;
	temp->data = data;
	temp->Next = NULL;
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	else
	{
		Head = Tail = temp;
	}
	Count++;
}
void List::Del()
{
	Element* temp = Head;
	Head = Head->Next;
	delete temp;
	Count--;
}
void List::DelAll()
{
	while (Head != 0)
		Del();
}
void List::Print()
{
    Element* temp = Head;
	while (temp != 0)
	{
		cout << temp->data << " ";
		temp = temp->Next;
	}
	cout << "\n";
}