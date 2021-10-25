#include "CustomerMenu.h"

void CustomerMenu::ShowMainCustomerMenu()
{
	char customerInput;

	do {
		showCustomerMenu();
		cin >> customerInput;
		safeHandleCustomerInput(customerInput);

		cout << endl;
	} while (customerInput != '0');
}

void CustomerMenu::showCustomerMenu()
{
	cout << "\nYou are a customer in the Gym \"Tears of fat\" !\n";
	cout << "Please select an option:\n";
	cout << "1 -> Sort by brand and show Equipments\n";
	cout << "2 -> Sort by kind and show Equipments\n";
	cout << "3 -> Get most popular Equipment brand\n";
	cout << "4 -> Get most popular kind of Equipment\n";
	cout << "p -> Print all Equipments to console\n";
	cout << "0 -> Exit customer menu\n\n";
}

void CustomerMenu::executeSortByBrandMenu()
{
	customer.SortEquipmentsByBrand();
	Customer::storage.PrintEquipments();
}

void CustomerMenu::executeSortBykindMenu()
{
	customer.SortEquipmentsBykind();
	Customer::storage.PrintEquipments();
}

void CustomerMenu::executeGetMostPopularBrandMenu()
{
	cout << "Most popular brand: " << customer.GetMostPopularEquipmentBrand() << endl;
}

void CustomerMenu::executeGetMostPopularkindMenu()
{
	cout << "Most popular  kind of Equipment: " << customer.GetMostPopularEquipmentkind() << endl;
}

void CustomerMenu::handleCustomerInput(char customerInput)
{
	switch (customerInput)
	{
	case '1':
		executeSortByBrandMenu();
		break;
	case '2':
		executeSortBykindMenu();
		break;
	case '3':
		executeGetMostPopularBrandMenu();
		break;
	case '4':
		executeGetMostPopularkindMenu();
		break;
	case 'p':
		Customer::storage.PrintEquipments();
		cout << endl;
		break;
	case '0':
		break;
	default:
		cout << "Wrong command selected\n";
		break;
	}
}

void CustomerMenu::safeHandleCustomerInput(char customerInput)
{
	try
	{
		handleCustomerInput(customerInput);
	}
	catch (Error& error)
	{
		/*ofstream fout("errors.txt");
		fout << error.ToString();
		fout.close();*/

		cout << "Error occured: " << error.ToString() << endl;
	}
	catch (...)
	{
		cout << "Some error occured" << endl;
	}
}