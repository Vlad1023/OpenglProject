#pragma once
#include <map> 
#include <iostream>
#include "Interfaces.h"
using namespace std;
class Container
{
private:
	static map <string, unique_ptr<IShape>> container;
	static int contrNumb;
	static IShape* curContr;
public:
	static void Insert(IShape* toAdd)
	{
		container.insert(pair<string, IShape*>(toAdd->name, toAdd));
	}
	static void setControlled(IShape* toSet)
	{
		curContr = toSet;
	}
    static void changeControlller(string name) {
        map<string, unique_ptr<IShape>>::iterator it;
        for (it = container.begin(); it->second->name != name; it++)
        {
            if((it++) == container.end())
            {
				setControlled(container.begin()->second.get());
                curContr = 0;
            }
            else
            {
                setControlled(it->second.get());
                curContr++;
            }

        }
    }
	static void manEvs()
	{
        map<string, unique_ptr<IShape>>::iterator it;
        for (it = container.begin(); it != container.end(); it++)
        {
            it->second->IDraw();
        }
	}
    static void groupShapes() {

    }
};
map <string, unique_ptr<IShape>> Container::container;
IShape* Container::curContr;