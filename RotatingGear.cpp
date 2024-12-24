#include "RotatingGear.h"
#include "Player.h"
#include"SaveAction.h"



RotatingGear::RotatingGear(const CellPosition & gearposition,bool clockwise) : GameObject(gearposition)
{
	isClockWise = clockwise;
}

void RotatingGear::Draw(Output* pOut) const
{
	pOut->DrawRotatingGear(position, isClockWise);
}

void RotatingGear::Apply(Grid* pGrid, Player* pPlayer)

{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message and change the message according to direction of rotation "You have reached a rotating gear, you will rotate (clockwise/ anti-clockwise) Click to continue ..." and wait mouse click
	
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int x, y;

	if (isClockWise)
	{
		pOut->PrintMessage("You will rotate clockwise. Click to continue");
	}
	else
	{
		pOut->PrintMessage("You will rotate anti-clockwise. Click to continue");
	}
	
	pIn->GetPointClicked(x, y);

	//2- Apply the roating gear's effect by rotating the player according to the direction
	Direction dir = pPlayer->GetDirection();
	Direction newdir;
	if (isClockWise)
	{
		switch (dir)
		{
		case UP:
			newdir = RIGHT;
		case RIGHT:
			newdir = DOWN;
		case DOWN:
			newdir = LEFT;
		case LEFT:
			newdir = UP;
		}
	}
	else
	{
		switch (dir)
		{
		case UP:
			newdir = LEFT;
		case RIGHT:
			newdir = UP;
		case DOWN:
			newdir = RIGHT;
		case LEFT:
			newdir = DOWN;
		}
	}

	pPlayer->SetDirection(newdir);
	pGrid->UpdateInterface();
}
bool RotatingGear::GetisClockWise() const
{
	return isClockWise;
}
void RotatingGear::Save(ofstream& OutFile, GameObjectType type) {
	if (!OutFile.is_open()) return;
	else {

		int Data = position.GetCellNum();
		OutFile << Data;

	}
}

	GameObjectType RotatingGear::GetType()  const
	{
		return RotatingGears;
	}
	RotatingGear::~RotatingGear(){}
	

