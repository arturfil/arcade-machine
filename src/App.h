#ifndef APP_H
#define APP_H

#include <stdint.h>
#include <SDL2/SDL.h>

class App {
  private: 
    SDL_Window * mnoptrWindow;
  
  public:
    static App& Singleton();
    bool Init(uint32_t width, uint32_t height, uint32_t mag);
    inline uint32_t Width() const {return Width();}
    inline uint32_t Height() const {return Height();}
    static void SetPixel(SDL_Surface * noptrWindowSurface, uint32_t color, int x, int y);
    static size_t GetIndex(SDL_Surface * noptrSurface, int r, int c);

    void Run();
};

#endif