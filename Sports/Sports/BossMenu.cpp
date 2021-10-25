#include "BossMenu.h"

void BossMenu::ShowMainBossMenu()
{
	char BossInput;

	do {
		showBossMenu();
		cin >> BossInput;
		safeHandleBossInput(BossInput);

		cout << endl;
	} while (BossInput != '0');
}

void BossMenu::showBossMenu()
{
	cout << "\nYou are the Boss of a Gym\"Tears of fat\".\n";
	cout << "Please select an option:\n";
	cout << "1 -> Add new Equipment\n";
	cout << "2 -> Add several identical Equipments\n";
	cout << "3 -> Remove an existing Equipment\n";
	cout << "4 -> Remove several last Equipments\n";
	cout << "5 -> Remove all Equipments of a certain brand\n";
	cout << "6 -> Remove all Equipments of a certain kind\n";
	cout << "7 -> Replace an existing Equipment\n";
	cout << "p -> Print all Equipments to console\n";
	cout << "0 -> Exit Boss menu\n\n";
}

void BossMenu::executeAddEquipmentMenu()
{
	Equipment Equipment(Boss.CreateAndReturnEquipment());
	Boss::storage.AddEquipment(Equipment);

	cout << "\nEquipment was successfully added!\n\n";
}

void BossMenu::executeAddSeveralEquipmentsMenu()
{
	int quantity;
	cout << "\nHow many identical Equipments do you want to add?\n";
	cin >> quantity;

	/*Equipment Equipment(Boss.CreateAndReturnEquipment());
	Boss.AddSeveralEquipments(Equipment, quantity);*/

	Boss.AddSeveralEquipmentsViaOverload(quantity);

	cout << "\nSeveral identical Equipments were successfully added!\n\n";
}

void BossMenu::executeRemoveEquipmentMenu()
{
	int idx;
	cout << "\nEnter Equipment id:\n";
	cin >> idx;

	Boss::storage.RemoveEquipment(idx);
	cout << "\nEquipment was successfully removed\n\n";
}

void BossMenu::executeRemoveSeveralLastEquipmentsMenu()
{
	int quantity;
	cout << "\nHow many Equipments from the end do you want to remove?\n";
	cin >> quantity;

	Boss.RemoveSeveralEquipmentsViaOverload(quantity);

	cout << "\nSeveral Equipments from the end were successfully removed!\n\n";
}

void BossMenu::executeRemoveByBrandMenu()
{
	string brand;
	cout << "\nEnter the brand:\n";
	cin.ignore();
	getline(cin, brand);

	if (Boss.BrandIsInStock(brand))
	{
		Boss.RemoveEquipmentsByBrand(brand);
		cout << "\nEquipments of brand " << brand << " were successfully removed\n\n";
	}
	else
	{
		throw Error(ErrorCode::UnknownBrand);
	}
}

void BossMenu::executeRemoveBykindMenu()
{
	string kind;
	cout << "\nEnter the kind of the Equipment:\n";
	cin.ignore();
	getline(cin, kind);

	if (Boss.kindIsInStock(kind))
	{
		Boss.RemoveEquipmentsBykind(kind);
		cout << "\n kind of Equipments: " << kind << " - were successfully removed\n\n";
	}
	else
	{
		throw Error(ErrorCode::Unknownkind);
	}
}

void BossMenu::executeReplaceEquipmentMenu()
{
	int idx;
	cout << "\nEnter id of the Equipment you want to replace:\n";
	cin >> idx;

	Equipment Equipment(Boss.CreateAndReturnEquipment());
	Boss.ReplaceEquipment(Equipment, idx);
}

void BossMenu::handleBossInput(char BossInput)
{
	switch (BossInput)
	{
	case '1':
		executeAddEquipmentMenu();
		break;
	case '2':
		executeAddSeveralEquipmentsMenu();
		break;
	case '3':
		executeRemoveEquipmentMenu();
		break;
	case '4':
		executeRemoveSeveralLastEquipmentsMenu();
		break;
	case '5':
		executeRemoveByBrandMenu();
		break;
	case '6':
		executeRemoveBykindMenu();
		break;
	case '7':
		executeReplaceEquipmentMenu();
		break;
	case 'p':
		Boss::storage.PrintEquipments();
		cout << endl;
		break;
	case '0':
		break;
	default:
		cout << "Wrong command selected.\n";
		break;
	}
}

void BossMenu::safeHandleBossInput(char BossInput)
{
	try
	{
		handleBossInput(BossInput);
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