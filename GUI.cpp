#include "GUI.h"

GUI::GUI(ButtonFunctionManager* btnFunctionManager):
	window(nullptr), _isRunning(false), _isExit(false),
	buttonFunctionManager(btnFunctionManager)	
{
	Start();
	mouseToggleState=true;

	buttons.push_back(buttonPlayPause);
	buttons.push_back(buttonEnterMineAndDigForNugget);
	buttons.push_back(buttonVisitBankAndDepositGold);
	buttons.push_back(buttonQuenchThirst);
	buttons.push_back(buttonGoHomeAndSleepTilRestedMiner);
	buttons.push_back(buttonStartAndKeepFightingMiner);
	buttons.push_back(buttonEatStew);
	buttons.push_back(buttonVisitBathroom);
	buttons.push_back(buttonDoHouseWork);
	buttons.push_back(buttonCookStew);
	buttons.push_back(buttonGoBarAndDrink);
	buttons.push_back(buttonBecameDrunkAndAgressive);
	buttons.push_back(buttonGoHomeAndSleepTilRestedDrunkard);
	buttons.push_back(buttonStartAndKeepFightingDrunkard);

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
	buttonPlayPause = new Button(800,5,150,40,"Play/Pause", sf::Color(100,0,100), std::bind(&ButtonFunctionManager::PlayPauseGame,buttonFunctionManager));
	buttonEnterMineAndDigForNugget = new Button(240,190,90,90,"", sf::Color(100,0,100,0), std::bind(&ButtonFunctionManager::ChangeStateMinerEnterMineAndDigForNugget,buttonFunctionManager));
	buttonVisitBankAndDepositGold = new Button(60,245,90,90,"", sf::Color(100,0,100,0), std::bind(&ButtonFunctionManager::ChangeStateMinerVisitBankAndDepositGold,buttonFunctionManager));
	buttonQuenchThirst = new Button(440,190,90,90,"", sf::Color(100,0,100,0), std::bind(&ButtonFunctionManager::ChangeStateMinerQuenchThirst,buttonFunctionManager));
	buttonGoHomeAndSleepTilRestedMiner = new Button(240,325,90,90,"", sf::Color(100,0,100,0), std::bind(&ButtonFunctionManager::ChangeStateMinerGoHomeAndSleepTilRested,buttonFunctionManager));
	buttonStartAndKeepFightingMiner = new Button(440,325,90,90,"", sf::Color(100,0,100,0), std::bind(&ButtonFunctionManager::ChangeStateMinerStartAndKeepFighting,buttonFunctionManager));
	buttonEatStew = new Button(240,425,90,90,"", sf::Color(100,0,100,0), std::bind(&ButtonFunctionManager::ChangeStateMinerEatStew,buttonFunctionManager));
	buttonVisitBathroom = new Button(645,225,90,90,"", sf::Color(100,0,100,0), std::bind(&ButtonFunctionManager::ChangeStateMinersWifeVisitBathroom,buttonFunctionManager));
	buttonDoHouseWork = new Button(935,225,90,90,"", sf::Color(100,0,100,0), std::bind(&ButtonFunctionManager::ChangeStateMinersWifeDoHouseWork,buttonFunctionManager));
	buttonCookStew = new Button(765,380,90,90,"", sf::Color(100,0,100,0), std::bind(&ButtonFunctionManager::ChangeStateMinersWifeCookStew,buttonFunctionManager));
	buttonGoBarAndDrink = new Button(1155,165,90,90,"", sf::Color(100,0,100,0), std::bind(&ButtonFunctionManager::ChangeStateDrunkardGoBarAndDrink,buttonFunctionManager));
	buttonBecameDrunkAndAgressive = new Button(1450,165,90,90,"", sf::Color(100,0,100,0), std::bind(&ButtonFunctionManager::ChangeStateDrunkardBecameDrunkAndAgressive,buttonFunctionManager));
	buttonGoHomeAndSleepTilRestedDrunkard = new Button(1300,305,90,90,"", sf::Color(100,0,100,0), std::bind(&ButtonFunctionManager::ChangeStateDrunkardGoHomeAndSleepTilRested,buttonFunctionManager));
	buttonStartAndKeepFightingDrunkard = new Button(1555,305,90,90,"", sf::Color(100,0,100,0), std::bind(&ButtonFunctionManager::ChangeStateDrunkardStartAndKeepFighting,buttonFunctionManager));

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
		}

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			if(mouseToggleState == true){
				mouseToggleState=false;
				CheckForButtons();
			}
		}else{
			if(mouseToggleState == false){
				mouseToggleState=true;
			}
		}
		
		// Clean window
		window->clear(sf::Color(255, 255, 255));
		
		//On affiche nos sprites
		//Header
		window->draw(header);
		window->draw(buttonPlayPause->shape);
		window->draw(buttonPlayPause->buttonText);
		
		
		// Graph
		window->draw(SBob);
		window->draw(SElsa);
		window->draw(SJean);

		// Button Graph
		window->draw(buttonEnterMineAndDigForNugget->shape);
		window->draw(buttonVisitBankAndDepositGold->shape);
		window->draw(buttonQuenchThirst->shape);
		window->draw(buttonGoHomeAndSleepTilRestedMiner->shape);
		window->draw(buttonStartAndKeepFightingMiner->shape);
		window->draw(buttonEatStew->shape);
		window->draw(buttonVisitBathroom->shape);
		window->draw(buttonDoHouseWork->shape);
		window->draw(buttonCookStew->shape);
		window->draw(buttonGoBarAndDrink->shape);
		window->draw(buttonBecameDrunkAndAgressive->shape);
		window->draw(buttonGoHomeAndSleepTilRestedDrunkard->shape);
		window->draw(buttonStartAndKeepFightingDrunkard->shape);

		
		//Fin
		window->display();
	}
}

void GUI::CheckForButtons()
{
	for(unsigned int i=0; i<buttons.size(); i++){
		if(buttons[i]->CheckCursor(sf::Mouse::getPosition(*window).x,sf::Mouse::getPosition(*window).y)){
			buttons[i]->ExecuteFunction();
		}
	}
}
