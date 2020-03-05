#pragma once
#include "Interfaces.h"
#include <iostream>
#include <vector>
using namespace std;
# define M_PI 3.14159265358979323846
# define SPEED 0.01
class Circle :  public IPrimitive {
public:
    void IDraw() override
    {
        xTail = x;
        yTail = y;
        if (ifDrawTail)
        IDrawTail();
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
        glColor3f(colorInfo[0], colorInfo[1], colorInfo[2]);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, allCircleVertices);
        glDrawArrays(GL_TRIANGLE_FAN, 0, numberOfVertices);
        glDisableClientState(GL_VERTEX_ARRAY);
        OutOfWindow();
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
    void IDrawTail() override {
            int numberOfVertices = 202;
            GLfloat twicePi = 2.0f * M_PI;

            GLfloat circleVerticesX[202];
            GLfloat circleVerticesY[202];
            GLfloat circleVerticesZ[202];

            circleVerticesX[0] = this->xTail;
            circleVerticesY[0] = this->yTail;
            circleVerticesZ[0] = 0;

            for (int i = 1; i < 202; i++)
            {
                circleVerticesX[i] = this->xTail + (this->radius * cos(i * twicePi / 200));
                circleVerticesY[i] = this->yTail + (this->radius * sin(i * twicePi / 200));
                circleVerticesZ[i] = 0;
            }

            GLfloat allCircleVertices[(202) * 3];

            for (int i = 0; i < 202; i++)
            {
                allCircleVertices[i * 3] = circleVerticesX[i];
                allCircleVertices[(i * 3) + 1] = circleVerticesY[i];
                allCircleVertices[(i * 3) + 2] = circleVerticesZ[i];
            }
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glColor4f(colorInfo[0], colorInfo[1], colorInfo[2], 0.5);
            glEnableClientState(GL_VERTEX_ARRAY);
            glVertexPointer(3, GL_FLOAT, 0, allCircleVertices);
            glDrawArrays(GL_TRIANGLE_FAN, 0, numberOfVertices);
            glDisableClientState(GL_VERTEX_ARRAY);
    }
    void moveLeft() override
    {
        
            x -= SPEED;

    }
    void moveRight() override
    {

           x += SPEED;

    }
    void moveDown() override
    {
           y -= SPEED;

    }
    void moveUp() override
    {
       
            y += SPEED;
        
    }
    void OutOfWindow() override
    {
        if (abs(x) >= 1 && abs(y) >= 1) { 
            x = -x;
            y = -y;
        }
    }
private:
    GLfloat x, y, radius;
    GLfloat xTail, yTail;
};




class Rectangle : public IPrimitive {
public:
    void IDraw() override
    {
        for (int i = 0; i < 8; i++)
        {
            float tmp = vertices[i];
            tail[i] = tmp;
        }
    	if (ifDrawTail)
        IDrawTail();
        glColor3f(colorInfo[0], colorInfo[1], colorInfo[2]);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(2, GL_FLOAT, 0, vertices);
        glDrawArrays(GL_QUADS, 0, 4);
        glDisableClientState(GL_VERTEX_ARRAY);
        OutOfWindow();
    }
	void moveLeft() override
    {
        int j = 0;
        for (int i = 0; i <= 3; i++, j += 2)
        {
            vertices[j] -= SPEED;
        }
    }
	void moveRight() override
    {
        int j = 0;
        for (int i = 0; i <= 3; i++, j += 2)
        {
            vertices[j] += SPEED;
        }
    }
	void moveDown() override
    {
        int j = 1;
        for (int i = 0; i <= 3; i++, j += 2)
        {
            vertices[j] -= SPEED;
        }
    }
	void moveUp() override
    {
        int j = 1;
        for (int i = 0; i <= 3; i++,j+=2)
        {
            vertices[j] += SPEED;
        }
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
	void OutOfWindow() override
    {
       bool isOut = false;
       for (int i = 0; i < 8; i++)
       {
           if (abs(vertices[i]) > 1) {
               isOut = true;
           	break;
           }
       }
       if (isOut) {
           for (int i = 0; i < 8; i++)
           {
               vertices[i] = -vertices[i];
           }
       }
    }
    bool ICheckCollision(IShape& another) override {
        return false;
    }
    void IDrawTail() override {
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glColor4f(colorInfo[0], colorInfo[1], colorInfo[2], 0.5);
            glEnableClientState(GL_VERTEX_ARRAY);
            glVertexPointer(2, GL_FLOAT, 0, tail);
            glDrawArrays(GL_QUADS, 0, 4);
            glDisableClientState(GL_VERTEX_ARRAY);
    }
private:
    float vertices[8];
    float tail[8];
};