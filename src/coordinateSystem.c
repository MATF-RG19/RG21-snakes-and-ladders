#include "../headers/coordinateSystem.h"

void drawCoordinateSystem(){
    glBegin(GL_LINES);

        glColor3f(1, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(100, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(-100, 0, 0);


        glColor3f(0, 1, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 100, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, -100, 0);


        glColor3f(0, 0, 1);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 100);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, -100);

    glEnd();
}
