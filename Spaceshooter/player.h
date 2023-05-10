#include "gameEntity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/Vector2.hpp>
#include <string.h>
using namespace sf;
class Player : public GameEntity {
public:
  float speed = 0.25;

  Player() { this->setSprite("img/player_ship.png"); }
  void fire() {}
  void movement(std::string s) {
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

    // this->setPosition(delta_x, delta_y);

    sprite.move(delta_x, delta_y);
  }
  void movementMouse(Vector2i mousePosition) {
    float delta_x = mousePosition.x, delta_y = mousePosition.y;
    // delta_x *= speed;
    // delta_y *= speed;
    // this->setPosition(delta_x, delta_y);
    sprite.move(delta_x, delta_y);
  }
};