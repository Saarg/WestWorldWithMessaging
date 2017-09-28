#include "MinersWife.h"

bool MinersWife::HandleMessage(const Telegram& msg)
{
	return m_pStateMachine->HandleMessage(msg);
}


void MinersWife::Update()
{
	isUpdating=true;
	while (true) {
		if(isUpdating){
			LockConsole(); 
			SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);

			m_pStateMachine->Update();
			UnLockConsole(); 

			sf::sleep(sf::milliseconds(1500));
			isSendingMsg=false;
		}
	}
}