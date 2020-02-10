#pragma once
#include "Interfaces.h"
#include <iostream>
#include <vector>
using namespace std;
class Composite:  public Component {
private:
	vector<Component> childs;

public:
	void addChild(const Component &toAdd) {
		childs.push_back(toAdd);
	}
	Component& findByName(string name) {
		for (Component& n : childs) {


			return n;
		}
	}
	void IDraw() override {
		
	}
	bool ICheckCollision(Component& another) override {
		return false;
	}
	void IDrawShape() override {
		
	}
	void IChangeableColor() override {
		
	}
};