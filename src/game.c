#include "../include/game.h"
#include "../include/level.h"
#include "../include/player.h"
#include <stdlib.h>
#include "stdio.h"
#include <raylib.h>

Rectangle platformRec = {200, 500, 900, 500};

Collision col;



void gameInit() {
  InitWindow(1280, 720, "platformer");
  SetTargetFPS(60);

  playerInit();

  col.rec = malloc(sizeof(Rectangle) * 1);
  col.num = 1;
  col.rec[0] = platformRec;
}

void gameUpdate() { 
  playerUpdate(col); 
}

void gameDraw() {
  ClearBackground(RAYWHITE);
  BeginDrawing();

  playerDraw();

  DrawRectangleRec(platformRec, BROWN);

  EndDrawing();
}
