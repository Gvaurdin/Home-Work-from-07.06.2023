#include "Figure.h"

ostream& operator<<(ostream& os, Point& p)
{
    SetColor(15, 0);
    cout << "Point (" << p.x << ',' << p.y << ')' << endl;
    SetColor(Point::i_color, 0);
    char tmp = 16 + rand()% (17-15);
    GotoXY(p.x, p.y);
    cout << tmp;
    return os;
}

void Set_User_Color(int color)
{
    switch (color)
    {
    case 1:
        Point::i_color = color;
        Point::color = "Blue";
        break;
    case 2:
        Point::i_color = color;
        Point::color = "Green";
        break;
    case 3:
        Point::i_color = color;
        Point::color = "Cyan";
        break;
    case 4:
        Point::i_color = color;
        Point::color = "Red";
        break;
    case 5:
        Point::i_color = color;
        Point::color = "Magenta";
        break;
    }
}

ostream& operator<<(ostream& os, Figure& p)
{
    GotoXY(25, 20);
    if (p.obj)
    {
        cout << "Figure`s color : ";
        SetColor(Point::i_color, 0);
        cout << Point::color << endl;
        SetColor(15, 0);
        GotoXY(0, 0);
        for (int i = 0; i < p.count; i++)
        {
            cout << p.obj[i];
            GotoXY(0, i + 1);
        }
        SetColor(15, 0);
        Sleep(10000);
    }
    else
    {
        GotoXY(20, 6);
        cout << "Figure don`t create!\n";
    }
    return os;
}

istream& operator>>(istream& is, Figure& p)
{
    cout << "Enter the number of vertices of the polygon : ";
    cin >> p.count;
    while (p.count < 3 && p.count > 10)
    {
        cout << "Error input\n" <<
            "Enter to again: ";
        cin >> p.count;
    }
    cout << "Colors : 1 - Blue ; 2 - Green; 3 - Cyan; 4 - Red; 5 - Magenta\n" <<
        "Enter the color of your figure, from 1 to 5 : ";
    cin >> Point::i_color;
    while (Point::i_color < 1 && Point::i_color > 5)
    {
        cout << "Error input\n" <<
            "Enter to again: ";
        cin >> Point::i_color;
    }
    p.obj = new Point[p.count];
    Set_User_Color(Point::i_color);
    system("cls");
    int tmp = 1;
    for (int i = 0; i < p.count; i++)
    {
        if(tmp % 2 != 0) p.obj[i].SetP(15 + rand() % (30-15), 5);
        else p.obj[i].SetP(15 + rand() % (30 - 15), 7 + rand()% (15 - 7));
        tmp++;
    }
    return is;
}

