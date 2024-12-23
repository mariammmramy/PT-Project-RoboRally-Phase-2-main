#pragma once
#include "Action.h"
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Player.h"
class ExecutePlayerMovement :public Action
{
public:
	ExecutePlayerMovement(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();  // Executes movement
	virtual ~ExecutePlayerMovement();

};


