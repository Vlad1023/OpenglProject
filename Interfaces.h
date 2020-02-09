#pragma once
class Component {
private:
	GLfloat xCol, yCol, sizeX, sizeY;
public:
	virtual bool CheckCollision(Component& one, Component& two) = 0;
	virtual void IDraw() = 0;
	virtual void IDrawShape() = 0;
	virtual void IChangeableColor() = 0;
};
