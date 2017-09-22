#include "ButtonFunctionManager.h"

ButtonFunctionManager::ButtonFunctionManager(Miner* miner, MinersWife* minersWife, Drunkard* drunkard):
ptr_Miner(miner), ptr_MinersWife(minersWife), ptr_Drunkard(drunkard)
{

}


ButtonFunctionManager::~ButtonFunctionManager()
{

}

void ButtonFunctionManager::PlayPauseGame(){
	ptr_Miner->ToggleIsUpdating();
	ptr_MinersWife->ToggleIsUpdating();
	ptr_Drunkard->ToggleIsUpdating();
	std::cout<<"\n\n //////////////////////////////// \n Play/Pause \n //////////////////////////////// \n";
}

void ButtonFunctionManager::ChangeStateMinerEnterMineAndDigForNugget(){
	ptr_Miner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
	std::cout<<"\n\n //////////////////////////////// \n Miner state changed to	EnterMineAndDigForNugget \n //////////////////////////////// \n";
}

void ButtonFunctionManager::ChangeStateMinerVisitBankAndDepositGold(){
	ptr_Miner->GetFSM()->ChangeState(VisitBankAndDepositGold::Instance());
	std::cout<<"\n\n //////////////////////////////// \n Miner state changed to VisitBankAndDepositGold \n //////////////////////////////// \n";
}

void ButtonFunctionManager::ChangeStateMinerQuenchThirst(){
	ptr_Miner->GetFSM()->ChangeState(QuenchThirst::Instance());
	std::cout<<"\n\n //////////////////////////////// \n Miner state changed to QuenchThirst \n //////////////////////////////// \n";
}

void ButtonFunctionManager::ChangeStateMinerGoHomeAndSleepTilRested(){
	ptr_Miner->GetFSM()->ChangeState(GoHomeAndSleepTilRestedMiner::Instance());
	std::cout<<"\n\n //////////////////////////////// \n Miner state changed to GoHomeAndSleepTilRested \n //////////////////////////////// \n";
}

void ButtonFunctionManager::ChangeStateMinerStartAndKeepFighting(){
	ptr_Miner->GetFSM()->ChangeState(StartAndKeepFightingMiner::Instance());
	std::cout<<"\n\n //////////////////////////////// \n Miner state changed to StartAndKeepFighting \n //////////////////////////////// \n";
}

void ButtonFunctionManager::ChangeStateMinerEatStew(){
	ptr_Miner->GetFSM()->ChangeState(EatStew::Instance());
	std::cout<<"\n\n //////////////////////////////// \n Miner state changed to EatStew \n //////////////////////////////// \n";
}

void ButtonFunctionManager::ChangeStateMinersWifeVisitBathroom(){
	ptr_MinersWife->GetFSM()->ChangeState(VisitBathroom::Instance());
	std::cout<<"\n\n //////////////////////////////// \n MinersWife state changed to VisitBathroom \n //////////////////////////////// \n";
}

void ButtonFunctionManager::ChangeStateMinersWifeDoHouseWork(){
	ptr_MinersWife->GetFSM()->ChangeState(DoHouseWork::Instance());
	std::cout<<"\n\n //////////////////////////////// \n MinersWife state changed to DoHouseWork \n //////////////////////////////// \n";
}

void ButtonFunctionManager::ChangeStateMinersWifeCookStew(){
	ptr_MinersWife->GetFSM()->ChangeState(CookStew::Instance());
	std::cout<<"\n\n //////////////////////////////// \n MinersWife state changed to CookStew \n //////////////////////////////// \n";
}

void ButtonFunctionManager::ChangeStateDrunkardGoBarAndDrink(){
	ptr_Drunkard->GetFSM()->ChangeState(GoBarAndDrink::Instance());
	std::cout<<"\n\n //////////////////////////////// \n Drunkard state changed to GoBarAndDrink \n //////////////////////////////// \n";
}

void ButtonFunctionManager::ChangeStateDrunkardBecameDrunkAndAgressive(){
	ptr_Drunkard->GetFSM()->ChangeState(BecomeDrunkAndAgressive::Instance());
	std::cout<<"\n\n //////////////////////////////// \n Drunkard state changed to BecameDrunkAndAgressive \n //////////////////////////////// \n";
}

void ButtonFunctionManager::ChangeStateDrunkardGoHomeAndSleepTilRested(){
	ptr_Drunkard->GetFSM()->ChangeState(GoHomeAndSleepTilRestedDrunkard::Instance());
	std::cout<<"\n\n //////////////////////////////// \n Drunkard state changed to GoHomeAndSleepTilRested \n //////////////////////////////// \n";
}

void ButtonFunctionManager::ChangeStateDrunkardStartAndKeepFighting(){
	ptr_Drunkard->GetFSM()->ChangeState(StartAndKeepFightingDrunkard::Instance());
	std::cout<<"\n\n //////////////////////////////// \n Drunkard state changed to StartAndKeepFighting \n //////////////////////////////// \n";
}