#include "AddRotatingGearAction.h"

AddRotatingGearAction::AddRotatingGearAction(ApplicationManager * pApp, bool direction):Action(pApp)
{
	clockwise = direction;
}

void AddRotatingGearAction::ReadActionParameters()
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();    //Output pointer
	Input* pIn = pGrid->GetInput();       //Input pointer 


	// 2- Read the gearPos

	pOut->PrintMessage("New Rotating Gear: Click on the cell to add a Rotating Gear...");
	gearPos = pIn->GetCellClicked();
	// 3- Read whether the direction will be clockwise or not
	// (Done in the constructor)

	// 4- Make the needed validations on the read parameters
	if (gearPos.HCell() == 0 && gearPos.VCell() == 4)
	{
		pOut->PrintMessage("You can't put a game object in the first cell");
		return;
	}


	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void AddRotatingGearAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1-Create a rotating gear object
	RotatingGear* pGear = new RotatingGear(gearPos, clockwise);
	Grid* pGrid = pManager->GetGrid();

	// 2-get a pointer to the Grid from the ApplicationManager
	

	// 3-Add the rotating object to the GameObject of its Cell:
	
	bool added = pGrid->AddObjectToCell(pGear);

	// 4-Check if the Rotatinggear was added and print an errror message if rotating gear couldn't be added
	if (!added)
	{
		pGrid->PrintErrorMessage("Rotating gear couldn't be added");
	}
	// 4-Check if the rotating gear was added and print an errror message if flag couldn't be added
}


AddRotatingGearAction::~AddRotatingGearAction()
{
}
