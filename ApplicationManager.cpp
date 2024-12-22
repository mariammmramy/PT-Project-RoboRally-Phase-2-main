#include "ApplicationManager.h"

#include "Grid.h"
#include "AddBeltAction.h"
#include "AddRotatingGearAction.h"
#include "AddFlagAction.h"
#include "ToPlayModeAction.h"
#include "ToDesignModeAction.h"
#include "AddWaterpitAction.h"
#include "AddDangerZoneAction.h"
#include "Exit.h"
<<<<<<< Updated upstream

=======
#include "AddWorkshopAction.h"
#include "DeleteAction.h"
>>>>>>> Stashed changes
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
	case SET_BELT:
		pAct = new AddBeltAction(this);
		break;

	case SET_ROTATING_CW:
		// create an object of AddRotatingGearAction here
		pAct = new AddRotatingGearAction(this, true);
		break;
	case SET_ROTATING_ACW:
		// create an object of AddRotatingGearAction here
		pAct = new AddRotatingGearAction(this, false);
		break;
	case SET_FLAG_CELL:
		// create an object of AddFlagAction here
		pAct = new AddFlagAction(this);
		break;

	case EXIT:
		/*Clear all areas to ensure smoother exit*/
		/*pOut->ClearStatusBar();
		pOut->ClearCommandsBar();
		pOut->ClearGridArea();*/
		pAct = new Exit(this);
		delete pIn;//deletes memory in pIn 
		delete pOut;//deletes memory in pIn 
		break;

	case TO_PLAY_MODE:					//TODO:
		pAct = new ToPlayModeAction(this); // temporary till you made its action class (CHANGE THIS LATTER) 
		/*pOut->CreatePlayModeToolBar()*/;
		//in progress
		break;
	

	case TO_DESIGN_MODE:				//TODO:
		pAct = new ToDesignModeAction(this); // temporary till you made its action class (CHANGE THIS LATTER)
		//in progress
		break;
	case SET_WATERPIT:				//TODO:
		pAct = new AddWaterpitAction(this);
		break;
	case SET_DANGERZONE:				//TODO:
		pAct = new AddDangerZoneAction(this);
		break;
<<<<<<< Updated upstream
=======
	case SET_WORKSHOP:				//TODO:
		pAct = new AddWorkshopAction(this);
		break;
	case DELETE_OBJECT:				//TODO:
		pAct = new DeleteAction(this);
		break;
>>>>>>> Stashed changes

	/* for each of these enums you have to add a case in the switch case and to include its addobjectaction.h 
			SET_ANTENNA,
			SET_BELT, (Done)
			SET_WATERPIT, (Done)
			SET_DANGERZONE, (Done)
			SET_WORKSHOP,  (done)
			SET_ROTATING_CW, (Done)
			SET_ROTATING_ACW, (Done)
			COPY, 
			CUT,
			PASTE,
			DELETE_OBJECT,
			SAVE,
			OPEN,
			EXIT, (done)
			EXITP (done)*/

		///TODO: Add a case for EACH Action type in the Design mode or Play mode

	case(REBOOT):

		break;
	case(USE_TOOLKIT):


		break;
	case(USE_HACK):

		break;
	case(NEW):


		break;
	case(EXITP):
		pAct = new Exit(this); //class to exit the app
		delete pIn; //deletes memory in pIn 
		delete pOut; // deletes memory in pOut
		break;

		break; 

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
