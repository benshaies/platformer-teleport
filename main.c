#include <raylib.h>
#include "include/game.h"

int main() {

  gameInit(); 
  while (!WindowShouldClose()) {
  
    gameUpdate();
    gameDraw();

  }
}
