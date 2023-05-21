#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Addon
{
public:
Texture tex;
Sprite sprite;

float speed=1.5;
int x,y = 0;
int x2, y2;      
bool used = false;

void setpos(float a)
{
    x=x2=a;y=y2=0;
    sprite.setPosition(x+25,y+50);
}
virtual void move(){
float delta_x=0,delta_y=0;

delta_y=1;

delta_x*=speed;
delta_y*=speed;

sprite.move(delta_x, delta_y);
x2+=delta_x;
y2+=delta_y;

}
};

class Life : public Addon
{
public:
Life()
{
tex.loadFromFile("img/PNG/Power-ups/powerupBlue_shield.png");
sprite.setTexture(tex);
sprite.setScale(1,1);

}

};

class Danger : public Addon
{
public:
Danger()
{
tex.loadFromFile("img/PNG/Power-ups/powerupRed.png");
sprite.setTexture(tex);
sprite.setScale(1,1);
}
};

class Fire : public Addon
{
public:
Fire()
{
tex.loadFromFile("img/PNG/Power-ups/powerupBlue_bolt.png");
sprite.setTexture(tex);
sprite.setScale(1,1);

}
};
