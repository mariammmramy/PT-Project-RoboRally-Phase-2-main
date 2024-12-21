#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
class ToPlayModeAction: public Action
{
public:
	ToPlayModeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters(); 
	virtual void Execute();  // Executes switch to play mode
	virtual ~ToPlayModeAction();
};

