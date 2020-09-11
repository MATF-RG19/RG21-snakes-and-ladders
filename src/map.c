#include "../headers/map.h"
#include "../headers/globals.h"


void drawMap(int mapWidth, int mapHeight){
    glPushMatrix();
    glTranslatef(floorScaleX/2, floorScaleY/2, 0);
    for (int i=0; i<mapWidth; i++){
        glPushMatrix();

        for (int j=0; j<mapHeight; j++){
            glPushMatrix();
                glColor3f(0.6, 0.2, 0);
                glScalef(floorScaleX, floorScaleY, floorScaleZ);
                glutSolidCube(1);
                if (DEBUG_MODE){
                    glColor3f(0.6, 1, 0);
                    glutWireCube(1);
                }
            glPopMatrix();
            glTranslatef(floorScaleX, 0, 0);
        }

        glPopMatrix();
        glTranslatef(0, levelHeight, 0);
    }
    glPopMatrix();
}