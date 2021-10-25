#ifndef CUSTOMERMENU_H
#define CUSTOMERMENU_H

#include "Customer.h"

class CustomerMenu
{
public:
	void ShowMainCustomerMenu();
private:
	Customer customer;
	//EquipmentWarehouse storage;
	void showCustomerMenu();

	void executeSortByBrandMenu();
	void executeSortBykindMenu();
	void executeGetMostPopularBrandMenu();
	void executeGetMostPopularkindMenu();
	void handleCustomerInput(char customerInput);
	void safeHandleCustomerInput(char customerInput);
};

#endif // !CUSTOMERMENU_H
