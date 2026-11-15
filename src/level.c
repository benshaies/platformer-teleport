#include "../include/level.h"


void levelInit() {}

void levelUpdate() {}

void levelDraw() {}

Collision GetNearbyCollisionRecs(SB_Level level, Rectangle playerRec){
  
  Collision col;
  
  //Get current player index
  int iY = playerRec.y / DRAW_TILE_SIZE;
  int iX = playerRec.x / DRAW_TILE_SIZE;
  
  int **arr = level.layer[0].data;

 
}


