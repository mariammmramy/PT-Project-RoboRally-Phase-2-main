﻿#include "Output.h"

#include "Input.h"

#include <iostream>
////////////////////////////////////////////////////////////////////////////////////////// 

Output::Output()
{
	// Initialize user interface parameters
	UI.InterfaceMode = MODE_DESIGN;

	// Widths and Heights

	UI.StatusBarHeight = 60;
	UI.CommandsBarHeight = 100;
	UI.CommandItemWidth = 70;
	UI.ToolBarHeight = 55;
	UI.MenuItemWidth = 55;

	UI.width = 1210; // make it divisible by NumHorizontalCells
	UI.height = 610;
	UI.wx = 5;
	UI.wy = 5;

	UI.CellWidth = UI.width / NumHorizontalCells;
	UI.CellHeight = (UI.height - UI.ToolBarHeight - UI.StatusBarHeight - UI.CommandsBarHeight) / NumVerticalCells;

	// Pen Colors of messages of status bar and players' info
	UI.MsgColor = DARKRED;
	UI.PlayerInfoColor = DARKSLATEBLUE;

	// Background Colors of toolbar and statusbar 
	UI.ToolBarColor = WHITE;
	UI.StatusBarColor = LIGHTGRAY;
	UI.CommandBarColor = BLACK;

	// Line Colors of the borders of each cell
	UI.GridLineColor = WHITE;

	// Cell Color if Empty & Cell Number Font & Color
	UI.CellColor = LIGHTSLATEBLUE;
	UI.CellNumFont = 13;
	UI.CellNumColor = UI.GridLineColor;


	// Belt Line Width and Color
	UI.BeltLineWidth = 6;
	UI.BeltColor = DARKSLATEBLUE;

	// The X and Y Offsets of the Space BEFORE Drawing the Belt (offset from the start X and Y of the Cell)
	UI.BeltXOffset = (UI.CellWidth - 2 * UI.BeltLineWidth) / 5;
	UI.BeltYOffset = (UI.CellHeight / 4) * 3;

	// Flag and Flag Pole Colors
	UI.FlagPoleWidth = 4;
	UI.FlagPoleHeight = UI.CellHeight / 2;
	UI.FlagWidth = UI.CellWidth / 4;
	UI.FlagHeight = UI.FlagPoleHeight / 2;

	UI.FlagColor = RED;
	UI.FlagPoleColor = GHOSTWHITE;


	// Commands X and Y Coordinates
	UI.SpaceBetweenCommandsSlots = 10;
	UI.AvailableCommandsXOffset = (UI.CommandItemWidth + UI.SpaceBetweenCommandsSlots) * 6;


	// Colors of the 2 Players
	UI.PlayerColors[0] = GOLD;
	UI.PlayerColors[1] = DARKSLATEBLUE;
	/*UI.PlayerColors[2] = KHAKI;
	UI.PlayerColors[3] = CHOCOLATE;*/

	// Create the output window
	pWind = CreateWind(UI.width + 15, UI.height, UI.wx, UI.wy);

	// Change the title
	pWind->ChangeTitle("RoboRally");

	// Create the toolbar, grid area and status bar
	CreateDesignModeToolBar();
	ClearGridArea();
	ClearStatusBar();
	ClearCommandsBar();

}

////////////////////////////////////////////////////////////////////////////////////////// 

window* Output::CreateWind(int w, int h, int x, int y) const
{
	// The Window Object is created inside the Ouput class
	window* pW = new window(w, h, x, y);
	return pW;
}

////////////////////////////////////////////////////////////////////////////////////////// 

