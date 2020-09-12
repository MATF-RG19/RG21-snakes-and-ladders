#include "../headers/lights.h"







void init_light(){

    /* Spekularna boja svetla. */
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    GLfloat light_position[] = { 1, 0, 1, 0 };
    GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1 };
    GLfloat light_diffuse[] = { 0.7, 0.7, 0.7, 1 };
    GLfloat light_specular[] = { 0.2, 0.3, 0.2, 1 };

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    GLfloat light_position_1[] = { 3, 0.2, 4, 0 };
    glLightfv(GL_LIGHT1, GL_POSITION, light_position_1);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);

}

void set_player_materials(){

    GLfloat ambient_coeffs[] = { 1.0, 0.1, 0.1, 1 };
    GLfloat specular_coeffs[] = { 0.5, 0.5, 0.5, 0.5};
    GLfloat shininess = 20;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

void set_map_materials(){
    GLfloat ambient_coeffs[] = { 0.2295f, 0.08825f, 0.0275f, 1.0f };
    GLfloat diffuse_coeffs[] = {0.5508f, 0.2118f, 0.066f, 1.0f };  
    GLfloat specular_coeffs[] = { 0.580594f, 0.223257f, 0.0695701f, 1.0f };
    GLfloat shininess = 51.2f;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}