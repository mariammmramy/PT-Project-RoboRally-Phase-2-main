#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
class ToPlayMode: public Action
{
	Command availableCommands[COMMANDS_COUNT] = {
		   NO_COMMAND, MOVE_FORWARD_ONE_STEP, MOVE_BACKWARD_ONE_STEP,
		   MOVE_FORWARD_TWO_STEPS, MOVE_BACKWARD_TWO_STEPS,
		   MOVE_FORWARD_THREE_STEPS, MOVE_BACKWARD_THREE_STEPS,
		   ROTATE_CLOCKWISE, ROTATE_COUNTERCLOCKWISE,

	};                          // Initialize available commands
	Command savedCommands[5];   //saved commands in command bar
public:
	ToPlayMode(ApplicationManager* pApp);
	virtual void ReadActionParameters(); 
	virtual void Execute();  // Executes switch to play mode
	virtual ~ToPlayMode();
};