Input* Output::CreateInput() const
{
	// The Input Object is created inside the Output class
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Some Utility Functions										//
//======================================================================================//

int Output::GetCellStartX(const CellPosition& cellPos) const
{
	///TODO: implement the following function as described in Output.h file

	if (cellPos.IsValidCell())
	{
		return cellPos.HCell() * UI.CellWidth;
	}
	else
	{
		return 0;
	}

}

//////////////////////////////////////////////////////////////////////////////////////////

int Output::GetCellStartY(const CellPosition& cellPos) const
{
	///TODO: implement the following function as described in Output.h file

	if (cellPos.IsValidCell())
	{
		return (cellPos.VCell() * UI.CellHeight) + UI.ToolBarHeight;
	}
	else
	{
		return 0;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearToolBar() const
{
	// Clear by drawing a rectangle filled with toolbar background color
	pWind->SetPen(UI.ToolBarColor, 1);
	pWind->SetBrush(UI.ToolBarColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawTriangle(int triangleCenterX, int triangleCenterY, int triangleHeight, int triangleWidth, Direction direction, color triangleColor, drawstyle style, int penWidth) const
{
	int x1, y1, x2, y2, x3, y3;

	///TODO: Calculate the coordiantes of the 3 vertices of the triangle based on the passed parameters

	if (direction == UP)
	{
		x1 = triangleCenterX - triangleWidth / 2;
		y1 = triangleCenterY + triangleHeight / 2;
		x2 = triangleCenterX + triangleWidth / 2;
		y2 = triangleCenterY + triangleHeight / 2;
		x3 = triangleCenterX;
		y3 = triangleCenterY - triangleHeight / 2;
	}
	else if (direction == DOWN)
	{
		x1 = triangleCenterX - triangleWidth / 2;
		y1 = triangleCenterY + triangleHeight / 2;
		x2 = triangleCenterX + triangleWidth / 2;
		y2 = triangleCenterY + triangleHeight / 2;
		x3 = triangleCenterX;
		y3 = triangleCenterY + triangleHeight / 2;
	}
	else if (direction == RIGHT)
	{
		x1 = triangleCenterX - triangleWidth / 2;
		y1 = triangleCenterY + triangleHeight / 2;
		x2 = triangleCenterX - triangleWidth / 2;
		y2 = triangleCenterY - triangleHeight / 2;
		x3 = triangleCenterX + triangleHeight / 2;
		y3 = triangleCenterY;
	}
	else if (direction == LEFT)
	{
		x1 = triangleCenterX + triangleWidth / 2;
		y1 = triangleCenterY + triangleHeight / 2;
		x2 = triangleCenterX + triangleWidth / 2;
		y2 = triangleCenterY - triangleHeight / 2;
		x3 = triangleCenterX - triangleHeight / 2;
		y3 = triangleCenterY;
	}
	///TODO: Continue the implementation (Completed)
	pWind->DrawTriangle(x1, y1, x2, y2, x3, y3, style);

}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawImageInCell(const CellPosition& cellPos, string image, int width, int height) const
{
	// TODO: Validate the cell position
	if (!cellPos.IsValidCell())
		return;

	int x = GetCellStartX(cellPos) + (UI.CellWidth / 4);
	int y = GetCellStartY(cellPos) + (UI.CellHeight / 4);

	// TODO: Complete the implementation of this function
	pWind->DrawImage(image, x, y, UI.CellWidth / 2, UI.CellHeight / 2);
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

void Output::ClearStatusBar() const
{
	// Clear drawing a rectangle filled with statusbar background color
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}

void Output::ClearCommandsBar() const
{
	// Clear drawing a rectangle filled with command bar background color
	pWind->SetPen(UI.CommandBarColor, 1);
	pWind->SetBrush(UI.CommandBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight - UI.CommandsBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearGridArea() const
{
	// Draw each cell in the Grid: ( NumVerticalCells * NumberHorizontalCells )
	for (int i = 0; i < NumVerticalCells; i++)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			CellPosition cellPos(i, j);
			DrawCell(cellPos);
		}
	}

}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateDesignModeToolBar() const
{
	UI.InterfaceMode = MODE_DESIGN;

	ClearToolBar(); // in order not to draw above the icons of the other mode when you switch

	// You can draw the tool bar icons in any way you want.
	// Below is one possible way

	// First prepare List of images for each menu item
	// To control the order of these images in the menu, 
	// reoder them in UI_Info.h ==> enum DESIGN_MODE_ITEMS
	// ** MAKE SURE THAT THE IMAGES ARE .JPG FILES **
	string MenuItemImages[DESIGN_ITM_COUNT];
	MenuItemImages[ITM_EXIT] = "images\\Menu_Exit.jpg";
	MenuItemImages[ITM_SWITCH_TO_PLAY_MODE] = "images\\Menu_SwitchToGame.jpg";

	///TODO: Change the path of the images as needed
	MenuItemImages[ITM_SET_FLAG_CELL] = "images\\Flag.jpg";

	///TODO: Prepare images for each menu item and add it to the list
	MenuItemImages[ITM_SET_ANTENNA] = "images\\Antenna.jpg";
	MenuItemImages[ITM_SET_BELT] = "images\\Belt.jpg";
	MenuItemImages[ITM_SET_WATERPIT] = "images\\Waterpit.jpg";
	MenuItemImages[ITM_SET_DANGERZONE] = "images\\Dangerzone.jpg";
	MenuItemImages[ITM_SET_WORKSHOP] = "images\\Workshop.jpg";
	MenuItemImages[ITM_SET_ROTATING_CW] = "images\\RotatingCW.jpg";
	MenuItemImages[ITM_SET_ROTATING_ACW] = "images\\RotatingACW.jpg";
	MenuItemImages[ITM_COPY] = "images\\Copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\Cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\Paste.jpg";
	MenuItemImages[ITM_DELETE] = "images\\Delete.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Save.jpg";
	MenuItemImages[ITM_OPEN] = "images\\Open.jpg";


	// Draw menu item one image at a time
	for (int i = 0; i < DESIGN_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);


}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayModeToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	ClearToolBar(); // in order not to draw above the icons of the other mode when you switch

	// You can draw the tool bar icons in any way you want.
	// Below is one possible way

	// First prepare List of images for each menu item
	// To control the order of these images in the menu, 
	// reoder them in UI_Info.h ==> enum DESIGN_MODE_ITEMS
	// ** MAKE SURE THAT THE IMAGES ARE .JPG FILES **
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_SWITCH_TO_DESIGN_MODE] = "images\\Menu_SwitchToGrid.jpg";

	///TODO: Change the path of the images as needed
	MenuItemImages[ITM_EXECUTE_COMMANDS] = "images\\Execute.jpg";
	MenuItemImages[ITM_SELECT_COMMAND] = "images\\Select.jpg";

	///TODO: Prepare images for each menu item and add it to the list
	/*ITM_REBOOT,
		ITM_USE_TOOLKIT,
		ITM_USE_HACK,
		ITM_NEW,
		ITM_EXITP,*/
	MenuItemImages[ITM_REBOOT] = "images\\Repair.jpg";
	MenuItemImages[ITM_USE_TOOLKIT] = "images\\Toolkit.jpg";
	MenuItemImages[ITM_USE_HACK] = "images\\Hack.jpg";
	MenuItemImages[ITM_NEW] = "images\\New.jpg";
	MenuItemImages[ITM_EXITP] = "images\\Menu_Exit.jpg";




	// Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

}

void Output::CreateCommandsBar(Command savedCommands[], int savedCommandsCount, Command availableCommands[], int availableCommandsCount) const
{
	ClearCommandsBar();
	UI.InterfaceMode = MODE_PLAY;
	string CommandItemImages[COMMANDS_COUNT];
	CommandItemImages[NO_COMMAND] = "images\\CommandSlot-grey.jpg";
	CommandItemImages[MOVE_FORWARD_ONE_STEP] = "images\\MoveForwardCard.jpg";
	// TODO: Prepare images for more items with .jpg extensions and add them to the list 


	CommandItemImages[MOVE_BACKWARD_ONE_STEP] = "images\\Backward.jpg";
	CommandItemImages[MOVE_FORWARD_TWO_STEPS] = "images\\2stepsF.jpg";
	CommandItemImages[MOVE_BACKWARD_TWO_STEPS] = "images\\2stepsB.jpg";
	CommandItemImages[MOVE_FORWARD_THREE_STEPS] = "images\\3stepsF.jpg";
	CommandItemImages[MOVE_BACKWARD_THREE_STEPS] = "images\\3stepsB.jpg";
	CommandItemImages[ROTATE_CLOCKWISE] = "images\\CW.jpg";
	CommandItemImages[ROTATE_COUNTERCLOCKWISE] = "images\\CCW.jpg";

	DrawSavedCommands(savedCommands, savedCommandsCount, CommandItemImages);
	DrawAvailableCommands(availableCommands, availableCommandsCount, CommandItemImages);

}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawSavedCommands(Command savedCommands[], int savedCommandsCount, string CommandItemImages[]) const
{
	if (UI.InterfaceMode == MODE_DESIGN)
		return;

	int spaceBetweenSlots = 10;
	for (int i = 0; i < savedCommandsCount; ++i)
	{
		int x = i * (UI.CommandItemWidth + spaceBetweenSlots);
		int y = UI.height - UI.StatusBarHeight - UI.CommandsBarHeight;
		pWind->DrawImage(CommandItemImages[savedCommands[i]], x, y, UI.CommandItemWidth, UI.CommandsBarHeight);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawAvailableCommands(Command availableCommands[], int availableCommandsCount, string CommandItemImages[]) const
{
	if (UI.InterfaceMode == MODE_DESIGN)
		return;

	// Define the size and spacing for the available commands
	int availableCommandWidth = UI.CommandItemWidth / 2;
	int availableCommandHeight = UI.CommandsBarHeight / 2;

	// Define the starting position for the available commands
	int startX = UI.AvailableCommandsXOffset;
	int startY = UI.height - UI.StatusBarHeight - UI.CommandsBarHeight;

	// Draw the "Available Commands" text above the command slots
	pWind->SetPen(WHITE);
	pWind->SetFont(UI.CellNumFont, BOLD, BY_NAME, "Arial");
	string availableCommandsText = "Available Commands";
	int textWidth = 0, textHeight = 0; // to be used in the next line as they are passed by reference
	pWind->GetStringSize(textWidth, textHeight, availableCommandsText);
	pWind->DrawString(startX, startY, availableCommandsText);




	UI.AvailableCommandsYOffset = textHeight + 10;  // vertical space between the start of the command bar and the cards of available commands
	// will be used in detecting selected command from the user click
	for (int i = 0; i < availableCommandsCount; ++i)
	{
		int x = startX + i * (availableCommandWidth);
		int y = startY + UI.AvailableCommandsYOffset; // Adjust the Y position to be below the text


		// Draw the command slot (assuming you have an image for the available commands)
		if (availableCommands[i] != NO_COMMAND)
			pWind->DrawImage(CommandItemImages[availableCommands[i]], x, y, availableCommandWidth, availableCommandHeight);


		// Draw the command number below the card
		pWind->SetPen(UI.CellNumColor);
		pWind->SetFont(UI.CellNumFont, BOLD | ITALICIZED, BY_NAME, "Arial");
		int w = 0, h = 0;
		pWind->GetIntegerSize(w, h, i + 1);
		int numX = x + (availableCommandWidth - w) / 2;
		int numY = y + availableCommandHeight + 5; // Adjust the Y position to be below the card
		pWind->DrawInteger(numX, numY, i + 1);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	// First clear the status bar from any previous writing

	// Set pen and font before drawing the string on the window
	pWind->SetPen(UI.MsgColor);
	pWind->SetFont(18, BOLD, BY_NAME, "Verdana");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.3), msg);
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintPlayersInfo(string info)
{
	///TODO: Clear what was written on the toolbar

	// One of the correct ways to implement the above TODO is to call CreatePlayModeToolBar(); 
	// to clear what was written in the player info (there are other ways too   You are free to use any)

	// Set the pen and font before drawing the string on the window
	pWind->SetPen(UI.PlayerInfoColor);
	pWind->SetFont(20, BOLD, BY_NAME, "Verdana");

	int w = 0, h = 0;

	///TODO: Calculate the Width and Height of the string if drawn using the current font 
	//       (Use GetStringSize() window function) and set the "w" and "h" variables with its width and height
	pWind->GetStringSize(w, h, info);


	// Set the start X & Y coordinate of drawing the string
	int x = UI.width - w - 20; // space 20 before the right-side of the window
	// ( - w ) because x is the coordinate of the start point of the string (upper left)
	int y = (UI.ToolBarHeight - h) / 2; // in the Middle of the toolbar height

	///TODO: Draw the string "info" in the specified location (x, y)

	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(x, y, x + 300, y + 100);
	pWind->DrawString(x, y, info);

}

//======================================================================================//
//			         			Game Drawing Functions   								//
//======================================================================================//

void Output::DrawCell(const CellPosition& cellPos, color cellColor) const
{
	// Get the Cell Number (from 1 to NumVerticalCells*NumHorizontalCells) and the X & Y of its upper left corner
	int cellNum = cellPos.GetCellNum();
	int cellStartX = GetCellStartX(cellPos);
	int cellStartY = GetCellStartY(cellPos);

	// ----- 1- Draw the cell itself (background) --> Filled Rectangle -----
	pWind->SetPen(UI.GridLineColor, 1);

	pWind->SetBrush(cellColor);


	///TODO: Draw the Cell Rectangle using the appropriate coordinates
	//       using cellStartX, cellStartY, UI.CellWidth, UI.CellHeight
	pWind->DrawRectangle(cellStartX, cellStartY, cellStartX + UI.CellWidth, cellStartY + UI.CellHeight);

	// ----- 2- Draw the CELL number (the small number at the bottom right of the cell) -----
	pWind->SetPen(UI.CellNumColor);
	pWind->SetFont(UI.CellNumFont, BOLD, BY_NAME, "Verdana");

	int w = 0, h = 0;

	///TODO: Get the Width and Height of the Cell Number if written using the current font 
	//       (Use GetIntegerSize() window function) and set the "w" and "h" variables with its width and height

	pWind->GetIntegerSize(w, h, cellNum);


	// Calculate X & Y coordinate of the start point of writing the card number (upper left point of the cell num)
	int x = cellStartX + (UI.CellWidth - w - 1);   // space 1 from the end of the cell width
	// ( - w ) because x is for the start point of cell num (num's left corner)
	int y = cellStartY + (UI.CellHeight - h - 1);  // space 1 from the end of the cell height
	// ( - w ) because y is for the start point of cell num (num's upper corner)

///TODO: Draw the cell number in the x and y location

	pWind->DrawInteger(x, y, cellNum);
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawPlayer(const CellPosition& cellPos, int playerNum, color playerColor, Direction direction) const
{
	// TODO: Validate the cell position and the playerNum, if not valid return
	if (!cellPos.IsValidCell()) {
		return;
	}
	if (playerNum > 1 || playerNum < 0) {
		return;
	}

	// Get the X & Y coordinates of the start point of the cell (its upper left corner)
	int cellStartX = GetCellStartX(cellPos);
	int cellStartY = GetCellStartY(cellPos);

	// Calculate the Radius of the Player's Triangle
	int radius = UI.CellWidth / 14; // proportional to cell width

	// Calculate the horizontal space before drawing players triangles (space from the left border of the cell)
	int ySpace = UI.CellHeight / 6; // proportional to cell height

	// Note: Players' Triangles Locations depending on "playerNum" is as follows:
	// Player_0
	// Player_1

	// Calculate the Y coordinate of the center of the player's triangle (based on playerNum)
	int y = cellStartY + ySpace + radius + 2;
	if (playerNum == 1)
		y += 2 * (radius + 2); // because playerNum 1 is drawn in the second row of triangles

	// Calculate the X coordinate of the center of the player's triangle (based on playerNum)
	int x = cellStartX + UI.BeltXOffset + radius + 4; // UI.BeltXOffset is used to draw players' triangles 
	// AFTER the Belt start vertical line (assuming there is a belt)
	// for not overlapping with belts

// TODO: Draw the player triangle in center(x,y) and filled with the playerColor passed to the function
	pWind->SetPen(playerColor);
	pWind->SetBrush(playerColor);

	int triangleWidth = UI.CellWidth / 4;
	int triangleHeight = UI.CellHeight / 4;

	DrawTriangle(x, y, triangleHeight, triangleWidth, direction, playerColor);
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawBelt(const CellPosition& fromCellPos, const CellPosition& toCellPos) const
{
	// TODO: Validate the fromCell and toCell (Must be Horizontal or Vertical, and we can't have the first cell as a starting cell for a belt)
	if (!fromCellPos.IsValidCell() || fromCellPos.GetCellNum() == 0) {  //check if cell is valid & not starting cell
		return;
	}
	if (!toCellPos.IsValidCell()) {
		return;
	}
	bool isHorizontal = (fromCellPos.HCell() != toCellPos.HCell() && fromCellPos.VCell() == toCellPos.VCell()); //check if cell is horizontal
	bool isVertical = (fromCellPos.VCell() != toCellPos.VCell() && fromCellPos.HCell() == toCellPos.HCell()); //check if cell is vertical
	if (!isHorizontal && !isVertical) {
		return;
	}

	// Get the start X and Y coordinates of the upper left corner of the fromCell and toCell
	int fromCellStartX = GetCellStartX(fromCellPos);
	int fromCellStartY = GetCellStartY(fromCellPos);
	int toCellStartX = GetCellStartX(toCellPos);
	int toCellStartY = GetCellStartY(toCellPos);

	int beltFromCellX = fromCellStartX + UI.BeltXOffset;
	int beltFromCellY = fromCellStartY + UI.BeltYOffset;

	int beltToCellX = toCellStartX + UI.BeltXOffset;
	int beltToCellY = toCellStartY + UI.BeltYOffset;


	// TODO: Draw the belt line and the triangle at the center of the line pointing to the direction of the belt

	Direction dirOfBelt;
	if (isHorizontal) {
		if (beltFromCellX < beltToCellX) {
			dirOfBelt = RIGHT;
		}
		else {
			dirOfBelt = LEFT;
		}
	}
	else if (isVertical) {
		if (beltFromCellY < beltToCellY) {
			dirOfBelt = DOWN;
		}
		else {
			dirOfBelt = UP;
		}
	}

	// TODO: 1. Set pen color and width using the appropriate parameters of UI_Info object (UI)
	//       2. Draw the line of the belt using the appropriate coordinates
	pWind->SetPen(UI.BeltColor, UI.BeltLineWidth);
	pWind->DrawLine(beltFromCellX, beltFromCellY, beltToCellX, beltToCellY);


	// TODO: Draw the triangle at the center of the belt line pointing to the direction of the belt

	int triangleWidth = UI.CellWidth / 4;
	int triangleHeight = UI.CellHeight / 4;


	int xCenter = (beltFromCellX + beltToCellX) / 2;
	int yCenter = (beltFromCellY + beltToCellY) / 2;



	pWind->SetPen(UI.BeltColor);
	pWind->SetBrush(UI.BeltColor);
	DrawTriangle(xCenter, yCenter, triangleHeight, triangleWidth, dirOfBelt, UI.BeltColor);


}//////////////////////////////////////////////////////////////////////////////////////////



void Output::DrawFlag(const CellPosition& cellPos) const
{
	// TODO: Validate the cell position
	if (!cellPos.IsValidCell() || cellPos.GetCellNum() == 1) {
		return;
	}

	// Get the X and Y coordinates of the start point of the cell (its upper left corner)
	int cellStartX = GetCellStartX(cellPos);
	int cellStartY = GetCellStartY(cellPos);

	// TODO: Draw the flag as a line with a triangle connected to it directed to right
	// TODO: 1. Draw the flag pole (the line)
	int flagPoleStartX = cellStartX + UI.CellWidth / 2;
	int flagPoleStartY = cellStartY + UI.CellHeight / 4;
	int flagPoleEndX = flagPoleStartX;
	int flagPoleEndY = flagPoleStartY + UI.FlagPoleHeight;

	pWind->SetPen(UI.FlagPoleColor, UI.FlagPoleWidth);
	pWind->DrawLine(flagPoleStartX, flagPoleStartY, flagPoleEndX, flagPoleEndY);


	// 		 2. Draw the flag (the triangle)

	int triangleWidth = UI.CellWidth / 4;
	int triangleHeight = UI.CellHeight / 4;

	int xCenter = flagPoleStartX + triangleWidth / 2;
	int yCenter = flagPoleStartY + (triangleHeight / 2);


	pWind->SetPen(UI.FlagColor);
	pWind->SetBrush(UI.FlagColor);
	DrawTriangle(xCenter, yCenter, triangleHeight, triangleWidth, RIGHT, UI.FlagColor);


}


void Output::DrawRotatingGear(const CellPosition& cellPos, bool clockwise) const
{
	// TODO: Validate the cell position

	if (!cellPos.IsValidCell() || cellPos.GetCellNum() == 1)
	{
		return;
	}

	// TODO: Draw the rotating gear image in the cell based on the passed direction (clockwise or counter clockwise)

	if (clockwise)
	{
		DrawImageInCell(cellPos, "images\\RotatingCW.jpg", UI.CellWidth, UI.CellHeight);
	}
	else
	{
		DrawImageInCell(cellPos, "images\\RotatingACW.jpg", UI.CellWidth, UI.CellHeight);
	}
}

void Output::DrawAntenna(const CellPosition& cellPos) const
{
	// TODO: Validate the cell position
	if (!cellPos.IsValidCell() || cellPos.GetCellNum() == 1)
	{
		return;
	}

	// TODO: Draw the antenna image in the cell
	DrawImageInCell(cellPos, "images\\Antenna.jpg", UI.CellWidth, UI.CellHeight);


}

void Output::DrawWorkshop(const CellPosition& cellPos) const
{
	// TODO: Validate the cell position

	if (!cellPos.IsValidCell() || cellPos.GetCellNum() == 1)
	{
		return;
	}


	// TODO: Draw the workshop image in the cell
	DrawImageInCell(cellPos, "images\\Workshop.jpg", UI.CellWidth, UI.CellHeight);


}

void Output::DrawDangerZone(const CellPosition& cellPos) const
{
	///TODO: Complete the implementation of the following function
	if (!cellPos.IsValidCell() || cellPos.GetCellNum() == 1)
	{
		return;
	}

	DrawCell(cellPos, RED);

}

void Output::DrawWaterPit(const CellPosition& cellPos) const
{
	///TODO: Complete the implementation of the following function
	int cellnum = cellPos.GetCellNumFromPosition(cellPos);
	if (!cellPos.IsValidCell() || cellnum == 1)
	{
		return;
	}

	DrawCell(cellPos, BLUE);

}



Output::~Output()
{
	// deallocating the window object
	delete pWind;
}

