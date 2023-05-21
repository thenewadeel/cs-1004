#include <SFML/Graphics.hpp>
#include<string.h>
#include "bomb.h"
using namespace sf;



class Enemy
{
public:
 
	Texture tex;
	Sprite sprite;
	float speed=2.4;
	int ShapeCount = 1;
	bool CanMove;
	int interval;
	int x,y;
	int points;
	Bomb b;
	MyArraySprite enemies;
	bool toDisplay;

	Enemy()
	{
		x=250;y=20;
		sprite.setPosition(x,y);
	}

	void Update()
	{
		int EnemyPos_x, EnemyPos_y;
		if(enemies.size > 0)
		{
			int pos = rand() % enemies.size;
			EnemyPos_x = enemies.get(pos).getPosition().x;
			EnemyPos_y = enemies.get(pos).getPosition().y + 5;
			
		}
		else
		{
			EnemyPos_x = (rand() % 430) + 170;
			EnemyPos_y = (rand() % 355) + 70;
		}
		b.Update(EnemyPos_x, EnemyPos_y);
	}
	
	void Move(bool bDisplay)
	{
	toDisplay = bDisplay;
	if(CanMove == true)
	 {
 	   // move enemy horizontally
 	   sprite.setPosition(sprite.getPosition().x + speed, sprite.getPosition().y);
	
 	   // check if enemy has hit right boundary
 	   if (sprite.getPosition().x + sprite.getGlobalBounds().width >= 720) {
 	       speed = -speed; // reverse direction
  	      sprite.setPosition(720 - sprite.getGlobalBounds().width, sprite.getPosition().y);
  	  }

  	  // check if enemy has hit left boundary
   	 if (sprite.getPosition().x <= -50) {
    	    speed = -speed; // reverse direction
   	     sprite.setPosition(0, sprite.getPosition().y);
		 
   	 }
   	 b.sprite.setScale(2.5,10);
   	 b.sprite.setPosition(sprite.getPosition().x+150, sprite.getPosition().y+280);
 	}
	}

	virtual void Draw(RenderTarget &window)=0;
	virtual void SetEnemiesShape(int n)=0;
};

// INVADER CLASS /////////////////////////

class Invader:public Enemy
{
public:
	Invader():Enemy()
	{
		CanMove = false;
		sprite.setScale(0.45,0.45);
	}
	void SetEnemiesShape(int n)
	{
		if(n == 1)
			DrawRectangleEnemies();
		else if(n == 2)
			DrawTriangleEnemies();
		else if(n == 3)
			DrawCrossEnemies();
		else if(n == 4)
			DrawCircleEnemies();
		else if(n == 5)
			DrawDiamondEnemies();
		else if(n == 6)
			DrawHeartEnemies();
		else if(n == 7)
			DrawFilledRectangleEnemies();
		else if(n == 8)
			DrawFilledTriangleEnemies();
		else if(n == 9)
			DrawFilledCrossEnemies();
		else if(n == 10)
			DrawFilledCrossEnemies();
		else if(n == 11)
			DrawFilledDiamondEnemies();
		else if(n == 12)
			DrawFilledHeartEnemies();
	}
	void DrawRectangleEnemies();//1
	void DrawTriangleEnemies();//2
	void DrawCrossEnemies();//3
	void DrawCircleEnemies();//4
	void DrawDiamondEnemies();//5
	void DrawHeartEnemies();//6
	void DrawFilledRectangleEnemies();//7
	void DrawFilledTriangleEnemies();//8
	void DrawFilledCrossEnemies();//9
	//circle
	void DrawFilledDiamondEnemies();//11
	void DrawFilledHeartEnemies();//12

	void Draw(RenderTarget &window)
	{
		for(int i = 0; i < enemies.size;i++)
		{
			window.draw(enemies.get(i));
		}
	}
};


class Alpha:public Invader
{
public:
	Alpha():Invader()
	{
		interval = 5;
		points = 10;
		tex.loadFromFile("img/enemy_1.png");
		//sprite.setScale(0.75,0.75);
		sprite.setTexture(tex);
		b.SetBombImage(0);
		SetEnemiesShape(1);
	}
	
};

