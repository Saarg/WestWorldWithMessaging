#include "MinersWife.h"

bool MinersWife::HandleMessage(const Telegram& msg)
{
  return m_pStateMachine->HandleMessage(msg);
}


void MinersWife::Update()
{
  while (true) {
		LockConsole(); 
		SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		m_pStateMachine->Update();
		UnLockConsole(); 

		sf::sleep(sf::milliseconds(800));
	}
}