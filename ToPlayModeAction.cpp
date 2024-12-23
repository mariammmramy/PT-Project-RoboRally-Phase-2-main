#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Action.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"
#include "ToPlayModeAction.h"
#include "Player.h"
ToPlayMode::ToPlayMode(ApplicationManager* pApp) : Action(pApp) {   //Created Constructor

}
ToPlayMode::~ToPlayMode() {  //Created destructor

}
void ToPlayMode::ReadActionParameters() { 
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	pOut->ClearStatusBar();
}
void ToPlayMode::Execute(){    //Switch to play mode 
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Player* pPlayer = pGrid->GetCurrentPlayer();
	Command commands[10] = { NO_COMMAND };
	//get random commands
	
	srand(time(NULL)); //initialize the random seed
	
	int availableCommandNum = pPlayer->GetHealth();
	int savedCommandNum;
	if (pPlayer->GetHealth() >= 5) {
		savedCommandNum = 5;
	}
	else {
		savedCommandNum = pPlayer->GetHealth();

	}
	for (int i = 0; i < availableCommandNum; i++) {
		int RandIndex = rand() % availableCommandNum; //generates a random number between 0 and 7
		commands[i] = availableCommands[RandIndex];
	}

	pOut->CreatePlayModeToolBar();
	pOut->CreateCommandsBar(savedCommands, savedCommandNum,commands, availableCommandNum); //commands bar with random commands
	pOut->PrintMessage("Switched to play mode...");
	pGrid->UpdateInterface();
	pGrid->SetEndGame(false);

}
