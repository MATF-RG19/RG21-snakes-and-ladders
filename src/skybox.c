#include "../headers/skybox.h"

/*http://www.it.hiof.no/~borres/j3d/explain/light/p-materials.html*/



void drawSkybox(){

    glPushMatrix();
       
        GLfloat ambient_coeffs_wall[] = {0.0f,0.05f,0.05f,1.0f};
        GLfloat diffuse_coeffs_wall[] = {0.4f,0.5f,0.5f,1.0f };
        GLfloat diffuse_coeffs_floor[] = {0.4f,0.9f,0.5f,1.0f };
        GLfloat specular_coeffs_wall[] = {0.04f,0.7f,0.7f,1.0f};
        GLfloat shininess_wall = 10.0f;

        //BEHIND
        glPushMatrix();
            glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_wall);
            glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_wall);
            glMaterialf(GL_FRONT, GL_SHININESS, shininess_wall);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_wall);
            glTranslatef(5, 8, -3);
            glScalef(100, 20, 1);
            glutSolidCube(1);
        glPopMatrix();

        //RIGHT
        glPushMatrix();
             glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_floor);
            glTranslatef(5, -5, -3);
            glRotatef(90,1,0, 0);
            glScalef(100, 20, 1);
            glutSolidCube(1);
        glPopMatrix();

    glPopMatrix();
}