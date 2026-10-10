#ifndef PLAYER_H
#define PLAYER_H

#define GRAVITY 10.0

#include <raylib.h>
typedef struct {
  Rectangle rec;
  Vector2 vel;
  int xInput;
  float speed;
  float groundFriction;
  bool grounded;
  bool jumpPressed;
} Player;

void playerInit(Player *player);


void playerUpdate(Player *player);

void playerDraw(Player player);

#endif // !PLAYER_H
