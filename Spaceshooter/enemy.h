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
using namespace sf;
class Enemy : public GameEntity {
public:
  float speed = 0.25;

  Enemy() { this->setSprite("img/enemy_1.png"); }
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
  // void draw(RenderWindow &window) {
  //   // (GameEntity) this->draw(window);
  //   sf::Text text;
  //   sf::Font font;
  //   if (!font.loadFromFile("font1.otf")) {
  //     // error...
  //   }

  //   text.setFont(font); // font is a sf::Font

  //   // set the string to display
  //   Int8 a = 12;
  //   text.setString(std::string("En"));

  //   // set the character size
  //   text.setCharacterSize(24); // in pixels, not points!

  //   // set the color
  //   text.setFillColor(sf::Color::Red);

  //   // set the text style
  //   text.setStyle(sf::Text::Bold);

  //   // inside the main loop, between window.clear() and window.display()
  //   text.move(sprite.getPosition().x, sprite.getPosition().y);
  //   window.draw(boundingRect());
  //   window.draw(sprite);
  //   window.draw(text);
  // }
};