#include "../include/player.h"
#include <raylib.h>
#include <stdio.h>

void playerInit(Player *player) {
  player->rec = (Rectangle){600, 100, 50, 100};
  player->vel = (Vector2){0, 0};
  player->xInput = 0;

  player->grounded = false;
  player->jumpPressed = false;

  player->speed = 150;
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

void playerInput(Player *player){
  
  if(IsKeyDown(KEY_D)){
    player->xInput = 1;
  }
  else if(IsKeyDown(KEY_A)){
    player->xInput = -1;
  }
  else{
    player->xInput = 0;
  }

  if(IsKeyPressed(KEY_SPACE)){
    player->jumpPressed = true;
  }
}

void velocityUpdate(Player *player){
  float targetX = player->xInput * player->speed;
  player->vel.x = MoveToward(player->vel.x, targetX, 10.0);
  player->vel.y += GRAVITY * GetFrameTime();

  if(player->jumpPressed && player->grounded){
    player->vel.y = -15;
  }
}

void playerMovement(Player *player){
  player->grounded = false;
  
  // X Axis
  player->rec.x += player->vel.x * GetFrameTime();


  // Y Axis
  player->rec.y += player->vel.y * GetFrameTime();
}

void playerUpdate(Player *player) {
  playerInput(player);
  velocityUpdate(player);
  playerMovement(player);
  


} 

void playerDraw(Player player) { DrawRectangleRec(player.rec, BLUE); }
