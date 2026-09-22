#include <raylib.h>

int main(){
  
  InitWindow(1280, 720, "platformer");
  SetTargetFPS(60);

  while(!WindowShouldClose()){
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawRectangle(500, 500, 50, 50, BLACK);

    EndDrawing();
  }
}
