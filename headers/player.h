#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <GL/glut.h>

typedef struct Player{
    GLfloat color[3];
    int positionX;
    int positionY;
    char name[10];
} Player;

Player *createPlayer(GLfloat color[3], char name[10]);
void drawPlayer(Player *player);
void drawPlayerNames();

#endif