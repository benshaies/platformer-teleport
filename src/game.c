#include "../include/game.h"
#include "../include/level.h"
#include "../include/player.h"
#include "stdio.h"
#include <raylib.h>
#include <stdlib.h>

Rectangle platformRec = {200, 500, 900, 500};
Rectangle otherRec = {200, 100, 100, 100};
Rectangle otherOtherRec = {800, 100, 100, 100};

//Collision related 
Collision col;
SB_IntArray colTileValues;

//Level stuff
Texture tempTileset;
SB_Level level;
SB_Tileset tileset;

void gameInit() {
  InitWindow(1280, 720, "platformer");
  SetTargetFPS(60);

  playerInit();

  //Collision
  SB_IntArray_Init(&colTileValues, 2);
  colTileValues.data[0] = 1;
  colTileValues.data[1] = 2;


  //Level
  tempTileset = LoadTexture("assets/tempTileset.png");
  level = SB_Level_Load("levels/testlevel1.sblevel" );
  tileset = SB_Tileset_Init("assets", level.tilesetName, level.tileSize);

}

void gameUpdate() { playerUpdate(col); }

void gameDraw() {
  ClearBackground(RAYWHITE);
  BeginDrawing();

  playerDraw();

  SB_Level_Draw(level, tileset, 50, 50, -1);

  EndDrawing();
}
