#include "Drunkard.h"

bool Drunkard::HandleMessage(const Telegram& msg)
{
	return m_pStateMachine->HandleMessage(msg);
}


void Drunkard::Update()
{
	isUpdating=true;
	while (true) {
		if(isUpdating){
			LockConsole();  
			SetTextColor(FOREGROUND_BLUE| FOREGROUND_INTENSITY);

			m_pStateMachine->Update();
			UnLockConsole(); 

			sf::sleep(sf::milliseconds(1500));
			isSendingMsg=false;
		}
	}
}



bool Drunkard::Drunk()const
{
	if (m_AlcoholLevel > AlcoholThreshold)
	{
		return true;
	}

	return false;
}

bool Drunkard::Sober()const
{
	if (m_AlcoholLevel <= 0)
	{
		return true;
	}

	return false;
}

bool Drunkard::Fatigued()const
{
	if (m_iFatigue > TirednessThreshold)
	{
		return true;
	}

	return false;
}
