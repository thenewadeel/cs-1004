
#include "game.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>
class Menu {
  string defaultMenuStrings[4] = {"Go to Battle!", "Options", "Instructions",
                                  "Exit Game"};

public:
  Sprite background; // Game background sprite
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
  } defaultMenuOptions;
  // add menu attributes here
  Menu() {
    menuOptions selectedOption = menuOption_None;
    if (!font.loadFromFile("font1.otf")) {
      // error...
      cout << "ERR loading font";
    }
    bg_texture.loadFromFile("img/background.jpg");
    background.setTexture(bg_texture);
    background.setScale(1, 1);
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
      return stylizeText(obj, 72, sf::Color::Red, sf::Color::White, 8);
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
  void display_menu() {
    srand(time(0));
    RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), title);
    Clock clock;
    float timer = 0;
    // cout << makeText().getString();
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

      if (Keyboard::isKeyPressed(Keyboard::Up) ||
          Keyboard::isKeyPressed(Keyboard::W)) // If up key is pressed
        ;
      if (Keyboard::isKeyPressed(Keyboard::Down) ||
          Keyboard::isKeyPressed(Keyboard::S)) // If down key is pressed
        ;

      ////////////////////////////////////////////////
      /////  Call your functions here            ////
      //////////////////////////////////////////////
      window.clear(Color::Black); // clears the screen
      window.draw(background);    // setting background
      sf::Text titleText;
      titleText.setString("Space Shooter!");
      titleText.move(SCREEN_WIDTH / 4, 50);
      //   textx = stylizeText(textx);
      titleText = applyStyles(titleText, textStyle_Title);
      window.draw(titleText);
      for (int i = 0; i < 4; i++) {
        sf::Text menuText;
        menuText.setString(defaultMenuStrings[i]);
        menuText.move(SCREEN_WIDTH / 3, (150 + 60 * i));
        menuText = applyStyles(menuText, textStyle_Menu);
        window.draw(menuText);
      }

      //   titleText.setString("Tip: close the game & go study");
      //   titleText.move(0, 100);
      //   //   textx = stylizeText(textx);
      //   titleText = applyStyles(titleText, textStyle_Tip);
      //   window.draw(titleText);

      //   titleText.setString("Info: Wow it works");
      //   titleText.move(0, 100);
      //   //   textx = stylizeText(textx);
      //   titleText = applyStyles(titleText, textStyle_Info);
      //   window.draw(titleText);

      window.display(); // Displying all the sprites

      //   Game g;
      // display menu screen here

      // add functionality of all the menu options here

      // if Start game option is chosen

      //   g.start_game();
    }
  }
};