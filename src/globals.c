#include "../headers/globals.h"


void initGlobals(){
    appWindowWidth = glutGet(GLUT_SCREEN_HEIGHT)/1.25;

    floorWidth = 7;
    totalFloors = 7;

    GLfloat color1[3] = {1, 0, 0};
    player1 = createPlayer(color1, "Joka");
    player1->positionX = 2;
    player1->positionY = 0;

    GLfloat color2[3] = {0, 1, 0};
    player2 = createPlayer(color2, "Saskic");
    player2->positionX = 3;
    player2->positionY = 3;

    GLfloat color3[3] = {0, 0, 1};
    player3 = createPlayer(color3, "Mika");
    player3->positionX = 4;
    player3->positionY = 1;

    GLfloat color4[3] = {0, 0, 0};
    player4 = createPlayer(color4, "Igi");
    player4->positionX = 1;
    player4->positionY = 4;

    glRasterPos2d(4, 4);
    
}