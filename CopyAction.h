#pragma once
#include "Action.h"
#include "GameObject.h"

class CopyAction : public Action
{
	CellPosition copyPos;

public:
	CopyAction(ApplicationManager* pApp);


	virtual void ReadActionParameters();

	virtual void Execute(); // executes copy action

	~CopyAction();
};