void Create_User_Figure(Figure& p)
{
    system("cls");
    int choise_figure{}; int S, L_side{}, side_A{}, side_B{}, diagonal{};
    cout << "\n\t\t\tSelect the shape you want to create\n" <<
        "\t\tEnter to 1 - create equilateral triangle\n" <<
        "\t\tEnter to 2 - create square\n" <<
        "\t\tEnter to 3 - create rectangle\n" <<
        "\t\tEnter to 4 - exit from creator\n" <<
        "\t\t\tYour choise : ";
    cin >> choise_figure;
    while (choise_figure < 1 && choise_figure > 4)
    {
        cout << "Error input\n" <<
            "Enter to again: ";
        cin >> choise_figure;
    }
    switch (choise_figure)
    {
    case 1:
        system("cls");
        cout << "Colors : 1 - Blue ; 2 - Green; 3 - Cyan; 4 - Red; 5 - Magenta\n" <<
            "Enter the color of your figure, from 1 to 5 : ";
        cin >> Point::i_color;
        while (Point::i_color < 1 && Point::i_color > 5)
        {
            cout << "Error input\n" <<
                "Enter to again: ";
            cin >> Point::i_color;
        }
        cout << "Enter the equilateral triangle area (max 300) : ";
        cin >> S;
        while (S < 4 && S > 300)
        {
            cout << "Error input\n" <<
                "Enter to again: ";
            cin >> S;
        }
        L_side = RootNumber(4 * S / 1.732, 4);
        p.count = 3;
        p.obj = new Point[p.count];
        Set_User_Color(Point::i_color);
        p.obj[0].SetP(20, 6);
        p.obj[1].SetP(20 - L_side / 2, 6 + L_side / 2);
        p.obj[2].SetP(20 + L_side / 2, 6 + L_side / 2);
        system("cls");
        GotoXY(20 + L_side / 2, 3);
        cout << "The length of the sides of the equilateral triangle = " << L_side;
        cout << p;
        break;
    case 2:
        system("cls");
        cout << "Colors : 1 - Blue ; 2 - Green; 3 - Cyan; 4 - Red; 5 - Magenta\n" <<
            "Enter the color of your figure, from 1 to 5 : ";
        cin >> Point::i_color;
        while (Point::i_color < 1 && Point::i_color > 5)
        {
            cout << "Error input\n" <<
                "Enter to again: ";
            cin >> Point::i_color;
        }
        cout << "Enter the square area (max 300) : ";
        cin >> S;
        while (S < 4 && S > 300)
        {
            cout << "Error input\n" <<
                "Enter to again: ";
            cin >> S;
        }
        L_side = RootNumber(S, 4);
        p.count = 4;
        p.obj = new Point[p.count];
        Set_User_Color(Point::i_color);
        p.obj[0].SetP(20, 10);
        p.obj[1].SetP(20, 10 + L_side / 2);
        p.obj[2].SetP(20 + L_side, 10 + L_side / 2);
        p.obj[3].SetP(20 + L_side, 10);
        system("cls");
        GotoXY(20 + L_side / 2, 3);
        cout << "The length of the sides of the square = " << L_side;
        cout << p;
        break;
    case 3:
        system("cls");
        cout << "Colors : 1 - Blue ; 2 - Green; 3 - Cyan; 4 - Red; 5 - Magenta\n" <<
            "Enter the color of your figure, from 1 to 5 : ";
        cin >> Point::i_color;
        while (Point::i_color < 1 && Point::i_color > 5)
        {
            cout << "Error input\n" <<
                "Enter to again: ";
            cin >> Point::i_color;
        }
        cout << "Enter the diagonal of the rectangle(Max = 20) : ";
        cin >> diagonal;
        while (diagonal < 2 && diagonal > 300)
        {
            cout << "Error input\n" <<
                "Enter to again: ";
            cin >> diagonal;
        }
        cout << "Enter the rectangle`s side B (Max = 20) : ";
        cin >> side_B;
        while (side_B < 2 && side_B > 20)
        {
            cout << "Error input\n" <<
                "Enter to again: ";
            cin >> side_B;
        }
        side_A = RootNumber(diagonal * diagonal / side_B * side_B, 1);
        p.count = 4;
        p.obj = new Point[p.count];
        Set_User_Color(Point::i_color);
        p.obj[0].SetP(20, 10);
        p.obj[1].SetP(20 + side_A, 10);
        p.obj[2].SetP(20, 10 + side_B / 2);
        p.obj[3].SetP(20 + side_A, 10 + side_B / 2);
        system("cls");
        GotoXY(20 + L_side / 2, 3);
        cout << "The length of the side A = " << side_A;
        GotoXY(20 + L_side / 2, 4);
        cout << "The length of the side B = " << side_B;
        cout << p;
        break;
    case 4:
        system("cls");
        cout << "\t\tThe program exits\n";
        system("pause");
        break;
    default:
        system("cls");
        cout << "Error!!!\n";
        break;
    }

    
}

void SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void GotoXY(int X, int Y)
{
    HANDLE hConsole;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);
}

double RootNumber(int n, int i)
{
    if ((n * 10000) - (i * i) <= 0)
        return ((double)i / 100);
    else
        RootNumber(n, i + 1);
}

void func_menu()
{
    char menu{};
    bool flag = false;
    while (flag == false)
    {
        system("cls");
        cout << "\t\t\t\tFigure editor\n" <<
            "\t\t\Enter 1 to create random figure\n" <<
            "\t\tEnter 2 to create a shape with a custom color and number of vertices\n" <<
            "\t\tEnter 3 to create a square, triangle, or rectangle\n" <<
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
            Figure f1(rand() % 10 + 3, rand() % 5 + 1);
            cout << f1;
        }
            break;
        case '2':
        {
            system("cls");
            Figure f1;
            cin >> f1;
            cout << f1;
        }
            break;
        case '3':
        {
            system("cls");
            Figure f1;
            Create_User_Figure(f1);
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


Figure::Figure(int count, int color)
{
    if (count < 3 || count > 10 ||
        color < 1 || color > 5)
    {
        GotoXY(20, 5);
        cout << "Mistake. Figure must have at least 3 vertex points\n";
        return;
    }
    this->count = count;
    this->obj = new Point[count];
    if (!obj) return;
    Set_User_Color(color);
    for (int i = 0; i < count; i++)
    {
        if (i % 2 == 0) obj[i].SetP(rand() % 30 + 10, rand() % 10 + 5);
        else obj[i].SetP(rand() % 30 + 15, rand() % 5 + 2);

    }
}

Figure::~Figure()
{
    if (obj != nullptr) delete[] obj;
}

string Point::color = "none";
int Point::i_color = 15;

void Point::SetP(int x, int y)
{
    this->x = x,
    this->y = y;
}
