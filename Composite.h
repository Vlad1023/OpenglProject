#pragma once
#include "Interfaces.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Composite :  public IShape {
private:
	vector<IShape*> childs;
public:
	void addChild(IShape* to_Add) override{
		childs.push_back(to_Add);
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
	name = "standart";
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
	~Composite() override {
		for (IShape* n : childs) {
			delete n;
		}
	}	
};