#include "../include/player.h"
#include <stdio.h>
#include <raylib.h>

void playerInit(Player *player) {
  player->rec = (Rectangle){400, 400, 50, 100};
  player->vel = (Vector2){0,0};
  player->grounded = false;

  player->speed = 2;
  player->groundFriction = 1.5f; 
}


float MoveToward(float current, float target, float maxDelta)
{
    if (current < target) {
        current += maxDelta;
        if (current > target) current = target;
    } else if (current > target) {
        current -= maxDelta;
        if (current < target) current = target;
    }
    return current;
}

float clmp(float current, float max, float min){
  if(current > max){
    return max;
  }
  else if(current < min){
    return min;
  }
  else{
    return current;
  }
}


void playerUpdate(Player *player) {
  
  /*First update velocity*/

  // Gravity adding
  if(!player->grounded){
    player->vel.y += GRAVITY; 
  }
  else{player->vel.y = 0;}

  //Sideways movement
  if(IsKeyDown(KEY_D)){
    player->vel.x += player->speed;
  }
  else if(IsKeyDown(KEY_A)){
    player->vel.x -= player->speed;
  }
  else{
    player->vel.x = MoveToward(player->vel.x, 0, player->groundFriction);
  }

  player->vel.x = clmp(player->vel.x, 10, -10);

  
  //Update position based on velocity
  if(player->rec.y <= 720 - player->rec.height){
      player->rec.y += player->vel.y;

  }

  player->rec.x += player->vel.x;


  


}

void playerDraw(Player player) { DrawRectangleRec(player.rec, BLUE); }
