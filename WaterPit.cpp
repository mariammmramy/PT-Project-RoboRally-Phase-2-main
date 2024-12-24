#include "WaterPit.h"
#include "Player.h"
#include"SaveAction.h"


WaterPit::WaterPit(const CellPosition & waterPitPosition):GameObject(waterPitPosition)
{
}

void WaterPit::Draw(Output * pOut) const
{
	pOut->DrawWaterPit(position);
}

void WaterPit::Apply(Grid * pGrid, Player * pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message, make sure to edit this message according to which player wins "You drowned in a water pit. Player (0/1) wins !  Click to continue ..." and wait mouse click
	Output* pOut = pGrid->GetOutput();
	int playernum = pPlayer->Getplayernum();
	pOut->PrintMessage("You drowned in a water pit. Player " + to_string(2 - playernum) + " wins! Click to continue");

	// 2- Apply the water pit's effect by setting the player's health which drowned to zero and ending the game
	
	pPlayer->SetHealth(0);
	pGrid->SetEndGame(true);

	// 3- Update the players info which is displayed (check Grid class and decide which function to use)
	pGrid->UpdateInterface();
}
void WaterPit::Save(ofstream& OutFile, GameObjectType type) {
	if (!OutFile.is_open()) return;
	else {

		int Data = position.GetCellNum();
		OutFile << Data;

	}
}

GameObjectType WaterPit::GetType() const {
	return WaterPits;
}

WaterPit::~WaterPit()
{
}
