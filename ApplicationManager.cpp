#include "ApplicationManager.h"

#include "Grid.h"
#include "AddBeltAction.h"
#include "AddRotatingGearAction.h"
#include "AddFlagAction.h"
#include "ToPlayModeAction.h"
#include "ToDesignModeAction.h"
#include "RebootAndRepair.h"
#include "AddWaterpitAction.h"
#include "AddDangerZoneAction.h"
#include "Exit.h"
#include "AddWorkshopAction.h"
#include "DeleteAction.h"
#include "AddAntennaAction.h"
#include "CopyAction.h"
#include "ExecutePlayerMovement.h"
#include "CutAction.h"
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
		pAct = new ToPlayMode(this); // temporary till you made its action class (CHANGE THIS LATTER) 
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
	case SET_WORKSHOP:				//TODO:
		pAct = new AddWorkshopAction(this);
		break;
	case DELETE_OBJECT:
		pAct = new DeleteAction(this);
		break;
	case SET_ANTENNA:
		pAct = new AddAntennaAction(this);
		break;
	case COPY:
		pAct = new CopyAction(this);
		break;
	case CUT:
		pAct = new CutAction(this);
		break;
	case SAVE:
		pAct = new CutAction(this);
		break;

	/* for each of these enums you have to add a case in the switch case and to include its addobjectaction.h 
			SET_ANTENNA, (Done)
			SET_BELT, (Done)
			SET_WATERPIT, (Done)
			SET_DANGERZONE, (Done)
			SET_ROTATING_CW, (Done)
			SET_ROTATING_ACW, (Done)
			COPY, 
			CUT,
			PASTE,
			DELETE_OBJECT, (Done)
			SAVE,
			OPEN,
			EXIT, (done)
			EXITP,(done)
			EXECUTE_COMMANDS (done)*/

		///TODO: Add a case for EACH Action type in the Design mode or Play mode

	case(REBOOT):
		pAct = new RebootAndRepair(this);
		break;

	case(EXECUTE_COMMANDS):
		pAct = new ExecutePlayerMovement(this);
		break;

	case(USE_TOOLKIT):


		break;
	case(USE_HACK):

		break;
	case(NEW):

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
