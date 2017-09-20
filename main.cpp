#include <fstream>
#include <time.h>

#include "Locations.h"
#include "Miner.h"
#include "MinersWife.h"
#include "Drunkard.h"
#include "EntityManager.h"
#include "MessageDispatcher.h"
#include "misc/ConsoleUtils.h"
#include "EntityNames.h"

#include <SFML/Graphics.hpp>

std::ofstream os;
sf::RenderWindow *window = nullptr;

void WindowParameters()
{
	window = new sf::RenderWindow(sf::VideoMode(1700, 600),"TP1 - Bob, Elsa & Jean");
	while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
		window->clear(sf::Color(0, 0, 0));
		//Debut
		//On load les textures
		sf::Texture SM_Bob;SM_Bob.loadFromFile("FSM-MinerBob.jpg");
		sf::Texture SM_Elsa;SM_Elsa.loadFromFile("FSM-WifeElsa.jpg");
		sf::Texture SM_Jean;SM_Jean.loadFromFile("FSM-Drunkard.jpg");
		//On crée les sprites et on les lisses
		sf::Sprite SBob; SBob.setTexture(SM_Bob); SM_Bob.setSmooth(true);
		sf::Sprite SElsa; SElsa.setTexture(SM_Elsa); SM_Elsa.setSmooth(true);
		sf::Sprite SJean; SJean.setTexture(SM_Jean); SM_Jean.setSmooth(true);
		//On les places correctement
		SBob.setPosition(sf::Vector2f(50,0));
		SElsa.setPosition(sf::Vector2f(600, 0));;
		SJean.setPosition(sf::Vector2f(1150, 0));;
		//On affiche nos sprites
		window->draw(SBob);
		window->draw(SElsa);
		window->draw(SJean);
		//Fin 
		window->display();
    }
}


void RenderingLoop(sf::RenderWindow* window)
{
	while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

		window->clear(sf::Color(220, 220, 220));

		window->display();
    }
}

int main()
{
//define this to send output to a text file (see locations.h)
#ifdef TEXTOUTPUT
  os.open("output.txt");
#endif

  //GUI
  sf::Thread thread(WindowParameters);
  thread.launch();

  //seed random number generator
  srand((unsigned) time(NULL));

  //create a miner
  Miner* Bob = new Miner(ent_Miner_Bob, Dispatch->GetLogMutex());

  //create his wife
  MinersWife* Elsa = new MinersWife(ent_Elsa, Dispatch->GetLogMutex());

  //create Drunkard
  Drunkard* Jean = new Drunkard(ent_Jean, Dispatch->GetLogMutex());

  //register them with the entity manager
  EntityMgr->RegisterEntity(Bob);
  EntityMgr->RegisterEntity(Elsa);
  EntityMgr->RegisterEntity(Jean);

  sf::Thread bobThread(&Miner::Update, Bob);
  sf::Thread elsaThread(&MinersWife::Update, Elsa);
  sf::Thread jeanThread(&Drunkard::Update, Jean);

  // Launch all agents
  bobThread.launch();
  elsaThread.launch();
  jeanThread.launch();

  for (;;)
  {
    //dispatch any delayed messages
    Dispatch->DispatchDelayedMessages();

    Sleep(800);
  }

  //tidy up
  delete Bob;
  delete Elsa;
  delete Jean;

  //wait for a keypress before exiting
  PressAnyKeyToContinue();

  return 0;
}








