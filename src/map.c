#include "../headers/map.h"
#include "../headers/globals.h"


void drawMap(int mapWidth, int mapHeight){
    glPushMatrix();

    GLfloat ambient_coeffs[] = { 0.2295f, 0.08825f, 0.0275f, 1.0f };

    /* Koeficijenti difuzne refleksije materijala. */
    GLfloat diffuse_coeffs[] = {0.5508f, 0.2118f, 0.066f, 1.0f };
    
    GLfloat specular_coeffs[] = { 0.580594f, 0.223257f, 0.0695701f, 1.0f };

    GLfloat shininess = 51.2f;
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

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

