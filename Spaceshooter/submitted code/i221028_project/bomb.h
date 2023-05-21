#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;



class Bomb
{
public:
	int n1;
	Texture tex;
 	Sprite sprite;
    	MyArraySprite Bombs;
    	 
	void SetBombImage(int n)
	{
		n1 = n;
		sprite.setScale(1.5f,1.5f);
		if(n == 0)
	    		{tex.loadFromFile("img/bomb1.png");
				sprite.setScale(1.5f,1.5f);}
			
	    	else if(n == 1)
	    		{tex.loadFromFile("img/missile.png");
				sprite.setScale(0.045,0.025);}
	    	else if(n == 2)
	    		{tex.loadFromFile("img/bomb1.png");
				sprite.setScale(1.5f,1.5f);}
	    	else if(n == 3)
	    	{
	    		tex.loadFromFile("img/bomb4.png");
	    		sprite.setScale(2.5,2.5);
	    	}
	    	else if(n == 4)
	    	{
	    		tex.loadFromFile("img/laserBlue05.png");
	    		sprite.setScale(1,5);
	    	}
		sprite.setTexture(tex);	
    	}

    	void Update(int HugeEnemyCenter_x, int HugeEnemyCenter_y)
    	{
    		if(n1 != 4)//if not monster
    		{
    		int bombPos_x, bombPos_y;
    		if(n1 == 3)//Dragon
    		{
    			bombPos_x = HugeEnemyCenter_x + 95;
    			bombPos_y = HugeEnemyCenter_y + 200;
    			sprite.setPosition(bombPos_x, bombPos_y);
    		}
    		else if(n1 == 4)//Monster
    		{
    			sprite.setPosition(HugeEnemyCenter_x+150, HugeEnemyCenter_y+250);
    		}
    		else
    			sprite.setPosition(HugeEnemyCenter_x, HugeEnemyCenter_y);
    		Bombs.push_back(Sprite(sprite));
    		}
    	}

	void Move(int spaceShipPos_x, int spaceShipPos_y)
	{
		if(n1 != 4)//if not monster
		{
		Sprite s;  
		for(int i = 0; i < Bombs.size;i++)
		{
			s = Bombs.get(i);
			if(n1 == 3)
			{ 
				if(spaceShipPos_x > 300)
					s.move(2.f, 5.f);//Dragon Enemy
				else if(spaceShipPos_x < 300)
					s.move(-2.f, 5.f);//Dragon Enemy
				else
					s.move(0.f, 3.f);	
			}
			else
				s.move(0.f, 3.f);
			Bombs.update(i, s);
			if(Bombs.get(i).getPosition().y>600)
				Bombs.erase(i);
		}
		}
	}
	
	void Draw(RenderTarget &window)
	{
		if(n1 != 4)//if not monster
		{
		for(int i = 0; i < Bombs.size;i++)
		{
			window.draw(Bombs.get(i));
		}
		}
	}
	
};
