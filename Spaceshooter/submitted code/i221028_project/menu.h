
#include "game.h"
#include <fstream>
using namespace std;

class Menu
{
public:
	Sprite background; //Game background sprite
	Texture bg_texture;
	Menu()
	{
		bg_texture.loadFromFile("img/menubackground2.jpg");
		background.setTexture(bg_texture);
		background.setScale(1.2, 1.9);
	}
	void display_menu()
	{
	    	Game g;
	    	srand(time(NULL));
		RenderWindow window(VideoMode(700, 680), title);
		window.setFramerateLimit(60); 
		//display menu screen here
		window.clear(Color::Black);
		window.draw(background);
		while (window.isOpen())
		{
			
			DisplayMenuOptions(window);
			
			Event e;
			while (window.pollEvent(e))
			{  
			    if (e.type == Event::Closed) // If cross/close is clicked/pressed
				window.close(); //close the game                        	    
			}
			if (Keyboard::isKeyPressed(Keyboard::P))//Play game option
			{
				window.close();
				//if Start game option is chosen 
	    			g.start_game();
			}
			if (Keyboard::isKeyPressed(Keyboard::H))//Highest score option 
			{
				//display menu screen here
				window.clear(Color::Black);
				window.draw(background);
				DisplayMenuOptions(window);
				DisplayHighestScore(window);
			}
			if (Keyboard::isKeyPressed(Keyboard::I))//Instructions option
			{
				//display menu screen here
				window.clear(Color::Black);
				window.draw(background);
				DisplayMenuOptions(window);
				DisplayInstructions(window);
			}
			if (Keyboard::isKeyPressed(Keyboard::E))//Exit option
			{
				window.close();
			}
			window.display();
		}//end while
	}
	void DisplayMenuOptions(RenderWindow &window)
	{
		//Display Score, lives and level on Screen
		Font font;
		font.loadFromFile("arial.ttf");
			
		Text text10;
		text10.setFont(font);
		text10.setCharacterSize(40);
		text10.setStyle(sf::Text::Regular);

		
		text10.setFillColor(sf::Color::Cyan);
		text10.setString("Game Menu");
		text10.setPosition(240, 50);
		window.draw(text10);
		
		Text text1;
		text1.setFont(font);
		text1.setCharacterSize(30);
		text1.setStyle(sf::Text::Regular);

		text1.setFillColor(sf::Color::Cyan);
		text1.setString("P => Play Game");
		text1.setPosition(240, 150);
		window.draw(text1);
		
		text1.setFillColor(sf::Color::Cyan);
		text1.setString("H => Highest Score");
		text1.setPosition(240, 200);
		window.draw(text1);
		
		text1.setFillColor(sf::Color::Cyan);
		text1.setString("I => Instructions");
		text1.setPosition(240, 250);
		window.draw(text1);
		
		text1.setFillColor(sf::Color::Cyan);
		text1.setString("E => Exit");
		text1.setPosition(240, 300);
		window.draw(text1);
	}
	void DisplayInstructions(RenderWindow &window)
	{
		//Display Score, lives and level on Screen
		Font font;
		font.loadFromFile("arial.ttf");
			
		Text text1;
		text1.setFont(font);
		text1.setCharacterSize(30);
		text1.setStyle(sf::Text::Regular);
		
		text1.setFillColor(sf::Color::Cyan);
		text1.setString("Instructions :");
		text1.setPosition(70, 350);
		window.draw(text1);
		
		text1.setFillColor(sf::Color::Cyan);
		text1.setString("The Game has three levels.");
		text1.setPosition(70, 400);
		window.draw(text1);
		
		text1.setFillColor(sf::Color::Cyan);
		text1.setString("Use Arrow Keys for moving player.");
		text1.setPosition(70, 450);
		window.draw(text1);
		
		text1.setFillColor(sf::Color::Cyan);
		text1.setString("RIGHT, LEFT, UP and DOWN");
		text1.setPosition(70, 500);
		window.draw(text1);
		
		text1.setFillColor(sf::Color::Cyan);
		text1.setString("Press 'P' to Pause  and 'spacebar' to Resume .");
		text1.setPosition(70, 550);
		window.draw(text1);

		text1.setFillColor(sf::Color::Cyan);
		text1.setString("Press 'M' to open Menu .");
		text1.setPosition(70, 600);
		window.draw(text1);
	}

	void DisplayHighestScore(RenderWindow &window)
	{
		Font font;
		font.loadFromFile("arial.ttf");
		
		string s;	
		Text text1;
		text1.setFont(font);
		text1.setCharacterSize(30);
		text1.setStyle(sf::Text::Regular);
		text1.setFillColor(sf::Color::Cyan);
		text1.setString("High Scorers : ");
		text1.setPosition(70, 350);
		window.draw(text1);
		
		ifstream ifile("HighScore.txt");
		int y = 400;
		for(int i = 0; i <= 2; i++)
		{
			getline(ifile, s);
			text1.setString(s);
			text1.setPosition(70, y);
			text1.setFillColor(sf::Color::Cyan);

			y = y + 50;
			window.draw(text1);
		}	
	}
};

