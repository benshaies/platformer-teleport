#include "../include/level.h"
#include "stdlib.h"
#include <raylib.h>
#include <stdio.h>

IVec2 checkIndex[6];


void levelInit() {
  checkIndex[0] = (IVec2){0, -1};
  checkIndex[1] = (IVec2){1, 0};
  checkIndex[2] = (IVec2){1, 1};
  checkIndex[3] = (IVec2){0, 2};
  checkIndex[4] = (IVec2){-1, 1};
  checkIndex[5] = (IVec2){-1, 0};
}

void levelUpdate() {}

void levelDraw() {}

Collision GetNearbyCollisionRecs(SB_Level level, Rectangle playerRec, SB_IntArray colTileValues){
  
  Collision col = {0};
  int count = 0;

  
  //Get current player index
  int iY = playerRec.y / DRAW_TILE_SIZE;
  int iX = (playerRec.x + (playerRec.width/2)) / DRAW_TILE_SIZE;
  
  int **arr = level.layer[0].data;

  for(int i = 0; i < 6; i++){
    
    // Index we are checking
    IVec2 check = {iX + checkIndex[i].x, iY + checkIndex[i].y};
    if(check.x < 0 || check.x >= level.layer->cols || check.y < 0 || check.y >= level.layer->rows){
      continue;
    } 

    // Loop through collision tile values
    for(int j  = 0; j < colTileValues.size; j++){
       if(arr[check.y][check.x] == colTileValues.data[j]){
        
        // Find a collision rectangle slot
        if(count < COL_REC_NUM){
          col.rec[count] = (Rectangle){check.x * DRAW_TILE_SIZE, check.y * DRAW_TILE_SIZE, DRAW_TILE_SIZE, DRAW_TILE_SIZE};
          col.active[count] = true;
          count++;
          }
         break;
        }
      }
    }
  

  return col;

 
}




