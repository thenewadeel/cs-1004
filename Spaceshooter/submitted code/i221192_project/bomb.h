#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
class Bomb{
public:
Texture tex;
Sprite sprite;
float speed=1;
int x,y;
double x2,y2;
bool hitdone = false;
Bomb( double a = 340, double b=200)
{
tex.loadFromFile("img/enemy_laser.png");
sprite.setTexture(tex);
sprite.setScale(1.5,1.5);
}

void setpos(float a,float b)
{
    x=x2=a;y=y2=b;
  sprite.setPosition(x+25,y+50);
}
void move(){
float delta_x=0,delta_y=0;

delta_y=1;

delta_x*=speed;
delta_y*=speed;

sprite.move(delta_x, delta_y);
x+=delta_x;
y+=delta_y;

}

Bomb operator=(Bomb& abc)
{    this->x = abc.x;
     this->y = abc.y;
     setpos(x,y);
     return *this;
}
};

class Beam{
public:
Texture tex;
Sprite sprite;
float speed=0.5;
int x,y;
double x2,y2;
char direction = 'r';
bool hitdone = false;
Beam( double a = 340, double b=200)
{
tex.loadFromFile("img/PNG/Lasers/laserRed02.png");
sprite.setTexture(tex);
sprite.setScale(5,25);
}

void setpos(float a,float b)
{
    x=x2=a;y=y2=b;
    sprite.setPosition(x2+85,y2+100);
}
void move(){
float delta_x=0,delta_y=0;

delta_x=1;
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


};

class DBullet{
public:
Texture tex;
Sprite sprite;
float speed=0.5;
int x,y;
double x2,y2;
bool hitdone = false;
DBullet( double a = 340, double b=200)
{
tex.loadFromFile("img/PNG/Lasers/laserRed10.png");
sprite.setTexture(tex);
sprite.setScale(1.5,1.5);
}

void setpos(float a,float b)
{
    x=x2=a;y=y2=b;
  sprite.setPosition(x+25,y+50);
}
void move(double n){
float delta_x=0,delta_y=0;

delta_y=1;
delta_x = 0;
if(n<x2)
delta_x=-1;
if(n>x2)
delta_x=1;
delta_x*=speed;
delta_y*=speed;

sprite.move(delta_x, delta_y);
x2+=delta_x;
y2+=delta_y;

}
void move2(){
float delta_x=0,delta_y=0;

delta_y=1;
delta_x=1;

delta_x*=speed;
delta_y*=speed;

sprite.move(delta_x, delta_y);
x+=delta_x;
y+=delta_y;

}
void move3(){
float delta_x=0,delta_y=0;

delta_y=1;
delta_x=-1;

delta_x*=speed;
delta_y*=speed;

sprite.move(delta_x, delta_y);
x+=delta_x;
y+=delta_y;

}
DBullet operator=(DBullet& abc)
{    this->x = abc.x;
     this->y = abc.y;
     setpos(x,y);
     return *this;
}
};

