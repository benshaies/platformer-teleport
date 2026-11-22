#include "../include/game.h"
#include "../include/level.h"
#include "../include/player.h"
#include "stdio.h"
#include <raylib.h>
#include <stdlib.h>


Game game;

RenderTexture2D target;

//Collision related 
Collision col;

//Level stuff
Texture tempTileset;
SB_Level level;
SB_Tileset tileset;

Vector2 mousePos;
IVec2 playerClickIndex = {0,0};

void checkPlayerMouseClick(){

  if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
    playerClickIndex.x = mousePos.x / DRAW_TILE_SIZE;
    playerClickIndex.y = mousePos.y / DRAW_TILE_SIZE;

    destroyTile(&level, playerClickIndex);
  }

}

void gameInit() {
  InitWindow(1280, 720, "platformer");
  SetTargetFPS(60);


  target = LoadRenderTexture(1280, 720);


  playerInit();

  //Collision

  //Level
  tempTileset = LoadTexture("assets/tempTileset.png");
  level = SB_Level_Load("levels/chunk1.sblevel" );
  tileset = SB_Tileset_Init("assets", level.tilesetName, level.tileSize);
  levelInit();

}

void gameUpdate() { 
  mousePos = SB_GameResolution_GetMouse((Vector2){1280, 720});
  col = GetNearbyCollisionRecs(level, player.rec);
  playerUpdate(col); 

  checkPlayerMouseClick();

}

void gameDraw() {
  BeginTextureMode(target);

    ClearBackground(SKYBLUE);

    SB_Level_Draw(level, tileset, 50, 50, -1);
    playerDraw();

  EndTextureMode();

  SB_GameResolution_Draw((Vector2){1280, 720}, &target);



}
