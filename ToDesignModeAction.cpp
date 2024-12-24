#include "ToDesignModeAction.h"
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"
ToDesignModeAction::ToDesignModeAction(ApplicationManager* pApp) : Action(pApp) {   //Created Constructor

}
void ToDesignModeAction::ReadActionParameters() {  
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Game is ended! Switching to Design Mode... Click anywhere to confirm.");
	int x, y;
	pIn->GetPointClicked(x, y); // wait for user to click anywhere
	pOut->ClearStatusBar();

}
void ToDesignModeAction::Execute() {    //Switch to Design mode 
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	//code to delete game objects from cells 
   for (int i = 0; i < NumVerticalCells; ++i) {
       for (int j = 0; j < NumHorizontalCells; ++j) {
           CellPosition cellPos(i, j);
           if (pGrid->Getgameobjectfromcell(cellPos)) {
               pGrid->RemoveObjectFromCell(cellPos); //delete each game object in cell
           }
       }
   }

	pOut->ClearCommandsBar();
	pOut->CreateDesignModeToolBar();  

	pGrid->UpdateInterface();  
	pGrid->SetEndGame(true);
}
ToDesignModeAction::~ToDesignModeAction() {  //Created destructor

}