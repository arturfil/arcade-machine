#ifndef GRAPHICS_COLOR_H
#define GRAPHICS_COLOR_H

#include <iostream>
#include <SDL2/SDL.h>

struct SDL_PixelFormat;

class Color {
  uint32_t mColor;
  public:
    static const SDL_PixelFormat * mFormat;
    static void InitColorFormat(const SDL_PixelFormat * format);
    // constructors
    Color() {
      this -> mColor = 0;
    }
    // Color(uint32_t color): mColor(color) {}
    Color(uint32_t color) {
      this -> mColor = color;
    }
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    
    inline bool operator ==(const Color& c) const {return mColor == c.mColor;}
    inline bool operator !=(const Color& c) const {return !(*this == c);}
    inline uint32_t GetPixelColor() const {return mColor;}

    void SetRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

    void SetRed(uint8_t red);
    void SetGreen(uint8_t green);
    void SetBlue(uint8_t blue);
    void SetAlpha(uint8_t alpha);

    uint8_t GetRed() const;
    uint8_t GetGreen() const;
    uint8_t GetBlue() const;
    uint8_t GetAlpha() const;
};

#endif 