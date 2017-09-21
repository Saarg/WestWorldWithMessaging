#include "Miner.h"

bool Miner::HandleMessage(const Telegram& msg)
{
  return m_pStateMachine->HandleMessage(msg);
}


void Miner::Update()
{
	while (true) {
		m_iThirst += 1;
  
		LockConsole();  
		SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);

		m_pStateMachine->Update();
		UnLockConsole();  

		sf::sleep(sf::milliseconds(800));
		
	}
}



void Miner::AddToGoldCarried(const int val)
{
  m_iGoldCarried += val;

  if (m_iGoldCarried < 0) m_iGoldCarried = 0;
}

void Miner::AddToWealth(const int val)
{
  m_iMoneyInBank += val;

  if (m_iMoneyInBank < 0) m_iMoneyInBank = 0;
}

bool Miner::Thirsty()const
{
  if (m_iThirst >= ThirstLevel){return true;}

  return false;
}

bool Miner::Fatigued()const
{
  if (m_iFatigue > TirednessThresholdMiner)
  {
    return true;
  }

  return false;
}
