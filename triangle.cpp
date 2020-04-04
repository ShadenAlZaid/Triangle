
#include <iostream>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <stdlib.h>
#include <string.h>

int flag = 0;
int x1 = 0;
int y1 = 0;

void DrawTriangle (void) {
      if (flag == 1){
        glColor3f(1,1,1); // sets color of triangle to white
        glBegin(GL_TRIANGLES);
        glVertex2i(x1, y1);
        glVertex2i(x1, y1 + 50);
        glVertex2i(x1 - 50, y1);
        glEnd();
      }


    glFlush();
}

void Mouse (int button, int state, int x, int y) {
    
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){ // if left button is clicked down
         x1 = x;
         y1 = y;
         flag = 1; // set flag to 1  to draw triangle
         glutPostRedisplay();

}
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("TRIANGLES");
    glutDisplayFunc(DrawTriangle);

    glutMouseFunc(Mouse);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 600, 600, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutMainLoop();
    return 0;
}
