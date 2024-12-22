#pragma once
#include "Action.h"
#include "GameObject.h"
class deleteAction : public Action
{
	CellPosition deletePos;

public:

	deleteAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute(); // executes delete action


};

