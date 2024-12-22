
#include "DeleteAction.h"
#include "Action.h"
#include "GameObject.h"
#include "Input.h"
#include"Output.h"
#include "Grid.h"



void DeleteAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Delete a figure ");

	deletePos = pIn->GetCellClicked();


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