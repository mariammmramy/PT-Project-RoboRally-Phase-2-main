#pragma once
#pragma once
#include "Action.h"
class ActivateExmem : public Action
{
public:
	ActivateExmem(ApplicationManager* pApp);


	virtual void ReadActionParameters();

	virtual void Execute(); // executes cut action

	~ActivateExmem();
};

\

