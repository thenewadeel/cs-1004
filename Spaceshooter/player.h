#include <SFML/Graphics.hpp>
#include <string.h>
using namespace sf;
class Player {
public:
  Texture tex;
  Sprite sprite;
  float speed = 0.25;
  int x, y;
  Player(std::string png_path) {

    tex.loadFromFile(png_path);
    sprite.setTexture(tex);
    x = 140;
    y = 100;
    sprite.setPosition(x, y);
    sprite.setScale(0.175, 0.175);
  }
  void fire() {}
  void move(std::string s) {
    float delta_x = 0, delta_y = 0;
    // if(s=="l")
    // move the player left
    // else if(s=="r")
    // move the player right
    if (s == "l")
      delta_x = -1;
    else if (s == "r")
      delta_x = 1;
    else if (s == "u")
      delta_y = -1;
    else if (s == "d")
      delta_y = 1;

    delta_x *= speed;
    delta_y *= speed;

    sprite.move(delta_x, delta_y);
  }
};
