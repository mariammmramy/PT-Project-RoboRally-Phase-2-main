#include "RebootAndRepair.h"
#include "Player.h"
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"
RebootAndRepair::RebootAndRepair(ApplicationManager* pApp) : Action(pApp) {   //Created Constructor

}
void RebootAndRepair::ReadActionParameters() {  //(in progress)
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	pOut->ClearStatusBar();
}
void RebootAndRepair::Execute() {    //Switch to Design mode (in progress)
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Player* pPlay;
	//add health points
	//robot does not move or shoot

}
RebootAndRepair::~RebootAndRepair() {  //Created destructor

}
