#ifndef BUTTON_H
#define BUTTON_H
//------------------------------------------------------------------------
//
//  Name:   Button.h
//
//  Desc:   A class defining the GUI.
//
//------------------------------------------------------------------------
#include <string>
#include <cassert>
#include <iostream>

#include <SFML/Graphics.hpp>

typedef std::function<void (void)> vFunctionCall;

class Button
{
public:
	sf::IntRect rect;
	sf::RectangleShape shape;
	sf::Font font;
	sf::Text buttonText;
	//void (*funcToCallOnPress)();
	vFunctionCall func;

public:

	Button( float posX,float posY,float sizeX, float sizeY, std::string text, sf::Color col, vFunctionCall tmpFunc) :
	  func(tmpFunc)
	{
		rect.left = (int)posX;
		rect.top = (int)posY;
		rect.width = (int)sizeX;
		rect.height = (int)sizeY;
		shape.setPosition(posX, posY);
		shape.setSize(sf::Vector2f(sizeX,sizeY));
		shape.setFillColor(col);
		shape.setTextureRect(rect);
		if (!font.loadFromFile("arial.ttf"))
			return;
		buttonText = sf::Text(text, font, 25);
		buttonText.setPosition(sf::Vector2f(posX,posY));
	}
	Button::~Button();

	bool CheckCursor(int x, int y){
		sf::Vector2i mousePos(x,y);
		if(shape.getTextureRect().contains(mousePos)){
			return true;
		}
		return false;
	}

	void ExecuteFunction(){
		func();
	}

};


#endif
