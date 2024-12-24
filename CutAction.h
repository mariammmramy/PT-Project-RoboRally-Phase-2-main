#pragma once
#include "Action.h"
#include "GameObject.h"

class CutAction : public Action
{
	CellPosition cutPos;

public:
	CutAction(ApplicationManager* pApp);


	virtual void ReadActionParameters();

	virtual void Execute(); // executes cut action

	~CutAction();
};
};
