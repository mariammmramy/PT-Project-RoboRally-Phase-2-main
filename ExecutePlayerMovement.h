#pragma once
#include "Grid.h"
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Player.h"
class ExecutePlayerMovement :public Action
{
	Player* pPlayer;
	int health;
public:
	ExecutePlayerMovement(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();  // Executes movement
	virtual ~ExecutePlayerMovement();

};


