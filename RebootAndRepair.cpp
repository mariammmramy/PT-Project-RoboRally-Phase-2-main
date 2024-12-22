#include "RebootAndRepair.h"
#include "Player.h"
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"
RebootAndRepair::RebootAndRepair(ApplicationManager* pApp) : Action(pApp) {   //Created Constructor

}
void RebootAndRepair::ReadActionParameters() {  //
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	pOut->ClearStatusBar();
}
void RebootAndRepair::Execute() {   
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Player* pPlayer = pGrid->GetCurrentPlayer();
    if (pPlayer) {
        // Reboot: Reset player's health points to maximum
        pPlayer->SetHealth(10);

        //Disable movement and shooting for this round (in progress)
        //pPlayer->DisableMovement();
        //pPlayer->DisableShooting();

        // message to inform the player
        Output* pOut = pGrid->GetOutput();
        pOut->PrintMessage("Player rebooted and repaired! Health restored and actions disabled for this round.");
    }
    else {
        // Handle case where no player is selected or valid
        Output* pOut = pGrid->GetOutput();
        pOut->PrintMessage("Error: No valid player to reboot and repair.");
    }
}


RebootAndRepair::~RebootAndRepair() {  //Created destructor

}
