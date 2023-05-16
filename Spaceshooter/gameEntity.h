#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
#include <string.h>
using namespace sf;
#ifndef GAMEENTITY
#define GAMEENTITY
int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;
class GameEntity {
  Texture *tex;
  sf::Font font;

public:
  int health = 100, maxHealth = 100;
  bool collision = false;
  int w, h;
  float scoreMultiplier = 1;
  float scaleX = 1, scaleY = 1;
  Sprite sprite;
  // int health;
  // Force accumulation - insert here -
  GameEntity() {
    if (!font.loadFromFile("font1.otf")) {
      // error...
      // cout << "ERR loading font";
    }
  }
  // ~GameEntity();
  void setSprite(std::string png_path = "img/gameEntity.png") {
    // tex=Texture a;
    tex = new Texture();
    tex->loadFromFile(png_path);
    w = tex->getSize().x;
    h = tex->getSize().y;
    sf::IntRect texRect = IntRect(0, 0, w, h);
    sprite.setTexture(*tex);
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
    RectangleShape current = boundingRect();
    RectangleShape foreign = g.boundingRect();
    IntRect A =
        IntRect(current.getPosition().x, current.getPosition().y,
                current.getSize().x * scaleX, current.getSize().y * scaleY);
    IntRect B =
        IntRect(foreign.getPosition().x, foreign.getPosition().y,
                foreign.getSize().x * g.scaleX, foreign.getSize().y * g.scaleY);
    collision = B.intersects(A);
    return B.intersects(A);
  }
  void setPosition(int x, int y) { sprite.setPosition(x, y); }
  void setPosition(Vector2f pos) { sprite.setPosition(pos); }
  void setRotation(float angle) { sprite.setRotation(angle); }
  void setScale(float x, float y) {
    sprite.setScale(x, y);
    scaleX = x;
    scaleY = y;
  }
  void destroy() { this->~GameEntity(); }
  void receiveDamage(int damageAmount) {
    this->collision = true;
    if (health > 0) {
      this->health -= damageAmount;
      // destroy();
    }
  }

  void positionalText(RenderWindow &window) {
    sf::Text text;
    text.setFont(font);
    String pos = "P:";
    text.setString(pos + std::to_string(sprite.getPosition().x) + ", " +
                   std::to_string(sprite.getPosition().y));
    text.setCharacterSize(12); // in pixels, not points!
    text.setPosition(sprite.getPosition() + Vector2f(w * scaleX, h * scaleY));
    window.draw(text);
  }

  RectangleShape healthRect() {
    RectangleShape healthRect =
        RectangleShape(Vector2f(health * w * scaleX / maxHealth, 2));
    healthRect.setPosition(sprite.getPosition());
    healthRect.setFillColor(sf::Color::Green);
    return healthRect;
  }
  bool isAlive() { return health > 0; }
  void draw(RenderWindow &window, bool drawBounds = false,
            bool drawHealth = true, bool drawPositionalText = false) {
    if (isAlive()) {
      window.draw(sprite);
      if (drawHealth) {
        window.draw(healthRect());
      }
      if (drawBounds)
        window.draw(boundingRect());
      if (drawPositionalText)
        positionalText(window);
    }
  }
};
#endif