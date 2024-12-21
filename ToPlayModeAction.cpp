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
	/*ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	pOut->CreatePlayModeToolBar();*/

}
void ToPlayModeAction::ExecuteAction(ActionType ActType) {

	Action* pAct = NULL;

	// According to Action Type, create the corresponding action in play mode
	//in progress
	switch (ActType)
	{
	case(REBOOT):
		//pAct->
		break;
	case(USE_TOOLKIT):
		break;
	case(USE_HACK):
		break;
	case(NEW):
		break;
	case(EXITP):
		break; 
	}
	// Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}