#include <SFML/Graphics.hpp>
#include<string.h>
#include"enemy.h"

using namespace sf;
class Invaders : public Enemy
{
public:
Texture tex;
Sprite sprite;
bool scored = false;
float speed=5;
int x,y;
int x2, y2;
bool alive = true;
Bomb* bomb=nullptr;
int bombnum=0;
Invaders(/*std:: string png_path = "img/enemy_1.png"*/)
{
/*
tex.loadFromFile(png_path);
sprite.setTexture(tex);
sprite.setScale(0.75,0.75);
*/
}
void fire()
{    if (bombnum==0)
     {  bomb = new Bomb[1];
        bombnum=1;
        bomb[0].setpos(x,y);
     }
     else
     {  delete[] bomb;
        bomb = new Bomb[1];
        bomb[0].setpos(x,y);
     }
     bomb[0].move();
        
}



};
