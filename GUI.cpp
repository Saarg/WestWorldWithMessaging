#include "GUI.h"

GUI::GUI(bool isRunning, bool isExit):window(nullptr), _isRunning(isRunning), _isExit(isExit)                               
{
	Start();
	ptr_GUIThread = new sf::Thread(&GUI::Update, this);
	ptr_GUIThread->launch();
}

GUI::~GUI()
{
	ptr_GUIThread->terminate();
	delete ptr_GUIThread;
}

void GUI::Start()
{
	window = new sf::RenderWindow(sf::VideoMode(1700, 600),"TP1 - Bob, Elsa & Jean");

	// Header
	header.setSize(sf::Vector2f(1700, 50));
	header.setFillColor(sf::Color(100, 100, 100));
	// On gère le button "Play/Pause"
	buttonPlayPause = new Button(800,5,150,40,"Play/Pause", sf::Color(100,0,100));
	/*start.setSize(sf::Vector2f(150, 40));
	start.setPosition(sf::Vector2f(800,5));
	start.setFillColor(sf::Color(150, 150, 150));	
	sf::Font* font = new sf::Font();
	if (!font->loadFromFile("arial.ttf"))
		return;
	startText = sf::Text("Play/Pause", *font, 25);
	startText.setPosition(sf::Vector2f(810,8));*/

	// Graphs
	//On load les textures
	SM_Bob.loadFromFile("FSM-MinerBob.png");
	SM_Elsa.loadFromFile("FSM-WifeElsa.png");
	SM_Jean.loadFromFile("FSM-Drunkard.png");
	//On crée les sprites et on les lisses
	SBob.setTexture(SM_Bob); SM_Bob.setSmooth(true);
	SElsa.setTexture(SM_Elsa); SM_Elsa.setSmooth(true);
	SJean.setTexture(SM_Jean); SM_Jean.setSmooth(true);
	//On les places correctement
	SBob.setPosition(sf::Vector2f(50,100));
	SElsa.setPosition(sf::Vector2f(600, 100));
	SJean.setPosition(sf::Vector2f(1150, 100));
}

void GUI::Update()
{
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
			if(event.type == sf::Event::MouseButtonPressed){
				
			}
		}

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			std::cout<<"slkgfbdlfglsdfgsdfgsldf";
				CheckForButtons();
		}
		
		// Clean window
		window->clear(sf::Color(255, 255, 255));
		
		//On affiche nos sprites
		//Header
		window->draw(header);
		window->draw(buttonPlayPause->sprite);
		window->draw(buttonPlayPause->shape);
		window->draw(buttonPlayPause->buttonText);
		
		// Graph
		window->draw(SBob);
		window->draw(SElsa);
		window->draw(SJean);

		// CurrentState

		//Fin
		
		window->display();
		sf::sleep(sf::milliseconds(800));
	}
}

void GUI::CheckForButtons()
{
	buttonPlayPause->CheckCursor(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y);
}
