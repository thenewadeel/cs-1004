#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;

class Bullet
{
public: CircleShape projectile;
	MyArrayCircle projectiles;
	   	   
	Bullet()
	{
	    	projectile.setFillColor(Color::Magenta);
	    	projectile.setRadius(5.f);
	    	projectiles.push_back(CircleShape(projectile));
    }

    	void Update(int playerCenter_x, int playerCenter_y)
    	{
    	
    		projectile.setPosition(playerCenter_x, playerCenter_y);
		projectiles.push_back(CircleShape(projectile));
    	}

	void Move()
	{
		CircleShape s;  
		for(int i = 0; i < projectiles.size;i++)
		{
			s = projectiles.get(i);
			s.move(0.f, -10.f);
			projectiles.update(i, s);
			if(projectiles.get(i).getPosition().y<=0)
				projectiles.erase(i);
		}
	}

	void Draw(RenderTarget &window)
	{
		for(int i = 0; i < projectiles.size;i++)
		{
			window.draw(projectiles.get(i));
		}
	}
	
};


class FireBullet
{
public: 	
	Texture tex;
 	Sprite sprite;
    	MyArraySprite FireBullets;
    	   
	FireBullet()
	{
	    	sprite.setScale(1.f,1.f);
	    	tex.loadFromFile("img/fire.png");
		sprite.setTexture(tex);
    	}
    	void Update(int playerCenter_x, int playerCenter_y)
    	{
    	
    		sprite.setPosition(playerCenter_x, playerCenter_y);
		FireBullets.push_back(Sprite(sprite));
    	}
	void Move()
	{
		Sprite s;  
		for(int i = 0; i < FireBullets.size;i++)
		{
			s = FireBullets.get(i);
			s.move(0.f, -10.f);
			FireBullets.update(i, s);
			if(FireBullets.get(i).getPosition().y<=0)
				FireBullets.erase(i);
		}
	}
	void Draw(RenderTarget &window)
	{
		for(int i = 0; i < FireBullets.size;i++)
		{
			window.draw(FireBullets.get(i));
		}
	}	
};


class PowerUpBullet
{
public: Texture tex;
 	Sprite sprite;
    	MyArraySprite PowerUpBullets;
    	   
	PowerUpBullet()
	{
	    	sprite.setScale(1.f,1.f);
	    	tex.loadFromFile("img/powerupb.png");
		sprite.setTexture(tex);
	}

    	void Update(int playerCenter_x, int playerCenter_y)
    	{
    	
    		sprite.setPosition(playerCenter_x, playerCenter_y);
		PowerUpBullets.push_back(Sprite(sprite));
    	}

	void Move()
	{
		Sprite s;  
		for(int i = 0; i < PowerUpBullets.size;i++)
		{
			s = PowerUpBullets.get(i);
			s.move(0.f, -10.f);
			PowerUpBullets.update(i, s);
			if(PowerUpBullets.get(i).getPosition().y<=0)
				PowerUpBullets.erase(i);
		}
	}
	
	void Draw(RenderTarget &window)
	{
		for(int i = 0; i < PowerUpBullets.size;i++)
		{
			window.draw(PowerUpBullets.get(i));
		}
	}
	
};
