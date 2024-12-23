#include "CutAction.h"
#include "Action.h"
#include "GameObject.h"
#include "Input.h"
#include"Output.h"
#include "Grid.h"

CutAction::CutAction(ApplicationManager* pApp) : Action(pApp)
{

}

void CutAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Cut a figure ");

	cutPos = pIn->GetCellClicked();
	GameObject* pObj = pGrid->Getgameobjectfromcell(cutPos);

	if (pObj == NULL)
	{
		pGrid->PrintErrorMessage("There is no game object in this cell to cut. Click to continue...");
		return;
	}

	pOut->ClearStatusBar();
}

void CutAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	GameObject* pObj = pGrid->Getgameobjectfromcell(cutPos); // getting a pointer to the game object in the selected cell

	pGrid->SetClipboard(pObj); // putting that game object in the clipboard
	pGrid->RemoveObjectFromCell(cutPos);
	pOut->PrintMessage("Cut successfully!. Click to continue...");

	pGrid->UpdateInterface();
}

CutAction:: ~CutAction()
{

}