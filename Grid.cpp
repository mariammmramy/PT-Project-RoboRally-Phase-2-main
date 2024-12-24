#include "Grid.h"
#include<vector>
#include<iostream>
#include "Cell.h"
#include "GameObject.h"
#include "Belt.h"
#include "Player.h"
using namespace std;

Grid::Grid(Input * pIn, Output * pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells-1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;
}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject * pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject * pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if( pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}


// Note: You may need to change the return type of this function (Think)
void Grid::RemoveObjectFromCell(const CellPosition & pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note: you can deallocate the object here before setting the pointer to null if it is needed

		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
	}
}

void Grid::UpdatePlayerCell(Player * player, const CellPosition & newPosition)
{
	// Clear the player's triangle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell * newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);	

	// Draw the player's triangle on the new cell position
	player->Draw(pOut);
}

bool Grid::flagfound()
{

	for (int i = 0; i < NumVerticalCells; ++i)
	{
		for (int j = 0; j < NumHorizontalCells; ++j)
		{
			Cell* cell = CellList[i][j];
			if (cell->GetGameObject() != nullptr && cell->HasFlag())
			{
				return true;
			}
		}

		return false;
	}
}

bool Grid::antennafound()
{

	for (int i = 0; i < NumVerticalCells; ++i)
	{
		for (int j = 0; j < NumHorizontalCells; ++j)
		{
			Cell* cell = CellList[i][j];
			if (cell->GetGameObject() != nullptr && cell->HasAntenna())
			{
				return true;
			}
		}

		return false;
	}
}

bool Grid::checkOverlap(const Belt* belt1, const Belt& belt2) {

	using Position = std::pair<int, int>;

	// Extract start and end positions for Belt 1 & Belt 2
	Position belt1Start = { belt1->GetPosition().HCell(), belt1->GetPosition().VCell() };
	Position belt1End = { belt1->GetEndPosition().HCell(), belt1->GetEndPosition().VCell() };
	Position belt2Start = { belt2.GetPosition().HCell(), belt2.GetPosition().VCell() };
	Position belt2End = { belt2.GetEndPosition().HCell(), belt2.GetEndPosition().VCell() };

	// If Belt 1 Vertical & Belt 2 Horizontal
	if ((belt1Start.first == belt1End.first) && (belt2Start.second == belt2End.second)) {
		// Check if X & Y Ranges Overlap
		return ((belt1Start.first >= min(belt2Start.first, belt2End.first)) && (belt1Start.first <= max(belt2Start.first, belt2End.first))) &&
			((belt2Start.second >= min(belt1Start.second, belt1End.second)) && (belt2Start.second <= max(belt1Start.second, belt1End.second)));
	}
	// If Belt 1 Horizontal & Belt 2 Vertical
	else if ((belt1Start.second == belt1End.second) && (belt2Start.first == belt2End.first)) {
		// Check if X & Y Ranges Overlap
		return ((belt2Start.first >= min(belt1Start.first, belt1End.first)) && (belt2Start.first <= max(belt1Start.first, belt1End.first))) &&
			((belt1Start.second >= min(belt2Start.second, belt2End.second)) && (belt1Start.second <= max(belt2Start.second, belt2End.second)));
	}
	// If Belt 1 and Belt 2 Horizontal
	else if ((belt1Start.first == belt1End.first) && (belt2Start.first == belt2End.first)) {
		// If Lines are in Same Horizontal Level
		if (belt1Start.second == belt2Start.second) {
			int x1Min = min(belt1Start.first, belt1End.first);
			int x1Max = max(belt1Start.first, belt1End.first);
			int x2Min = min(belt2Start.first, belt2End.first);
			int x2Max = max(belt2Start.first, belt2End.first);
			return x1Min <= x2Max && x2Min <= x1Max; // Overlapping x-ranges
		}
		return false;
	}
	// If Belt 1 and Belt 2 Vertical
	else if ((belt1Start.second == belt1End.second) && (belt2Start.second == belt2End.second)) {
		// If Lines are in Same Vertical Level
		if (belt1Start.first == belt2Start.first) {
			int y1Min = min(belt1Start.second, belt1End.second);
			int y1Max = max(belt1Start.second, belt1End.second);
			int y2Min = min(belt2Start.second, belt2End.second);
			int y2Max = max(belt2Start.second, belt2End.second);
			return y1Min <= y2Max && y2Min <= y1Max; // Overlapping y-ranges
		}
		return false;
	}
	return false;
}

bool Grid::isBeltOverlap(CellPosition beltStartPosition, CellPosition beltEndPosition)
{
	std::vector<CellPosition> forbiddenStarts;
	Belt beltToAdd = Belt(beltStartPosition, beltEndPosition);
	for (int i = 0; i < NumVerticalCells; ++i)
	{
		for (int j = 0; j < NumHorizontalCells; ++j)
		{
			Cell* cell = CellList[i][j];
			if (cell->GetGameObject() != nullptr)
			{
				Belt* cellBelt = cell->HasBelt();
				if (cellBelt) {
					if (checkOverlap(cellBelt, beltToAdd)) return true;
					CellPosition cellBeltEnd = cellBelt->GetEndPosition();
					forbiddenStarts.push_back(cellBeltEnd);
				}
			}
		}
	}
	for (CellPosition pos : forbiddenStarts) {
		if ((pos.VCell() == beltStartPosition.VCell()) && (pos.HCell() == beltStartPosition.HCell())) {
			return true;
		}
	}
	return false;
}
// ========= Setters and Getters Functions =========

 

GameObject* Grid::Getgameobjectfromcell(CellPosition pos)
{
	GameObject* pObj = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
	return pObj;
}

Input * Grid::GetInput() const
{
	return pIn;
}

Output * Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard(GameObject * gameObject) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard = gameObject;
}

GameObject * Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

// ========= Other Getters =========


Player * Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Belt * Grid::GetNextBelt(const CellPosition & position)
{
	
	int startH = position.HCell(); // represents the start hCell in the current row to search for the belt in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{


			///TODO: Check if CellList[i][j] has a belt, if yes return it
			

		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}
// Gets a Pointer to the Current Player	                                   
Player *Grid:: GetOppositePlayer() const {
	int oppPlayerNum;
	if (currPlayerNumber == 0) {
		oppPlayerNum = 1;
	}
	else {
		oppPlayerNum = 0;
	}
	return PlayerList[oppPlayerNum];
}

int Grid::GetCurrentPlayerNum() const {
	return currPlayerNumber;
}

// ========= User Interface Functions =========


void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without waterpits or dangerzone 
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrWaterPitOrDangerZone(pOut);
			}
		}

		// 2- Draw other game objects(excluding waterpit and dangerzone)
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawGameObject(pOut);
			}
		}

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount-1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cgame objects do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}


Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) 
	{
		for (int j = 0; j < NumHorizontalCells; j++) 
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		delete PlayerList[i];
	}
}

void Grid::SaveAll(ofstream& OutFile, GameObjectType type)
{
	int count = 0;

	for (int i = 0; i < NumVerticalCells; i++)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			Cell* pCell = CellList[i][j];
			if (pCell)
			{
				GameObject* pGameObject = pCell->GetGameObject();
				if (pGameObject && pGameObject->GetType() == type)
				{
					count++;
				}
			}
		}
	}

	

	for (int i = 0; i < NumVerticalCells; i++)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			Cell* pCell = CellList[i][j];
			if (pCell)
			{
				GameObject* pGameObject = pCell->GetGameObject();
				if (pGameObject && pGameObject->GetType() == type)
				{
					pGameObject->Save(OutFile, type);
				}
			}
		}
	}
}
