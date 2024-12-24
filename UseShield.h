#pragma once
#include "Action.h"
#include "Grid.h"
#include "Player.h"
class UseShield:public Action
{
public:
    UseShield(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual ~UseShield();
};

