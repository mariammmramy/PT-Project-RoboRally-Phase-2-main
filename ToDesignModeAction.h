#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
class ToDesignModeAction: public Action
{
public:
	ToDesignModeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();  // Executes switch to play mode

	virtual ~ToDesignModeAction();
};


