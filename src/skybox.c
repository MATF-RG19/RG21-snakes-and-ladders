#include "../headers/skybox.h"

void drawSkybox(){

    glPushMatrix();
        glColor3f(1, 1, 0);
        glBegin(GL_QUADS);
            glVertex3f(0, 0, -20);
            glVertex3f(0, 15, -20);
            glVertex3f(15, 15, -20);
            glVertex3f(15, 0, -20);
        glEnd();
    glPopMatrix();
}