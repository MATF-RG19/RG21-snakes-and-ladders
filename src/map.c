#include "../headers/map.h"
#include "../headers/globals.h"
#include "../headers/lights.h"

void drawMap(int mapWidth, int mapHeight){
    glPushMatrix();


    set_map_materials();

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
/* gits.github.com/nikAizuddin/5ea402e9073f1ef76ba6*/


void draw_cylinder(GLfloat radius, GLfloat height, GLubyte R, GLubyte G, GLubyte B)
{
    GLfloat x = 0.0;
    GLfloat y = 0.0;
    GLfloat angle = 0.0;
    GLfloat angle_stepsize = 0.1;

    // Draw the tube
    glColor3ub(R-40,G-40,B-40);
    glBegin(GL_QUAD_STRIP);
        angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            glVertex3f(x, y , 0.0);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
        glVertex3f(radius, 0.0, 0.0);
    glEnd();

    // Draw the circle on top of cylinder
    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
        angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
    glEnd();
}


void drawEdges(){
    int i = 1;

    glPushMatrix();
        while(i < totalFloors){
            if(i%2 == 0){  
                glPushMatrix();
                    glTranslatef(-0.7, levelHeight*i, 0);
                    glRotatef(90,1,0, 0);
                    draw_cylinder(0.1, levelHeight, 255, 160, 100);
                glPopMatrix();
            }
            else{
                glPushMatrix();
                    glTranslatef(floorScaleX * floorWidth - 0.8, levelHeight*i, 0);
                    glRotatef(90,1,0, 0);
                    draw_cylinder(0.1, levelHeight, 255, 160, 100);
                glPopMatrix();
            }
            i++;
        }
    glPopMatrix();
}
