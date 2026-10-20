#include "../include/player.h"
#include <raylib.h>
#include <stdio.h>

Player player;
float dt;

void playerInit() {
  player.rec = (Rectangle){600, 1, 50, 100};
  player.vel = (Vector2){0, 0};
  player.xInput = 0;

  player.grounded = false;
  player.jumpPressed = false;

  player.speed = 500;
  player.jumpStrenght = -400;

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
  player.vel.x = MoveToward(player.vel.x, targetX, 2500 * dt);

  player.vel.y += GRAVITY * dt;

  if (player.jumpPressed && player.grounded) {
    player.vel.y = player.jumpStrenght;
  }
}

float moveX(Collision col) {
  for (int i = 0; i < col.num; i++) {
    float newX = player.rec.x + (player.vel.x * dt);
    Rectangle newRec = {newX, player.rec.y, player.rec.width,
                        player.rec.height};

    if (CheckCollisionRecs(newRec, col.rec[i])) {
      if (player.vel.x > 0) {
        player.vel.x = 0;
        return col.rec[i].x - player.rec.width - 0.05;
      } else if (player.vel.x < 0) {
        player.vel.x = 0;
        return col.rec[i].x + col.rec[i].width + 0.05;
      }
    }
  }

  return player.rec.x + (player.vel.x * dt);
}

float moveY(Collision col) {
  for (int i = 0; i < col.num; i++) {
    float newY = player.rec.y + (player.vel.y * dt);
    Rectangle newRec = {player.rec.x, newY, player.rec.width,
                        player.rec.height};

    if (CheckCollisionRecs(newRec, col.rec[i])) {
      if (player.vel.y > 0) {
        player.vel.y = 0;
        player.grounded = true;
        player.jumpPressed = false;
        return col.rec[i].y - player.rec.height - 0.05;

      } else if (player.vel.y < 0) {
        player.vel.y = 0;
        return col.rec[i].y + col.rec[i].height - 0.05;
      }
    }
  }
  player.grounded = false;
  return player.rec.y + (player.vel.y * dt);
}

void playerMovement(Collision col) {
  player.grounded = false;

  player.rec.x = moveX(col);

  player.rec.y = moveY(col);
}

void playerUpdate(Collision col) {
  dt = GetFrameTime();
  playerInput(); // Gets player input 
  velocityUpdate(); // Uses player input to updatye velocity
  playerMovement(col); // Uses velocity and collision recs to move and resolve collisions
}

void playerDraw() { DrawRectangleRec(player.rec, BLUE); }
