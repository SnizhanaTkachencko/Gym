#include "Boss.h"

EquipmentWarehouse Boss::storage = {};

void Boss::AddSeveralEquipments(Equipment& Equipment, int quanity)
{
	for (int i = 0; i < quanity; i++)
	{
		if (storage.GetSize() >= storage.GetMaxCapacity())
			throw Error(ErrorCode::MaxSizeReached);
		storage.AddEquipment(Equipment);
	}
}

void Boss::AddSeveralEquipmentsViaOverload(int quantity)
{
	storage = storage + quantity;
}

void Boss::RemoveSeveralEquipmentsViaOverload(int quantity)
{
	storage = storage - quantity;
}

void Boss::RemoveEquipmentsByBrand(string brand)
{
	for (int i = 0; i < storage.GetSize(); i++)
	{
		if (storage.GetEquipmentBrand(i) == brand)
		{
			storage.RemoveEquipment(i);
			i--;
		}
	}
}

void Boss::RemoveEquipmentsBykind(string kind)
{
	for (int i = 0; i < storage.GetSize(); i++)
	{
		if (storage.GetEquipmentkind(i) == kind)
		{
			storage.RemoveEquipment(i);
			i--;
		}
	}
}

void Boss::ReplaceEquipment(Equipment& Equipment, int idx)
{
	if (idx < 0 || idx >= storage.GetSize())
		throw Error(ErrorCode::IndexOutsideLimit);

	//storage.GetEquipmentByIndex(idx) = Equipment;
	storage[idx] = Equipment;
}

const Equipment Boss::CreateAndReturnEquipment()
{
	/*string brand, kind;
	double price;
	cout << "\nBrand:\n";
	cin.ignore();
	getline(cin, brand);
	cout << "kind:\n";
	getline(cin, kind);
	cout << "Price:\n";
	cin >> price;
	Equipment Equipment(brand, kind, price);*/

	Equipment Equipment;
	cin >> Equipment;

	return Equipment;
}

bool Boss::BrandIsInStock(string brand)
{
	for (int i = 0; i < storage.GetSize(); i++)
	{
		if (storage.GetEquipmentBrand(i) == brand)
			return true;
	}
	return false;
}

bool Boss::kindIsInStock(string kind)
{
	for (int i = 0; i < storage.GetSize(); i++)
	{
		if (storage.GetEquipmentkind(i) == kind)
			return true;
	}
	return false;
}
