#include "raylib.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <stdlib.h>

typedef struct {
  int w, h;
  unsigned char *pixels;
} MyImage;

typedef struct {
  int x, y;
  int w, h;
  int color[3];
} Square;

void SetColorForPixel(MyImage *img, int x, int y, int rgb[3]) {

  img->pixels[(y * img->w + x) * 3 + 0] = rgb[0];
  img->pixels[(y * img->w + x) * 3 + 1] = rgb[1];
  img->pixels[(y * img->w + x) * 3 + 2] = rgb[2];
}

void FillGradient(MyImage *img) {
  int color[3] = {0, 0, 128};
  for (int y = 0; y < img->h; ++y) {
    for (int x = 0; x < img->w; ++x) {
      color[0] = x;
      color[1] = y;
      SetColorForPixel(img, x, y, color);
    }
  }
}

void DrawSquare(MyImage *img, Square *params) {
  int lastX = params->x + params->w;
  int lastY = params->y + params->h;
  for (int y = params->y; y < lastY; ++y) {
    for (int x = params->x; x < lastX; ++x) {
      SetColorForPixel(img, x, y, params->color);
    }
  }
}

int main(int argc, char **argv) {
  if (argc < 3)
    return 1; // need 2 args to proceed

  int w = atoi(argv[1]);
  int h = atoi(argv[2]);
  MyImage img = {.w = w, .h = h, .pixels = malloc(w * h * 3)};

  Square square = {
      .x = w / 2, .y = h / 2, .w = w / 4, .h = h / 4, .color = {128, 45, 22}};

  FillGradient(&img);
  DrawSquare(&img, &square);

  stbi_write_png("out.png", w, h, 3, img.pixels, w * 3);

  free(img.pixels);
  return 0;
}
