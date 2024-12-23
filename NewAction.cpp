#include "NewAction.h"
#include "Player.h"
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"
NewAction::NewAction(ApplicationManager* pApp) : Action(pApp) {   //Created Constructor

}
void NewAction::ReadActionParameters() {  //
    // Get a Pointer to the Input / Output Interfaces
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    pOut->ClearStatusBar();
}
void NewAction::Execute() {
    ReadActionParameters();
    Grid* pGrid = pManager->GetGrid();
    Player* pPlayer = pGrid->GetCurrentPlayer();
    
}


NewAction::~NewAction() {  //Created destructor

}
