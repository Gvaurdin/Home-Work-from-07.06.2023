#include "Container.h"

Container::Container(string _nc, double _cost)
{
	name_container = _nc;
	cost = _cost;
}

Container::Container(const Container& obj)
{
	name_container = obj.name_container;
	cost = obj.cost;
}

void Container::Set_Container(string nc, double _cost)
{
	name_container = nc;
	cost = _cost;
}
