#include "../headers/player.h"
#include "../headers/globals.h"
#include "../headers/map.h"
#include <string.h>

void drawPlayerName(Player *player);
float fontScale = 352.38;

void drawPlayer(Player *player){
    glPushMatrix();
    
    float x = (float)player->positionX;
    x = x * floorScaleX + floorScaleX/2;

    float y = (float)player->positionY;
    y = y * levelHeight + levelHeight/2;

    glTranslatef(x, y, 0);
    glColor3f(player->color[0], player->color[1], player->color[2]);

    GLfloat ambient_coeffs[] = { 1.0, 0.1, 0.1, 1 };

    /* Koeficijenti difuzne refleksije materijala. */
    GLfloat diffuse_coeffs[] = { player->color[0], player->color[1], player->color[2], 1 };

    /* Koeficijenti spekularne refleksi je materijala. */
    GLfloat specular_coeffs[] = { 0.5, 0.5, 0.5, 0.5};

    /* Koeficijent glatkosti materijala. */
    GLfloat shininess = 20;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    glutSolidSphere(levelHeight*0.7 / 2, 50, 50);

    glPopMatrix();
}
void drawPlayerName(Player *player){
    glColor3f(player->color[0], player->color[1], player->color[2]);
    for (int i=0; i<strlen(player->name); i++){
        glutStrokeCharacter(GLUT_STROKE_ROMAN, player->name[i]);
    }
    glTranslatef(fontScale, 0, 0);

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
    memcpy(player->name, name, sizeof(char)* 10);

    return player;
}