#include "DangerZone.h"
#include "Player.h"
#include"SaveAction.h"


DangerZone::DangerZone(const CellPosition & dangerZonePosition): GameObject(dangerZonePosition)
{
}

void DangerZone::Draw(Output * pOut) const
{
	pOut->DrawDangerZone(position);
}

void DangerZone::Apply(Grid * pGrid, Player * pPlayer)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a danger zone. Click to continue ..." and wait mouse click
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int x, y;

	pOut->PrintMessage("You have reached a danger zone. Click to continue");
	pIn->GetPointClicked(x, y);

	// 2- Apply the danger zone's effect by reducing the health of the player by 1 
	int health = pPlayer->GetHealth();
	pPlayer->SetHealth(health - 1);
	if (health - 1 == 0)
	{
		pGrid->SetEndGame(true);
	}

	// 3- Update the players info which is displayed (check Grid class and decide which function to use)
	pGrid->UpdateInterface();
}
void DangerZone::Save(ofstream& OutFile, GameObjectType type) {
	if (!OutFile.is_open()) return;
	else {

		int Data = position.GetCellNum();
		OutFile << Data;

	}
}


GameObjectType DangerZone::GetType() const {
	return DangerZones;
}

DangerZone::~DangerZone()
{
}
