#include "ExecutePlayerMovement.h"
#include "Player.h"
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"
#include "ToPlayModeAction.h"
ExecutePlayerMovement::ExecutePlayerMovement(ApplicationManager* pApp) : Action(pApp) {   //Created Constructor

}
void ExecutePlayerMovement::ReadActionParameters() {  //
    // Get a Pointer to the Input / Output Interfaces
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    pOut->ClearStatusBar();
}
void ExecutePlayerMovement::Execute() {
    ReadActionParameters();
    Grid* pGrid = pManager->GetGrid();
    Player* pPlayer = pGrid->GetCurrentPlayer();
    ToPlayMode* pPlay; //pointer to get commands in play mode
    Command commands[5];
    commands[5] = pPlay->GetSavedCommands(); //save commands in array
    pPlayer->Move(pGrid,commands);   //execute move
}


ExecutePlayerMovement::~ExecutePlayerMovement(){  //Created destructor

}
