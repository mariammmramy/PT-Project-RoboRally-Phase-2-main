#include "ActivateReflectionGear.h"
#include "Action.h"
#include "GameObject.h"
#include "Input.h"
#include"Output.h"
#include "Grid.h"
#include "Player.h"

ActivateReflectionGear::ActivateReflectionGear(ApplicationManager* pApp) : Action(pApp)

{
}

void ActivateReflectionGear::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	Player* pPlayer = pGrid->GetCurrentPlayer();



}
void ActivateReflectionGear::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Player* pPlayer = pGrid->GetCurrentPlayer();

	if (pPlayer->getReflectionGear() == 1)
	{
		pPlayer->SetisReflected(1);

		pOut->PrintMessage("ReflectionGear Activated Successfully!, click to continue...");
	}
	else {
		pOut->PrintMessage("You have no ReflectionGear yet, Click to continue ...");
	}
	int x, y;
	pIn->GetPointClicked(x, y);
	pGrid->UpdateInterface();

}

ActivateReflectionGear:: ~ActivateReflectionGear()
{

}
//bool isref player done 
//get set hena true player



//pOut->drawline