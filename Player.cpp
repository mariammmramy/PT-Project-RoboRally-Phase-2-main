#include "Player.h"

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
	//		then wait for a mouse click (display a message "Click anywhere to execute the next command").
	if (COMMANDS_COUNT>5){
		pOut->PrintMessage("Error! there are more than 5 commands...");
		
	}
	else if (COMMANDS_COUNT <= 0) {
		pOut->PrintMessage("Error! there areno commands to execute...");

	}
	else {
		for (int i = 0; i < COMMANDS_COUNT; i++) {
			//code to do command
			pOut->PrintMessage("Click anywhere to execute the next command");
			pIn->GetUserAction();
		}
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