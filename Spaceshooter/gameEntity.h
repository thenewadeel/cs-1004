#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/View.hpp>
#include <string.h>
using namespace sf;
#ifndef GAMEENTITY
#define GAMEENTITY
int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;
class GameEntity {
  Texture tex;
  bool collision = false;

public:
  Sprite sprite;
  // int health;
  // Force accumulation - insert here -
  GameEntity() { setSprite(); }
  void setSprite(std::string png_path = "img/gameEntity.png") {
    tex.loadFromFile(png_path);
    sf::IntRect texRect = IntRect(0, 0, tex.getSize().x, tex.getSize().y);
    sprite.setTexture(tex);
    sprite.setTextureRect(texRect);
    sprite.setPosition(240, 150); // TODO . . . set position mech
    sprite.setScale(1, 1);
  }

public:
  RectangleShape boundingRect() {
    RectangleShape shp(Vector2f(sprite.getLocalBounds().width,
                                sprite.getLocalBounds().height));
    shp.setFillColor(sf::Color::Transparent);
    if (collision)
      shp.setOutlineColor(sf::Color::Red);
    else {
      shp.setOutlineColor(sf::Color::Cyan);
    }
    shp.setOutlineThickness(3.f);
    shp.setPosition(sprite.getPosition());
    shp.setScale(sprite.getScale());
    shp.rotate(sprite.getRotation());
    return shp;
  }
  bool isColliding(GameEntity g) {
    // boundingRect().getLocalBounds().intersects(IntRect(g.boundingRect().getSize()));
    RectangleShape asd = boundingRect();
    RectangleShape qwe = g.boundingRect();
    IntRect A = IntRect(asd.getPosition().x, asd.getPosition().y,
                        asd.getSize().x, asd.getSize().y);
    IntRect B = IntRect(qwe.getPosition().x, qwe.getPosition().y,
                        qwe.getSize().x, qwe.getSize().y);
    collision = B.intersects(A);
    return B.intersects(A);
  }
  void setPosition(int x, int y) { sprite.setPosition(x, y); }
  void setScale(float x, float y) { sprite.setScale(x, y); }
};
#endif