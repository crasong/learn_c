#include "raylib.h"

void FillGradient() {
  for (int y = 0; y < GetScreenHeight(); ++y) {
    for (int x = 0; x < GetScreenWidth(); ++x) {
      int r = ((float)x / GetScreenWidth()) * 255;
      int g = ((float)y / GetScreenHeight()) * 255;
      Color color = {r, g, 128, 255};
      DrawPixel(x, y, color);
    }
  }
}

int main(void) {
  const int screenWidth = 800;
  const int screenHeight = 600;

  InitWindow(screenWidth, screenHeight, "My Little Pony");

  int currentFPS = 60;

  Vector2 deltaCircle = {0, (float)screenHeight / 3.0f};
  Vector2 frameCircle = {0, (float)screenHeight * (2.0f / 3.0f)};

  const float speed = 10.0f;
  const float circleRadius = 32.0f;

  SetTargetFPS(currentFPS);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    FillGradient();
    DrawText("WeeWoo Yeehaw cowboy", screenWidth / 2, screenHeight / 2, 24,
             LIGHTGRAY);
    EndDrawing();
  }

  FillGradient();

  CloseWindow();

  return 0;
}
