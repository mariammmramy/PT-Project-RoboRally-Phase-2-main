#pragma once
#include "Action.h"
#include "GameObject.h"
<<<<<<< Updated upstream
class deleteAction : public Action
=======
class DeleteAction : public Action
>>>>>>> Stashed changes
{
	CellPosition deletePos;

public:

<<<<<<< Updated upstream
	deleteAction(ApplicationManager* pApp);
=======
	DeleteAction(ApplicationManager* pApp);
>>>>>>> Stashed changes

	virtual void ReadActionParameters();

	virtual void Execute(); // executes delete action


};
<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
