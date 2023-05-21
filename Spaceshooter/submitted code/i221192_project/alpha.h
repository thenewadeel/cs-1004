#include <SFML/Graphics.hpp>
#include<string.h>
#include"invaders.h"
using namespace sf;
class Alpha : public Invaders
{
public:

Alpha(std:: string png_path = "img/enemy_1.png")
{

tex.loadFromFile(png_path);
sprite.setTexture(tex);
sprite.setScale(0.75,0.75);

}

bool checkcollision(int bx, int by)
{    if ( ( (bx>=x-50 && bx<=(x+93-50) ) && (by>=y && by<=(y+79.5) ) ) || ( (bx+6.75>=x-50 && bx+6.75<=(x+93-50) ) && (by+40.5>=y && by+40.5<=(y+79.5) ) ) )
     {    alive = false;
          return true;
     } 
     return false;
}

};
