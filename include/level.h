#ifndef LEVEL_H
#define LEVEL_H
#include <raylib.h>
#include "../sblib/include/sblib.h"

//MACROS
#define COL_REC_NUM 24
#define DRAW_TILE_SIZE 50

typedef struct{
  Rectangle rec[COL_REC_NUM];
}Collision;


void levelInit();

void levelUpdate();

void levelDraw();

Collision GetNearbyCollisionRecs(SB_Level level, Rectangle playerRec);


#endif // !LEVEL_H
