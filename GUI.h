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

#include <SFML/Graphics.hpp>
#include "Button.h"

class GUI
{
public:

	sf::RenderWindow *window;
	sf::Thread* ptr_GUIThread;

	//GUI state
	bool _isRunning;
	bool _isExit;

	//GUI items Header
	sf::RectangleShape header;
	Button* buttonPlayPause;

	sf::Texture SM_Bob;
	sf::Texture SM_Elsa;
	sf::Texture SM_Jean;

	sf::Sprite SBob;
	sf::Sprite SElsa; 
	sf::Sprite SJean; 

public:

	GUI(bool isRunning, bool isExit);
	GUI::~GUI();

	void Start();
	void Update(); 
	void CheckForButtons();

};


#endif
