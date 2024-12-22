#include"CellPosition.h"
#include "AddAntennaAction.h"
#include"Antenna.h"
AddAntennaAction::AddAntennaAction(ApplicationManager* pApp) : Action(pApp)
{
    /// Initializes the pManager pointer of Action with the passed pointer
}


void AddAntennaAction::ReadActionParameters()
{
    Grid* pGrid = pManager->GetGrid();
    Input* pIn = pGrid->GetInput();
    Output* pOut = pGrid->GetOutput();


    pOut->PrintMessage("Click on the cell to add  antenna...");
    antennapos = pIn->GetCellClicked();


    if (!antennapos.IsValidCell())
    {
        pOut->PrintMessage("The cell isinvalid");

    }
    if (pGrid->antennafound())
    {
        pOut->PrintMessage("An antenna already exists");
    }

}

void AddAntennaAction::Execute()
{

    Grid* pGrid = pManager->GetGrid();


    ReadActionParameters();


    if (!antennapos.IsValidCell())
        return;

    Antenna* pantenna = new Antenna(antennapos);
    bool addantenna = pGrid->AddObjectToCell(pantenna);
    if (!addantenna)
    {

        pGrid->PrintErrorMessage("Error! cell already has an object");
        delete pantenna;
    }



    if (pGrid->AddObjectToCell(pantenna))
    {
        pGrid->GetOutput()->PrintMessage("Antenna added successfully!");
    }
    else
    {
        delete pantenna;
        pGrid->GetOutput()->PrintMessage("Failed to add antenna.");
    }
}

AddAntennaAction::~AddAntennaAction()
{

