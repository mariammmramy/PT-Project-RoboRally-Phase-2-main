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
	
	pOut->CreatePlayModeToolBar();
	pPlayer->Draw(pOut);
	std::string playerInfo = "Player " + std::to_string(pPlayer->Getplayernum()) + "'s Turn";
	pOut->PrintMessage(playerInfo);
	pOut->PrintMessage("Switched to play mode...");
	pGrid->UpdateInterface();
	pGrid->SetEndGame(false);
	
}
