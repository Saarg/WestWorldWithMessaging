#ifndef MINER_OWNED_STATES_H
#define MINER_OWNED_STATES_H
//------------------------------------------------------------------------
//
//  Name:   MinerOwnedStates.h
//
//  Desc:   All the states that can be assigned to the Miner class.
//          Note that a global state has not been implemented.
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include "fsm/State.h"


class Miner;
struct Telegram;




//------------------------------------------------------------------------
//
//  In this state the miner will walk to a goldmine and pick up a nugget
//  of gold. If the miner already has a nugget of gold he'll change state
//  to VisitBankAndDepositGold. If he gets thirsty he'll change state
//  to QuenchThirst
//------------------------------------------------------------------------
class EnterMineAndDigForNugget : public State<Miner>
{
private:
  
  EnterMineAndDigForNugget(){}

  //copy ctor and assignment should be private
  EnterMineAndDigForNugget(const EnterMineAndDigForNugget&);
  EnterMineAndDigForNugget& operator=(const EnterMineAndDigForNugget&);
 
public:

  //this is a singleton
  static EnterMineAndDigForNugget* Instance();

  virtual void Enter(Miner* miner);

  virtual void Execute(Miner* miner);

  virtual void Exit(Miner* miner);

  virtual bool OnMessage(Miner* agent, const Telegram& msg);

};

//------------------------------------------------------------------------
//
//  Entity will go to a bank and deposit any nuggets he is carrying. If the 
//  miner is subsequently wealthy enough he'll walk home, otherwise he'll
//  keep going to get more gold
//------------------------------------------------------------------------
class VisitBankAndDepositGold : public State<Miner>
{
private:
  
  VisitBankAndDepositGold(){}

  //copy ctor and assignment should be private
  VisitBankAndDepositGold(const VisitBankAndDepositGold&);
  VisitBankAndDepositGold& operator=(const VisitBankAndDepositGold&);
 
public:

  //this is a singleton
  static VisitBankAndDepositGold* Instance();

  virtual void Enter(Miner* miner);

  virtual void Execute(Miner* miner);

  virtual void Exit(Miner* miner);

  virtual bool OnMessage(Miner* agent, const Telegram& msg);
};


//------------------------------------------------------------------------
//
//  miner will go home and sleep until his fatigue is decreased
//  sufficiently
//------------------------------------------------------------------------
class GoHomeAndSleepTilRestedMiner : public State<Miner>
{
private:
  
  GoHomeAndSleepTilRestedMiner(){}

  //copy ctor and assignment should be private
  GoHomeAndSleepTilRestedMiner(const GoHomeAndSleepTilRestedMiner&);
  GoHomeAndSleepTilRestedMiner& operator=(const GoHomeAndSleepTilRestedMiner&);
 
public:

  //this is a singleton
  static GoHomeAndSleepTilRestedMiner* Instance();

  virtual void Enter(Miner* miner);

  virtual void Execute(Miner* miner);

  virtual void Exit(Miner* miner);

  virtual bool OnMessage(Miner* agent, const Telegram& msg);
};


//------------------------------------------------------------------------
//
//  miner changes location to the saloon and keeps buying Whiskey until
//  his thirst is quenched. When satisfied he returns to the goldmine
//  and resumes his quest for nuggets.
//------------------------------------------------------------------------
class QuenchThirst : public State<Miner>
{
private:
  
  QuenchThirst(){}

  //copy ctor and assignment should be private
  QuenchThirst(const QuenchThirst&);
  QuenchThirst& operator=(const QuenchThirst&);
 
public:

  //this is a singleton
  static QuenchThirst* Instance();

  virtual void Enter(Miner* miner);

  virtual void Execute(Miner* miner);

  virtual void Exit(Miner* miner);

  virtual bool OnMessage(Miner* agent, const Telegram& msg);
};


//------------------------------------------------------------------------
//
//  this is implemented as a state blip. The miner eats the stew, gives
//  Elsa some compliments and then returns to his previous state
//------------------------------------------------------------------------
class EatStew : public State<Miner>
{
private:
  
  EatStew(){}

  //copy ctor and assignment should be private
  EatStew(const EatStew&);
  EatStew& operator=(const EatStew&);
 
public:

  //this is a singleton
  static EatStew* Instance();

  virtual void Enter(Miner* miner);

  virtual void Execute(Miner* miner);

  virtual void Exit(Miner* miner);

  virtual bool OnMessage(Miner* agent, const Telegram& msg);
};


class StartAndKeepFightingMiner : public State<Miner>
{
private:
  
  StartAndKeepFightingMiner(){}

  //copy ctor and assignment should be private
  StartAndKeepFightingMiner(const StartAndKeepFightingMiner&);
  StartAndKeepFightingMiner& operator=(const StartAndKeepFightingMiner&);
 
public:

  //this is a singleton
  static StartAndKeepFightingMiner* Instance();

  virtual void Enter(Miner* drunkard);

  virtual void Execute(Miner* drunkard);

  virtual void Exit(Miner* drunkard);

  virtual bool OnMessage(Miner* agent, const Telegram& msg);
};

#endif