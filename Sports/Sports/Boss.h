#ifndef Boss_H
#define Boss_H

#include "EquipmentWarehouse.h"


class Boss
{
	friend class BossMenu;
private:
	static EquipmentWarehouse storage;
public:
	double GetCurrentAmountOfMoney();

	void AddSeveralEquipments(Equipment& Equipment, int quanity);
	void AddSeveralEquipmentsViaOverload(int quantity);
	void RemoveSeveralEquipmentsViaOverload(int quantity);
	void RemoveEquipmentsByBrand(string brand);
	void RemoveEquipmentsBykind(string kind);
	void ReplaceEquipment(Equipment& Equipment, int idx);

	const Equipment CreateAndReturnEquipment();

	bool BrandIsInStock(string brand);
	bool kindIsInStock(string kind);
};

#endif // !BOSS_H