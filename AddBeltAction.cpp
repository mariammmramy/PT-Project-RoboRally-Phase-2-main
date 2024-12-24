#include "AddBeltAction.h"

AddBeltAction::AddBeltAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}


void AddBeltAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Belt: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Belt: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	// Clear messages
	pOut->ClearStatusBar();
}

void AddBeltAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	if ((startPos.VCell() == 4 && startPos.HCell() == 0) || (endPos.VCell() == 4 && endPos.HCell() == 0))
	{
		pGrid->PrintErrorMessage("You can't put a game object in the first cell");
		return;
	}
	if (!startPos.IsValidCell())
	{
		pGrid->PrintErrorMessage("The Start Cell is invalid");
		return;
	}
	if (!endPos.IsValidCell())
	{
		pGrid->PrintErrorMessage("The End Cell is invalid");
		return;
	}
	if ((startPos.VCell() != endPos.VCell()) && (startPos.HCell() != endPos.HCell()))
	{
		pGrid->PrintErrorMessage("The Belt Must be On Same Column or Row!");
		return;
	}
	if (pGrid->isBeltOverlap(startPos, endPos))
	{
		pGrid->PrintErrorMessage("Belts Must not be Overlapping or Starting after one another!");
		return;
	}

	// Create a belt object with the parameters read from the user
	Belt* pBelt = new Belt(startPos, endPos);

	bool added = pGrid->AddObjectToCell(pBelt);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the belt is created and added to the GameObject of its Cell, so we finished executing the AddBeltAction
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Added successfully!.");
}

AddBeltAction::~AddBeltAction()
{
}