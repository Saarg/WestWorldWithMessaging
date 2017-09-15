#include "DrunkardOwnedStates.h"
#include "fsm/State.h"
#include "Drunkard.h"
#include "Locations.h"
#include "messaging/Telegram.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "Time/CrudeTimer.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;


#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif


//------------------------------------------------------------------------methods for EnterMineAndDigForNugget
GoBarAndDrink* GoBarAndDrink::Instance()
{
  static GoBarAndDrink instance;

  return &instance;
}


void GoBarAndDrink::Enter(Drunkard* pDrunkard)
{
  if (pDrunkard->Location() != saloon)
  {
    cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": " << "Going to the bar. Just for one drink .. Promise ..";

    pDrunkard->ChangeLocation(saloon);
  }
}


void GoBarAndDrink::Execute(Drunkard* pDrunkard)
{  
  pDrunkard->IncreaseAlcoholLevel();
  cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": " << "Drinking a whiskey";

  if (pDrunkard->Drunk())
  {
    pDrunkard->GetFSM()->ChangeState(BecomeDrunkAndAgressive::Instance());
  }


}


void GoBarAndDrink::Exit(Drunkard* pDrunkard)
{

}


bool GoBarAndDrink::OnMessage(Drunkard* pDrunkard, const Telegram& msg)
{
  SetTextColor(BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);

  switch(msg.Msg)
  {
    case Msg_EnterSaloon:
    {
      cout << "\nMessage received by " << GetNameOfEntity(msg.Sender) <<
           " at time: " << Clock->GetCurrentTime();

      SetTextColor(FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	  cout << "\n" << GetNameOfEntity(msg.Receiver) << ": Hi " << GetNameOfEntity(msg.Sender) << "!";
    }

    return true;

  }//end switch

  return false;
}

//------------------------------------------------------------------------methods for BecomeDrunkAndAgressive

BecomeDrunkAndAgressive* BecomeDrunkAndAgressive::Instance()
{
  static BecomeDrunkAndAgressive instance;

  return &instance;
}

void BecomeDrunkAndAgressive::Enter(Drunkard* pDrunkard)
{  
  cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": " << "Feelin' ready to fight";
  cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": " << "U pussies !! Got no balls !!! MADAFAKA!!";
}


void BecomeDrunkAndAgressive::Execute(Drunkard* pDrunkard)
{   
  pDrunkard->IncreaseFatigue();
  cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": " << "is looking for a fight...";

  //if Ben is here : start fighting
  /*if (pDrunkard->Thirsty())
  {
    pDrunkard->GetFSM()->ChangeState(QuenchThirst::Instance());
  }*/
  
  //if enough tired, go to sleep
  if (pDrunkard->Fatigued())
  {
    pDrunkard->GetFSM()->ChangeState(GoHomeAndSleepTilRested::Instance());
  }
}


void BecomeDrunkAndAgressive::Exit(Drunkard* pDrunkard)
{
  // cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": " << "Leavin' the bar cause none wanna fight";
}


bool BecomeDrunkAndAgressive::OnMessage(Drunkard* pDrunkard, const Telegram& msg)
{
  SetTextColor(BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);

  switch(msg.Msg)
  {
    case Msg_EnterSaloon:
    {
      cout << "\nMessage received by " << GetNameOfEntity(msg.Sender) <<
           " at time: " << Clock->GetCurrentTime();

      SetTextColor(FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	  cout << "\n" << GetNameOfEntity(msg.Receiver) << ": I want to fight you " << GetNameOfEntity(msg.Sender) << "!"; 

	  Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, //time delay
                              pDrunkard->ID(),        //ID of sender
                              ent_Miner_Bob,            //ID of recipient
                              Msg_Fight,   //the message
                              NO_ADDITIONAL_INFO); 

	  pDrunkard->GetFSM()->ChangeState(StartAndKeepFighting::Instance());

    }

    return true;

  }//end switch

  return false;
}
//------------------------------------------------------------------------methods for StartAndKeepFighting

GoHomeAndSleepTilRested* GoHomeAndSleepTilRested::Instance()
{
  static GoHomeAndSleepTilRested instance;

  return &instance;
}

void GoHomeAndSleepTilRested::Enter(Drunkard* pDrunkard)
{
  if (pDrunkard->Location() != drunkardShack)
  {
	SetTextColor(FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": " << "Walkin' home";

    pDrunkard->ChangeLocation(drunkardShack); 
  }
}

void GoHomeAndSleepTilRested::Execute(Drunkard* pDrunkard)
{ 
  //if Drunkard is not fatigued start to dig for nuggets again.
	if (!pDrunkard->Fatigued() && pDrunkard->Sober())
  {
     SetTextColor(FOREGROUND_BLUE|FOREGROUND_INTENSITY);
     cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": " 
          << "All mah fatigue has drained away. Ready for another wonderful day !";

     pDrunkard->GetFSM()->ChangeState(GoBarAndDrink::Instance());
  }

  else 
  {
    //sleep
    pDrunkard->DecreaseFatigue();
	pDrunkard->DecreaseAlcoholLevel();

	SetTextColor(FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": " << "ZZZZ... ";
  } 
}

void GoHomeAndSleepTilRested::Exit(Drunkard* pDrunkard)
{ 
}


bool GoHomeAndSleepTilRested::OnMessage(Drunkard* pDrunkard, const Telegram& msg)
{
   return false; //send message to global message handler
}

//------------------------------------------------------------------------StartAndKeepFighting

StartAndKeepFighting* StartAndKeepFighting::Instance()
{
  static StartAndKeepFighting instance;

  return &instance;
}

void StartAndKeepFighting::Enter(Drunkard* pDrunkard)
{
	SetTextColor(FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": " << "I gonna rekt ur ass dude !";
}

void StartAndKeepFighting::Execute(Drunkard* pDrunkard)
{
  //pDrunkard->HitBob();
  SetTextColor(FOREGROUND_BLUE|FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": " << "Smashing Bob";

  // if( BobIsKO || DrunkardIsKO)
  pDrunkard->GetFSM()->ChangeState(GoHomeAndSleepTilRested::Instance());  
}


void StartAndKeepFighting::Exit(Drunkard* pDrunkard)
{ 
  SetTextColor(FOREGROUND_BLUE|FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(pDrunkard->ID()) << ": " << "That was a good fight !";
}


bool StartAndKeepFighting::OnMessage(Drunkard* pDrunkard, const Telegram& msg)
{
  //send msg to global message handler
  return false;
}

