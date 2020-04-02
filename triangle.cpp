//
//  triangle.cpp
//  Interaction in OpenGl using Mouse
//
//  Created by UNI on 4/2/20.
//  Copyright © 2020 jennan sowayan. All rights reserved.
//

#include "triangle.hpp"
#include <iostream>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <stdlib.h>
#include <string.h>

float r, g, b, x, y, x1, x2, x3, y1, y2, y3;
bool check = true;

void mouse(int button, int state, int x, int y)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
       check = true;
        int x1 = x;
        int y1 = 600 - y;

         r=(rand()%9)/8;
         g=(rand()%9)/8;
         b=(rand()%9)/8;

         x2 = x1 - 50;
         y2 = y1 - 50;

         x3 = x1 + 50;
         y3 = y1 + 50;
     }
}

void DrawTriangle(){
           glColor3f(r,g,b);

            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluOrtho2D(0.0, 600.0, 0.0, 600.0);
        
    
    if(check)
        {
        glPointSize(50);
        
        glBegin(GL_TRIANGLES);
        
        glVertex2i(x1, y1);
        glVertex2i(x2, y2);
        glVertex2i(x3, y3);

        
        glEnd();
        glFlush();
    }

}

int main()
{
    glutInitWindowSize(640, 600);   //sets the width and height of the window in pixels
    glutInitDisplayMode(GLUT_RGB);//creates a single frame buffer of RGB color capacity.
    glutCreateWindow("TRIANGLE");//creates the window as specified by the user as above.
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(DrawTriangle);
    glutMouseFunc(mouse);
    glutMainLoop();
}
