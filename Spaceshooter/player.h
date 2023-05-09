#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <string.h>
using namespace sf;
class Player : public sf::Transformable {
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
    sprite.setPosition(240, 150);
    sprite.setScale(1, 1);
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
  RectangleShape boundingRect() {

    RectangleShape shp(Vector2f(sprite.getLocalBounds().width,
                                sprite.getLocalBounds().height));
    shp.setFillColor(sf::Color::Transparent);
    shp.setOutlineColor(sf::Color::Cyan);
    shp.setOutlineThickness(3.f);
    shp.setPosition(sprite.getPosition().x, sprite.getPosition().y);
    return shp;
  }
};