#include <SFML/Graphics.hpp>
#include <fstream>

using namespace std;

class Menu2
{
public:
	Sprite background; //Game background sprite
	Texture bg_texture;
	Menu2()
	{
		bg_texture.loadFromFile("img/menubackground2.jpg");
		background.setTexture(bg_texture);
		background.setScale(1.2, 1.5);
	}
	bool display_menu2()
	{
		bool choice=false;
	    	
	    	srand(time(NULL));
		RenderWindow window(VideoMode(700, 500), "In Game Menu");
		window.setFramerateLimit(60); 
		//display menu screen here
		window.clear(Color::Black);
		window.draw(background);
		while (window.isOpen())
		{
			
			DisplayMenu2Options(window);
			
			Event e;
			while (window.pollEvent(e))
			{  
			    if (e.type == Event::Closed) // If cross/close is clicked/pressed
				window.close(); //close the game                        	    
			}
			if (Keyboard::isKeyPressed(Keyboard::R))//Play game option
			{
				window.close();
				choice=true;
			
			}
			if (Keyboard::isKeyPressed(Keyboard::H))//Highest score option 
			{
				//display menu screen here
				window.clear(Color::Black);
				window.draw(background);
				DisplayMenu2Options(window);
				DisplayHighestScore(window);
			}
			if (Keyboard::isKeyPressed(Keyboard::I))//Instructions option
			{
				//display menu screen here
				window.clear(Color::Black);
				window.draw(background);
				DisplayMenu2Options(window);
				DisplayInstructions(window);
			}
			if (Keyboard::isKeyPressed(Keyboard::E))//Exit option
			{
				window.close();
			}
			window.display();
		}//end while
		return choice;
	}
	void DisplayMenu2Options(RenderWindow &window)
	{
		//Display Score, lives and level on Screen
		Font font;
		font.loadFromFile("arial.ttf");
			
		Text text1;
		text1.setFont(font);
		text1.setCharacterSize(30);
		text1.setStyle(sf::Text::Regular);
		text1.setFillColor(sf::Color::Cyan);
		text1.setString("R => Resume Game");
		text1.setPosition(230, 100);
		window.draw(text1);
		
		text1.setFillColor(sf::Color::Cyan);
		text1.setString("H => Highest Score");
		text1.setPosition(230, 150);
		window.draw(text1);
		
		text1.setFillColor(sf::Color::Cyan);
		text1.setString("I => Instructions");
		text1.setPosition(230, 200);
		window.draw(text1);
		
		text1.setFillColor(sf::Color::Cyan);
		text1.setString("E => End Game");
		text1.setPosition(230, 250);
		window.draw(text1);
	}
	void DisplayInstructions(RenderWindow &window)
	{
		//Display Score, lives and level on Screen
		Font font;
		font.loadFromFile("arial.ttf");
			
		Text text1;
		text1.setFont(font);
		text1.setCharacterSize(25);
		text1.setStyle(sf::Text::Regular);
		
		text1.setFillColor(sf::Color::Cyan);
		text1.setString("Use Arrow Keys for moving player");
		text1.setPosition(70, 350);
		window.draw(text1);
		
		text1.setFillColor(sf::Color::Cyan);
		text1.setString("RIGHT, LEFT, UP and DOWN");
		text1.setPosition(70, 400);
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
		text1.setString("High Scorers are ");
		text1.setPosition(70, 300);
		window.draw(text1);
		
		ifstream ifile("HighScore.txt");
		int y = 350;
		for(int i = 0; i <= 2; i++)
		{
			getline(ifile, s);
			text1.setString(s);
			text1.setFillColor(sf::Color::Cyan);
			text1.setPosition(70, y);
			y = y + 50;
			window.draw(text1);
		}	
	}
};

