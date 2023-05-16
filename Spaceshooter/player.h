#include "bullet.h"
#include "enemy.h"
#include "gameEntity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/String.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
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
  int score = 0;
  Player() {
    this->setSprite("img/player_ship.png");
    this->setScale(0.5, 0.5);
    this->health = this->maxHealth = 500;
  }
  void fire() {
    if (activeBullets < MAX_ACTIVE_BULLETS) {
      Bullet b;
      // b.setSprite("img/bullet.png");
      b.setHeading(Vector2f(0, -1));
      b.setPosition(sprite.getPosition().x + (w * scaleX / 3),
                    sprite.getPosition().y + (h * scaleY / 3));
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
    sprite.move(delta_x, delta_y);
    Vector2f pos = sprite.getPosition();
    if (pos.x > SCREEN_WIDTH)
      pos.x = std::fmod(pos.x, SCREEN_WIDTH);
    if (pos.y > SCREEN_HEIGHT)
      pos.y = std::fmod(pos.y, SCREEN_HEIGHT);
    if (pos.x <= 0)
      pos.x = SCREEN_WIDTH - pos.x;
    if (pos.y <= 0)
      pos.y = SCREEN_HEIGHT - pos.y;
    sprite.setPosition(pos.x, pos.y);
  }
  void checkEnemy(Enemy &enemy) {
    if (enemy.isAlive()) {
      if (this->isColliding((GameEntity)enemy)) {
        enemy.receiveDamage(2);
        this->receiveDamage(1);
      }
      for (int j = 0; j < activeBullets; j++) {
        // bullets[i].tick();
        // bullets[i].draw(window);
        if (bullets[j].isAlive() && bullets[j].isColliding((GameEntity)enemy)) {
          // cout << "X";
          enemy.receiveDamage(1);
          bullets[j].receiveDamage(1);
          score += enemy.scoreMultiplier * 1;
          // en->draw(window);
        } else {
          // en->~GameEntity();
          // en = NULL;
        }
      }
    }
  }
  void checkEnemies(Enemy enemies[], const int length) {
    for (int i = 0; i < length; i++) {
      checkEnemy(enemies[i]);
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