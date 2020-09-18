#ifndef _MAP_H_
#define _MAP_H_

#include <GL/glut.h>
#include <math.h>

#define floorScaleX 1.5
#define floorScaleY 0.15
#define floorScaleZ 2.0
#define levelHeight 1.3

#define PI 3.1415927


typedef struct Position{
    int x;
    int y;
} Position;

void drawMap(int mapWidth, int mapHeight);
void draw_cylinder(GLfloat radius, GLfloat height, GLubyte R, GLubyte G, GLubyte B);
void drawEdges();

#endif
