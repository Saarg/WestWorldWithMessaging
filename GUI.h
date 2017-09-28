#ifndef GUI_H
#define GUI_H
//------------------------------------------------------------------------
//
//  Name:   GUI.h
//
//  Desc:   A class defining the GUI.
//
//------------------------------------------------------------------------
#include <string>
#include <cassert>
#include <iostream>
#include <functional>

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "ButtonFunctionManager.h"

class GUI
{
public:

	sf::RenderWindow *window;
	sf::Thread* ptr_GUIThread;
	ButtonFunctionManager* buttonFunctionManager;
	std::vector<Button*> buttons;
	bool mouseToggleState;
	Miner* ptr_Miner;
	MinersWife* ptr_MinersWife;
	Drunkard* ptr_Drunkard;


	//GUI state
	bool _isRunning;
	bool _isExit;

	//GUI items Header
	sf::RectangleShape header;
	Button* buttonPlayPause;
	Button* buttonEnterMineAndDigForNugget;
	Button* buttonVisitBankAndDepositGold;
	Button* buttonQuenchThirst;
	Button* buttonGoHomeAndSleepTilRestedMiner;
	Button* buttonStartAndKeepFightingMiner;
	Button* buttonEatStew;
	Button* buttonVisitBathroom;
	Button* buttonDoHouseWork;
	Button* buttonCookStew;
	Button* buttonGoBarAndDrink;
	Button* buttonBecameDrunkAndAgressive;
	Button* buttonGoHomeAndSleepTilRestedDrunkard;
	Button* buttonStartAndKeepFightingDrunkard;

	sf::Texture msgTexture;
	sf::Sprite msgSpriteBob;
	sf::Sprite msgSpriteElsa;
	sf::Sprite msgSpriteJean;

	sf::Texture SM_Bob;
	sf::Texture SM_Elsa;
	sf::Texture SM_Jean;

	sf::Sprite SBob;
	sf::Sprite SElsa; 
	sf::Sprite SJean; 

public:

	GUI(ButtonFunctionManager* buttonFunctionManager,Miner* ptr_Miner, MinersWife* ptr_MinersWife, Drunkard* ptr_Drunkard);
	GUI::~GUI();

	void Start();
	void Update(); 
	void CheckForButtons();

	static void test(){std::cout<<"GOOOOD";}

};


#endif
