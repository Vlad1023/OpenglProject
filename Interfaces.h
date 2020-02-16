#pragma once
#include <string>
#include <iostream>
using namespace std;
class IShape {
protected:
	string name;
public:
	virtual bool ICheckCollision(IShape& another) = 0;
	virtual void IClone() = 0;
	virtual void IDraw() = 0;
	virtual void IDrawShape() = 0;
	virtual void IChangeableColor() = 0;
	virtual void IInitialize() = 0;
	string IgetName()
	{
		return name;
	}
	string IsetName(string name)
	{
		this->name = name;
	}
	virtual ~IShape() {}
};
class IPrimitive : public IShape {
public:
	void IChangeableColor() override {
		glColor3b(rand() % 255, rand() % 255, rand() % 255);
	}

};
