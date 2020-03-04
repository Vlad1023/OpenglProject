#pragma once
#include <map> 
#include <iostream>
#include "Interfaces.h"
using namespace  std;
class Container
{
private:
	map <string, IShape*> container;
public:
	void Insert(IShape* toAdd)
	{
		container.insert(pair<string, IShape*>(toAdd->name, toAdd));
	}
};