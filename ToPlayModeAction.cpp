#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Action.h"
#include"Grid.h"
#include "Input.h"
#include "Output.h"
#include "ToPlayModeAction.h"
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
<<<<<<< Updated upstream

	//get random commands
	
	srand(time(NULL)); //initialize the random seed

	Command availableCommands[COMMANDS_COUNT] = {
		NO_COMMAND, MOVE_FORWARD_ONE_STEP, MOVE_BACKWARD_ONE_STEP, 
		MOVE_FORWARD_TWO_STEPS, MOVE_BACKWARD_TWO_STEPS, 
		MOVE_FORWARD_THREE_STEPS, MOVE_BACKWARD_THREE_STEPS, 
		ROTATE_CLOCKWISE, ROTATE_COUNTERCLOCKWISE,

	}; // Initialize available commands

	Command savedCommands[5];

	for (int i = 0; i < 5; i++) {
		int RandIndex = rand() % 9; //generates a random number between 0 and 8
		savedCommands[i] = availableCommands[RandIndex];
	}


	pOut->CreatePlayModeToolBar();
	pOut->CreateCommandsBar(savedCommands,5,availableCommands,5); //commands bar with random commands
=======
	Player* pPlayer = pGrid->GetCurrentPlayer();
	
	pOut->CreatePlayModeToolBar();
	pPlayer->Draw(pOut);
	std::string playerInfo = "Player " + std::to_string(pPlayer->Getplayernum()) + "'s Turn";
	pOut->PrintMessage(playerInfo);
	pOut->PrintMessage("Switched to play mode...");
	pGrid->UpdateInterface();
	pGrid->SetEndGame(false);
>>>>>>> Stashed changes

	pGrid->SetEndGame(false);
	pGrid->UpdateInterface();
}