#include "ToPlayModeAction.h"
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"
ToPlayModeAction::ToPlayModeAction(ApplicationManager* pApp) : Action(pApp) {   //Created Constructor

}
ToPlayModeAction::~ToPlayModeAction() {  //Created destructor

}
void ToPlayModeAction::ReadActionParameters() {  //(in progress)
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	pOut->ClearStatusBar();
}
void ToPlayModeAction::Execute(){    //Switch to play mode (in progress)
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	pOut->CreatePlayModeToolBar();

}