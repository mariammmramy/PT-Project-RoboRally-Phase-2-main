#include "PasteAction.h"
#include "Action.h"
#include "GameObject.h"
#include "Input.h"
#include"Output.h"
#include "Grid.h"

PasteAction::PasteAction(ApplicationManager* pApp) : Action(pApp)
{

}

void PasteAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Paste a figure ");

	pastePos = pIn->GetCellClicked();
	GameObject* pObj = pGrid->GetClipboard();

	if (pObj == NULL)
	{
		pGrid->PrintErrorMessage("There is no game object in the clipboard to paste. Click to continue...");
		return;
	}

	pOut->ClearStatusBar();
}

void PasteAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();



	GameObject* testobj = pGrid->Getgameobjectfromcell(pastePos);

	if (testobj)
	{
		pGrid->PrintErrorMessage("Cell already has another game object, click to continue...");
		return;
	}

	GameObject* pObj = pGrid->GetClipboard();	// getting a pointer to the game object in the selected cell
	CellPosition oldpos = pObj->GetPosition();

	GameObject* pNewObj = pObj;

	pNewObj->SetPosition(pastePos);
	
	pGrid->AddObjectToCell(pNewObj);


	pOut->PrintMessage("Pasted successfully!. Click to continue...");

	pGrid->UpdateInterface();
}

PasteAction:: ~PasteAction()
{

}