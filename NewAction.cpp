#include "NewAction.h"
#include "Player.h"
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"
#include "DeleteAction.h"
NewAction::NewAction(ApplicationManager* pApp) : Action(pApp) {   //Created Constructor

}
void NewAction::ReadActionParameters() {  //
    // Get a Pointer to the Input / Output Interfaces
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();
    pOut->PrintMessage("Starting a new game... Click anywhere to confirm.");
    int x, y;
    pIn->GetPointClicked(x, y); // wait for user to click anywhere
    pOut->ClearStatusBar();

}
void NewAction::Execute() {
    ReadActionParameters();
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    Player* pPlayer1 = pGrid->GetCurrentPlayer();
    Player* pPlayer2 = pGrid->GetOppositePlayer();
    Command commands[5] = { NO_COMMAND,NO_COMMAND,NO_COMMAND,NO_COMMAND,NO_COMMAND };  //initialise saved commands

    /*reset player health, direction and moved commands*/
    if (pPlayer1) {
        pPlayer1->ClearDrawing(pOut);
        pPlayer1->SetHealth(10);
        pPlayer1->SetDirection(RIGHT);
        pPlayer1->SetSavedCommands(commands, 5);
        pPlayer1->sethackdevice(0);
        pPlayer1->settoolkit(0);
    }    
    if (pPlayer2) {
        pPlayer2->ClearDrawing(pOut);
        pPlayer2->SetHealth(10);
        pPlayer2->SetDirection(RIGHT);
        pPlayer2->SetSavedCommands(commands, 5);
        pPlayer2->sethackdevice(0);
        pPlayer2->settoolkit(0);

    }
    
     //code to delete game objects from cells 
    //for (int i = 0; i < NumVerticalCells; ++i) {
    //    for (int j = 0; j < NumHorizontalCells; ++j) {
    //        CellPosition cellPos(i, j);
    //        if (pGrid->Getgameobjectfromcell(cellPos)) {
    //            pGrid->RemoveObjectFromCell(cellPos); //delete each game object in cell
    //        }
    //    }
    //}

    //clear status bar
    pOut->ClearStatusBar();
    
    //clear commands bar
    pOut->ClearCommandsBar();

    //clear grid area
    pOut->ClearGridArea();

    //update user interface
    pGrid->UpdateInterface();

    pGrid->SetEndGame(false);

}


NewAction::~NewAction() {  //Created destructor

}
