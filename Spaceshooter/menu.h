
#include "game.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <ctime>
#include <string>
class Menu {
  string defaultMenuStrings[4] = {"Go to Battle!", "Options", "Instructions",
                                  "Exit Game"};
  string storyline =
      "Our galaxy is attacked by enemies. The enemy invaders \n"
      "beat our squad, they destroyed all of galactica. Space \n"
      "team is waiting for your order. Please command the ship \n"
      "to protect the galaxy and the surrounding asteroids ";
  Clock grandClock;

public:
  Sprite background;     // Game background sprite
  GameEntity menuCursor; // Menu cursor sprite
  Texture bg_texture;
  sf::Font font;
  struct gameOptions {
    int lives = 3;
  } defaultGameOptions;
  enum menuOptions {
    menuOption_StartGame,
    menuOption_GameOptions,
    menuOption_Instructions,
    menuOption_Quit,
    menuOption_None
  } defaultMenuOptions,
      currentOption, selectedOption;
  int menuStops(menuOptions index) { return 160 + 75 * index; }
  // add menu attributes here
  Menu() {
    selectedOption = menuOption_None;
    currentOption = menuOption_StartGame;
    if (!font.loadFromFile("font1.otf")) {
      // error...
      cout << "ERR loading font";
    }
    bg_texture.loadFromFile("img/background.jpg");
    background.setTexture(bg_texture);
    background.setScale(1, 1);

    menuCursor.setSprite("img/PNG/playerShip3_red.png");
    menuCursor.setRotation(90);
    menuCursor.setScale(0.75, 0.75);
    // constructors body
  }
  sf::Text stylizeText(sf::Text &obj, int fontSize = 12,
                       sf::Color fillColor = sf::Color::White,
                       sf::Color outlineColor = sf::Color::Red,
                       int outlineWidth = 1,
                       sf::Text::Style style = sf::Text::Bold) {
    obj.setFont(font);              // font is a sf::Font
    obj.setCharacterSize(fontSize); // in pixels, not points!
    obj.setFillColor(fillColor);
    obj.setOutlineColor(outlineColor);
    obj.setOutlineThickness(outlineWidth);
    obj.setStyle(style);
    return obj;
  }
  enum textStyles {
    textStyle_Title,
    textStyle_Menu,
    textStyle_Tip,
    textStyle_Info
  };
  sf::Text applyStyles(sf::Text &obj, textStyles stl) {
    switch (stl) {
    case textStyle_Title:
      return stylizeText(obj, 150, sf::Color::Red, sf::Color::White, 8);
    case textStyle_Menu:
      return stylizeText(obj, 45, sf::Color::White, sf::Color::Red, 1);
    case textStyle_Info:
      return stylizeText(obj, 24, sf::Color::Blue, sf::Color::White, 1);
    case textStyle_Tip:
      return stylizeText(obj, 24, sf::Color::Green, sf::Color::Black, 1);
    default:
      return stylizeText(obj, 24, sf::Color::White);
    }
  }
  void drawMainMenu(RenderWindow &window) {
    window.clear(Color::Black); // clears the screen
    window.draw(background);    // setting background
    sf::Text titleText;
    titleText.setString("Space Shooter!");
    titleText.move(25, -20);
    //   textx = stylizeText(textx);
    titleText = applyStyles(titleText, textStyle_Title);
    window.draw(titleText);
    for (int i = 0; i < 4; i++) {
      sf::Text menuText;
      menuText.setString(defaultMenuStrings[i]);
      menuText.move(SCREEN_WIDTH / 3, menuStops((menuOptions)i));
      menuText = applyStyles(menuText, textStyle_Menu);
      window.draw(menuText);
    }
    menuCursor.setPosition(40 + SCREEN_WIDTH / 4, menuStops(currentOption) - 5);
    menuCursor.draw(window, 0, 0);

    window.display(); // Displying all the sprites
  }
  void drawInstrsMenu(RenderWindow &window) {
    float timer = clock();
    window.clear(Color::Black); // clears the screen
    window.draw(background);    // setting background
    sf::Text storylineText;
    storylineText.setString(storyline);
    int yLocation = SCREEN_HEIGHT - 100 -
                    (int)(50 * grandClock.getElapsedTime().asSeconds()) %
                        (SCREEN_HEIGHT - 150);
    storylineText.move(25, yLocation);
    //   textx = stylizeText(textx);
    storylineText = applyStyles(storylineText, textStyle_Info);
    window.draw(storylineText);

    window.display(); // Displying all the sprites
  }
  void display_menu() {
    Game g;
    srand(time(0));
    RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), title);
    Clock clock, actionClock;
    float timer = 0;
    // cout << makeText().getString();
    while (window.isOpen()) {
      float actionCooldownTime = 250;
      float actionTime = actionClock.getElapsedTime().asMilliseconds();
      float time = clock.getElapsedTime().asSeconds();
      clock.restart();
      timer += time;
      // cout<<time<<endl;
      Event e;
      while (window.pollEvent(e)) {
        if (e.type == Event::Closed) // If cross/close is clicked/pressed
          window.close();            // close the game
      }

      //   if (Keyboard::isKeyPressed(Keyboard::Up) ||
      //       Keyboard::isKeyPressed(Keyboard::W)) // If up key is pressed
      //   {
      //     if (actionTime > actionCooldownTime) {
      //       actionClock.restart();
      //       selectedOption = (menuOptions)((selectedOption - 1) % 4);
      //     }
      //   }
      if (Keyboard::isKeyPressed(Keyboard::Down) ||
          Keyboard::isKeyPressed(Keyboard::S)) // If down key is pressed
      {
        if (actionTime > actionCooldownTime) {
          actionClock.restart();
          currentOption = (menuOptions)((currentOption + 1) % 4);
        }
      }
      if (Keyboard::isKeyPressed(Keyboard::Enter) ||
          Keyboard::isKeyPressed(Keyboard::Space)) // If down key is pressed
      {
        if (actionTime > actionCooldownTime) {
          actionClock.restart();
          //   selectedOption = (menuOptions)((selectedOption + 1) % 4);
          selectedOption = currentOption;
        }
      }

      switch (selectedOption) {
      default:
        drawMainMenu(window);
        break;
      case menuOption_Instructions:
        drawInstrsMenu(window);
        break;
      case menuOption_Quit:
        window.close();
        break;
      case menuOption_GameOptions:
        cout << "Not implemented yet";
        break;
      case menuOption_StartGame:
        window.close();
        g.start_game();
        break;
      }

      //   Game g;
      // display menu screen here

      // add functionality of all the menu options here

      // if Start game option is chosen

      //   g.start_game();
    }
  }
};