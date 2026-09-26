#include "../include/game.h"
#include <raylib.h>
#include "../include/player.h"

Player player;

void gameInit(){
  InitWindow(1280, 720, "platformer");
  SetTargetFPS(60);

  playerInit(&player);
} 

void gameUpdate(){
  playerUpdate(&player);
}

void gameDraw(){
  ClearBackground(RAYWHITE);
  BeginDrawing();

  playerDraw(player);


  EndDrawing();
}
