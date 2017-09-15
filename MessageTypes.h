#ifndef MESSAGE_TYPES
#define MESSAGE_TYPES

#include <string>

enum message_type
{
  Msg_HiHoneyImHome,
  Msg_StewReady,
  Msg_EnterSaloon,
  Msg_Fight
};


inline std::string MsgToStr(int msg)
{
  switch (msg)
  {
  case Msg_HiHoneyImHome:
    
    return "HiHoneyImHome"; 

  case Msg_StewReady:
    
    return "StewReady";

  case Msg_EnterSaloon:
    
    return "Someone new in the saloon";

  case Msg_Fight:
    
    return "A fight is begining";

  default:

    return "Not recognized!";
  }
}

#endif