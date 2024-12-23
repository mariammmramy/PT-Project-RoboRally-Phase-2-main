#include "Player.h"
#include "RotatingGear.h"
#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), health(10), playerNum(playerNum), currDirection(RIGHT), canMove(true), canShoot(true)
{
	this->pCell = pCell;

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

int Player::getweapon()
{
	return weapon;
}

void Player::setweapon(int w)
{
	weapon = w;
}

int Player::gethackdevice()
{
	return hackdevice;
}

void Player::sethackdevice(int h)
{
	hackdevice = h;
}

int Player::gettoolkit()
{
	return toolkit;
}

void Player::settoolkit(int t)
{
	toolkit = t;
}


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
void Player::SetMovement(bool move) {

}
bool Player::GetMovement() {
	return canMove;
}

void Player::SetShooting(bool shoot) {

}
bool Player::GetShooting() {
	return canShoot;
}
Command* Player::GetSavedCommands() {
	return savedCommands; // Return a pointer to saved commands
}
void Player::SetSavedCommands(Command commands[], int num) {
	for (int i = 0; i < num; i++)
		savedCommands[i] = commands[i];
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
	ShootingPhase(pGrid); //start shooting phase
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	// TODO: Modify the Info as needed
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(currDirection) + ", ";
	playersInfo += to_string(health) + ")";

}
void Player::ShootingPhase(Grid* pGrid) {
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	if (canShoot == false) {
		pGrid->PrintErrorMessage("Player cannot currently shoot...");
		return;
	}

	// Get opponent player
	int currNum = pGrid->GetCurrentPlayerNum();
	int oppNum; 

	if (currNum == 0) {
		oppNum == 1;
	}
	else {
		oppNum == 0;
	}
	//Player* currentP = pGrid->GetCurrentPlayer();
	Player* opponentP= pGrid->GetOppPlayer(oppNum);

	// Get positions and directions
	CellPosition currentPos = pCell->GetCellPosition();
	CellPosition opponentPos = opponentP->GetCell()->GetCellPosition();
	Direction myDir = currDirection;

	// Check if in the same row or column
	bool canShootInPhase = false; //check to see if can shoot
	if (myDir == UP || myDir == DOWN) {
		canShootInPhase = (currentPos.HCell() == opponentPos.HCell()) &&
			((myDir == UP && opponentPos.VCell() < currentPos.VCell()) ||
				(myDir == DOWN && opponentPos.VCell() > currentPos.VCell()));
	}
	else if (myDir == LEFT || myDir == RIGHT) {
		canShootInPhase = (currentPos.VCell() == opponentPos.VCell()) &&
			((myDir == LEFT && opponentPos.HCell() < currentPos.HCell()) ||
				(myDir == RIGHT && opponentPos.HCell() > currentPos.HCell()));
	}

	// If shooting is possible
	if (canShootInPhase) {
		int damage = 1; // Basic Laser damage
		if (weapon == 1)
			damage = 2; //check if the player has a double laser
		else
			damage = 1;//damage = 1 if single laser

		opponentP->SetHealth(health-damage); //reduce opponent's health

		// Display hit message
		pOut->PrintMessage("You hit another player, click to continue...");
		pIn->GetCellClicked(); // Wait for user to click
	}
	else {
		pOut->PrintMessage("No opponent in line of sight. Shooting skipped.");
	}
}
