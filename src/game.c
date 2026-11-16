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

//Level stuff
Texture tempTileset;
SB_Level level;
SB_Tileset tileset;

void gameInit() {
  InitWindow(1280, 720, "platformer");
  SetTargetFPS(60);

  playerInit();

  //Collision

  //Level
  tempTileset = LoadTexture("assets/tempTileset.png");
  level = SB_Level_Load("levels/chunk1.sblevel" );
  tileset = SB_Tileset_Init("assets", level.tilesetName, level.tileSize);
  levelInit();

}

void gameUpdate() { 
  col = GetNearbyCollisionRecs(level, player.rec);
  playerUpdate(col); 
}

// TEMPORARY

void drawActiveColRecs(){
  
  for(int i = 0; i < COL_REC_NUM; i++){
    if(col.active[i]){
      DrawRectangleRec(col.rec[i], RED);
    }
  }

}

void gameDraw() {
  ClearBackground(RAYWHITE);
  BeginDrawing();


  SB_Level_Draw(level, tileset, 50, 50, -1);
    playerDraw();


  drawActiveColRecs();

  EndDrawing();
}
