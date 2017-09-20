#ifndef DRUNKARD_H
#define DRUNKARD_H
//------------------------------------------------------------------------
//
//  Name:   Drunkard.h
//
//  Desc:   A class defining a goldminer.
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include <string>
#include <cassert>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "BaseGameEntity.h"
#include "Locations.h"
#include "misc/ConsoleUtils.h"
#include "DrunkardOwnedStates.h"
#include "fsm/StateMachine.h"

template <class entity_type> class State; //pre-fixed with "template <class entity_type> " for vs8 compatibility

struct Telegram;

//the amount of drink the drunkard need to enter drunk mode
const int AlcoholThreshold       = 5;

//above this value a drunkard is sleepy
const int TirednessThreshold = 5;

class Drunkard : public BaseGameEntity
{
private:

  //an instance of the state machine class
  StateMachine<Drunkard>*  m_pStateMachine;
  
  location_type         m_Location;

  //how many nuggets the miner has in his pockets
  int                   m_AlcoholLevel;

  //the higher the value, the more tired the drunkard
  int                   m_iFatigue;
  
public:

  Drunkard(int id, sf::Mutex& logMutex):m_Location(drunkardShack),
                          m_AlcoholLevel(0),
						  m_iFatigue(0),
                          BaseGameEntity(id, logMutex)
                               
  {
    //set up state machine
    m_pStateMachine = new StateMachine<Drunkard>(this);
    
    m_pStateMachine->SetCurrentState(GoHomeAndSleepTilRested::Instance());

    /* NOTE, A GLOBAL STATE HAS NOT BEEN IMPLEMENTED FOR THE MINER */
  }

  ~Drunkard(){delete m_pStateMachine;}

  //this must be implemented
  void Update();

  //so must this
  virtual bool  HandleMessage(const Telegram& msg);

  
  StateMachine<Drunkard>* GetFSM()const{return m_pStateMachine;}


  
  //-------------------------------------------------------------accessors
  location_type Location()const{return m_Location;}
  void          ChangeLocation(location_type loc){m_Location=loc;}
    
  bool          Drunk()const;
  bool          Sober()const;
  void          DecreaseAlcoholLevel(){m_AlcoholLevel -= 1;}
  void          IncreaseAlcoholLevel(){m_AlcoholLevel += 1;}

  bool          Fatigued()const;
  void          DecreaseFatigue(){m_iFatigue -= 1;}
  void          IncreaseFatigue(){m_iFatigue += 1;}

};



#endif
