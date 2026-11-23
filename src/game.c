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
SB_Level chunk1;
SB_IntArray2D chunk1BlockHealth;

SB_Level *currentChunk;

SB_Tileset tileset;

Vector2 mousePos;
IVec2 playerClickIndex = {0,0};

Camera2D cam;

void checkPlayerMouseClick(){

  if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
    playerClickIndex.x = mousePos.x / DRAW_TILE_SIZE;
    playerClickIndex.y = mousePos.y / DRAW_TILE_SIZE;

    destroyTile(currentChunk, playerClickIndex);
  }

}

void gameInit() {
  InitWindow(1280, 720, "platformer");
  SetTargetFPS(60);


  target = LoadRenderTexture(1280, 720);
  cam.target = (Vector2){player.rec.x, player.rec.y};
  cam.offset = (Vector2){1280/2, 720/2};
  cam.zoom = 0.75f;


  playerInit();

  //Collision

  //Level
  chunk1 = SB_Level_Load("levels/chunk1.sblevel" );
  tileset = SB_Tileset_Init("assets", chunk1.tilesetName, chunk1.tileSize);

  currentChunk = &chunk1;

  levelInit();

}

void gameUpdate() { 
  mousePos = SB_GameResolution_GetMouse((Vector2){1280, 720});
  col = GetNearbyCollisionRecs(*currentChunk, player.rec);
  playerUpdate(col); 

  cam.target = (Vector2){player.rec.x, player.rec.y};
  mousePos = GetScreenToWorld2D(mousePos, cam);


  checkPlayerMouseClick();

}

void gameDraw() {
  BeginTextureMode(target);

    BeginMode2D(cam);

      ClearBackground(SKYBLUE);

      SB_Level_Draw(*currentChunk, tileset, 50, 50, -1);
      playerDraw();

    EndMode2D();

  EndTextureMode();

  SB_GameResolution_Draw((Vector2){1280, 720}, &target);



}
