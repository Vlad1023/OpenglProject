#pragma once
#include <fstream>
#include <string>
#include "Interfaces.h"
#include <sstream>
class ShapeMemento
{
private:
	static string current;
public:
	static void saveState(IShape& toSave)
	{
		ofstream out;
		out.open("save.txt");
		out << toSave.returnToFile();
	}
	
	static void loadState(IShape& toLoad)
	{
		fstream in;
		in.open("save.txt");
		getline(in, current);
		loadStateHelper(toLoad, in);
		in.close();
	}
	static void loadStateHelper(IShape& toLoad,fstream& in)
	{
		int chdCount = 0;
		getline(in, current);
		while(current != "}")
		{
			if(current == "{")
			{			
				loadStateHelper(*toLoad.operator[](chdCount),in);
			}
			std::vector<string> ref;
			std::istringstream ss(current);
			string tmp;
			while (getline(ss, tmp, ' '))
			{
				ref.push_back(tmp.c_str());
			}
			if(ref.at(0) == "Circle")
			{
				loadCircle(toLoad, chdCount ,ref);
			}
			else if (ref.at(0) == "Rectangle")
			{
				loadRectangle(toLoad, chdCount, ref);
			}
			getline(in, current);
			chdCount++;	
		}
	}
	static void loadCircle(IShape& toInit, int index, std::vector<string> ref)
	{
		auto* circ = new Circle(stof(ref.at(1)),stof(ref.at(2)),stof(ref.at(3)), stof(ref.at(4)), stof(ref.at(5)), stof(ref.at(6)), false);
		toInit.setChild(index, circ);	
	}
	static void loadRectangle(IShape& toInit, int index, std::vector<string> ref)
	{
		float vertices[8];
		for (int i = 0; i < 8; i++)
		{
			vertices[i] = stof(ref.at(i+1));
		}
		auto* circ = new Rectangle(vertices, stof(ref.at(9)), stof(ref.at(10)), stof(ref.at(11)), false);
		toInit.setChild(index, circ);
	}
};
string ShapeMemento::current;