#include "../include/game.h"
#include "stdio.h"
#include <raylib.h>
#include "../include/player.h"
#include "../include/level.h"

Rectangle platformRec = {200, 500, 900, 500};

Collision collision;

void gameInit(){
  InitWindow(1280, 720, "platformer");
  SetTargetFPS(60);

  playerInit();

  collision.rec = malloc(sizeof(Rectangle) * 1);

  collision.rec[0] = platformRec;

} 

void gameUpdate(){
  playerUpdate(collision.rec[0]);
}

void gameDraw(){
  ClearBackground(RAYWHITE);
  BeginDrawing();

  playerDraw();

  DrawRectangleRec(platformRec, BROWN);


  EndDrawing();
}
