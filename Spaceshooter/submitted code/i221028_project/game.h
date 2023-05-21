
#include <SFML/Graphics.hpp>
#include <time.h>
#include "player.h"
#include "enemy.h"
#include "menu2.h"
#include<cstdlib>

const char title[] = "OOP-Project,Spring-2023";
class Game
{
	public:
	Sprite background; //Game background sprite
	Texture bg_texture;

	Player* p;
	Enemy *H_en[5];

	Menu2 m;
	Clock clock, clock1;

	float delay = 5;
	float AddOntimer = 0;
	float EnemyResettimer = 0;
	int pLives;	
	int Score = 0;
	int Lives = 3;
	int ShapeCount = 1;
	int GameLevel =1;
	int select = 0;
	int power = 0;
	int  levelSpeed = 80;

	bool EnemyCheck = true;
	bool GameEnd = false;
	bool pauseGame = false;
	bool bDisplay = true;
	bool collisionOccurred=false;

	time_t collisionTime = 0;
	const int collisionDuration = 5; 

	// CONSTRUCTOR INITIALIZING BACKGROUND 
	Game()
	{
		p=new Player("img/player_ship.png");
		
		H_en[0] = new Alpha;
		H_en[1] = new Beta;
		H_en[2] = new Gamma;
		H_en[3] = new Dragon;
		H_en[4] = new Monster;
		
		bg_texture.loadFromFile("img/myb.png");
		background.setTexture(bg_texture);
		background.setScale(2.25, 2.2);
	}

