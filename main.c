#include <raylib.h>
#include "include/game.h"

int main() {
  
  ChangeDirectory(GetApplicationDirectory());
  gameInit(); 
  while (!WindowShouldClose()) {
  
    gameUpdate();
    gameDraw();

  }
}
