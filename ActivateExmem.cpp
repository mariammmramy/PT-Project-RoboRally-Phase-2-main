#include "ActivateExmem.h"
#include "Action.h"
#include "GameObject.h"
#include "Input.h"
#include"Output.h"
#include "Grid.h"
#include "Player.h"

ActivateExmem::ActivateExmem(ApplicationManager* pApp) : Action(pApp)
{
}

void ActivateExmem::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	Player* pPlayer = pGrid->GetCurrentPlayer();
	if (!pPlayer->getexmem())
	{
		pGrid->PrintErrorMessage("You don't own an extended memory yet. Click to contnue...");
		return;
	}


}

void ActivateExmem::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	Player* pPlayer = pGrid->GetCurrentPlayer();
	int oldnum = pPlayer->getnumsavedcommands();

	pPlayer->setnumsavedcommands(oldnum + 1);
	pPlayer->setexmem(0);

	pGrid->UpdateInterface();
}

ActivateExmem:: ~ActivateExmem()
{

}