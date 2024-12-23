#include "UseHackDevice.h"
#include "Action.h"
#include "GameObject.h"
#include "Input.h"
#include"Output.h"
#include "Grid.h"
#include "Player.h"

UseHackDevice:: UseHackDevice(ApplicationManager* pApp) : Action(pApp)
{
}

void UseHackDevice::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	Player* pPlayer = pGrid->GetCurrentPlayer();
	if (!pPlayer->gethackdevice())
	{
		pGrid->PrintErrorMessage("You don't own any hack device yet. Click to contnue...");
		return;
	}

	playernum = pGrid->GetCurrentPlayerNum();
	
}

void UseHackDevice::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	int hackednum;
	if (playernum)
	{
		hackednum = 0;
	}
	else
	{
		hackednum = 1;
	}

	Player* pPlayer = pGrid->GetCurrentPlayer();
	Player* phacked = pGrid->GetOppositePlayer();

	phacked->SetMovement(false);
	pPlayer->sethackdevice(0);

	pGrid->UpdateInterface();
}

UseHackDevice:: ~UseHackDevice()
{

}