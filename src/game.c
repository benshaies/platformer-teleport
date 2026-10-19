#include "../include/game.h"
#include "../include/level.h"
#include "../include/player.h"
#include "stdio.h"
#include <raylib.h>
#include <stdlib.h>

Rectangle platformRec = {200, 500, 900, 500};
Rectangle otherRec = {200, 100, 100, 100};
Rectangle otherOtherRec = {800, 100, 100, 100};

Collision col;

void gameInit() {
  InitWindow(1280, 720, "platformer");
  SetTargetFPS(60);

  playerInit();

  col.rec = malloc(sizeof(Rectangle) * 3);
  col.num = 3;
  col.rec[0] = platformRec;
  col.rec[1] = otherRec;
  col.rec[2] = otherOtherRec;
}

void gameUpdate() { playerUpdate(col); }

void gameDraw() {
  ClearBackground(RAYWHITE);
  BeginDrawing();

  playerDraw();

  DrawRectangleRec(platformRec, BROWN);
  DrawRectangleRec(otherRec, GREEN);
  DrawRectangleRec(otherOtherRec, RED);

  EndDrawing();
}