// ///////////////////////////////////////
class Beta:public Invader
{
public:
	Beta():Invader()
	{
		
		interval = 3;
		points = 20;
		tex.loadFromFile("img/enemy_2.png");
		sprite.setTexture(tex);
		b.SetBombImage(1);
		SetEnemiesShape(1);
	}
};

// ///////////////////////////////////////
class Gamma:public Invader
{
public:
	Gamma():Invader()
	{
		interval = 2;
		points = 30;
		tex.loadFromFile("img/enemy_3.png");
		sprite.setTexture(tex);
		b.SetBombImage(2);
		SetEnemiesShape(1);
	}
};

// ///////////////////////////////////////
class Dragon:public Enemy
{
public:
	Dragon():Enemy()
	{
		interval = 10;
		CanMove = false;
		points = 50;
		tex.loadFromFile("img/dragon1.png");
		sprite.setTexture(tex);
		sprite.setScale(1,1);
		b.SetBombImage(3);
	}
	void Draw(RenderTarget &window)
	{
		for(int i = 0; i < enemies.size;i++)
			window.draw(sprite);
	}
	void SetEnemiesShape(int n)
	{	
		enemies.push_back(Sprite(sprite));
	}
};

// ///////////////////////////////////////
class Monster:public Enemy
{
public:
	Monster():Enemy()
	{
		interval = 10;
		CanMove = true;
		points = 40;
		tex.loadFromFile("img/monster1.png");
		sprite.setScale(0.5,0.5);
		sprite.setTexture(tex);
		b.SetBombImage(4);
	}
	void Draw(RenderTarget &window)
	{
		for(int i = 0; i < enemies.size;i++)
			window.draw(sprite);
		if(toDisplay == true)
			window.draw(b.sprite);
	}
	void SetEnemiesShape(int n)
	{
		enemies.push_back(Sprite(sprite));
	}
};


// SHAPES ///////////////////////////////////////

void Invader::DrawRectangleEnemies()
{
	enemies.clear();
	x=200;y=150;
	for(int i = 0; i <= 3; i++)
	{	
		sprite.setPosition(x,y);
		enemies.push_back(Sprite(sprite));
		x = x+75;
	}
	x=200;y=350;
	for(int i = 0; i <= 3; i++)
	{	
		sprite.setPosition(x,y);
		enemies.push_back(Sprite(sprite));
		x = x+75;
	}
	x=200;y=225;
	for(int i = 0; i <= 1; i++)
	{	
		sprite.setPosition(x,y);
		enemies.push_back(Sprite(sprite));
		y = y+65;
	}
	x=425;y=225;
	for(int i = 0; i <= 1; i++)
	{	
		sprite.setPosition(x,y);
		enemies.push_back(Sprite(sprite));
		y = y+65;
	}
}//1
void Invader::DrawTriangleEnemies()
{
	enemies.clear();
	x=311;y=125;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
		
	x=274;y=200;
	for(int i = 0; i <= 1; i++)
	{	
		sprite.setPosition(x,y);
		enemies.push_back(Sprite(sprite));
		x = x+75;
	}
	x=237;y=275;
	for(int i = 0; i <= 2; i++)
	{	
		if(i==1)
		{x=x+75;
		continue;}
		sprite.setPosition(x,y);
		enemies.push_back(Sprite(sprite));
		x = x+75;
	}
	x=200;y=350;
	for(int i = 0; i <= 3; i++)
	{	
		sprite.setPosition(x,y);
		enemies.push_back(Sprite(sprite));
		x = x+75;
	}
}//2
void Invader::DrawCrossEnemies()
{
    	enemies.clear();
	x=240;y=120;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=380;y=120;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=190;y=70;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=430;y=70;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=240;y=230;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=380;y=230;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=190;y=280;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=430;y=280;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
}//3
void Invader::DrawDiamondEnemies()
{
	enemies.clear();
	x=311;y=125;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
		
	x=274;y=200;
	for(int i = 0; i <= 1; i++)
	{	
		sprite.setPosition(x,y);
		enemies.push_back(Sprite(sprite));
		x = x+75;
	}
	x=237;y=275;
	for(int i = 0; i <= 2; i++)
	{	if(i==1)
	{x=x+75;
	continue;}
	else{
		sprite.setPosition(x,y);
		enemies.push_back(Sprite(sprite));
		x = x+75;
	}
	}
	
	x=274;y=350;
	for(int i = 0; i <= 1; i++)
	{	
		sprite.setPosition(x,y);
		enemies.push_back(Sprite(sprite));
		x = x+75;
	}

	x=311;y=425;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	

}//5
void Invader::DrawFilledTriangleEnemies()
{
	enemies.clear();
	x=311;y=125;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
		
	x=274;y=200;
	for(int i = 0; i <= 1; i++)
	{	
		sprite.setPosition(x,y);
		enemies.push_back(Sprite(sprite));
		x = x+75;
	}
	x=237;y=275;
	for(int i = 0; i <= 2; i++)
	{	
		sprite.setPosition(x,y);
		enemies.push_back(Sprite(sprite));
		x = x+75;
	}
	x=200;y=350;
	for(int i = 0; i <= 3; i++)
	{	
		sprite.setPosition(x,y);
		enemies.push_back(Sprite(sprite));
		x = x+75;
	}
}//8

