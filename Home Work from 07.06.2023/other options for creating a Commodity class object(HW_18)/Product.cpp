#include "Product.h"

Product::Product(string _np, double _cost)
{
	name_product = _np;
	cost = _cost;
}

void Product::Set_Product(string np, double _cost)
{
	name_product = np;
	cost = _cost;
}
