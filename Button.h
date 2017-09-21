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

class Button
{
public:
	sf::FloatRect* rect;
	sf::RectangleShape shape;
	sf::Font font;
	sf::Text buttonText;
	
public:

	Button( float posX,float posY,float sizeX, float sizeY, std::string text, sf::Color col)
	{
		rect = new sf::FloatRect(sf::Vector2f(posX,posY),sf::Vector2f(sizeX,sizeY));
		shape.setPosition(posX, posY);
		shape.setSize(sf::Vector2f(sizeX,sizeY));
		shape.setFillColor(col);
		if (!font.loadFromFile("arial.ttf"))
			return;
		buttonText = sf::Text(text, font, 25);
		buttonText.setPosition(sf::Vector2f(posX,posY));
	}
	Button::~Button();

	bool CheckCursor(int x, int y){
		sf::Vector2f mousePos((float)x,(float)y);
		if(rect->getGlobalBounds().contains(mousePos)){
			std::cout<<"YOLLLOOO!!!";
			return true;
		}
		std::cout<<"YO2222222!!!";
		return false;
	}

};


#endif
