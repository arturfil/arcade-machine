#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "./Constants.h"
#include "./Screen.h"
#include "./Utils/Vec2D.h"
#include "./Graphics/Color.h"

void SetPixel(SDL_Surface * noptrWindowSurface, uint32_t color, int x, int y);
size_t GetIndex(SDL_Surface * noptrSurface, int r, int c);

int main(int argc, const char *argv[]) {
  // Screen theScreen;
  // theScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);
  if (SDL_Init(SDL_INIT_EVERYTHING)) {
    std::cout << "error SDL_Init Failed" << std::endl;
    return 1;
  }
  SDL_Window *optrWindow = SDL_CreateWindow(
    "Arcade", 
    SDL_WINDOWPOS_CENTERED, 
    SDL_WINDOWPOS_CENTERED, 
    SCREEN_WIDTH, 
    SCREEN_WIDTH, 
    0
  );
  if (optrWindow == nullptr) {
    std::cout << "Could not create window, got eror: " << SDL_GetError() << std::endl;
    return 1;
  }

  // SDL_Renderer *renderer = SDL_CreateRenderer(optrWindow, -1, 0);

  SDL_Surface* noptrWindowSurface = SDL_GetWindowSurface(optrWindow);
  SDL_PixelFormat * pixelFormat = noptrWindowSurface -> format;

  Color::InitColorFormat(pixelFormat);
  Color c(255, 255, 0, 255);
  
  SetPixel(noptrWindowSurface, c.GetPixelColor(), SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
  SDL_UpdateWindowSurface(optrWindow);

  std::cout << "The window pixel format is: " << SDL_GetPixelFormatName(pixelFormat -> format); 

  SDL_Event sdlEvent;
  bool running = true;

  while (running) {
    while (SDL_PollEvent(&sdlEvent)) {
      switch (sdlEvent.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_KEYDOWN:
        if (sdlEvent.key.keysym.sym == SDLK_ESCAPE)
          running = false;
        break;
      default:
        break;
      }
    }
  }

  SDL_DestroyWindow(optrWindow);
  SDL_Quit();

  return 0;
}

void SetPixel(SDL_Surface * noptrWindowSurface, uint32_t color, int x, int y) {
  SDL_LockSurface(noptrWindowSurface);
  uint32_t * pixels = (uint32_t*) noptrWindowSurface -> pixels;
  size_t index = GetIndex(noptrWindowSurface, y, x);
  pixels[index] = color;
  SDL_UnlockSurface(noptrWindowSurface);
}

size_t GetIndex(SDL_Surface * noptrSurface, int r, int c) {
  return r * noptrSurface -> w + c;
}