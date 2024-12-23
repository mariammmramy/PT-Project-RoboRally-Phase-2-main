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
	pOut->CreateCommandsBar(savedCommands, numsaved, commands, health);

	int iteration;
	if (health >= numsaved)
	{
		iteration = numsaved;
	}
	else
	{
		iteration = health;
	}

	for (int i = 0; i < iteration; i++)
	{
		int x = -1, y = -1;
		pIn->GetPointClicked(x, y);
		int clickedItemOrder = 999;

		if (y >= (UI.height - UI.CommandsBarHeight + UI.AvailableCommandsYOffset) && y < (UI.AvailableCommandsYOffset))
		{
			float availableCommandWidth = UI.CommandItemWidth / 2;
			if (x >= UI.AvailableCommandsXOffset && x < UI.AvailableCommandsXOffset + (health * availableCommandWidth))
			{
				clickedItemOrder = ((x-UI.AvailableCommandsXOffset) / availableCommandWidth);
			}
			else
			{
				pGrid->PrintErrorMessage("Invalid x coordinate");
			}
			
		}
		else
		{
			pGrid->PrintErrorMessage("Invalid y coordinate");
		}
		// after this if function, you have the item number that was clicked from the available commands

		savedCommands[i] = (availableCommands[clickedItemOrder]);
		pOut->CreateCommandsBar(savedCommands, 5, availableCommands, health);
	}

	pPlayer->SetSavedCommands(savedCommands, iteration);
}

Selectcommands::~Selectcommands()
{
}
