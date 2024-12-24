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

	CellPosition testPos = pIn->GetCellClicked();

	if (testPos.IsValidCell())
	{
		copyPos = testPos;
	}
	else
	{
		pGrid->PrintErrorMessage("Invalid cell, Click to continue...");
		copyPos.SetHCell(0);
		copyPos.SetVCell(4);
		return;
	}

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

	if (copyPos.HCell() == 0 && copyPos.VCell() == 4)
	{
		return;
	}
	GameObject* pObj = pGrid->Getgameobjectfromcell(copyPos); // getting a pointer to the game object in the selected cell
	GameObject* pNewObj = pObj;

	pGrid->SetClipboard(pNewObj); // putting that game object in the clipboard
	pOut->PrintMessage("Copied successfully!. Click to continue...");

	pGrid->UpdateInterface();
}

CopyAction:: ~CopyAction()
{

}