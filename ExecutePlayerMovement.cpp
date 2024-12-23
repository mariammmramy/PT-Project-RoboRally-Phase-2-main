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
    Output* pOut = pGrid->GetOutput();
    Player* pPlayer = pGrid->GetCurrentPlayer();
    Command* commands = pPlayer->GetSavedCommands();
    if (commands==NULL) {
        pOut->PrintMessage("Cannot fetch play mode commands.");
        return;
    }

    pPlayer->Move(pGrid,commands);   //execute move
    pGrid->UpdateInterface();
}


ExecutePlayerMovement::~ExecutePlayerMovement(){  //Created destructor

}
