
#include "DeleteAction.h"
#include "Action.h"
#include "GameObject.h"
#include "Input.h"
#include"Output.h"
#include "Grid.h"

deleteAction::deleteAction(ApplicationManager* pApp) : Action(pApp)
{
	deletePos = NULL;

}

void deleteAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Delete a figure ");

	deletePos = pIn->GetCellClicked();


}

void deleteAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pGrid->RemoveObjectFromCell(deletePos);
	pGrid->UpdateInterface();
}