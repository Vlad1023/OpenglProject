#pragma once
#include <string>
#include <iostream>
using namespace std;
class IShape {
protected:
	GLfloat colorInfo[3];
public:
	virtual void IChangeableColor(){
		for (int i = 0; i < 3; i++)
		{
			colorInfo[i] = float(rand()) / RAND_MAX;
		}
	}
	float sizeX;
	float sizeY;
	float PosX;
	float PosY;
	bool trajectoryMove = true;
	void changeTrajectory() { trajectoryMove = !trajectoryMove; }
	virtual void sizeIncrease() = 0;
	virtual bool CheckCollision(IShape& ref) = 0;
	virtual IShape* IClone() = 0;
	virtual void IInitialize() = 0;
	virtual void IDraw() = 0;
	virtual string returnToFile() = 0;
	virtual void moveLeft() = 0;
	virtual void moveRight() = 0;
	virtual void moveUp() = 0;
	virtual void moveDown() = 0;
	virtual void changeTail() = 0;
	virtual void addChild(IShape* to_Add) = 0;
	virtual void setChild(int index, IShape* toAdd) {}
	virtual IShape* operator[] (int index) { return this; }
	string name;
	virtual ~IShape() {};
};
class IPrimitive : public IShape {
protected:
	bool ifDrawTail;
public:
	void addChild(IShape* to_Add) override{}
	IPrimitive()
	{
		IChangeableColor();
	}
	void changeTail() override
	{
		this->ifDrawTail = !(this->ifDrawTail);
	}
	virtual void IDrawTail() = 0;
	virtual void OutOfWindow() = 0;
	virtual void QuickInit() = 0;
};
