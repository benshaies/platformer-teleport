#ifndef PLAYER_H
#define PLAYER_H

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

void playerUpdate(Rectangle groundRec);

void playerDraw();

#endif // !PLAYER_H
