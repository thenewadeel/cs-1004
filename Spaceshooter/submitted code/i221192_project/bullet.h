#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
class Bullet{
public:
Texture tex;
Sprite sprite;
float speed=2;
int x,y;
double x2,y2;
Bullet( double a = 340, double b=200)
{
tex.loadFromFile("img/PNG/Lasers/laserBlue01.png");
sprite.setTexture(tex);
sprite.setScale(0.75,0.75);
}

void setpos(float a,float b)
{
    x=x2=a;y=y2=b;
  sprite.setPosition(x+50,y);
}
void move(){
float delta_x=0,delta_y=0;

delta_y=-1;
delta_y*=speed;

sprite.move(delta_x, delta_y);
x+=delta_x;
y+=delta_y;
}



Bullet operator=(Bullet& abc)
{    this->x = abc.x;
     this->y = abc.y;
     setpos(x,y);
     return *this;
}

};

