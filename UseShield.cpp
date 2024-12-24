#include"UseShield.h"
#include "Player.h"
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"
UseShield::UseShield(ApplicationManager* pApp) : Action(pApp) {   //Created Constructor

}
void UseShield::ReadActionParameters() {  //
    // Get a Pointer to the Input / Output Interfaces
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    Player* pPlayer = pGrid->GetCurrentPlayer();
    if (!pPlayer->GetShield())
    {
        pGrid->PrintErrorMessage("You don't own any shield yet. Click to continue...");
        return;
    }
    pOut->ClearStatusBar();

}
void UseShield::Execute() {
    ReadActionParameters();
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();


    Player* pPlayer = pGrid->GetCurrentPlayer();

    //clear status bar
    pOut->ClearStatusBar();


    //update user interface
    pGrid->UpdateInterface();


}


UseShield::~UseShield() {  //Created destructor
}
