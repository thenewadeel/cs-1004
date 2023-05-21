#include "gameEntity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/Vector2.hpp>
#include <math.h>
#include <string.h>
using namespace sf;
#ifndef BULLET
#define BULLET
class Bullet : public GameEntity {
public:
  float speed = 0.3;
  float decayRate = 0.9;
  Vector2f heading;
  Bullet() {
    this->setSprite("img/bullet.png");
    this->setScale(0.75, 0.75);
  }
  void setHeading(Vector2f v) {
    float v_mag = sqrt(v.x * v.x + v.y * v.y);
    Vector2f v_normalised = Vector2f(v.x / v_mag, v.y / v_mag);
    heading = v_normalised;
  }
  void tick() {
    // heading = Vector2f(heading.x * decayRate, heading.y * decayRate);
    sprite.move(heading * speed);
    // sprite.move(((int)(100 * speed * heading.x) % SCREEN_WIDTH) / 100,
    //             ((int)(100 * speed * heading.y) % SCREEN_HEIGHT) / 100);
    Vector2f position = sprite.getPosition();
    if (position.x < 0)
      health = 0;
    if (position.y < 0)
      health = 0;
    if (position.x > SCREEN_WIDTH)
      health = 0;
    if (position.y > SCREEN_HEIGHT)
      health = 0;
    // sprite.setPosition((int)sprite.getPosition().x % SCREEN_WIDTH,
    //                    (int)sprite.getPosition().y % SCREEN_HEIGHT);
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
};
#endif