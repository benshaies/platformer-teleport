#ifndef LEVEL_H
#define LEVEL_H
#include <raylib.h>

typedef struct{
  Rectangle *rec;
  int num;
}Collision;
void levelInit();

void levelUpdate();

void levelDraw();

#endif // !LEVEL_H
