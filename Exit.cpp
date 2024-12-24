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
	Input* pIn = pGrid->GetInput();//Input pointer 
	int x, y;
	pOut->PrintMessage("Exiting the application. All progress will be lost. Click anywhere to confirm.");
	pIn->GetPointClicked(x,y); // Wait for user confirmation
	pOut->ClearStatusBar(); // Clear the status bar after confirmation
	
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