#include "enemy.h"
#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/String.hpp>
#include <cstdlib>
#include <string.h>
using namespace sf;
#ifndef INVADER
#define INVADER
class Invader : public Enemy {
  Texture tex;

public:
  float speed = 0.25;

  Invader() {
    this->setSprite("img/enemy_2.png");
    this->setScale(0.5, 0.5);
  }
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
  // void draw(RenderWindow &window, bool drawBounds = false,
  //           bool drawHealth = false) {
  //   window.draw(sprite);
  //   if (drawHealth) {
  //     RectangleShape healthRect = RectangleShape(Vector2f(health * w / 100,
  //     2)); healthRect.setPosition(sprite.getPosition());
  //     healthRect.setFillColor(sf::Color::Green);
  //     window.draw(healthRect);
  //   }
  //   if (drawBounds)
  //     window.draw(boundingRect());
  // }
};
#endif