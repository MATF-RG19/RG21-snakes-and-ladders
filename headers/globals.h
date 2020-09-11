#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <GL/glut.h>
#include "../headers/player.h"

#define DEBUG_MODE 0

Player *player1;
Player *player2;
Player *player3;
Player *player4;

int appWindowWidth;

int floorWidth;
int totalFloors;


void initGlobals();

#endif