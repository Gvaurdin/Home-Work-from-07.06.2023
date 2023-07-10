#include "Commodity.h"
#include "Container.h"
#include "Product.h"

Commodity::Commodity(Product p, Container c)
{
	name_commodity = "Name product : " + p.Get_Name_Product() + " ; " + " Container : " + c.Get_Name_Container();
	cost = (p.Get_Cost_Product() + c.Get_Cost_Container()) * 1.2;
}

Commodity::Commodity(string _np, double _cost_p, string _nc, double _cost_c) :
	Product(_np, _cost_p), Container(_nc, _cost_c)
{
	name_commodity = "Name product : " + _np + " ; " + " Container : "  + _nc;
	cost = (_cost_p + _cost_c) * 1.2;
}

Commodity::Commodity()
{
	cost = (Product::cost + Container::cost) * 1.2;
	name_commodity = "Name product : " + Product::name_product + " ; " + " Container : " + Container::name_container;
}

void Commodity::Set_Commodity()
{
	cost = (Product::cost + Container::cost) * 1.2;
	name_commodity = "Name product : " + Product::name_product + " ; " + " Container : " + Container::name_container;
}

ostream& operator<<(ostream& os, Commodity com)
{
	cout << "Commodity : \n" << com.name_commodity << endl <<
		"Cost commodity = " << com.cost << endl;
	return os;

}

void func_menu()
{
	cout << "Option to cretae an object of class N-1 (class work)\n";
	Commodity com("Milk", 94.33, "Bottle", 10.50);
	cout << com;
	cout << "\n=========================================\n";
	cout << "Option to cretae an object of class N-2 (void set)\n";
	Commodity com_2;
	com_2.Product::Set_Product("Fish", 106.67);
	com_2.Container::Set_Container("Packet", 9.80);
	com_2.Set_Commodity();
	cout << com_2;
	cout << "\n=========================================\n";
	cout << "Option to cretae an object of class N-3 (void set with use get method)\n";
	Product p1("Meat", 231.87);
	Container c1("Vacuum packaging", 7.50);
	Commodity com_3;
	com_3.Set_Product(p1.Get_Name_Product(), p1.Get_Cost_Product());
	com_3.Set_Container(c1.Get_Name_Container(), c1.Get_Cost_Container());
	com_3.Set_Commodity();
	cout << com_3;
	cout << "\n=========================================\n";
	cout << "Option to cretae an object of class N-4 (the constructor with parameters adopts the sections of parents classes)\n";
	Product p2("Potato", 135.99);
	Container c2("Bag", 30.99);
	Commodity com_4(p2, c2);
	cout << com_4;
}
