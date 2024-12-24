#include "ActivateExmem.h"
#include "Action.h"
#include "GameObject.h"
#include "Input.h"
#include"Output.h"
#include "Grid.h"
#include "Player.h"

ActivateExMemory::ActivateExMemory(ApplicationManager* pApp) : Action(pApp)
{
}

void ActivateExMemory::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	Player* pPlayer = pGrid->GetCurrentPlayer();
	if (!pPlayer->getExMemory())
	{
		pGrid->PrintErrorMessage("You don't own an extended memory yet. Click to contnue...");
		return;
	}


}

void ActivateExMemory::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	Player* pPlayer = pGrid->GetCurrentPlayer();
	int oldnum = pPlayer->getnumsavedcommands();

	pPlayer->setnumsavedcommands(oldnum + 1);
	pPlayer->setExMemory(0);

	pGrid->UpdateInterface();
}

ActivateExMemory:: ~ActivateExMemory()
{

}