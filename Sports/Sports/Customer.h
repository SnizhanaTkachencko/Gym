#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <algorithm>

#include "EquipmentWarehouse.h"
#include "SortPredicates.h"

class Customer
{
	friend class CustomerMenu;
private:
	static EquipmentWarehouse storage;
public:
	void SortEquipmentsByBrand();
	void SortEquipmentsBykind();

	string GetMostPopularEquipmentBrand();
	string GetMostPopularEquipmentkind();

};

#endif // !CUSTOMER_H