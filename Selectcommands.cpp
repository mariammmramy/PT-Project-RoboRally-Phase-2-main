#include "Selectcommands.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Action.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"
#include "ToPlayModeAction.h"

Selectcommands::Selectcommands(ApplicationManager* pApp) : Action(pApp)
{
	
}

void Selectcommands::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pPlayer = pGrid->GetCurrentPlayer();

	health = pPlayer->GetHealth();

}
void Selectcommands::Execute()
{
	ReadActionParameters(); // call read action parameters
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	

	if (health <= 0)
	{
		pGrid->PrintErrorMessage("Game has already ended or not started yet, Click to continue...");
		return;
	}
	if (!pPlayer->GetMovement())
	{
		pGrid->PrintErrorMessage("This player cannot play this round click to continue");
		pPlayer->SetMovement(true);
		pGrid->AdvanceCurrentPlayer();
	}
	Command* commands = new Command[health];
	for (int i = 0; i < health; i++)
	{
		commands[i] = NO_COMMAND;
	}


	srand(time(NULL)); //initialize the random seed

	for (int i = 0; i < health; i++) {
		int RandIndex = rand() % 8; //generates a random number between 0 and 8
		commands[i] = availableCommands[RandIndex];
	}

	int numsaved = pPlayer->getnumsavedcommands();
	if (numsaved > health)
	{
		numsaved = health;

	}
	pOut->CreateCommandsBar(savedCommands, numsaved, commands, health);

	int iteration = min(health,numsaved);


	for (int i = 0; i < iteration; i++)
	{
		int x = -1, y = -1;
		pIn->GetPointClicked(x, y);
		int clickedItemOrder;



		clickedItemOrder = pIn->GetSelectedCommandIndex();
		
	
		// after this if function, you have the item number that was clicked from the available commands
		
		savedCommands[i] = (commands[clickedItemOrder]);
		commands[clickedItemOrder] = NO_COMMAND;
		pOut->CreateCommandsBar(savedCommands, numsaved, commands, health);
	}

	pPlayer->SetSavedCommands(savedCommands, iteration);
}

Selectcommands::~Selectcommands()
{
}
