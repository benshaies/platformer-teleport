#ifndef PLAYER_H
#define PLAYER_H
#include "level.h"

#define GRAVITY 500
#define RADIUS 300


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

  // Interaction
} Player;

extern Player player;


void playerInit();

void playerUpdate(Collision col);

void playerDraw();

#endif // !PLAYER_H
