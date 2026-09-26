#include "../include/player.h"
#include <raylib.h>

void playerInit(Player *player){
  player->rec = (Rectangle){400, 400, 50, 100};
}

void playerUpdate(Player *player){

}

void playerDraw(Player player){
  DrawRectangleRec(player.rec, BLUE);
}
