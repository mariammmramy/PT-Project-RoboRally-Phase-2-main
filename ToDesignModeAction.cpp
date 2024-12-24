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


	pOut->ClearStatusBar();
}
void ToDesignModeAction::Execute() {    //Switch to Design mode 
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	pOut->ClearCommandsBar();
	pOut->CreateDesignModeToolBar();  

	pGrid->UpdateInterface();  
	pGrid->SetEndGame(false);
}
ToDesignModeAction::~ToDesignModeAction() {  //Created destructor

}