#ifndef UTIL_VEC2D_H
#define UTIL_VEC2D_H

#include <iostream>

class Vec2D {
  public:
    static const Vec2D Zero;
    Vec2D() {
      mX = 0;
      mY = 0;
    }
    Vec2D(float x, float y) {
      mX = x;
      mY = y;
    }

    // Note, for inline classes you don't have to redefine inline classes in the .cpp file

    inline void SetX(float x) {
      mX = x;
    };
    inline void SetY(float y) {
      mY = y;
    }
    inline float GetX() const {
      return mX;
    }
    inline float GetY() const {
      return mY;
    }
    void Display() const;
    friend std::ostream& operator <<(std::ostream& consoleOut, const Vec2D& vec);

    bool operator == (const Vec2D& vec2) const;
    bool operator != (const Vec2D& vec2) const;

    Vec2D operator -() const;
    Vec2D operator *(float scale) const;
    Vec2D operator /(float scale) const;
    Vec2D& operator *=(float scale);
    Vec2D& operator /=(float scale);

  private:
    float mX, mY;

};

#endif