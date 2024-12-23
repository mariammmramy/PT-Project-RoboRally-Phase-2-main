#include "CopyAction.h"

#include "Action.h"
#include "GameObject.h"
#include "Input.h"
#include"Output.h"
#include "Grid.h"

CopyAction::CopyAction(ApplicationManager* pApp) : Action(pApp)
{

}

void CopyAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Copy a figure ");

	copyPos = pIn->GetCellClicked();
	GameObject* pObj = pGrid->Getgameobjectfromcell(copyPos);

	if (pObj == NULL)
	{
		pGrid->PrintErrorMessage("There is no game object in this cell to copy. Click to continue...");
		return;
	}

	pOut->ClearStatusBar();
}

void CopyAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	GameObject* pObj = pGrid->Getgameobjectfromcell(copyPos); // getting a pointer to the game object in the selected cell

	pGrid->SetClipboard(pObj); // putting that game object in the clipboard
	pOut->PrintMessage("Copied successfully!. Click to continue...");

	pGrid->UpdateInterface();
}

CopyAction:: ~CopyAction()
{

}