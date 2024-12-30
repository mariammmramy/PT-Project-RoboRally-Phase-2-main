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
        pOut->PrintMessage("The cell is invalid");

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
    {
        pGrid->PrintErrorMessage("The cell is invalid");
        return;

    }

    if ((antennapos.VCell() == 4 && antennapos.HCell() == 0))
    {
        pGrid->PrintErrorMessage("You can't put a game object in the first cell");
        return;
    }

    if (pGrid->antennafound())
    {
        pGrid->PrintErrorMessage("An antenna already exists");
        return;
    }

    Antenna* pantenna = new Antenna(antennapos);
    bool addantenna = pGrid->AddObjectToCell(pantenna);
    if (!addantenna)
    {
        pGrid->PrintErrorMessage("Error! cell already has an object");
        delete pantenna;
    }
    Output* pOut = pGrid->GetOutput();
    pOut->PrintMessage("Added successfully!.");
}

AddAntennaAction::~AddAntennaAction()
{

}

