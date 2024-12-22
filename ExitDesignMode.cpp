#include "ExitDesignMode.h"
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"
ExitDesignMode::ExitDesignMode(ApplicationManager* pApp):Action(pApp) {
	
}
void ExitDesignMode:: ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();     //Output pointer
	Input* pIn = pGrid->GetInput();        //Input pointer 

	pOut->PrintMessage(" Select this option to close the application ");
}
void ExitDesignMode:: Execute() {
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->ClearStatusBar();
    pOut->ClearCommandsBar();
	pOut->ClearGridArea();
}
ExitDesignMode:: ~ExitDesignMode() {

}