	// START GAME FUNCTION CONTROLS THE GAME
	void start_game()
	{	
		srand(time(NULL));
		RenderWindow window(VideoMode(700, 680), title);
		window.setFramerateLimit(60);
		  		
   			int shootTimer = 0;
   			int HugeEnemyTimer = 0;
    		int BombSpawnTimer = 0;
    		int AddonSpawnTimer=0;
	    	int playerCenter_x, playerCenter_y;
	    	int HugeEnemyPosition_x, HugeEnemyPosition_y;
	    	
			// LOOP THAT RUNS THE GAME 
    		while (window.isOpen() )
	    	{
	    	if (!pauseGame) // If the game is not paused
   		{
	    		float time = clock.getElapsedTime().asSeconds();
	    		clock.restart();
		   	
		   	AddOntimer += time;
		   	
		
		   	if(select == 3 || select == 4)
		   	{
		   		if(EnemyCheck == true)
		   		{
		   			pLives = Lives;
		   			clock1.restart();
		   			EnemyCheck = false;
		   		}
		   		float time1 = clock1.getElapsedTime().asSeconds();
	    			clock1.restart();
		   		EnemyResettimer+= time1;	
		   	}

		 	Event e;
		 	if(GameLevel == 2)
		 		levelSpeed = 60;
		 	else if(GameLevel == 3)
		 		levelSpeed = 40;
		 	if(GameLevel == 4)
		 		GameEnd = true;
		 		
			while (window.pollEvent(e))
			{  
			    if (e.type == Event::Closed) // If cross/close is clicked/pressed
				{window.close(); //close the game
				bool choice=m.display_menu2();
				if(choice==true)
				start_game(); 
				}


			}

	if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
       	{   
		  p->move("l");    // Player will move to left
	      p->tex.loadFromFile("img/player_ship.png");
	      p->sprite.setScale(0.8,0.8);
		}	
	if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
        {   p->move("r");  //player will move to right
            p->tex.loadFromFile("img/player_ship.png");
            p->sprite.setScale(0.8,0.8);
        }
	if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
        {    p->move("u");    //playet will move upwards
	     p->tex.loadFromFile("img/player_ship.png");
	    p->sprite.setScale(0.8,0.8);
	}
	if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
        {    p->move("d");  //player will move downwards
             p->tex.loadFromFile("img/player_ship.png");
             p->sprite.setScale(0.8,0.8);
        }
        if ( (Keyboard::isKeyPressed(Keyboard::Up)) && (Keyboard::isKeyPressed(Keyboard::Left)) )
        {    p->tex.loadFromFile("img/ship1.png"); 
        p->sprite.setScale(1,1);
	}
	if ( (Keyboard::isKeyPressed(Keyboard::Up)) && (Keyboard::isKeyPressed(Keyboard::Right)) )
        {    p->tex.loadFromFile("img/ship2.png"); 
           p->sprite.setScale(1,1);
	}
	if ( (Keyboard::isKeyPressed(Keyboard::Down)) && (Keyboard::isKeyPressed(Keyboard::Right)) )
        {    p->tex.loadFromFile("img/ship1.png"); 
           p->sprite.setScale(1,1);
	}
	if ( (Keyboard::isKeyPressed(Keyboard::Down)) && (Keyboard::isKeyPressed(Keyboard::Left)) )
        {    p->tex.loadFromFile("img/ship2.png"); 
           p->sprite.setScale(1,1);
	}
	    		   
	      if (Keyboard::isKeyPressed(Keyboard::M)) // Open Menu
			{window.close(); 
				bool choice=m.display_menu2();
				if(choice==true)
				start_game(); 
				}
				
			if (collisionOccurred && (GetCurrentTime() - collisionTime >= collisionDuration))
			{
    		 collisionOccurred = false;
			}

			playerCenter_x = p->sprite.getPosition().x+30;
			playerCenter_y = p->sprite.getPosition().y;
			
			//Update and move bullets of spaceship
			if(shootTimer < 30)
				shootTimer++;
			if(shootTimer>=30)
			{	if(p->mode == 0||p->mode == 3||p->mode == 4)
					p->b.Update(playerCenter_x, playerCenter_y);
				else if(p->mode == 1)
					p->p_up_b.Update(playerCenter_x, playerCenter_y);
				else if(p->mode == 2)
					p->f_b.Update(playerCenter_x, playerCenter_y);
				shootTimer = 0;
			}
			if(p->mode == 0||p->mode == 3||p->mode == 4)
				p->b.Move();
			else if(p->mode == 1)
				p->p_up_b.Move();
			else if(p->mode == 2)
				p->f_b.Move();
			
						
			//Update and move Add ons
			if(AddonSpawnTimer < 400)
				AddonSpawnTimer++;
			if(AddonSpawnTimer >= 400)
			{
				power = rand() % 4;
				p->P_up[power]->Update();
				AddonSpawnTimer=0;
			}
			
			p->P_up[power]->Move();
			
			// check for collisions
			CheckForCollisionBulletsEnemies();
			CheckForCollisionPowerupBulletsEnemies();
			CheckForCollisionFireBulletsEnemies();
			CheckForCollisionPlayerBombs();
			CheckForCollisionPlayerAddOns();
			CheckForCollisionPlayerEnemies();
			CheckForCollisionMonster();
			CheckForCollisionFireBulletsBombs();
			//CheckForCollisionBulletsBombs();
			CheckForCollisionPowerupBulletsBombs();
							
			ResetAddOnmode();
			ControlMonsterAndDragonDisplay();
				
			//Update and move bombs of enemy
						int btime;
						if(GameLevel==1)
						btime=120;
						else if(GameLevel==2)
						btime=90;
						else if(GameLevel==3)
						btime=60;
			
			if(BombSpawnTimer < btime)
				BombSpawnTimer++;
			if(BombSpawnTimer >= btime)
			{
				HugeEnemyPosition_x = rand()%int (window.getSize().x);
				HugeEnemyPosition_y = H_en[select]->sprite.getPosition().y+40;
				H_en[select]->Update();
				BombSpawnTimer=0;
				if(bDisplay == true)
					bDisplay = false;
				else
					bDisplay = true;
			}
			H_en[select]->b.Move(playerCenter_x, playerCenter_y); // bomb drops from enemy
			H_en[select]->Move(bDisplay);

			window.clear(Color::Black);
			window.draw(background);
			if(GameEnd == false)
			{
				window.draw(p->sprite);
				
				DisplayScoreLivesLevel(window, GameEnd);
					
				//Draw Bullets
				if(p->mode == 0||p->mode == 3||p->mode == 4)
					p->b.Draw(window);
				else if(p->mode == 1)
					p->p_up_b.Draw(window);
				else if(p->mode == 2)
					p->f_b.Draw(window);
				
				//Draw Add ons
				p->P_up[power]->Draw(window);
				
				//Draw Huge Enemies
				H_en[select]->Draw(window);;
				
				//Draw Bombs
				H_en[select]->b.Draw(window);
			} 
			//else
			{
				DisplayScoreLivesLevel(window, GameEnd);
			}
			window.display();
		}
		 else // If the game is paused
    		{
        	Event e;
        	while (window.pollEvent(e))
        	{
            if (e.type == Event::Closed)
                window.close();
            if (e.type == Event::KeyPressed && e.key.code == Keyboard::Space) // If the spacebar is pressed, resume the game
                pauseGame = false;
        	}
    		}

    	if (Keyboard::isKeyPressed(Keyboard::P)) //  pause the game
        pauseGame = true;

		}//end while  
	}

