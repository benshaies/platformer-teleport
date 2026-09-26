#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
typedef struct{
  Rectangle rec;


}Player;

void playerInit(Player *player);

void playerUpdate(Player *player);

void playerDraw(Player player);

#endif // !PLAYER_H
