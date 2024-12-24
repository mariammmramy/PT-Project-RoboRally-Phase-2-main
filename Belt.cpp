#include "Belt.h"


Belt::Belt(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
}
void Belt::Draw(Output* pOut) const
{
	pOut->DrawBelt(position, endCellPos);
}

void Belt::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a belt. Click to continue ..." and wait mouse click
	pGrid->GetOutput()->PrintMessage("You have reached a belt. Click to continue ...");
	Player* player = pGrid->GetCurrentPlayer();
	pGrid->UpdatePlayerCell(pPlayer, CellPosition(this->endCellPos.VCell(), this->endCellPos.HCell())); //updates player cell

	// 2- Apply the belt's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that

}
CellPosition Belt::GetEndPosition() const
{
	return endCellPos;
}


Belt::~Belt()
{
}