	void DisplayScoreLivesLevel(RenderTarget &window, bool GameEnd)
	{
		//Display Score, lives and level on Screen
		Font font;
		font.loadFromFile("arial.ttf");
		
		Text text1;
		text1.setFont(font);
		text1.setCharacterSize(20);
		text1.setStyle(sf::Text::Regular);
		text1.setString("Score:");
		text1.setPosition(580, 10);
		
		Text text2;
		text2.setFont(font);
		text2.setCharacterSize(20);
		text2.setStyle(sf::Text::Regular);
		text2.setString("Lives:");
		text2.setPosition(580, 35);
		
		Text text3;
		text3.setFont(font);
		text3.setCharacterSize(20);
		text3.setStyle(sf::Text::Regular);
		text3.setString("GAME LEVEL:");
		text3.setPosition(500, 60);
		
		Text text4;
		text4.setFont(font);
		text4.setCharacterSize(60);
		text4.setStyle(sf::Text::Regular);
		text4.setString("GAME OVER");
		text4.setPosition(100, 300);
		
		Text sScore(std::to_string(Score), font);
		sScore.setPosition(650, 10);
		sScore.setCharacterSize(20);
		
		Text sLives(std::to_string(Lives), font);
		sLives.setPosition(650, 35);
		sLives.setCharacterSize(20);
			
		Text sGameLevel(std::to_string(GameLevel), font);
		sGameLevel.setPosition(650, 60);
		sGameLevel.setCharacterSize(20);
		
		if(GameEnd == false)
		{
			window.draw(text1);
			window.draw(text2);
			window.draw(text3);

			window.draw(sScore);
			window.draw(sLives);
			window.draw(sGameLevel);
		}
		else
		{
			sScore.setPosition(500, 350);
sScore.setCharacterSize(40);
window.draw(sScore);

text4.setCharacterSize(40);
text4.setString("YOUR SCORE IS");
text4.setPosition(150, 350);
window.draw(text4);

sf::Text gameOverText;
gameOverText.setFont(font);
gameOverText.setCharacterSize(60);
//gameOverText.setFillColor(sf::Color::Red);
gameOverText.setString("Game Over");
sf::FloatRect gameOverTextBounds = gameOverText.getLocalBounds();
gameOverText.setPosition((window.getSize().x - gameOverTextBounds.width) / 2, 250);
window.draw(gameOverText);

		}
	}

