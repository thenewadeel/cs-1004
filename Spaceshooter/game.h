
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
#include "player.h"
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game
{
public:
Sprite background; //Game background sprite
Texture bg_texture;
Player* p; //player 
// add other game attributes


Game()
{
p=new Player("img/player_ship.png");
bg_texture.loadFromFile("img/background.jpg");
background.setTexture(bg_texture);
background.setScale(2, 1.5);

}
void start_game()
{
    srand(time(0));
    RenderWindow window(VideoMode(780, 780), title);
    Clock clock;
    float timer=0;
    
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds(); 
        clock.restart();
        timer += time;  
        //cout<<time<<endl; 
 	Event e;
        while (window.pollEvent(e))
        {  
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
                window.close(); //close the game                        	    
        }
          
	if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
            p->move("l");    // Player will move to left
	if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
            p->move("r");  //player will move to right
	if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
            p->move("u");    //playet will move upwards
	if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
            p->move("d");  //player will move downwards
            
	////////////////////////////////////////////////
	/////  Call your functions here            ////
	//////////////////////////////////////////////

	window.clear(Color::Black); //clears the screen
	window.draw(background);  // setting background
	window.draw(p->sprite);   // setting player on screen

	window.display();  //Displying all the sprites
    }


}


};

