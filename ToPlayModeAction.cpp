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
void ToPlayMode::ReadActionParameters() {  //(in progress)
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	pOut->ClearStatusBar();
}
void ToPlayMode::Execute(){    //Switch to play mode (in progress)
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Player* pPlayer = pGrid->GetCurrentPlayer();

	//get random commands
	
	srand(time(NULL)); //initialize the random seed

	for (int i = 0; i < 5; i++) {
		int RandIndex = rand() % 9; //generates a random number between 0 and 8
		savedCommands[i] = availableCommands[RandIndex];
	}

	pOut->CreatePlayModeToolBar();
	pOut->CreateCommandsBar(savedCommands,5,availableCommands,5); //commands bar with random commands
	pPlayer->SetSavedCommands(savedCommands, 5);  //initialise saved commands in player
	pGrid->UpdateInterface();
}
