#include "../include/player.h"
#include <raylib.h>
#include <stdio.h>

void playerInit(Player *player) {
  player->rec = (Rectangle){400, 400, 50, 100};
  player->vel = (Vector2){0, 0};
  player->grounded = false;

  player->speed = 2;
  player->groundFriction = 1.5f;
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

void playerUpdate(Player *player) {

  /*First update velocity*/

  // Gravity adding
  if (!player->grounded) {
    player->vel.y += GRAVITY;
  } else {
  }

  // Sideways movement
  if (IsKeyDown(KEY_D)) {
    player->vel.x += player->speed;
  } else if (IsKeyDown(KEY_A)) {
    player->vel.x -= player->speed;
  } else {
    // Smoothly move vel to zero
    player->vel.x = MoveToward(player->vel.x, 0, player->groundFriction);
  }

  // Jumping
  if (IsKeyPressed(KEY_SPACE) && player->grounded) {
    player->vel.y = 15;
    player->grounded = false;
  }

  player->vel.x = clmp(player->vel.x, 10, -10);

  // Update position based on velocity
  if (player->rec.y <= 720 - player->rec.height) {
    player->rec.y += player->vel.y;
  }

  player->rec.x += player->vel.x;
}

void playerDraw(Player player) { DrawRectangleRec(player.rec, BLUE); }
