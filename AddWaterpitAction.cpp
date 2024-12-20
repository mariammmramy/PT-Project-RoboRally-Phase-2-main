#include "AddWaterpitAction.h"


AddWaterpitAction::AddWaterpitAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}


void AddWaterpitAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	/* Implemented same method in AddBeltAction */
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();    //Output pointer
	Input* pIn = pGrid->GetInput();       //Input pointer 

	// 2- Read the WaterpitPos

	pOut->PrintMessage("New WaterPit: Click on the cell to add a WaterPit ...");
	WaterpitPos = pIn->GetCellClicked();

	
	// 4- Make the needed validations on the read parameters

<<<<<<< Updated upstream
	if (WaterpitPos.VCell() == WaterpitPos.HCell() == 0)
=======
	if (WaterpitPos.VCell() == 4 && WaterpitPos.HCell() == 0)
>>>>>>> Stashed changes
	{
		pOut->PrintMessage("You can't put a game object in the first cell");
		return;
	}



	// 5- Clear status bar
	pOut->ClearStatusBar();   //Use output pointer to clear status bar
}

void AddWaterpitAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1-Create a Waterpit object
	WaterPit* pWater = new WaterPit(WaterpitPos);

	// 2-get a pointer to the Grid from the ApplicationManager
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	// 3-Add the water pit object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pWater);

	// 4-Check if the waterpit was added and print an errror message if waterpit couldn't be added
	if (!added)
	{
		pOut->PrintMessage("Waterpit couldn't be added");
	}

}

AddWaterpitAction::~AddWaterpitAction()
{
}