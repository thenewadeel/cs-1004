#include <SFML/Graphics.hpp>
#include<string.h>

using namespace sf;
class Gamma : public Invaders
{
public:

Gamma(std:: string png_path = "img/enemy_3.png")
{

tex.loadFromFile(png_path);
sprite.setTexture(tex);
sprite.setScale(0.5,0.5);

}
bool checkcollision(int bx, int by)
{    if ( ( (bx>=x-50 && bx<=(x+86.5-50) ) && (by>=y && by<=(y+66) ) ) || ( (bx+6.75>=x-50 && bx+6.75<=(x+86.5-50) ) && (by+40.5>=y && by+40.5<=(y+66) ) ) )
     {    alive = false;
          return true;
     } 
     return false;
}

};
