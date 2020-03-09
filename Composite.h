#pragma once
#include "Interfaces.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
class Composite :  public IShape {	
public:
	vector<IShape*> childs;
	void addChild(IShape* to_Add) override{
		childs.push_back(to_Add);
	}
	void setChild(int index, IShape* toAdd) override
	{
		childs[index] = toAdd;
	}
	IShape* operator[] (int index) override
	{
		return childs.at(index);
	}
	void IDraw() override {
		for (IShape* n : childs) {
			n->IDraw();
		}
	}
	void moveLeft() override
	{
		for (IShape* n : childs) {
			n->moveLeft();
		}
	}
	void moveRight() override
	{
		for (IShape* n : childs) {
			n->moveRight();
		}
	}
	void moveDown() override
	{
		for (IShape* n : childs) {
			n->moveDown();
		}
	}
	void moveUp() override
	{
		for (IShape* n : childs) {
			n->moveUp();
		}
	}
	Composite()
	{
		IInitialize();
	}
	void changeTail() override
	{
		for (IShape* n : childs) {
			n->changeTail();
		}
		
	}
	void IInitialize() override
	{
		/*
		cout << "Input name of composite" << endl;
		cin >> name;
		*/
	name = "Composite";
	}
	bool ICheckCollision(IShape& another) override {
		return false;
	}
	void IChangeableColor() override {
		for (IShape* n : childs) {
			n->IChangeableColor();
		}
	}
	IShape* IClone() override
	{
		Composite* clone = new Composite();
		for (IShape* n : childs) {
			clone->addChild(n->IClone());
		}
		return clone;
	}
	string returnToFile() override
	{
		ostringstream oss;
		oss << "{";
		for (IShape* n : childs) {
			oss << "\n";
			oss << n->returnToFile();
		}
		oss << "\n";
		oss << "}";
		return oss.str();
	}
	~Composite() override {
		for (IShape* n : childs) {
			delete n;
		}
	}	
};