#pragma once
#include "Interfaces.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Composite:  public IShape {
private:
	vector<IShape*> childs;

public:
	void addChild(IShape* toAdd) {
		childs.push_back(toAdd);
	}
	void IDraw() override {

		for (IShape* n : childs) {
			n->IDraw();
		}
		
	}
	void IInitialize() override {
	}
	void IClone() override {
	}
	bool ICheckCollision(IShape& another) override {
		return false;
	}
	void IDrawShape() override {
		
	}
	void IChangeableColor() override {
		for (IShape* n : childs) {
			n->IChangeableColor();
		}
	}

	~Composite() override {
		for (IShape* n : childs) {
			delete n;
		}
	}
};