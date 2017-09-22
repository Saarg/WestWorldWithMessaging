#include "GUI.h"
#include <string.h>

GUI::GUI(ButtonFunctionManager* btnFunctionManager,Miner* miner, MinersWife* minersWife, Drunkard* drunkard):
	window(nullptr), _isRunning(false), _isExit(false),
	buttonFunctionManager(btnFunctionManager),
	ptr_Miner(miner), ptr_MinersWife(minersWife), ptr_Drunkard(drunkard)
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
	sf::CircleShape circle(200);

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
	sf::CircleShape circle(41);circle.setFillColor(sf::Color(255,0,0,98));
	sf::CircleShape circle2(48);circle2.setFillColor(sf::Color(0,255,0,98));
	sf::CircleShape circle3(45);circle3.setFillColor(sf::Color(0,0,255,98));
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
		//On récupère le nom de l'état courant
		std::string etat1,etat2,etat3;
		etat1 = ptr_Miner->GetFSM()->GetNameOfCurrentState();
		etat2 = ptr_MinersWife->GetFSM()->GetNameOfCurrentState();
		etat3 = ptr_Drunkard->GetFSM()->GetNameOfCurrentState();
		//Tableau de leurs états
		std::string MinerStat[][6] = {"EnterMineAndDigForNugget","VisitBankAndDepositGold","GoHomeAndSleepTilRestedMiner","QuenchThirst","EatStew","StartAndKeepFightingMiner"};
		std::string WifeStat[][3] = {"DoHouseWork","VisitBathroom","CookStew"};
		std::string DrunkardStat[][4] = {"GoBarAndDrink","BecomeDrunkAndAgressive","GoHomeAndSleepTilRestedDrunkard","StartAndKeepFightingDrunkard"};
		//On compare l'état actuel au tableau des états
		//Bob
		if(etat1.compare(MinerStat[0][0]) == 0){
			circle.setPosition(249,198);
			window->draw(circle);
		}
		else{
			if(etat1.compare(MinerStat[0][1]) == 0){
				circle.setPosition(60,251);
				window->draw(circle);
			}
			else{
				if(etat1.compare(MinerStat[0][2]) == 0){
					circle.setPosition(249,325);
					window->draw(circle);
				}
				else{
					if(etat1.compare(MinerStat[0][3]) == 0){
						circle.setPosition(438,198);
						window->draw(circle);
					}
					else{
						if(etat1.compare(MinerStat[0][4]) == 0){
							circle.setPosition(250,435);
							window->draw(circle);
						}
						else{
								circle.setPosition(439,325);
								window->draw(circle);
							}
						}
					}
				}
			}
		//Elsa
		if(etat2.compare(WifeStat[0][0]) == 0){
			circle2.setPosition(921,217);
			window->draw(circle2);
		}
		else{
			if(etat2.compare(WifeStat[0][1]) == 0){
				circle2.setPosition(647,218);
				window->draw(circle2);
			}
			else{
				circle2.setPosition(771,385);
				window->draw(circle2);
			}
		}
		//Drunkard
		if(etat3.compare(DrunkardStat[0][0]) == 0){
			circle3.setPosition(1155,159);
			window->draw(circle3);
		}
		else{
			if(etat3.compare(DrunkardStat[0][1]) == 0){
				circle3.setPosition(1451,159);
				window->draw(circle3);
			}
			else{
				if(etat3.compare(DrunkardStat[0][2]) == 0){
					circle3.setPosition(1292,305);
					window->draw(circle3);
				}
				else{
					circle3.setPosition(1555,305);
					window->draw(circle3);
				}
			}
		}
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
