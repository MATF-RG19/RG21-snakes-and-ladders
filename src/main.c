#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#include "../headers/globals.h"
#include "../headers/coordinateSystem.h"
#include "../headers/map.h"

//stanje tajmera
static int timer_active;


//deklaracije callback funkcija

static void on_keyboard(unsigned char key, int x, int y);
static void on_timer(int value);
static void on_reshape(int width, int height);
static void on_display(void);


int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    initGlobals();

    glutInitWindowSize(appWindowWidth, appWindowWidth);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-appWindowWidth)/2, (glutGet(GLUT_SCREEN_HEIGHT)-appWindowWidth)/2);
    glutCreateWindow(argv[0]);

    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);

    timer_active = 0;

    glClearColor(1, 1, 1, 0);
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 0;
}

static void on_keyboard(unsigned char key, int x, int y){
    switch(key) {
        case 27:
            exit(0);
            break;
    }
}

static void on_timer(int value){
    
    if(value != 0)
        return;

    //ponovno iscrtavanje prozora
    glutPostRedisplay();

    if(timer_active)
        glutTimerFunc(50, on_timer, 0);
}

static void on_reshape(int width, int height){

    glViewport(0, 0, width, height);

    //parametri projekcije
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float) width / height, 1, 1800);
}


static void on_display(void){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt((floorWidth*floorScaleX)/2, (totalFloors*levelHeight)/2, 30,
              (floorWidth*floorScaleX)/2, (totalFloors*levelHeight)/2, 0,
              0, 1, 0);

    if (DEBUG_MODE){
        drawCoordinateSystem();
    }        

    //draw map
    drawMap(floorWidth, totalFloors);

    
    glutSwapBuffers();
}

