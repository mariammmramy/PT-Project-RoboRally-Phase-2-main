#include "Player.h"
#include "RotatingGear.h"
#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), health(10), playerNum(playerNum), currDirection(RIGHT)
{
	this->pCell = pCell;

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

Direction  Player::GetDirection()
{
	return currDirection;
}

void Player::SetDirection(Direction d)
{
	currDirection = d;
}

int Player::Getplayernum()
{
	return playerNum;
}

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetHealth(int h)
{
	if (h > 10 || h < 0)
	{
		this->health = h;
	}
	
	///TODO: Do any needed validations (done)
}

int Player::GetHealth()
{
	return this->health;
}

// ====== Drawing Functions ======



void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];


	///TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	///TODO: Modify the cellColor to draw the correct cellColor (hint: if cell contains non-default cellColor)
	color cellColor = UI.CellColor;
	
	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, Command moveCommands[])
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	///TODO: Implement this function using the guidelines mentioned below

	// - If a player has 5 (could have less) saved moveCommands, the robot will execute the first saved command,
	//		then wait for a mouse click (display a message "Click anywhere to execute the next command"). (done)
	if (COMMANDS_COUNT>5){
		pOut->PrintMessage("Error! there are more than 5 commands...");    //cannot execute more than 5 commands
		
	}
	else if (COMMANDS_COUNT <= 0) {
		pOut->PrintMessage("Error! there are no commands to execute...");  //no commands entered

	}

		CellPosition currentPos = pCell->GetCellPosition();
		CellPosition newPos = currentPos;
	
	for (int i = 0; i < COMMANDS_COUNT; i++) {
		//code to do command
		Command pCmd = moveCommands[i];

		/*Switch case to determine what to do based on each command*/
		switch (pCmd) {
		case(NO_COMMAND):
			pOut->PrintMessage("No command to execute...");
			continue;

		case(MOVE_FORWARD_ONE_STEP):
			newPos.AddCellNum(1,currDirection);
			break;

		case(MOVE_BACKWARD_ONE_STEP):
			newPos.AddCellNum(-1, currDirection);
			break;

		case(MOVE_FORWARD_TWO_STEPS):
			newPos.AddCellNum(2, currDirection);
			break;

		case(MOVE_BACKWARD_TWO_STEPS):
			newPos.AddCellNum(-2, currDirection);
			break;

		case(MOVE_FORWARD_THREE_STEPS):
			newPos.AddCellNum(3, currDirection);
			break;

		case(MOVE_BACKWARD_THREE_STEPS):
			newPos.AddCellNum(-3, currDirection);
			break;

		case(ROTATE_CLOCKWISE): {
			RotatingGear rotateGear(currentPos, true);
			rotateGear.Apply(pGrid, this);   //Apply clockwise movement
			continue; //skip  turn

		}

		case(ROTATE_COUNTERCLOCKWISE): {
			RotatingGear rotateGear(currentPos, false);
			rotateGear.Apply(pGrid, this);   //Apply counter clockwise movement
			continue; //skip this turn
			break;
		}

		}

		if (!newPos.IsValidCell()) {  //validate the new position cell
			pOut->PrintMessage("Invalid move! Position out of bounds. Skipping...");
			continue;
		}
	
		pGrid->UpdatePlayerCell(this, newPos); //updates player cell
		// to do: code to interact with game objects 

		pOut->PrintMessage("Click anywhere to execute the next command");
		pIn->GetCellClicked(); //wait for user input
	}

	//		After executing all the 5 saved commands, the game object effect at the final destination cell will
	//		be applied.
	// 
	// - Use the CellPosition class to help you calculate the destination cell using the current cell
	// - Use the Grid class to update pCell
	// - Don't forget to apply game objects at the final destination cell and check for game ending

}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	// TODO: Modify the Info as needed
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(currDirection) + ", ";
	playersInfo += to_string(health) + ")";

}