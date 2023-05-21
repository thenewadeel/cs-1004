#include <SFML/Graphics.hpp>
#include<string.h>
#include"bomb.h"
using namespace sf;
class Enemy{
public:



Enemy(/*std:: string png_path = "img/enemy_1.png"*/)
{


}
virtual void fire() = 0;


};

class Monster : public Enemy
{
public:
Texture tex;
Sprite sprite;

bool scored = false;
float speed=0.5;
int x=50,y=50;
int x2=50, y2=50;
char direction = 'r';
Beam *beam = nullptr;
int beamnum = 0;
Monster(std:: string png_path = "img/monster.png")
{

tex.loadFromFile(png_path);
sprite.setTexture(tex);
sprite.setScale(0.25,0.25);

}
void move(){
float delta_x=0,delta_y=0;



if (direction == 'r')
delta_x=1;
if (direction == 'l')
delta_x = -1;
x2 += delta_x;
y2 += delta_y;

if (x2<0)
direction = 'r';
if (x2>3000)
direction = 'l';
delta_x*=speed;
delta_y*=speed;

sprite.move(delta_x, delta_y);
x+=delta_x;
y+=delta_y;

}

void fire()
{    
     if (beamnum==0)
     {  beam = new Beam[1];
        beamnum=1;
        beam[0].setpos(x2,y2);
     }
    /* else
     {  delete[] beam;
        beam = new Beam[1];
        beam[0].setpos(x,y);
     }*/
     beam[0].move();
}


};

class Dragon : public Enemy
{
public:
Texture tex;
Sprite sprite;

bool scored = false;
float speed=0.5;
int x=50,y=50;
int x2=50, y2=50;
char direction = 'r';
DBullet *Dbul = nullptr;
int Dbulnum = 0;
Dragon(std:: string png_path = "img/dragon.png")
{

tex.loadFromFile(png_path);
sprite.setTexture(tex);
sprite.setScale(1.75,1.75);
sprite.setPosition(700,20);

}
void move(){

}

void fire()
{    
    if (Dbulnum==0)
     {  Dbul = new DBullet[1];
        Dbulnum=1;
        Dbul[0].setpos(x2+800,y2+300);
     }
    /* else
     {  delete[] beam;
        beam = new Beam[1];
        beam[0].setpos(x,y);
     }*/
    // Dbul[0].move();

}


};




