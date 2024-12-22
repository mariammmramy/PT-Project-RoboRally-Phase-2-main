#include "Exit.h"
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"
Exit::Exit(ApplicationManager* pApp):Action(pApp) {
	
}
void Exit:: ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();     //Output pointer
	Input* pIn = pGrid->GetInput();        //Input pointer 

	pOut->PrintMessage(" Select this option to close the application ");
}
void Exit:: Execute() {
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->ClearStatusBar();
    pOut->ClearCommandsBar();
	pOut->ClearGridArea();
}
Exit:: ~Exit() {

}