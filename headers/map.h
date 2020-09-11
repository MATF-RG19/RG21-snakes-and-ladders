#ifndef _MAP_H_
#define _MAP_H_

#include <GL/glut.h>

#define floorScaleX 1.5
#define floorScaleY 0.15
#define floorScaleZ 2.0
#define levelHeight 1.2

typedef struct Position{
    int x;
    int y;
} Position;

void drawMap(int mapWidth, int mapHeight);
Position *getCoordinates(int x, int y);
#endif
