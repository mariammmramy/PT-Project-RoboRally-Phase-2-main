#include "AddFlagAction.h"



AddFlagAction::AddFlagAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}


void AddFlagAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	/* Implemented same method in AddBeltAction */
	Grid* pGrid = pManager->GetGrid(); 
	Output* pOut = pGrid->GetOutput();    //Output pointer
	Input* pIn = pGrid->GetInput();       //Input pointer 

	// 2- Read the flagPos

	pOut->PrintMessage("New Flag: Click on the cell to add a flag ...");  
	flagPos = pIn->GetCellClicked();

	// 4- Make the needed validations on the read parameters


	// 5- Clear status bar
	pOut->ClearStatusBar();   //Use output pointer to clear status bar
}

void AddFlagAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1-Create a flag object
	// 2-get a pointer to the Grid from the ApplicationManager
	// 3-Add the flag object to the GameObject of its Cell:
	// 4-Check if the flag was added and print an errror message if flag couldn't be added
	
}

AddFlagAction::~AddFlagAction()
{
}