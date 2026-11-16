#include "../include/level.h"
#include "stdlib.h"
#include <raylib.h>
#include <stdio.h>

IVec2 checkIndex[10];
SB_IntArray solidBlockList;






void levelInit() {

  // Collision check indexes
  checkIndex[0] = (IVec2){0, -1};
  checkIndex[1] = (IVec2){1, 0};
  checkIndex[2] = (IVec2){1, 1};
  checkIndex[3] = (IVec2){0, 2};
  checkIndex[4] = (IVec2){-1, 1};
  checkIndex[5] = (IVec2){-1, 0};
  checkIndex[6] = (IVec2){-1, -1}; // top-left
  checkIndex[7] = (IVec2){1, -1};  // top-right
  checkIndex[8] = (IVec2){-1, 2};  // bottom-left
  checkIndex[9] = (IVec2){1, 2};   // bottom-right
  
  // Solid block list
  SB_IntArray_Init(&solidBlockList, 2);
  solidBlockList.data[0] = 1;
  solidBlockList.data[1] = 2;


}

void levelUpdate() {}

void levelDraw() {}

bool isSolidBlock(int value){
  
  for(int i = 0; i < solidBlockList.size; i++){
    if(solidBlockList.data[i] != value){
      continue;
    }

    return true;
    
  }
  return false;

}

Collision GetNearbyCollisionRecs(SB_Level level, Rectangle playerRec){
  
  Collision col = {0};
  int count = 0;

  
  //Get current player index
  int iY = playerRec.y / DRAW_TILE_SIZE;
  int iX = (playerRec.x + (playerRec.width/2)) / DRAW_TILE_SIZE;
  
  int **arr = level.layer[0].data;
  
  // Looping through index  checks
  for(int i = 0; i < 10; i++){
    
    // Index we are checking
    IVec2 check = {iX + checkIndex[i].x, iY + checkIndex[i].y};
    if(check.x < 0 || check.x >= level.layer->cols || check.y < 0 || check.y >= level.layer->rows){
      continue;
    } 

    // Loop through collision tile values
    if(isSolidBlock(arr[check.y][check.x])){
        // Find a collision rectangle slot
        if(count < COL_REC_NUM){
          col.rec[count] = (Rectangle){check.x * DRAW_TILE_SIZE, check.y * DRAW_TILE_SIZE, DRAW_TILE_SIZE, DRAW_TILE_SIZE};
          col.active[count] = true;
          count++;
        }
    } 
  }
  

  return col;
 
}




