#pragma once

#include "Action.h"
class ActivateReflectionGear : public Action
{
public:
	ActivateReflectionGear(ApplicationManager* pApp);


	virtual void ReadActionParameters();

	virtual void Execute(); // executes cut action

	~ActivateReflectionGear();
};

