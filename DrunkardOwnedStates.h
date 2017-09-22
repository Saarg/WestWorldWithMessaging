#ifndef DRUNKARD_OWNED_STATES_H
#define DRUNKARD_OWNED_STATES_H
//------------------------------------------------------------------------
//
//  Name:   DRUNKARD_OWNED_STATES.h
//
//  Desc:   All the states that can be assigned to the Miner class.
//          Note that a global state has not been implemented.
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include "fsm/State.h"


class Drunkard;
struct Telegram;




//------------------------------------------------------------------------
//
//  In this state the miner will walk to a goldmine and pick up a nugget
//  of gold. If the miner already has a nugget of gold he'll change state
//  to VisitBankAndDepositGold. If he gets thirsty he'll change state
//  to QuenchThirst
//------------------------------------------------------------------------
class GoBarAndDrink : public State<Drunkard>
{
private:
  
  GoBarAndDrink(){}

  //copy ctor and assignment should be private
  GoBarAndDrink(const GoBarAndDrink&);
  GoBarAndDrink& operator=(const GoBarAndDrink&);
 
public:

  //this is a singleton
  static GoBarAndDrink* Instance();

  virtual void Enter(Drunkard* drunkard);

  virtual void Execute(Drunkard* drunkard);

  virtual void Exit(Drunkard* drunkard);

  virtual bool OnMessage(Drunkard* agent, const Telegram& msg);

};

//------------------------------------------------------------------------
//
//  Drunkard becomes drunks
//
//------------------------------------------------------------------------
class BecomeDrunkAndAgressive : public State<Drunkard>
{
private:
  
  BecomeDrunkAndAgressive(){}

  //copy ctor and assignment should be private
  BecomeDrunkAndAgressive(const BecomeDrunkAndAgressive&);
  BecomeDrunkAndAgressive& operator=(const BecomeDrunkAndAgressive&);
 
public:

  //this is a singleton
  static BecomeDrunkAndAgressive* Instance();

  virtual void Enter(Drunkard* drunkard);

  virtual void Execute(Drunkard* drunkard);

  virtual void Exit(Drunkard* drunkard);

  virtual bool OnMessage(Drunkard* agent, const Telegram& msg);
};


//------------------------------------------------------------------------
//
//  drunkard will go home and sleep until his fatigue is decreased
//  sufficiently
//------------------------------------------------------------------------
class GoHomeAndSleepTilRestedDrunkard : public State<Drunkard>
{
private:
  
  GoHomeAndSleepTilRestedDrunkard(){}

  //copy ctor and assignment should be private
  GoHomeAndSleepTilRestedDrunkard(const GoHomeAndSleepTilRestedDrunkard&);
  GoHomeAndSleepTilRestedDrunkard& operator=(const GoHomeAndSleepTilRestedDrunkard&);
 
public:

  //this is a singleton
  static GoHomeAndSleepTilRestedDrunkard* Instance();

  virtual void Enter(Drunkard* miner);

  virtual void Execute(Drunkard* miner);

  virtual void Exit(Drunkard* miner);

  virtual bool OnMessage(Drunkard* agent, const Telegram& msg);
};


//------------------------------------------------------------------------
//
//  miner changes location to the saloon and keeps buying Whiskey until
//  his thirst is quenched. When satisfied he returns to the goldmine
//  and resumes his quest for nuggets.
//------------------------------------------------------------------------
class StartAndKeepFightingDrunkard : public State<Drunkard>
{
private:
  
  StartAndKeepFightingDrunkard(){}

  //copy ctor and assignment should be private
  StartAndKeepFightingDrunkard(const StartAndKeepFightingDrunkard&);
  StartAndKeepFightingDrunkard& operator=(const StartAndKeepFightingDrunkard&);
 
public:

  //this is a singleton
  static StartAndKeepFightingDrunkard* Instance();

  virtual void Enter(Drunkard* drunkard);

  virtual void Execute(Drunkard* drunkard);

  virtual void Exit(Drunkard* drunkard);

  virtual bool OnMessage(Drunkard* agent, const Telegram& msg);
};

#endif