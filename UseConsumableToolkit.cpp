#include "UseConsumableToolkit.h"
#include "Player.h"
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"
UseConsumableToolkit::UseConsumableToolkit(ApplicationManager* pApp) : Action(pApp) {   //Created Constructor

}
void UseConsumableToolkit::ReadActionParameters() {  //
    // Get a Pointer to the Input / Output Interfaces
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();
   
    Player* pPlayer = pGrid->GetCurrentPlayer();
    if (!pPlayer->gettoolkit())
    {
        pGrid->PrintErrorMessage("You don't own any tool kits yet. Click to continue...");
        return;
    }
    pOut->ClearStatusBar();

}
void UseConsumableToolkit::Execute() {
    ReadActionParameters();
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

   
    Player* pPlayer = pGrid->GetCurrentPlayer();
    pPlayer->SetHealth(10);
    pPlayer->settoolkit(0);

    //clear status bar
    pOut->ClearStatusBar();


    //update user interface
    pGrid->UpdateInterface();


}


UseConsumableToolkit::~UseConsumableToolkit(){  //Created destructor
}
