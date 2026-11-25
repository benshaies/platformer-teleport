#include "../include/game.h"
#include "../include/level.h"
#include "../include/player.h"
#include "stdio.h"
#include <raylib.h>
#include <stdlib.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

Game game;

RenderTexture2D target;

//Collision related 
Collision col;

//Level stuff
SB_Level world;

SB_Tileset tileset;

Vector2 mousePos;
IVec2 playerClickIndex = {0,0};

Camera2D cam;
Rectangle visibleArea;

void checkPlayerMouseClick(){

  if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
    playerClickIndex.x = mousePos.x / DRAW_TILE_SIZE;
    playerClickIndex.y = mousePos.y / DRAW_TILE_SIZE;

    destroyTile(&world, playerClickIndex);
  }

}

void gameInit() {
  InitWindow(1280, 720, "platformer");
  SetTargetFPS(60);

  target = LoadRenderTexture(1280, 720);
  cam.target = (Vector2){player.rec.x, player.rec.y};
  cam.offset = (Vector2){1280/2, 720/2};
  cam.zoom = 1.0;

  visibleArea = (Rectangle){0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

  playerInit();

  //Level
  world = SB_Level_Load("levels/world.sblevel" );
  tileset = SB_Tileset_Init("assets", world.tilesetName, world.tileSize);
  
  generateWorld(&world);


  levelInit();

}

void gameUpdate() { 
  mousePos = SB_GameResolution_GetMouse((Vector2){SCREEN_WIDTH, SCREEN_HEIGHT});
  col = GetNearbyCollisionRecs(world, player.rec);
  playerUpdate(col); 
  
  // Updating camera and the visibleArea
  cam.target = (Vector2){player.rec.x, player.rec.y};
  if(IsKeyPressed(KEY_DOWN) && cam.zoom > 0.15){
    cam.zoom -= 0.05;
  }
  else if(IsKeyPressed(KEY_UP) && cam.zoom < 2){
    cam.zoom += 0.05;
  }


  mousePos = GetScreenToWorld2D(mousePos, cam);
  Vector2 cameraStart = GetScreenToWorld2D((Vector2){0,0}, cam);
  visibleArea = (Rectangle){
    cameraStart.x - 500,
    cameraStart.y - 500,
    (SCREEN_WIDTH + 1000) / cam.zoom,
    (SCREEN_HEIGHT + 1000) / cam.zoom,
  };

  checkPlayerMouseClick();

}

void gameDraw() {

  BeginTextureMode(target);

    BeginMode2D(cam);

      ClearBackground(SKYBLUE);
      
      SB_Level_Draw_Visible(world, tileset, DRAW_TILE_SIZE, DRAW_TILE_SIZE, -1, visibleArea);


      playerDraw();


    EndMode2D();

  DrawFPS(0, 0);

  EndTextureMode();




  SB_GameResolution_Draw((Vector2){1280, 720}, &target);



}
