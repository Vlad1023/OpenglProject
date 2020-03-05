#pragma once
#include <string>
#include <iostream>
using namespace std;
class IShape {
public:
	virtual bool ICheckCollision(IShape& another) = 0;
	virtual void IInitialize() = 0;
	virtual void IDraw() = 0;
	virtual void IDrawTail() = 0;
	virtual void IChangeableColor() = 0;
	virtual void moveLeft() = 0;
	virtual void moveRight() = 0;
	virtual void moveUp() = 0;
	virtual void moveDown() = 0;
	virtual void addChild(IShape* to_Add) = 0;
	bool ifDrawTail = true;
	string name;
	virtual ~IShape() {};
};
class IPrimitive : public IShape {
protected:
	GLfloat colorInfo[3];
public:
	void IChangeableColor() override {
		for (int i = 0; i < 3; i++)
		{
			colorInfo[i] = float(rand()) / RAND_MAX;
		}
	}
	void addChild(IShape* to_Add) override{}
	IPrimitive()
	{
		IChangeableColor();
	}
	virtual void OutOfWindow() = 0;
};
