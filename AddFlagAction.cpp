#include "AddFlagAction.h"



AddFlagAction::AddFlagAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}


void AddFlagAction::ReadActionParameters()
{



	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	// 2- Read the flagPos

	pOut->PrintMessage("New Flag: Click on the cell to add a flag ...");


	flagPos = pIn->GetCellClicked();

	if (!flagPos.IsValidCell())
	{
		pGrid->PrintErrorMessage("Invalid cell please select a valid cell.");
		return;
	}
	if (pGrid->flagfound())
	{
		pGrid->PrintErrorMessage("A flag already exists .You can't add another one");
		flagPos.SetVCell(-5);
		return;
	}

	


	// 5- Clear status bar

	pOut->ClearStatusBar();

}


void AddFlagAction::Execute()
{

	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// get a pointer to the Grid from the ApplicationManager
	Grid* pGrid = pManager->GetGrid();



	// 1-Create a flag object
	if (flagPos.VCell() == -5)
	{
		return;
	}

	Flag* pFlag = new Flag(flagPos);

	// 3-Add the flag object to the GameObject of its Cell:
	// 4-Check if the flag was added and print an errror message if flag couldn't be added
	bool addflag = pGrid->AddObjectToCell(pFlag);
	if (!addflag)
	{
		delete pFlag;
		pGrid->PrintErrorMessage("Error! cell already has an object");
	}
	Output* pOut = pGrid->GetOutput();
	pGrid->UpdateInterface();
	pOut->PrintMessage("Added successfully!.");
}

AddFlagAction::~AddFlagAction()
{
}