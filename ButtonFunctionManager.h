#ifndef BUTTONFUNCTIONMANAGER_H
#define BUTTONFUNCTIONMANAGER_H
//------------------------------------------------------------------------
//
//  Name:   ButtonFunctionManager.h
//
//  Desc:   Implements all function related to button event.
//
//------------------------------------------------------------------------
#include <string>
#include <cassert>
#include <iostream>

#include "Miner.h"
#include "MinersWife.h"
#include "Drunkard.h"

class ButtonFunctionManager
{
public :

	Miner* ptr_Miner;
	MinersWife* ptr_MinersWife;
	Drunkard* ptr_Drunkard;

public:

	ButtonFunctionManager(Miner* miner, MinersWife* minersWife, Drunkard* drunkard);
	~ButtonFunctionManager();

	void PlayPauseGame();

	void ChangeStateMinerEnterMineAndDigForNugget();
	void ChangeStateMinerVisitBankAndDepositGold();
	void ChangeStateMinerQuenchThirst();
	void ChangeStateMinerGoHomeAndSleepTilRested();
	void ChangeStateMinerStartAndKeepFighting();
	void ButtonFunctionManager::ChangeStateMinerEatStew();

	void ChangeStateMinersWifeVisitBathroom();
	void ChangeStateMinersWifeDoHouseWork();
	void ChangeStateMinersWifeCookStew();

	void ChangeStateDrunkardGoBarAndDrink();
	void ChangeStateDrunkardBecameDrunkAndAgressive();
	void ChangeStateDrunkardGoHomeAndSleepTilRested();
	void ChangeStateDrunkardStartAndKeepFighting();

};


#endif
