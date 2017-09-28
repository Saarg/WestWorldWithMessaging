#ifndef ENTITY_H
#define ENTITY_H
//------------------------------------------------------------------------
//
//  Name:   BaseGameEntity.h
//
//  Desc:   Base class for a game object
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include <string>
#include <SFML/Graphics.hpp>

#include "messaging/Telegram.h"


class BaseGameEntity
{

protected :
	//every entity must have a unique identifying number
  bool          isUpdating;
  bool			isSendingMsg;

private:

  //every entity must have a unique identifying number
  int          m_ID;

  

  //this is the next valid ID. Each time a BaseGameEntity is instantiated
  //this value is updated
  static int  m_iNextValidID;

  sf::Mutex&  m_logMutex;

  //this must be called within the constructor to make sure the ID is set
  //correctly. It verifies that the value passed to the method is greater
  //or equal to the next valid ID, before setting the ID and incrementing
  //the next valid ID
  void SetID(int val);

public:

  BaseGameEntity(int id, sf::Mutex& logMutex): m_logMutex(logMutex), isUpdating(true)
  {
    SetID(id);
  }

  virtual ~BaseGameEntity(){}

  //all entities must implement an update function
  virtual void  Update()=0;

  //all entities can communicate using messages. They are sent
  //using the MessageDispatcher singleton class
  virtual bool  HandleMessage(const Telegram& msg)=0;

  void ToggleIsUpdating();

  int           ID()const{return m_ID;}  

  void			LockConsole(){ m_logMutex.lock(); }
  void			UnLockConsole(){ m_logMutex.unlock(); }
  bool			GetIsSendingMsg(){return isSendingMsg;}
  void			SetIsSendingMsg(bool state){isSendingMsg=state;}
};



#endif


