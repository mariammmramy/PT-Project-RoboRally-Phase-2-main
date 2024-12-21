#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
class ExitDesignMode :public Action
{
	public:
		ExitDesignMode(ApplicationManager* pApp);
		virtual void ReadActionParameters();
		virtual void Execute();  //exits design mode when clicked and clears everything
		virtual ~ExitDesignMode();
};

