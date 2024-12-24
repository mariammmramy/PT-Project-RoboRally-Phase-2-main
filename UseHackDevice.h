#pragma once
#include "Action.h"
class UseHackDevice : public Action
{
	int playernum;
public:
	UseHackDevice(ApplicationManager* pApp);


	virtual void ReadActionParameters();

	virtual void Execute(); // executes cut action

	~UseHackDevice();
};

