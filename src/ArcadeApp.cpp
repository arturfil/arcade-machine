#include <iostream>
#include "./Constants.h"
#include "./Screen.h"
#include "./Utils/Vec2D.h"


int main(int argc, const char *argv[]) {
  // Screen theScreen;
  // theScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);
  Vec2D vector(3,7);
  vector.Display();
  std::cout << vector << std::endl;
  std::cout << "This vector is negated with the uniray operator '-' :\n" << -vector << std::endl;

  return 0;
}