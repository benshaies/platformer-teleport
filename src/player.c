#include "../include/player.h"
#include <raylib.h>
#include <stdio.h>

Player player;

void playerInit() {
  player.rec = (Rectangle){600, 100, 50, 100};
  player.vel = (Vector2){0, 0};
  player.xInput = 0;

  player.grounded = false;
  player.jumpPressed = false;

  player.speed = 500;
  player.groundFriction = 1.5f;
  player.jumpStrenght = -250;

  player = player;
}

float MoveToward(float current, float target, float maxDelta) {
  if (current < target) {
    current += maxDelta;
    if (current > target)
      current = target;
  } else if (current > target) {
    current -= maxDelta;
    if (current < target)
      current = target;
  }
  return current;
}

float clmp(float current, float max, float min) {
  if (current > max) {
    return max;
  } else if (current < min) {
    return min;
  } else {
    return current;
  }
}

void playerInput() {

  if (IsKeyDown(KEY_D)) {
    player.xInput = 1;
  } else if (IsKeyDown(KEY_A)) {
    player.xInput = -1;
  } else {
    player.xInput = 0;
  }

  if (IsKeyPressed(KEY_SPACE)) {
    player.jumpPressed = true;
  }
}

void velocityUpdate() {
  float targetX = player.xInput * player.speed;
  player.vel.x = MoveToward(player.vel.x, targetX, 10.0);
  player.vel.y += GRAVITY;

  if (player.jumpPressed && player.grounded) {
    player.vel.y = player.jumpStrenght;
  }
  
  
  player.vel.y = clmp(player.vel.y, 250, player.jumpStrenght);
}



void playerMovement() {
  player.grounded = false;

  // X Axis
  player.rec.x += player.vel.x * GetFrameTime();

  // Y Axis
  player.rec.y += player.vel.y * GetFrameTime();
}

void playerCollisions(Rectangle groundRec) {
  if(CheckCollisionRecs(player.rec, groundRec)){
    player.grounded = true;
  }
}

void playerUpdate(Rectangle groundRec) {
  playerInput();
  velocityUpdate();
  playerMovement();
  playerCollisions(groundRec);

  printf("x: %f y:%f \n", player.vel.x, player.vel.y);
}

void playerDraw() { DrawRectangleRec(player.rec, BLUE); }
