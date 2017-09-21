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
#include "GUI.h"

std::ofstream os;

int main()
{
	//define this to send output to a text file (see locations.h)
#ifdef TEXTOUTPUT
	os.open("output.txt");
#endif

	//seed random number generator
	srand((unsigned) time(NULL));

	//Generate GUI
	GUI* gui = new GUI(true,false);
	
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

	while(gui->_isExit != true){};

	bobThread.terminate();
	elsaThread.terminate();
	jeanThread.terminate();

	//tidy up
	delete Bob;
	delete Elsa;
	delete Jean;

	//wait for a keypress before exiting
	PressAnyKeyToContinue();

	return 0;
}








