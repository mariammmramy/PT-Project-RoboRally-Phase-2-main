#include "Action.h"
#include"Grid.h"
#include "Input.h"
#include "Output.h"
#include "ToPlayModeAction.h"
ToPlayMode::ToPlayMode(ApplicationManager* pApp) : Action(pApp) {   //Created Constructor

}
ToPlayMode::~ToPlayMode() {  //Created destructor

}
void ToPlayMode::ReadActionParameters() {  //(in progress)
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	pOut->ClearStatusBar();
}
void ToPlayMode::Execute(){    //Switch to play mode (in progress)
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	
	Command savedCommands[5] = { NO_COMMAND };     

	Command availableCommands[COMMANDS_COUNT] = {
		NO_COMMAND, MOVE_FORWARD_ONE_STEP, MOVE_BACKWARD_ONE_STEP, 
		MOVE_FORWARD_TWO_STEPS, MOVE_BACKWARD_TWO_STEPS, 
		MOVE_FORWARD_THREE_STEPS, MOVE_BACKWARD_THREE_STEPS, 
		ROTATE_CLOCKWISE, ROTATE_COUNTERCLOCKWISE,

	}; // Initialize available commands with default options

	pOut->CreatePlayModeToolBar();
	pOut->CreateCommandsBar(savedCommands,5,availableCommands,5);

	pGrid->SetEndGame(false);
	pGrid->UpdateInterface();
}