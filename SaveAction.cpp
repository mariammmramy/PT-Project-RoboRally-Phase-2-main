#include "SaveAction.h"

#include "Grid.h"
#include <iostream>
#include <fstream>



SaveAction::SaveAction(ApplicationManager* pApp) : Action(pApp)
{
}
void SaveAction::ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Enter file name ");
	Filename = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();

}
void SaveAction::Execute() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	ReadActionParameters();

	ofstream OutFile(Filename);
	if (!OutFile.is_open()) {
		pOut->PrintMessage("Could not open file to save the grid");
		pOut->ClearStatusBar();
		return;
	}

	pGrid->SaveAll(OutFile, Flags);
	pGrid->SaveAll(OutFile, WaterPits);
	pGrid->SaveAll(OutFile, DangerZones);
	pGrid->SaveAll(OutFile, Belts);
	pGrid->SaveAll(OutFile, Workshops);
	pGrid->SaveAll(OutFile, Antennas);
	pGrid->SaveAll(OutFile, RotatingGears);

	OutFile.close();
	pOut->PrintMessage("Saving file, Click to continue...");
	int x, y;
	pIn->GetPointClicked(x, y);
	
	pOut->PrintMessage("Grid was saved to " + Filename + ", Click to continue...");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();


}

SaveAction::~SaveAction()
{
}