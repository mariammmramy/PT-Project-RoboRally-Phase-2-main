
#include "DeleteAction.h"
#include "Action.h"
#include "GameObject.h"
#include "Input.h"
#include"Output.h"
#include "Grid.h"

DeleteAction::DeleteAction(ApplicationManager* pApp) : Action(pApp)
{

}

void DeleteAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Delete a figure ");

	deletePos = pIn->GetCellClicked();
	GameObject* pObj = pGrid->Getgameobjectfromcell(deletePos);

	if (pObj == NULL)
	{
		pGrid->PrintErrorMessage("There is no game object in this cell to delete. Click to continue...");
		return;
	}

	pOut->ClearStatusBar();
}

void DeleteAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pGrid->RemoveObjectFromCell(deletePos);
	pGrid->UpdateInterface();
}