	void ControlMonsterAndDragonDisplay()
	{
		if(EnemyResettimer > 10)
		{
			if(select == 3)
			{
				if(pLives == Lives)//score added to dodge dragon
					{	if(GameEnd==false)
					{
						if(GameLevel==1)
						Score=Score+50;
						else if(GameLevel==2)
						Score=Score+100;
						else if(GameLevel==3)
						Score=Score+150;
					}
					}
				EnemyCheck = true;
				H_en[select]->enemies.clear();
				select++;
			}
			else if(select == 4)
			{
				if(pLives == Lives)//score added to dodge monster
				{
					if(GameEnd==false)
					{
					if(GameLevel==1)
						Score=Score+40;
						else if(GameLevel==2)
						Score=Score+80;
						else if(GameLevel==3)
						Score=Score+120;
					}
				}
				EnemyCheck = true;
				H_en[select]->enemies.clear();
				select = 0;
			}
			EnemyResettimer = 0;
			H_en[select]->SetEnemiesShape(ShapeCount);
		}
	}

	void ResetAddOnmode()
	{
		if(AddOntimer > delay)
		{
			//reset AddOn mode
			p->mode = 0;
			AddOntimer = 0;
		}
	}


	void CheckForCollisionPlayerEnemies()
	{
		for(int k = 0; k < H_en[select]->enemies.size;k++)
		{
			if(CheckForCollision(p->sprite.getGlobalBounds(), H_en[select]-> enemies.get(k).getGlobalBounds()))
			{
				H_en[select]-> enemies.erase(k);
				Lives--;
				if(Lives<=0)
				GameEnd=true;
				break;
			}
			
		}
	}



	void CheckForCollisionPlayerBombs()
	{
		for(int k = 0; k < H_en[select]->b.Bombs.size;k++)
		{
			if(CheckForCollision(H_en[select]->b.Bombs.get(k).getGlobalBounds(), p->sprite.getGlobalBounds()))
			{
				H_en[select]->b.Bombs.erase(k);
				Lives --;
				if(Lives<=0)
				GameEnd=true;
				break;
			}
		}
	}


	void CheckForCollisionMonster()
	{
		if(CheckForCollision(H_en[select]->b.sprite.getGlobalBounds(), p->sprite.getGlobalBounds()))
			{
				if( collisionOccurred == false)
				{Lives --;
				collisionOccurred=true;
				collisionTime = GetCurrentTime();}
			//	p->sprite.setPosition(350,600);
				if(Lives<=0)
				GameEnd=true;
				
			}



		
	}
	/*
	void CheckForCollisionBulletsBombs()
	{
		if(select < 3)//if not dragon or monster
		{
		for(int i = 0; i < p->b.projectiles.size;i++)
		{
			for(int k = 0; k < H_en[select]->b.Bombs.size;k++)
			{
				if(CheckForCollision(p->b.projectiles.get(i).getGlobalBounds(),H_en[select]->b.Bombs.get(k).getGlobalBounds()))
				{
					H_en[select]->b.Bombs.erase(k);
					p->b.projectiles.erase(i);
					break;
				}
			}
		}
		}
	}
	*/
	void CheckForCollisionPowerupBulletsBombs()
	{	if(select < 3)//if not dragon or monster
		{
		for(int i = 0; i < p->p_up_b.PowerUpBullets.size;i++)
		{
			for(int k = 0; k < H_en[select]->b.Bombs.size;k++)
			{
				if(CheckForCollision(p->p_up_b.PowerUpBullets.get(i).getGlobalBounds(),H_en[select]->b.Bombs.get(k).getGlobalBounds()))
				{
					H_en[select]->b.Bombs.erase(k);
					break;
				}
			}
		}
		}
	}

	void CheckForCollisionFireBulletsBombs()
	{	if(select < 3)//if not dragon or monster
		{
		for(int i = 0; i < p->f_b.FireBullets.size;i++)
		{
			for(int k = 0; k < H_en[select]->b.Bombs.size;k++)
			{
				if(CheckForCollision(p->f_b.FireBullets.get(i).getGlobalBounds(),H_en[select]->b.Bombs.get(k).getGlobalBounds()))
				{
					H_en[select]->b.Bombs.erase(k);
					break;
				}
			}
		}
		}
	}

