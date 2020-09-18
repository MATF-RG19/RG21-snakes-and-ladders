#include "../headers/player.h"
#include "../headers/globals.h"
#include "../headers/map.h"
#include "../headers/lights.h"
#include <string.h>

void drawPlayerName(Player *player);
void animateIdle(Player *player, float y);

float fontScale = 352.38;
float playerHeight = levelHeight*0.7;
float maxIdleAnimationY = levelHeight*0.1;

void drawPlayer(Player *player){
    glPushMatrix();
    
    GLfloat diffuse_coeffs[] = {player->color[0], player->color[1], player->color[2], 1 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    set_player_materials();
    float x = (float)player->positionX;
    x = x * floorScaleX ;

    float y = (float)player->positionY;
    y = y * levelHeight + floorScaleY/2 + playerHeight/2;
    if (player->coordinateY == -100)
        player->coordinateY = y + ((float)rand() / (float)RAND_MAX) * maxIdleAnimationY;

    if (player->coordinateX == -100){
        player->velocityX = playerHeight/25;
        player->velocityY = 0.0024 * 5;
        player->coordinateX = x;
    }

    

    if (player->state == 0){
        animateIdle(player, y);
    }

    glTranslatef(player->coordinateX, player->coordinateY, 0);
    glColor3f( player->color[0], player->color[1], player->color[2]);
    glutSolidSphere( playerHeight / 2, 50, 50);
    glPopMatrix();
}
void animateIdle(Player *player, float y){
    float realY = player->coordinateY + player->velocityY;
    if (realY >= y + maxIdleAnimationY || realY <= y){
        player->velocityY *= -1;
    }
    player->coordinateY = realY;

}

void drawPlayerName(Player *player){
    glColor3f(player->color[0], player->color[1], player->color[2]);
    for (int i=0; i<strlen(player->name); i++){
        glutStrokeCharacter(GLUT_STROKE_ROMAN, player->name[i]);
    }
    glTranslatef(fontScale, playerHeight/100, 0);

}
void drawPlayerNames(){
    glPushMatrix();
    glTranslatef(0, -1, 0);
    glScalef(1/fontScale, 1/fontScale, 1/fontScale);

    drawPlayerName(player1);
    drawPlayerName(player2);
    drawPlayerName(player3);
    drawPlayerName(player4);

    glTranslatef(2*fontScale, 0, 0);

    glPopMatrix();
}

Player *createPlayer(GLfloat color[3], char name[10]){
    Player *player;
    player = (Player *) malloc(sizeof(Player));
    player->color[0] = color[0];
    player->color[1] = color[1];
    player->color[2] = color[2];
    player->positionX = 0;
    player->positionY = 0;
    player->coordinateX = -100;
    player->coordinateY = -100;
    player->velocityX = 0;
    player->velocityY = 0.0024;
    player->state = 0;
    memcpy(player->name, name, sizeof(char)* 10);

    return player;
}