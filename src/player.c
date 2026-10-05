#include "../include/player.h"
#include <raylib.h>
#include <stdio.h>

void playerInit(Player *player) {
  player->rec = (Rectangle){600, 100, 50, 100};
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

void playerCollisions(Player *player, Rectangle collisionRec) {

}

void playerUpdate(Player *player) {

  /*First update velocity*/

  // Gravity adding
  // if player isnt grounded we add gravity to velY
  if (!player->grounded) {
    player->vel.y += GRAVITY;
  }

  // Sideways movement
  if (player->grounded) {

    if (IsKeyDown(KEY_D)) {
      player->vel.x += player->speed;
    } else if (IsKeyDown(KEY_A)) {
      player->vel.x -= player->speed;
    } else {
      // Smoothly move vel to zero
      player->vel.x = MoveToward(player->vel.x, 0, player->groundFriction);
    }

    player->vel.x = clmp(player->vel.x, 10, -10);
  }


  player->rec.x += player->vel.x;
  player->rec.y += player->vel.y;
}

void playerDraw(Player player) { DrawRectangleRec(player.rec, BLUE); }
