#include <iostream>
#include "./App.h"
#include "./Constants.h"

App& App::Singleton() {
  static App theApp;
  return theApp;
}

// bool App::Init(int32_t width, uint32_t height, )

// int main() {
//   std::cout << "Testing that this works" << std::endl;

//   SDL_Window* optrWindow = SDL_CreateWindow("Arcade", 
//     SDL_WINDOWPOS_CENTERED, 
//     SDL_WINDOWPOS_CENTERED, 
//     SCREEN_WIDTH, 
//     SCREEN_HEIGHT, 
//     0
//   );

//   if (optrWindow == nullptr) {
//     std::cout << "Could not create window, got error: " << SDL_GetError() << std::endl;
//     return 1;
//   }

//   SDL_Surface* noptrWindowSurface = SDL_GetWindowSurface(optrWindow);
//   // color of the screen
//   uint32_t color = 0xFF00FF;
//   App::SetPixel(noptrWindowSurface, color, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
//   SDL_UpdateWindowSurface(optrWindow);

//   SDL_Event sdlEvent;
//   bool running = true;

//   while(running) {
//     while (SDL_PollEvent(&sdlEvent)) {
//       switch(sdlEvent.type) {
//         case SDL_QUIT:
//           running = false;
//           break;
//         case SDL_KEYDOWN:
//           if (sdlEvent.key.keysym.sym == SDLK_ESCAPE)
//             running = false;
//         default:
//           break;
//       }
//     }
//   }

//   SDL_DestroyWindow(optrWindow);
//   SDL_Quit();

//   return 0;
// }

// size_t App::GetIndex(SDL_Surface * noptrSurface, int r, int c) {
//   return r * noptrSurface -> w + c;
// }

// void App::SetPixel(SDL_Surface * noptrWindowSurface, uint32_t color, int x, int y) {
//   SDL_LockSurface(noptrWindowSurface);
//   SDL_UnlockSurface(noptrWindowSurface);
//   uint32_t * pixels = (uint32_t*) noptrWindowSurface -> pixels;
//   size_t index = App::GetIndex(noptrWindowSurface, y, x);
//   pixels[index] = color;
// }