void Invader::DrawFilledRectangleEnemies()
{
	enemies.clear();
	x=200;y=150;
	for(int i = 0; i <= 3; i++)
	{	
		sprite.setPosition(x,y);
		enemies.push_back(Sprite(sprite));
		x = x+75;
	}
	x=200;y=350;
	for(int i = 0; i <= 3; i++)
	{	
		sprite.setPosition(x,y);
		enemies.push_back(Sprite(sprite));
		x = x+75;
	}
	x=200;y=225;
	for(int i = 0; i <= 1; i++)
	{	
		sprite.setPosition(x,y);
		enemies.push_back(Sprite(sprite));
		y = y+65;
	}
	x=275;y=225;
	for(int i = 0; i <= 1; i++)
	{	
		sprite.setPosition(x,y);
		enemies.push_back(Sprite(sprite));
		y = y+65;
	}
	x=350;y=225;
	for(int i = 0; i <= 1; i++)
	{	
		sprite.setPosition(x,y);
		enemies.push_back(Sprite(sprite));
		y = y+65;
	}
	x=425;y=225;
	for(int i = 0; i <= 1; i++)
	{	
		sprite.setPosition(x,y);
		enemies.push_back(Sprite(sprite));
		y = y+65;
	}
}//7

void Invader::DrawFilledDiamondEnemies()
{
	enemies.clear();
	x=311;y=125;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
		
	x=274;y=200;
	for(int i = 0; i <= 1; i++)
	{	
		sprite.setPosition(x,y);
		enemies.push_back(Sprite(sprite));
		x = x+75;
	}
	x=237;y=275;
	for(int i = 0; i <= 2; i++)
	{	
		sprite.setPosition(x,y);
		enemies.push_back(Sprite(sprite));
		x = x+75;
	}
	
	x=274;y=350;
	for(int i = 0; i <= 1; i++)
	{	
		sprite.setPosition(x,y);
		enemies.push_back(Sprite(sprite));
		x = x+75;
	}

	x=311;y=425;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
}//11


void Invader::DrawHeartEnemies() {
    	enemies.clear();

	x=310;y=125;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
		
	x=240;y=70;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=380;y=70;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=170;y=125;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=450;y=125;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=210;y=185;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=410;y=185;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=270;y=255;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=350;y=255;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=310;y=300;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	}//6



void Invader::DrawFilledHeartEnemies() {
    enemies.clear();

	x=310;y=125;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
		
	x=240;y=70;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=380;y=70;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=170;y=125;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=450;y=125;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=240;y=125;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=380;y=125;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=310;y=185;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
		
	x=260;y=185;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=360;y=185;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
		
	x=210;y=185;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=410;y=185;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=270;y=255;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=350;y=255;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=310;y=300;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	}//12

void Invader::DrawFilledCrossEnemies() {
    enemies.clear();
    
	x=310;y=175;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
		
	x=240;y=120;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=380;y=120;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=190;y=70;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=430;y=70;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=240;y=230;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=380;y=230;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=190;y=280;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=430;y=280;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	}//9
void Invader::DrawCircleEnemies()
{
	enemies.clear();

	x=340;y=100;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=290;y=120;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=390;y=120;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=240;y=160;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=440;y=160;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=240;y=215;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=440;y=215;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	
	x=290;y=265;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=390;y=265;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
	
	x=340;y=285;
	sprite.setPosition(x,y);
	enemies.push_back(Sprite(sprite));
}//4

