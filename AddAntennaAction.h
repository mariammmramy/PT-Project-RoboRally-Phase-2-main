#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Flag.h"
#include"CellPosition.h"
class AddAntennaAction :public Action
{
	// Always add action parameters as private data members

	// [Action Parameters]
	CellPosition antennapos; // 1- The position of the antenna
public:

	AddAntennaAction(ApplicationManager* pApp);
	virtual void ReadActionParameters(); // Reads action parameters 

	virtual void Execute(); // Creates a new Antenna Object 

	~AddAntennaAction();
};
