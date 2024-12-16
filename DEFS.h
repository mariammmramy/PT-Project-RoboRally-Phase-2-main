#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (add more as needed)
{
	//  [1] Actions of Design Mode
	SET_FLAG_CELL,	// Set Flag on a Cell
	EXIT,			// Exit Application
	TO_PLAY_MODE,	// Go to Play Mode

	///TODO: Add more action types of Design Mode (COMPLETE)
	SET_ANTENNA,
	SET_BELT,
	SET_WATERPIT,
	SET_DANGERZONE,
	SET_WORKSHOP,
	SET_ROTATING_CW,
	SET_ROTATING_ACW,
	COPY,
	CUT,
	PASTE,
	DELETE_OBJECT,
	SAVE,
	OPEN,
	ADD_FLAG,
	ADD_BELT,
	ADD_ROTATINGGEAR,


	//  [2] Actions of Play Mode

	EXECUTE_COMMANDS,	// Execute the saved commands
	SELECT_COMMAND,		// Select a command from the available ones to be executed
	TO_DESIGN_MODE,	// Go to Design Mode


	///TODO: Add more action types of Play Mode
	REBOOT,
	USE_TOOLKIT,
	USE_HACK,
	NEW,
	EXITP,


	//  [3] Others

	EMPTY,							// Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,						// Inside Grid Area
	STATUS 							// Inside StatusBar Area
};

enum Direction // Directions of the game
{
	UP,
	DOWN,
	RIGHT,
	LEFT
};

enum Command
{
	NO_COMMAND,
	MOVE_FORWARD_ONE_STEP,
	MOVE_BACKWARD_ONE_STEP,
	MOVE_FORWARD_TWO_STEPS,
	MOVE_BACKWARD_TWO_STEPS,
	MOVE_FORWARD_THREE_STEPS,
	MOVE_BACKWARD_THREE_STEPS,
	ROTATE_CLOCKWISE,
	ROTATE_COUNTERCLOCKWISE,

	COMMANDS_COUNT,
};

#endif