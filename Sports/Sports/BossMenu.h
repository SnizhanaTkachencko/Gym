#ifndef BossMENU_H
#define BossMENU_H

#include <memory>
#include "Boss.h"

class BossMenu
{
public:
	void ShowMainBossMenu();
private:
	Boss Boss;
	//EquipmentWarehouse storage;
	void showBossMenu();

	void executeAddEquipmentMenu();
	void executeAddSeveralEquipmentsMenu();
	void executeRemoveEquipmentMenu();
	void executeRemoveSeveralLastEquipmentsMenu();
	void executeRemoveByBrandMenu();
	void executeRemoveBykindMenu();
	void executeReplaceEquipmentMenu();

	void handleBossInput(char BossInput);
	void safeHandleBossInput(char BossInput);
};

#endif // !BOSSMENU_H