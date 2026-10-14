#include "../include/game.h"
#include <raylib.h>
#include "../include/player.h"

Rectangle platformRec = {200, 500, 900, 500};

void gameInit(){
  InitWindow(1280, 720, "platformer");
  SetTargetFPS(60);

  playerInit();
} 

void gameUpdate(){
  playerUpdate(platformRec);
}

void gameDraw(){
  ClearBackground(RAYWHITE);
  BeginDrawing();

  playerDraw();

  DrawRectangleRec(platformRec, BROWN);


  EndDrawing();
}
