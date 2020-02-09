#pragma once
#include "Interfaces.h"
# define M_PI 3.14159265358979323846
class Circle : Component {
public:
    void IDraw()
    {
        int numberOfVertices = 202;

        GLfloat twicePi = 2.0f * M_PI;

        GLfloat circleVerticesX[202];
        GLfloat circleVerticesY[202];
        GLfloat circleVerticesZ[202];

        circleVerticesX[0] = x;
        circleVerticesY[0] = y;
        circleVerticesZ[0] = z;

        for (int i = 1; i < 202; i++)
        {
            circleVerticesX[i] = x + (radius * cos(i * twicePi / 200));
            circleVerticesY[i] = y + (radius * sin(i * twicePi / 200));
            circleVerticesZ[i] = z;
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
    Circle() {
        
    }
private:
    GLfloat x, y, z, radius;
};
class Rectangle : Component {

};