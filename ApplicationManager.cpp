#include "ApplicationManager.h"

#include "Grid.h"
#include "AddBeltAction.h"
#include "AddRotatingGearAction.h"
#include "AddFlagAction.h"
#include "ToPlayModeAction.h"
#include "ToDesignModeAction.h"
#include "Exit.h"

///TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid * ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_BELT:
		pAct = new AddBeltAction(this);
		break;

	case ADD_ROTATINGGEAR:
		// create an object of AddRotatingGearAction here
		pAct = new AddRotatingGearAction(this);
		break;
	case ADD_FLAG:
		// create an object of AddFlagAction here
		pAct = new AddFlagAction(this);
		break;

	case EXIT:EXITP:
		pAct = new Exit(this);
		delete pOut; //delete pointer to output
		pOut = nullptr;

		delete pGrid; //delete pointer to grid
		pGrid = nullptr;

		delete pIn;  //delete pointer to input
		pIn = nullptr;

		delete pAct; //delete pointer to any action
		pAct = nullptr;

		break;

	case TO_PLAY_MODE:					//TODO:
		pAct = new ToPlayModeAction(this); // temporary till you made its action class (CHANGE THIS LATTER) 
		//in progress
		break;
	

	case TO_DESIGN_MODE:				//TODO:
		pAct = new ToDesignModeAction(this); // temporary till you made its action class (CHANGE THIS LATTER)
		//in progress
		break;

		///TODO: Add a case for EACH Action type in the Design mode or Play mode


	case STATUS:	// a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}
