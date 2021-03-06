#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

#include "../headers/globals.h"
#include "../headers/coordinateSystem.h"
#include "../headers/map.h"
#include "../headers/skybox.h"
#include "../headers/player.h"
#include "../headers/lights.h"



//stanje tajmera
static int timer_active;

//deklaracije callback funkcija
static void on_keyboard(unsigned char key, int x, int y);
static void on_mouse(int button, int state, int x, int y);
static void on_timer(int value);
static void on_reshape(int width, int height);
static void on_display(void);

int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    initGlobals();

    glutInitWindowSize(appWindowWidth, appWindowWidth);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-appWindowWidth)/2, (glutGet(GLUT_SCREEN_HEIGHT)-appWindowWidth)/2);
    glutCreateWindow("Snakes n Ladders");
    glClearColor(1, 0, 0, 0);

    glEnable(GL_DEPTH_TEST);

    init_light();

    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);
    glutKeyboardFunc(on_keyboard);
    glutMouseFunc(on_mouse);
    timer_active = 1;
    glutTimerFunc(20, on_timer, 0);


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
static void on_mouse(int button, int state, int x, int y){
    printf("%d", button);
    printf("%d", state);
}

static void on_timer(int value){
    
    if(value != 0)
        return;

    currentFrame++;

    //ponovno iscrtavanje prozora
    glutPostRedisplay();

    if(timer_active)
        glutTimerFunc(20, on_timer, 0);
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
    gluLookAt((floorWidth*floorScaleX)/2, (totalFloors*levelHeight)*0.8 , 20,
              (floorWidth*floorScaleX)/2, (totalFloors*levelHeight)/2, 0,
              0, 1, 0);


    if (DEBUG_MODE){
        drawCoordinateSystem();
    }   


    
    drawSkybox();
    glTranslatef(floorScaleX/2, floorScaleY + floorScaleY/2, 0);
    drawMap(floorWidth, totalFloors);
    
    
    drawPlayer(player1);
    drawPlayer(player2);
    drawPlayer(player3);
    drawPlayer(player4);
    drawPlayerNames();        

    drawEdges();

    
    glutSwapBuffers();
}

