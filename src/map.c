#include "../headers/map.h"


void drawMap(int mapWidth, int mapHeight){
    glTranslatef(floorScaleX/2, floorScaleY/2, 0);
    for (int i=0; i<mapWidth; i++){
        glPushMatrix();

        for (int j=0; j<mapHeight; j++){
            glPushMatrix();
                glScalef(floorScaleX, floorScaleY, floorScaleZ);
                glutWireCube(1);
            glPopMatrix();
            glTranslatef(floorScaleX, 0, 0);
        }
        
        glPopMatrix();
        glTranslatef(0, levelHeight, 0);
    }
}