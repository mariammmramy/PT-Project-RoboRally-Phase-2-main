#pragma once
#include "Action.h"
#include "GameObject.h"

class DeleteAction : public Action
{
	CellPosition deletePos;

public:
	DeleteAction(ApplicationManager* pApp);


	virtual void ReadActionParameters();

	virtual void Execute(); // executes delete action
	
	~DeleteAction();

};
