#pragma once
#include "Interfaces.h"
#include <iostream>
using namespace std;
# define M_PI 3.14159265358979323846
class Circle :  public IPrimitive {
public:
    void IDraw() override
    {
        int numberOfVertices = 202;
        GLfloat twicePi = 2.0f * M_PI;

        GLfloat circleVerticesX[202];
        GLfloat circleVerticesY[202];
        GLfloat circleVerticesZ[202];

        circleVerticesX[0] = this->x;
        circleVerticesY[0] = this->y;
        circleVerticesZ[0] = 0;

        for (int i = 1; i < 202; i++)
        {
            circleVerticesX[i] = this->x + (this->radius * cos(i * twicePi / 200));
            circleVerticesY[i] = this->y + (this->radius * sin(i * twicePi / 200));
            circleVerticesZ[i] = 0;
        }

        GLfloat allCircleVertices[(202) * 3];

        for (int i = 0; i < 202; i++)
        {
            allCircleVertices[i * 3] = circleVerticesX[i];
            allCircleVertices[(i * 3) + 1] = circleVerticesY[i];
            allCircleVertices[(i * 3) + 2] = circleVerticesZ[i];
        }
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, allCircleVertices);
        glDrawArrays(GL_TRIANGLE_FAN, 0, numberOfVertices);
        glDisableClientState(GL_VERTEX_ARRAY);
    }
    void IInitialize() override {
        cout << "Input circle name" << endl;
        cin >> this->name;
        cout << "Input circle x" << endl;
        cin >> this->x;
        cout << "Input circle y" << endl;
        cin >> this->y;
        cout << "Input radius lenght" << endl;
        cin >> this->radius;
    }
    Circle() {
        IInitialize();
    }
    bool ICheckCollision(IShape& another) override {
        return false;
    }
    void IClone() override {

    }
    void IDrawShape() override {

    }
    void IChangeableColor() override {

    }
private:
    GLfloat x, y, radius;
};




class Rectangle : public IPrimitive {
public:
    void windowOut() {
       
    }
    void IDraw() override
    {
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(2, GL_FLOAT, 0, vertices);
        glDrawArrays(GL_QUADS, 0, 4);
        glDisableClientState(GL_VERTEX_ARRAY);
    }
    void IInitialize() override {      
        cout << "Input rectangle name" << endl;
        cin >> this->name;
        cout << "Input rectangle top right" << endl;
        cin >> vertices[0] >> vertices[1];
        cout << "Input rectangle top left" << endl;
        cin >> vertices[2] >> vertices[3];
        cout << "Input rectangle bottom left" << endl;  
        cin >> vertices[4] >> vertices[5];
        cout << "Input rectangle bottom right" << endl;
        cin >> vertices[6] >> vertices[7];
    }
    Rectangle() {
        IInitialize();
    }
    bool ICheckCollision(IShape& another) override {
        return false;
    }
    void IClone() override {

    }
    void IDrawShape() override {

    }
private:
    float vertices[8];
};