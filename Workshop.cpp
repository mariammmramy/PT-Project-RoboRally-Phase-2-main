#include "Workshop.h"
#include "Player.h"


Workshop::Workshop(const CellPosition & workshopPosition):GameObject( workshopPosition)
{

}


void Workshop::Draw(Output * pOut) const
{
	pOut->DrawWorkshop(position);
}

void Workshop::Apply(Grid * pGrid, Player * pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int x, y;

	pOut->PrintMessage("You have reached a Workshop. Click to continue");
	pIn->GetPointClicked(x, y);

	pOut->PrintMessage("Type 1 if you want to buy a toolkit, Type 2 if you want to buy a hack device, Type 3 if you want to buy a double laser, Click on the repair icon in the toolbar if you want to repair and reboot");

	int a = pIn->GetInteger(pOut);
	switch (a)
	{
	case 1:
		if (pPlayer->gettoolkit())
		{
			pGrid->PrintErrorMessage("You already have a toolkit, you can't buy more than one");
		}
	}
}

Workshop::~Workshop()
{
}
