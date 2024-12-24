#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Player.h"
class Selectcommands: public Action
{
	Player* pPlayer;
	int health;
	Command availableCommands[COMMANDS_COUNT - 1] = {
	   MOVE_FORWARD_ONE_STEP, MOVE_BACKWARD_ONE_STEP,
	   MOVE_FORWARD_TWO_STEPS, MOVE_BACKWARD_TWO_STEPS,
	   MOVE_FORWARD_THREE_STEPS, MOVE_BACKWARD_THREE_STEPS,
	   ROTATE_CLOCKWISE, ROTATE_COUNTERCLOCKWISE, };

	   Command savedCommands[5] = { NO_COMMAND, NO_COMMAND, NO_COMMAND, NO_COMMAND, NO_COMMAND};

public:
	Selectcommands(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Execute();  // Executes switch to play mode
	virtual ~Selectcommands();



};