	void CheckForCollisionPlayerAddOns()
	{
		for(int i = 0; i < p->P_up[power]->AddOns.size;i++)
		{
			if(CheckForCollision(p->P_up[power]->AddOns.get(i).getGlobalBounds(), p->sprite.getGlobalBounds()))
			{
				p->mode = power + 1;//power up add on
				p->P_up[power]->AddOns.erase(i);
				AddOntimer = 0;
				//Lives Addon mode
				if(p->mode == 3)
				{if(Lives<=2)	
				  Lives++;
				  }				
				//Danger Addon mode
				if(p->mode == 4)
				{  Lives--;
				if(Lives<=0)
				GameEnd=true;
				}
			}
		}
	}

	void CheckForCollisionFireBulletsEnemies()
	{
		if(select < 3)//if not dragon or monster
		{
		for(int i = 0; i < p->f_b.FireBullets.size;i++)
		{			
			for(int k = 0; k < H_en[select]->enemies.size;k++)
			{
			if(CheckForCollision(p->f_b.FireBullets.get(i).getGlobalBounds(), H_en[select]-> enemies.get(k).getGlobalBounds()))
				{
					H_en[select]->enemies.erase(k);
						if(GameEnd==false)
					{
						if(GameLevel==1)
						Score=Score+20;
						else if(GameLevel==2)
						Score=Score+40;
						else if(GameLevel==3)
						Score=Score+60;

					break;
					}
				}	
			}
		}
		}
	}

	void CheckForCollisionPowerupBulletsEnemies()
	{
		if(select < 3)//if not dragon or monster
		{
		for(int i = 0; i < p->p_up_b.PowerUpBullets.size;i++)
		{			
			for(int k = 0; k < H_en[select]->enemies.size;k++)
			{
			if(CheckForCollision(p->p_up_b.PowerUpBullets.get(i).getGlobalBounds(), H_en[select]-> enemies.get(k).getGlobalBounds()))
				{
					H_en[select]->enemies.erase(k);
					if(GameEnd==false)
					{
					if(GameLevel==1)
						Score=Score+20;
						else if(GameLevel==2)
						Score=Score+40;
						else if(GameLevel==3)
						Score=Score+60;

					break;
					}
				}
			}
		}
		}
	}

	void CheckForCollisionBulletsEnemies()
	{
		
		if(select < 3)//if not dragon or monster
		{
			for(int i = 0; i < p->b.projectiles.size;i++)
			{
				
						
				for(int k = 0; k < H_en[select]->enemies.size;k++)
				{

				if(CheckForCollision(p->b.projectiles.get(i).getGlobalBounds(), H_en[select]-> enemies.get(k).getGlobalBounds()))
					{
						p->b.projectiles.erase(i);
						H_en[select]->enemies.erase(k);
						if(GameEnd==false)
					{
						if(GameLevel==1)
						Score=Score+20;
						else if(GameLevel==2)
						Score=Score+40;
						else if(GameLevel==3)
						Score=Score+60;
						break;
					}
					}
				}
			}
		
		if(H_en[select]->enemies.size == 0)
		{
			if(ShapeCount == 3 || ShapeCount == 6 || ShapeCount == 12 )
			{
				GameLevel++;
				if(GameLevel == 4)
					GameEnd = true;
			}
			if(ShapeCount<12 && (select != 3 && select !=4))
			{
				ShapeCount++;	
			}
			if(select < 3)
			{
				select++;
			}
			H_en[select]->SetEnemiesShape(ShapeCount);
		}
		}
	}
	
	// COLLISION FUNCTION
	bool CheckForCollision(FloatRect A, FloatRect B)
	{
		if((A.left > B.left + B.width) ||
		(A.left + A.width < B.left) ||
		(A.top > B.top + B.height) ||
		(A.top + A.height < B.top))
			return false;
		else
			return true;
	}	  

	time_t GetCurrentTime()
	{
    	return time(nullptr);
	}

};

