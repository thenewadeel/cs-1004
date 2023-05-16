
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
using namespace std;
#include "bullet.h"
#include "dragon.h"
#include "enemy.h"
#include "gameEntity.h"
#include "invader.h"
#include "monster.h"
#include "player.h"
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;
const int ENEMY_COUNT = 20;
const int ROW_SPACING = 50;
const int COL_SPACING = 75;
const int MAX_ENEMIES_PER_ROW = 8;
const int ENEMY_ROWS = 5;
const int GAME_LEVELS = 10;
const string arrangement[GAME_LEVELS][ENEMY_ROWS] = {
    {"i--d-ddddd-i", "i-i-i-i-", "---i---i", "----m----", "-i-i-i-i"},
    {"i--d-----i", "i-i-i-i-", "--ii--ii", "----i----", "-i-i-i-i"},
    {"i--d-----i", "i-i-i-i-", "-iii-iii", "----i----", "-i-i-i-i"},
    {"i--d-----i", "i-i-i-i-", "iiiiiiii", "----i----", "-i-i-i-i"},
    {"i--d-----i", "i-i-i-i-", "---i---i", "----i----", "-i-i-i-i"}};
Enemy charToEnemy(char c) {
  switch (c) {
  case 'm':
    return Monster();
  case 'd':
    return Dragon();
  case 'i':
    return Invader();
  default:
    return Enemy();
  };
}
std::vector<Enemy> decodeRowString(string str, int rowX, int rowY = 20) {
  cout << "Decoding str:" << str << endl;
  // Enemy *enemies;
  std::vector<Enemy> enemies;
  int pushed = 0;
  for (int i = 0; i < MAX_ENEMIES_PER_ROW; i++) {
    bool skipSlot = false;
    Enemy en;
    if (str[i] != '-') {
      en = charToEnemy(str[i]);
      en.setPosition(rowX + ROW_SPACING * i, rowY);
      enemies.push_back(en);
    }
  }
  cout << "Returning:" << str << endl;
  return enemies;
};
class Game {
public:
  Sprite background; // Game background sprite
  Texture bg_texture;
  Player *p; // player
  Enemy enemies[ENEMY_COUNT];
  std::vector<Enemy> en;
  bool showDebugInfo = false;
  // add other game attributes
  sf::Font font;
  sf::Text UIText_Score;

  Game() {
    if (!font.loadFromFile("font1.otf")) {
      // error...
      cout << "ERR loading font";
    }
    UIText_Score.setFont(font);        // font is a sf::Font
    UIText_Score.setCharacterSize(24); // in pixels, not points!
    UIText_Score.setFillColor(sf::Color::Red);
    UIText_Score.setStyle(sf::Text::Bold);
    UIText_Score.setPosition(SCREEN_WIDTH - 120, SCREEN_HEIGHT - 40);

    p = new Player();
    for (int i = 0; i < ENEMY_ROWS; i++) {
      std::vector<Enemy> line =
          decodeRowString(arrangement[0][i], 0, COL_SPACING * i);
      en.insert(en.end(), line.begin(), line.end());
    }
    bg_texture.loadFromFile("img/background.jpg");
    background.setTexture(bg_texture);
    background.setScale(1, 1);
  }
  void debugMessage(string str) {
    if (showDebugInfo) {
      cout << str;
    }
  }
  void paintUI(RenderWindow &window) {

    UIText_Score.setString("Score" + std::to_string(p->score));
    window.draw(UIText_Score);
    Vector2f temp = p->lifeSprite.getPosition();
    for (int i = 0; i < p->lives; i++) {
      p->lifeSprite.setPosition(50 + 25 * i, SCREEN_HEIGHT - 30);
      window.draw(p->lifeSprite);
    }
    p->lifeSprite.setPosition(temp);
    // Player x;
    // x.draw(window);
  }
  void start_game() {

    srand(time(0));
    RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), title);
    Clock clock, actionClock;
    float timer = 0;

    while (window.isOpen()) {
      float actionCooldownTime = 250;
      float actionTime = actionClock.getElapsedTime().asMilliseconds();
      float time = clock.getElapsedTime().asSeconds();
      clock.restart();
      timer += time;
      Event e;
      while (window.pollEvent(e)) {
        if (e.type == Event::Closed) // If cross/close is clicked/pressed
          window.close();            // close the game
      }

      if (Keyboard::isKeyPressed(Keyboard::Left) ||
          Keyboard::isKeyPressed(Keyboard::A)) // If left key is pressed
        p->movement("l");                      // Player will move to left
      if (Keyboard::isKeyPressed(Keyboard::Right) ||
          Keyboard::isKeyPressed(Keyboard::D)) // If right key is pressed
        p->movement("r");                      // player will move to right
      if (Keyboard::isKeyPressed(Keyboard::Up) ||
          Keyboard::isKeyPressed(Keyboard::W)) // If up key is pressed
        p->movement("u");                      // playet will move upwards
      if (Keyboard::isKeyPressed(Keyboard::Down) ||
          Keyboard::isKeyPressed(Keyboard::S)) // If down key is pressed
        p->movement("d");                      // player will move downwards
      if (Keyboard::isKeyPressed(Keyboard::Space) ||
          Mouse::isButtonPressed(sf::Mouse::Left)) // If space key is pressed
      {                                            // player will fire
        if (actionTime > actionCooldownTime) {
          actionClock.restart();
          p->fire();
        }
      }
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

      p->draw(window);
      if (!en.empty()) {
        for (int j = 0; j < en.size(); j++) {
          p->checkEnemy(en.at(j));
          en.at(j).tick();
          en.at(j).checkPlayer(*p);
          en.at(j).draw(window);
        }
      } else {
        p->health = 999;
      }
      // for (int i = 0; i < ENEMY_ROWS; i++)
      en.erase(std::remove_if(en.begin(), en.end(),
                              [](Enemy x) { return !x.isAlive(); }),
               en.end());
      if (p->lives < 0)
        break;
      // TODO:  Draw main game UI
      paintUI(window);
      window.display(); // Displying all the sprites
    }
  }
};
