#include "bullet.h"
#include "enemy.h"
#include "gameEntity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/Vector2.hpp>
#include <string.h>
using namespace sf;
#ifndef PLAYER
#define PLAYER
int MAX_ACTIVE_BULLETS = 100;
class Player : public GameEntity {
public:
  float speed = 0.25;
  Bullet bullets[1000];
  int activeBullets = 0;
  Player() {
    this->setSprite("img/player_ship.png");
    this->setScale(0.5, 0.5);
  }
  void fire() {
    if (activeBullets < MAX_ACTIVE_BULLETS) {
      Bullet b;
      // b.setSprite("img/bullet.png");
      b.setHeading(Vector2f(0, -1));
      b.setPosition(sprite.getPosition());
      bullets[activeBullets++] = b;
    }
  }
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
  void checkEnemies(Enemy enemies[], const int length) {
    for (int i = 0; i < length; i++) {
      if (enemies[i].isAlive()) {
        for (int j = 0; j < activeBullets; j++) {
          // bullets[i].tick();
          // bullets[i].draw(window);
          if (bullets[j].isColliding((GameEntity)enemies[i])) {
            // cout << "X";
            enemies[i].receiveDamage(1);
            bullets[j].receiveDamage(1);
            // en->draw(window);
          } else {
            // en->~GameEntity();
            // en = NULL;
          }
        }
      }
    }
  }
  void draw(RenderWindow &window, bool drawBounds = true) {
    for (int i = 0; i < activeBullets; i++) {
      bullets[i].tick();
      bullets[i].draw(window);
    }
    GameEntity::draw(window);
  }
  void movementMouse(Vector2i mousePosition) {
    float delta_x = mousePosition.x, delta_y = mousePosition.y;
    // delta_x *= speed;
    // delta_y *= speed;
    // this->setPosition(delta_x, delta_y);
    sprite.move(delta_x, delta_y);
  }
};
#endif