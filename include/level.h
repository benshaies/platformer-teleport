#ifndef LEVEL_H
#define LEVEL_H
#include <raylib.h>
#include "../sblib/include/sblib.h"

//MACROS
#define COL_REC_NUM 24
#define DRAW_TILE_SIZE 50
#define BLOCK_COUNT 3

typedef struct{
  Rectangle rec[COL_REC_NUM];
  bool active[COL_REC_NUM];
}Collision;

typedef struct{
  int x;
  int y;
}IVec2;

typedef enum{
 BLOCK_AIR = -1,
 BLOCK_DIRT,
 BLOCK_GRASS,
 BLOCK_STONE,
}BlockId;

typedef struct{
  const char *name;
  bool solid;
  int health;
}BlockDef;

static BlockDef blockDefs[BLOCK_COUNT] = {
  [BLOCK_DIRT] = {"dirt", true, 4},
  [BLOCK_GRASS] = {"grass", true, 4},
  [BLOCK_STONE] = {"stone", true, 10},
};

void levelInit();

void levelUpdate();

void levelDraw();

Collision GetNearbyCollisionRecs(SB_Level level, Rectangle playerRec);

bool destroyTile(SB_Level *level, IVec2 index);


#endif // !LEVEL_H
