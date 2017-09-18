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
  sf::RenderWindow window(sf::VideoMode(800, 600), "TP1 - Bob, Elsa & Jean");
  window.setActive(false);

  sf::Thread thread(&RenderingLoop, &window);
  thread.launch();

  //seed random number generator
  srand((unsigned) time(NULL));

  //create a miner
  Miner* Bob = new Miner(ent_Miner_Bob);

  //create his wife
  MinersWife* Elsa = new MinersWife(ent_Elsa);

  //create Drunkard
  Drunkard* Jean = new Drunkard(ent_Jean);

  //register them with the entity manager
  EntityMgr->RegisterEntity(Bob);
  EntityMgr->RegisterEntity(Elsa);
  EntityMgr->RegisterEntity(Jean);
  while (window.isOpen())
  {
    Bob->Update();
    Elsa->Update();
	Jean->Update();

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








