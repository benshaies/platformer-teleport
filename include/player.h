#ifndef PLAYER_H
#define PLAYER_H

#define GRAVITY 2.5

#include <raylib.h>
typedef struct {
  Rectangle rec;
  Vector2 vel;
  float speed;
  float groundFriction;
  bool grounded;
} Player;

void playerInit(Player *player);

void playerUpdate(Player *player);

void playerDraw(Player player);

#endif // !PLAYER_H
