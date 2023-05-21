#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
#include "MyArray.h"
#include "bullet.h"



class AddOn
{
    	public:
    	MyArraySprite AddOns;
    	protected:
    	Texture tex;
    	Sprite sprite;
    	int mode;
    	
    	public:
	AddOn()
	{
	    	sprite.setScale(0.5f,0.5f);	
    }

    	void Update()
    	{
    		sprite.setPosition(rand() % 600, 0);
		AddOns.push_back(Sprite(sprite));
    	}

	void Move()
	{
		Sprite s;  
		for(int i = 0; i < AddOns.size;i++)
		{
			s = AddOns.get(i);
			s.move(0.f, 2.f);
			AddOns.update(i, s);
			if(AddOns.get(i).getPosition().y>600)
				AddOns.erase(i);
		}
	}

	void Draw(RenderTarget &window)
	{
		for(int i = 0; i < AddOns.size;i++)
		{
			window.draw(AddOns.get(i));
		}
	}

};

class Powerup:public AddOn
{
public:
	Powerup():AddOn()
	{
		tex.loadFromFile("img/powerup.png");
		sprite.setTexture(tex);
		mode = 1;
	}
	
};

class Fire:public AddOn
{
public:
	Fire():AddOn()
	{
		sprite.setScale(1.5f,1.5f);
		tex.loadFromFile("img/fire.png");
		sprite.setTexture(tex);
		mode = 2;
	}
};

class Lives:public AddOn
{
public:
	Lives():AddOn()
	{
		sprite.setScale(1.5f,1.5f);
		tex.loadFromFile("img/heart.png");
		sprite.setTexture(tex);
		mode = 3;
	}
};

class Danger:public AddOn
{
public:
	Danger():AddOn()
	{
		sprite.setScale(0.095,0.095);
		tex.loadFromFile("img/danger.png");
		sprite.setTexture(tex);
		mode = 4;
	}
};



// //////////////////////////////////////////////////////////

class Player{
public:
 
	Texture tex;
	Sprite sprite;
	float speed=5;
	int x,y;
	int mode;
	Bullet b;
	PowerUpBullet p_up_b;
	FireBullet f_b;
	
	AddOn *P_up[4];
	
	Player(std::string png_path)
	{
		mode = 0;
		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		x=300;y=600;
		sprite.setPosition(x,y);
		sprite.setScale(0.75,0.75);
		P_up[0] = new Powerup;
		P_up[1] = new Fire;
		P_up[2] = new Lives;
		P_up[3] = new Danger;
	}

	void fire()
	{

	}
/*	
	void move(std::string s)
	{
		float delta_x=0,delta_y=0;
		if(s=="l")//move the player left
		{
			if (sprite.getPosition().x <= 0)
        			sprite.setPosition(620, sprite.getPosition().y);
			else
				delta_x=-1;
		}
		else if(s=="r")//move the player right
		{
			if (sprite.getPosition().x >= 620)
        			sprite.setPosition(0, sprite.getPosition().y);
        		else
				delta_x=1;
		}
		if(s=="u"&&sprite.getPosition().y>0)
			delta_y=-1;
		else if(s=="d"&&sprite.getPosition().y<600)
			delta_y=1;
		delta_x*=speed;
		delta_y*=speed;
		sprite.move(delta_x, delta_y);
	}

*/
void move(std::string s)
{
    float delta_x = 0, delta_y = 0;
    if (s == "l") // move the player left
    {
        if (sprite.getPosition().x <= 0)
            sprite.setPosition(620, sprite.getPosition().y);
        else
            delta_x = -1;
    }
    else if (s == "r") // move the player right
    {
        if (sprite.getPosition().x >= 620)
            sprite.setPosition(0, sprite.getPosition().y);
        else
            delta_x = 1;
    }
    if (s == "u") // move the player up
    {
        if (sprite.getPosition().y <= 0)
            sprite.setPosition(sprite.getPosition().x, 600);
        else
            delta_y = -1;
    }
    else if (s == "d") // move the player down
    {
        if (sprite.getPosition().y >= 600)
            sprite.setPosition(sprite.getPosition().x, 0);
        else
            delta_y = 1;
    }
    delta_x *= speed;
    delta_y *= speed;
    sprite.move(delta_x, delta_y);
}




};

