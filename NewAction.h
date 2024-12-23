#pragma once
#include "Action.h"
#include "Grid.h"
#include "Player.h"
class NewAction :public Action
{
    NewAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();// Executes new action
    virtual ~NewAction();
};