<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
#include "DeleteAction.h"
#include "Action.h"
#include "GameObject.h"
#include "Input.h"
#include"Output.h"
#include "Grid.h"

<<<<<<< Updated upstream
deleteAction::deleteAction(ApplicationManager* pApp) : Action(pApp)
{
	deletePos = NULL;

}

void deleteAction::ReadActionParameters()
=======
DeleteAction::DeleteAction(ApplicationManager* pApp) : Action(pApp)
{
	deletePos = NULL;
}

void DeleteAction::ReadActionParameters()
>>>>>>> Stashed changes
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
<<<<<<< Updated upstream
	pOut->PrintMessage("Delete a figure ");

	deletePos = pIn->GetCellClicked();


}

void deleteAction::Execute()
=======
	pOut->PrintMessage("Delete a figure");


	deletePos = pIn->GetCellClicked();
	if (pGrid->Getgameobjectfromcell(deletePos) == NULL)
	{
		pGrid->PrintErrorMessage("No Gameobject existing in this cell Click to continue...");
	}

	pOut->ClearStatusBar();
}

void DeleteAction::Execute()
>>>>>>> Stashed changes
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
<<<<<<< Updated upstream
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pGrid->RemoveObjectFromCell(deletePos);
	pGrid->UpdateInterface();
=======


	pGrid->RemoveObjectFromCell(deletePos);

	pGrid->UpdateInterface();

>>>>>>> Stashed changes
}