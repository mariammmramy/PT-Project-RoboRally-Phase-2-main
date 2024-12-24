#pragma once

#include "Grid.h"
#include "Cell.h"

class Player
{
	Cell * pCell;		   // pointer to the current Cell of the player

	const int playerNum;   // the player number (from 0 to MaxPlayerCount-1)
	                       // player number does NOT change after construction (const.)

	int stepCount;		   // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells
	Direction currDirection; // Current Direction of the player
	int health = 10;				// Player's current health points
	int toolkit = 0;
	int hackdevice = 0;		//tool kit and hack device should not be more than one so you should validate that in the buying conumables
	int weapon = 0;			// 0 means single laser and 1 means double laser
	bool ishacked = false;
	bool isrepaired = false;

	int ExMemory = 0;		//bonus; extended memory, cannot have more the one
	int numsavedcommands = 5;
	bool canMove = true;;
	bool canShoot = true;;

	Command savedCommands[5] = { NO_COMMAND,NO_COMMAND,NO_COMMAND,NO_COMMAND,NO_COMMAND };  //initialise saved commands
	// owned equipments
	// carried consumables
	// carried laser type (default, double laser)
	// isHacked (to indicate whether the player is blocked to play the round, as a result of the opponent using a hacking device)

	
public:

	Player(Cell * pCell, int playerNum); // Constructor making any needed initializations

	// ====== Setters and Getters ======
	void SetCell(Cell * cell);		// A setter for the pCell
	Cell* GetCell() const;			// A getter for the pCell

	void SetHealth(int h);			// A setter for the health points
	int GetHealth();				// A getter for the health points


	///TODO: You can add setters and getters for data members here (if needed)
	int getweapon();
	void setweapon(int w);
	int gethackdevice();
	void sethackdevice(int h);
	int gettoolkit();
	void settoolkit(int t);     //done by ziad

	bool getishacked();
	void setishacked(bool hacked);

	int getExMemory();
	int getnumsavedcommands();

	void setExMemory(int x);
	void setnumsavedcommands(int num);

	int Getplayernum();
	Direction GetDirection();
	void SetDirection(Direction d);

	void SetStepCount(int s);   //set position of player (for new game)
	int GetStepCount();

	void SetMovement(bool move);
	bool GetMovement();

	void SetShooting(bool shoot);
	bool GetShooting();    //done by mariam
	
	void SetSavedCommands(Command commands[], int num);  //set saved commands (should be used in select commands)
	void Player::GetSavedCommands(Command commands[]); //get saved commands in execute movement
	Command* GetSavedCommands();  //get saved commands
	// ====== Drawing Functions ======

	void Draw(Output* pOut) const;			// Draws the Player's Triangle on its current cell

	void ClearDrawing(Output* pOut) const;	// Clears the Player's Triangle from its current cell

	// ====== Game Functions ======

	void Move(Grid * pGrid, Command moveCommands[]);	// Moves the Player with the passed move command
														// and Applies the Game Object's effect (if any) of the end reached cell 
														// for example, if the end cell contains a belt, take it
	
	void AppendPlayerInfo(string & playersInfo) const; // Appends player's info to the input string, 
	                                                   // for example: P0(Direction, health)
	void ShootingPhase(Grid *pGrid);
};

