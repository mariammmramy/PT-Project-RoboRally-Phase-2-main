#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}

GameObject::GameObject(const GameObject& oldobj)	//copy constructor
{
	position = oldobj.position;
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

void GameObject::SetPosition(CellPosition pos)
{
	position = pos;
}

GameObject::~GameObject()
{
}