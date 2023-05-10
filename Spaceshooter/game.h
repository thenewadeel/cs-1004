
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <time.h>
using namespace std;
#include "bullet.h"
#include "gameEntity.h"
#include "player.h"
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game {
public:
  Sprite background; // Game background sprite
  Texture bg_texture;
  Player *p; // player
  Bullet *b;
  bool showDebugInfo = false;
  // add other game attributes

  Game() {
    p = new Player();
    b = new Bullet();
    b->setHeading(Vector2f(0, -1));
    b->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT);
    bg_texture.loadFromFile("img/background.jpg");
    background.setTexture(bg_texture);
    background.setScale(1, 1);
  }
  void debugMessage(string str) {
    if (showDebugInfo) {
      cout << str;
    }
  }
  void start_game() {
    sf::Font font;
    if (!font.loadFromFile("font1.otf")) {
      // error...
      cout << "ERR loading font";
    }

    srand(time(0));
    RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), title);
    Clock clock;
    float timer = 0;

    // GameEntity en;

    while (window.isOpen()) {
      float time = clock.getElapsedTime().asSeconds();
      clock.restart();
      timer += time;
      // cout<<time<<endl;
      Event e;
      while (window.pollEvent(e)) {
        if (e.type == Event::Closed) // If cross/close is clicked/pressed
          window.close();            // close the game
      }

      if (Keyboard::isKeyPressed(Keyboard::Left))  // If left key is pressed
        p->movement("l");                          // Player will move to left
      if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
        p->movement("r");                          // player will move to right
      if (Keyboard::isKeyPressed(Keyboard::Up))    // If up key is pressed
        p->movement("u");                          // playet will move upwards
      if (Keyboard::isKeyPressed(Keyboard::Down))  // If down key is pressed
        p->movement("d");                          // player will move downwards
      if (Keyboard::isKeyPressed(
              Keyboard::Comma))         // If comma (,) key is pressed
        showDebugInfo = !showDebugInfo; // toggle debug messages

      ////////////////////////////////////////////////
      /////  Call your functions here            ////
      //////////////////////////////////////////////

      window.clear(Color::Black); // clears the screen
      window.draw(background);    // setting background
      // get the local mouse position (relative to a window)
      sf::Vector2i localPosition =
          sf::Mouse::getPosition(window); // window is a sf::Window
      // p->setLocation(localPosition.x, localPosition.y);
      window.draw(p->sprite); // setting player on screen
      window.draw(p->boundingRect());
      b->tick();
      if (b->isColliding((GameEntity)*p)) {
        // cout << "X";
      }
      window.draw(b->sprite);
      window.draw(b->boundingRect());
      // window.draw(en.sprite);
      // window.draw(en.boundingRect());

      sf::Text text;

      // select the font
      text.setFont(font); // font is a sf::Font

      // set the string to display
      text.setString("Hello world");

      // set the character size
      text.setCharacterSize(24); // in pixels, not points!

      // set the color
      text.setFillColor(sf::Color::Red);

      // set the text style
      text.setStyle(sf::Text::Bold);

      // inside the main loop, between window.clear() and window.display()
      text.move(localPosition.x, localPosition.y);
      window.draw(text);
      window.display(); // Displying all the sprites
    }
  }
};
