#pragma once
#include <string>
#include <iostream>
using namespace std;
class Component {
protected:
	string name;
public:
	virtual bool ICheckCollision(Component& another) { return false; }
	virtual void IDraw() { return; }
	virtual void IDrawShape() { return; }
	virtual void IChangeableColor() { return; }
	string IgetName()
	{
		return name;
	}
};
