#include "../include/game.h"
#include <raylib.h>
#include "../include/player.h"

Player player;
Rectangle platformRec = {200, 500, 900, 75};

void gameInit(){
  InitWindow(1280, 720, "platformer");
  SetTargetFPS(60);

  playerInit(&player);
} 

void gameUpdate(){
  playerCollisions(&player, platformRec);
  playerUpdate(&player);
}

void gameDraw(){
  ClearBackground(RAYWHITE);
  BeginDrawing();

  playerDraw(player);

  DrawRectangleRec(platformRec, RED);


  EndDrawing();
}
