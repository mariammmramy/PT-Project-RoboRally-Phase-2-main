#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
class Exit :public Action
{
	public:
		Exit(ApplicationManager* pApp);
		virtual void ReadActionParameters();
		virtual void Execute();  //exits design mode when clicked and clears everything
		virtual ~Exit();
};

