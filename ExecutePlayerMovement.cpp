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

    pPlayer = pGrid->GetCurrentPlayer();
    health = pPlayer->GetHealth();

}
void ExecutePlayerMovement::Execute() {
    ReadActionParameters();
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    if (!pPlayer||health<=0) {
        pGrid->PrintErrorMessage("No player found. Click to continue...");
        return;
    }

    Command commands[5];
    pPlayer->GetSavedCommands(commands);

    if (commands[0]==NO_COMMAND) {   //check if commands are done yet or not
        pGrid->PrintErrorMessage("No saved commands to execute. Click to continue...");
        return;
    }
    pPlayer->Move(pGrid,commands);   //execute move after validation of health player and commands
    pGrid->UpdateInterface();
}


ExecutePlayerMovement::~ExecutePlayerMovement(){  //Created destructor

}
