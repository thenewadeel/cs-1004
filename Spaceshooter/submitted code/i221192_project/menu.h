#include "game.h"
#include<fstream>
#include <SFML/Graphics.hpp>
using namespace std;
#define maxitem 3
class Menu{
public:

//add menu attributes here
    Sprite background; //Game background sprite
    Texture bg_texture;
    
        
    void Up();
    void Down();
    int select;
    sf:: Font font;
    sf:: Text items[maxitem];
    char* fileName = "scores.txt";

Menu(float w=2000, float h=1000)
{
     bg_texture.loadFromFile("img/menu_bg.png");
     background.setTexture(bg_texture);
     background.setScale(1, 1.1);
     
     items[0].setFont(font);
     items[0].setFillColor(Color::White);
     items[0].setString("Play");
     items[0].setPosition(800,300);
     
     items[1].setFont(font);
     items[1].setFillColor(Color::White);
     items[1].setString("Instrctions");
     items[1].setPosition(800,400);
     
     items[2].setFont(font);
     items[2].setFillColor(sf::Color::White);
     items[2].setString("Scores");
     items[2].setPosition(800,500);
//constructors body
}

void display_menu()

{    Game g; 
     ofstream MyFile;
     MyFile.open(fileName, ios::app);
     MyFile.close();
            sf::Font scorefont;                                           //Declaring the downloaded font as font for display
        scorefont.loadFromFile("scorefont.ttf");
//display menu screen here
         RenderWindow window(VideoMode(640, 850), "Hasan's Space Shooter");
         
         while (window.isOpen())
         {
         Event e;
         while (window.pollEvent(e))
         {  
             if (e.type == Event::Closed) // If cross/close is clicked/pressed
                 window.close(); //close the game                        	    
         }
         
         window.clear();
         window.draw(background);
         

         if (Keyboard::isKeyPressed(Keyboard::Enter)) //If left key is pressed
         {    window.close();
              
              g.start_game();
              window.create(VideoMode(640, 850), "Hasan's Space Shooter");
              
         }
         if (Keyboard::isKeyPressed(Keyboard::I)) //If left key is pressed
         {    bg_texture.loadFromFile("img/instructions_bg.png");
              background.setTexture(bg_texture);
              background.setScale(1.1, 1.1);
         }
         if (Keyboard::isKeyPressed(Keyboard::Q)) //If left key is pressed
         {    window.close();
         }
         if (Keyboard::isKeyPressed(Keyboard::M))
         {   bg_texture.loadFromFile("img/menu_bg.png");
             background.setTexture(bg_texture);
             background.setScale(1, 1.1);
         }
         if (Keyboard::isKeyPressed(Keyboard::H))
         {   bg_texture.loadFromFile("img/highscores_bg.png");
             background.setTexture(bg_texture);
             background.setScale(1, 1.1);
         }
         if (g.p->lives <= 0)
              {    bg_texture.loadFromFile("img/gameover_bg.png");
                   background.setTexture(bg_texture);
                   background.setScale(1.2, 1.1);
                   sf::Text scorenum(std::to_string(g.score), scorefont);          //Details for displaying the actual score value
                   scorenum.setPosition(450,435);
                   scorenum.setScale(2,2);
                   window.draw(scorenum);
                   
	      }
                  window.display();
         }
         MyFile << g.score << "/" << "\n";
         MyFile.close();
// add functionality of all the menu options here

//if Start game option is chosen 
    
 //   Game g; 
   // g.start_game();
    


}


};



        
