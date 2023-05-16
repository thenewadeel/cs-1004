#include "bullet.h"
#include "gameEntity.h"
#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/String.hpp>
#include <cstdlib>
#include <string.h>
#include <vector>
using namespace sf;
#ifndef ENEMY
#define ENEMY
class Enemy : public GameEntity {
  Texture tex;
  std::vector<Bullet> bombs;
  Clock actionClock;

public:
  float speed = 0.25;
  float fireInterval = 500;
  int fireProbability = 10;
  int maxBombs = 2;
  Enemy() {
    this->setSprite("img/enemy_1.png");
    this->setScale(0.5, 0.5);
  }
  void tick() {
    float actionTime = actionClock.getElapsedTime().asMilliseconds();
    if (actionTime > fireInterval && bombs.size() < maxBombs) {
      actionClock.restart();
      if ((rand() % 100) < fireProbability)
        fire();
    }
    eraseDeadEntities(bombs);
  }
  void eraseDeadEntities(std::vector<Bullet> &en) {
    en.erase(std::remove_if(en.begin(), en.end(),
                            [](GameEntity x) { return !x.isAlive(); }),
             en.end());
  }
  void checkPlayer(GameEntity &player) {
    if (isAlive()) {
      if (this->isColliding(player)) {
        player.receiveDamage(2);
        this->receiveDamage(1);
      }
      for (int j = 0; j < bombs.size(); j++) {
        if (bombs.at(j).isColliding(player)) {
          player.receiveDamage(3);
          bombs.at(j).receiveDamage(1);
        }
      }
    }
  }
  void fire() {
    Bullet b;
    b.setSprite("img/enemy_laser.png");
    b.setHeading(Vector2f(0, 1));
    b.setPosition(sprite.getPosition().x + (w * scaleX / 2),
                  sprite.getPosition().y + (h * scaleY / 2));
    bombs.push_back(b);
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
  void draw(RenderWindow &window, bool drawBounds = true) {
    for (int i = 0; i < bombs.size(); i++) {
      bombs.at(i).tick();
      bombs.at(i).draw(window, 0, 0, 0);
    }
    GameEntity::draw(window);
  }
};
#endif