#pragma once
#include <iostream>
#include <fstream>
#include "Interfaces.h"
using namespace std;
class ShapeMemento
{
 static ifstream in;
public:
	static void saveState(IShape& toSave)
	{
		ofstream out;
		out.open("save.txt");
		out << toSave.returnToFile();
	}
	
	static void loadState(Composite& toLoad)
	{
		in.open("save.txt");
		string cur;
	}
	static void loadStateHelper(IShape& toLoad,fstream& in)
	{
		string current;
		int chdCount;
		getline(in, current);
		while(current != "}")
		{
			if(current == "{")
			{
				vector<IShape*>::iterator it;
				int i = 0;
				for (it = toLoad.childs.begin(); i < chdCount ; it++)
				{
					i++;
				}
				loadStateHelper(&it,in);
			}
			chdCount++;
		}
	}
};