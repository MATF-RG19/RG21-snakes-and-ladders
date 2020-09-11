#include "../headers/skybox.h"

/*http://www.it.hiof.no/~borres/j3d/explain/light/p-materials.html*/

void drawSkybox(){

    glPushMatrix();
       
        GLfloat ambient_coeffs_wall[] = {0.0f,0.05f,0.05f,1.0f};
        GLfloat ambient_coeffs_floor[] = {0.19125f, 0.0735f, 0.0225f, 1.0f};

        /* Koeficijenti difuzne refleksije materijala. */
        GLfloat diffuse_coeffs_wall_1[] = {0.4f,0.5f,0.5f,1.0f };
        GLfloat diffuse_coeffs_wall_2[] = {0.4f,0.8f,0.5f,1.0f };

        GLfloat diffuse_coeffs_floor_1[] = {0.1f,0.35f,0.1f,1.0f };
        GLfloat diffuse_coeffs_floor_2[] = {0.1f,0.1f,0.1f,1.0f };


        /* Koeficijenti spekularne refleksi je materijala. */
        GLfloat specular_coeffs_wall[] = {0.04f,0.7f,0.7f,1.0f};
        GLfloat specular_coeffs_floor[] = {0.256777f, 0.137622f, 0.086014f, 1.0f };

        /* Koeficijent glatkosti materijala. */
        GLfloat shininess_wall = 10.0f;
        GLfloat shininess_floor = 12.8f;

        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_wall);

        glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_wall);
        glMaterialf(GL_FRONT, GL_SHININESS, shininess_wall);

                //LEFT
        glBegin(GL_QUADS);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_wall_1);
            glVertex3f(-3, 0, -5);
            glVertex3f(-3, 50, -5);
            glVertex3f(0, 50, 13.5);
            glVertex3f(0, 0, 13.5);
        glEnd();
        //BACK
        glBegin(GL_QUADS);
           
            glVertex3f(-3, 0, -5);
            glVertex3f(-3, 50, -5);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_wall_2);
            glVertex3f(13.5, 50, -5);
            glVertex3f(13.5, 0, -5);
        glEnd();

        //RIGHT
        glBegin(GL_QUADS);
            glVertex3f(13.5, 0, -5);
            glVertex3f(13.5, 50, -5);
            glVertex3f(13.5, 50, 15);
            glVertex3f(13.5, 0, 15);
        glEnd();


        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_floor);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_floor_1);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_floor);
        glMaterialf(GL_FRONT, GL_SHININESS, shininess_floor);
        glColor3f(0, 0, 1);
        //BOTTOM
        glBegin(GL_QUADS);
            glVertex3f(-3, 0, -5);
            glVertex3f(-3, 0, 13.5);
            glVertex3f(13.5, 0, 13.5);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_floor_2);
            glVertex3f(13.5, 0, -5);
        glEnd();

    glPopMatrix();
}