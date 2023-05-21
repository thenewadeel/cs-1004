#include <SFML/Graphics.hpp>
#include<string.h>
#include"bullet.h"
using namespace sf;
class Player{
public:
Texture tex;
Sprite sprite;

Bullet *bul;
int bulnum;
float speed=2;
int x,y;
double x2, y2;
int lives = 3;
Player(std::string png_path)
{
bul = nullptr;
bulnum = 0;
tex.loadFromFile(png_path);
sprite.setTexture(tex);
x=x2=850;y=y2=900;
sprite.setPosition(x,y);
sprite.setScale(1,1);

}
void fire(int num = 1)
{
    if(bulnum==0)
    {  bul = new Bullet[++bulnum];
       bul[0].setpos(x2,y2);
    }
    else
    {  Bullet temparr[bulnum];
       for(int i=0; i<bulnum; i++)
       {   temparr[i] = bul[i];
       }
       delete[] bul;
       bul = new Bullet[bulnum+1];
       for(int i=0; i<bulnum; i++)
       {   bul[i] = temparr[i];
       }

       bul[bulnum++].setpos(x2,y2);
    }
    bul[bulnum-1].move();
   
}

void deletebul(int &n)
{    Bullet temparr[bulnum-1];
     int j=0;
     for(int i = 0; i<bulnum; i++)
     {  if (i!=n)
           temparr[j++] = bul[i];
     }
     delete[] bul;
     bul = new Bullet[--bulnum];
     for(int i = 0; i<bulnum; i++)
     {  temparr[i] = bul[i];
     }
}
void move(std::string s)
{
float delta_x=0,delta_y=0;
if(s=="l")
	delta_x=-1;
else if(s=="r")
	delta_x=1;
if(s=="u")
	delta_y=-1;
else if(s=="d")
	delta_y=1;

delta_x*=speed;
delta_y*=speed;

x2 += delta_x;
y2 += delta_y;

if (x2<-20)
{   x2 = 1990;
    sprite.setPosition(x2,y2);
}
else if (x2>1990)
{   x2 = 0;
    sprite.setPosition(x2,y2);
}
else if (y2<0)
{   y2 = 1000;
    sprite.setPosition(x2,y2);
}
else if (y2>1000)
{   y2 = 0;
    sprite.setPosition(x2,y2);
}

sprite.move(delta_x, delta_y);
}

bool playerbombcollision(int bx, int by)
{    if ( (bx>=(x2-50) && bx<=(x2+50)) && (by>=(y2-50) && by<=(y2)) )
     {    lives--;
          x2=80,y2=900;
          sprite.setPosition(80,900);
          return true;
     }    
     return false;
 
}

bool playerdragoncollision(int bx, int by)
{    if ( (bx>=(x2-50) && bx<=(x2+50)) && (by>=(y2-50) && by<=(y2)) )
     {    lives--;
          x2=80,y2=900;
          sprite.setPosition(80,900);
          return true;
     }    
     return false;

}
bool playermonstercollision(int bx, int by)
{    if ( ((bx-500)>=(x2)) && ((bx+500)<=x2))
     {    lives--;
          x2=80,y2=900;
          sprite.setPosition(80,900);
          return true;
     }    
     return false;

}

bool playeraddoncollision(int bx, int by)
{    if ( (bx>=(x2-50) && bx<=(x2+50)) && (by>=(y2-200) && by<=(y2)) )
     {    
          return true;
     }    
     return false;


}
};
