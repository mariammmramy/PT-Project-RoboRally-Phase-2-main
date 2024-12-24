#pragma once
#include "Action.h"
#include "Grid.h"
#include "ApplicationManager.h"
#include "Input.h"
#include "Output.h"
#include <iostream>
#include "fstream"




class SaveAction : public Action
{
    string Filename;

public:
    SaveAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();
    virtual void Execute();

    ~SaveAction();


};
