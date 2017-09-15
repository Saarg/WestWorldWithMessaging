#include "Drunkard.h"

bool Drunkard::HandleMessage(const Telegram& msg)
{
  return m_pStateMachine->HandleMessage(msg);
}


void Drunkard::Update()
{
  SetTextColor(FOREGROUND_BLUE| FOREGROUND_INTENSITY);
	
  //do something ?

  m_pStateMachine->Update();
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
