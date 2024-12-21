#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Player.h"
class RebootAndRepair :public Action, public Player
{
public:
	RebootAndRepair(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();  // Executes reboot and repair function
	virtual ~RebootAndRepair();

};



