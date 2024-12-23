#pragma once
#include "Action.h"
#include "GameObject.h"

class PasteAction : public Action
{
	CellPosition pastePos;

public:
	PasteAction(ApplicationManager* pApp);


	virtual void ReadActionParameters();

	virtual void Execute();

	~PasteAction();
};

