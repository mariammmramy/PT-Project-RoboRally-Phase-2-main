#pragma once
#pragma once
#include "Action.h"
class ActivateExMemory : public Action
{
public:
	ActivateExMemory(ApplicationManager* pApp);


	virtual void ReadActionParameters();

	virtual void Execute(); // executes cut action

	~ActivateExMemory();
};

\

