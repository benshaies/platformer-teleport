#ifndef PLAYER_H
#define PLAYER_H
#include "level.h"

#define GRAVITY 15


#include <raylib.h>
typedef struct {
  Rectangle rec;
  Vector2 vel;
  int xInput;
  float speed;
  float groundFriction;
  bool grounded;
  bool jumpPressed;
  float jumpStrenght;
} Player;

void playerInit();

void playerUpdate(Collision col);

void playerDraw();

#endif // !PLAYER_H
