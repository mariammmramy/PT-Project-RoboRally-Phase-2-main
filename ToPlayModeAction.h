#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
class ToPlayMode: public Action
{
public:
	ToPlayMode(ApplicationManager* pApp);
	virtual void ReadActionParameters(); 
	virtual void Execute();  // Executes switch to play mode
	virtual ~ToPlayMode();
};

