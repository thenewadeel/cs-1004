
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
using namespace sf;
#include "player.h"
#include "alpha.h"
#include "gamma.h"
#include "beta.h"
#include "addon.h"
const char title[] = "OOP-Project, Spring-2023";


class Game
{
public:
Sprite background; //Game background sprite
Texture bg_texture;
Sprite pbackground; //Pause background sprite
Texture pbg_texture;

Player* p; //player 
Alpha* en1;
Beta* en2;
Gamma* en3;
Monster* mon;
Dragon* drag;

int score = 0;
int level = 1;

// add other game attributes

void en1delete(int n, int &s)
{    Alpha *temp;
     temp = new Alpha[s];
     int j = 0;
     for(int i=0; i<s; i++)
     {   if (i!=n)
           temp[j++] = en1[i];
     }
     delete[] en1;
     en1 = new Alpha[--s];
     for(int i=0; i<s; i++)
     {    en1[i] = temp[i];
     }
     delete[] temp;
}
void en2delete(int n, int &s)
{    Beta *temp;
     temp = new Beta[s];
     int j = 0;
     for(int i=0; i<s; i++)
     {   if (i!=n)
           temp[j++] = en2[i];
     }
     delete[] en2;
     en2 = new Beta[--s];
     for(int i=0; i<s; i++)
     {    en2[i] = temp[i];
     }
     delete[] temp;
}
void en3delete(int n, int &s)
{    Gamma *temp;
     temp = new Gamma[s];
     int j = 0;
     for(int i=0; i<s; i++)
     {   if (i!=n)
           temp[j++] = en3[i];
     }
     delete[] en3;
     en3 = new Gamma[--s];
     for(int i=0; i<s; i++)
     {    en3[i] = temp[i];
     }
     delete[] temp;
}

void enemyformation(int shape, int temp1, int temp2, int temp3)
{
int c=0;

if (shape==4)
   shape--;
if (shape == 1)
{
int triangle[2][10] = { {820,690,630,740,730,1030,950,930,890,830} , {100,300,400,200,400,400,300,400,200,400} };
for(int i=0; i<temp1; i++)
{   en1[i].x = triangle[0][c];
    en1[i].y = triangle[1][c];
    en1[i].sprite.setPosition(en1[i].x,en1[i].y);
    c++;
} 
for(int i=0; i<temp2; i++)
{   en2[i].x = triangle[0][c];
    en2[i].y = triangle[1][c];
    en2[i].sprite.setPosition(en2[i].x,en2[i].y);
    c++;
}
for(int i=0; i<temp3; i++)
{   en3[i].x = triangle[0][c];
    en3[i].y = triangle[1][c];
    en3[i].sprite.setPosition(en3[i].x,en3[i].y);
    c++;
}

}
else if (shape == 2)
{
int diamond[2][10] = { {630,700,700,770,770,1010,940,940,870,870} , {300,180,420,90,530,300,180,420,90,530} };
for(int i=0; i<temp1; i++)
{   en1[i].x = diamond[0][c];
    en1[i].y = diamond[1][c];
    en1[i].sprite.setPosition(en1[i].x,en1[i].y);
    c++;
} 
for(int i=0; i<temp2; i++)
{   en2[i].x = diamond[0][c];
    en2[i].y = diamond[1][c];
    en2[i].sprite.setPosition(en2[i].x,en2[i].y);
    c++;
}
for(int i=0; i<temp3; i++)
{   en3[i].x = diamond[0][c];
    en3[i].y = diamond[1][c];
    en3[i].sprite.setPosition(en3[i].x,en3[i].y);
    c++;
}

}
else if (shape == 3)
{
int rectangle[2][10] = { {300,650,1000,1350,300,650,1000,1350,300,1350} , {50,50,50,50,450,450,450,450,250,250} };
for(int i=0; i<temp1; i++)
{   en1[i].x = rectangle[0][c];
    en1[i].y = rectangle[1][c];
    en1[i].sprite.setPosition(en1[i].x,en1[i].y);
    c++;
} 
for(int i=0; i<temp2; i++)
{   en2[i].x = rectangle[0][c];
    en2[i].y = rectangle[1][c];
    en2[i].sprite.setPosition(en2[i].x,en2[i].y);
    c++;
}
for(int i=0; i<temp3; i++)
{   en3[i].x = rectangle[0][c];
    en3[i].y = rectangle[1][c];
    en3[i].sprite.setPosition(en3[i].x,en3[i].y);
    c++;
}

}
else if (shape == 4)
{
int circle[2][10] = { {900,940,680,940,660,800,890,800,640,700} , {70,130,280,200,200,10,280,360,130,70} };
for(int i=0; i<temp1; i++)
{   en1[i].x = circle[0][c];
    en1[i].y = circle[1][c];
    en1[i].sprite.setPosition(en1[i].x,en1[i].y);
    c++;
} 
for(int i=0; i<temp2; i++)
{   en2[i].x = circle[0][c];
    en2[i].y = circle[1][c];
    en2[i].sprite.setPosition(en2[i].x,en2[i].y);
    c++;
}
for(int i=0; i<temp3; i++)
{   en3[i].x = circle[0][c];
    en3[i].y = circle[1][c];
    en3[i].sprite.setPosition(en3[i].x,en3[i].y);
    c++;
}
}


else if (shape == 5)
{
int circle[2][10] = { {1020,960,750,860,710,1010,910,610,740,610} , {10,100,200,200,300,400,300,400,100,10} };
for(int i=0; i<temp1; i++)
{   en1[i].x = circle[0][c];
    en1[i].y = circle[1][c];
    en1[i].sprite.setPosition(en1[i].x,en1[i].y);
    c++;
} 
for(int i=0; i<temp2; i++)
{   en2[i].x = circle[0][c];
    en2[i].y = circle[1][c];
    en2[i].sprite.setPosition(en2[i].x,en2[i].y);
    c++;
}
for(int i=0; i<temp3; i++)
{   en3[i].x = circle[0][c];
    en3[i].y = circle[1][c];
    en3[i].sprite.setPosition(en3[i].x,en3[i].y);
    c++;
}

}
}

int temp1 ,temp2,temp3, temp11,temp22,temp33,shape;
Game()
{srand(time(0));
p=new Player("img/player_ship.png");

bg_texture.loadFromFile("img/background1.jpg");
background.setTexture(bg_texture);
background.setScale(1.55, 1.25);

pbg_texture.loadFromFile("img/pause.png");
pbackground.setTexture(pbg_texture);
pbackground.setScale(0.75, 0.75);
pbackground.setPosition(450,220);
 temp1 = rand()%4+1;
 temp2 = rand()%4+1;
 temp3 = 10-temp1-temp2;
 temp11 = temp1;
 temp22 = temp2;
 temp33 = temp3;    
en1 = new Alpha[temp11];
en2 = new Beta[temp22];
en3 = new Gamma[temp33];
shape =rand()%5+1;
}


void start_game()
{RenderWindow window(VideoMode(2000, 1000), "Hasan's Space Shooter");
srand(time(0));

    drag = nullptr;
    mon = nullptr;
    bool pause = false;
    Clock clock;
    float timer=0;
    float timer2=0;
    float e1timer=1;
    float e2timer=1;
    float e3timer=1;        
    float montimer = 0;
    float montimer2 = 0;
    float dragtimer = 0;
    float dragtimer2 = 0;
    float lifetimer = 1;
    float dangertimer = 3;
    float firetimer = 5;
    float fireduration = 0;
    int bfire=0;
    int en1fire = 0;
    int en2fire = 0;
    int en3fire = 0;
    bool monst = false;
    bool dragst = false;
    bool newenemy = true;
    bool start = true;
    bool firepu = false;
    Life *LPU = nullptr;
    Danger *DNG = nullptr;
    Fire *FRE = nullptr;
    
    if ((int)timer % 30 == 0)
    {  level++;
       timer+=1;
    }
    
    int dbcheck = 0;	
    while (window.isOpen())
    {   bfire=0;
        float time = clock.getElapsedTime().asSeconds(); 
        clock.restart();
        timer += time;
        timer2 += time;  
        e1timer+=time;
        e2timer+=time;
        e3timer+=time;
        montimer+=time;
        dragtimer2+=time;
        lifetimer+=time;
        dangertimer+=time;
        firetimer+=time;
        
        
        if ( ((int)lifetimer)%8==0) 
        {  if (LPU!=nullptr)
               delete LPU;
           LPU = new Life;
           LPU->setpos(rand()%800+50);
           lifetimer+=1;
           
        }
        if ( ((int)dangertimer)%8==0) 
        {  if (DNG!=nullptr)
               delete DNG;
           DNG = new Danger;
           DNG->setpos(rand()%800+50);
           dangertimer+=1;
           
        }
        if ( ((int)firetimer)%8==0) 
        {  if (FRE!=nullptr)
               delete FRE;
           FRE = new Fire;
           FRE->setpos(rand()%800+50);
           firetimer+=1;
           
        }
        
        if (newenemy == true)
        {   if (start==false)
            {   delete[] en1;
                delete[] en2;
                delete[] en3;
            en1 = new Alpha[temp11];
            en2 = new Beta[temp22];
            en3 = new Gamma[temp33];
            shape = rand()%5 + 1;
            }
            start = false;
            temp1 = temp11;
            temp2 = temp22;
            temp3 = temp33;
            
            enemyformation(shape,temp1,temp2,temp3);
            newenemy = false;
        }
        
        
        if ( (monst == true))
        {  montimer2+=time;
        }
        int monarrive = rand()%10000;
        if ( (monarrive==1) && (dragst == false) && (mon == nullptr))
        {   monst = true;
            mon = new Monster;
            if (drag!=nullptr)
            {   delete drag;
                drag = nullptr;
            }
        }
        
        if ( (dragst == true))
        {  dragtimer+=time;
        }
        int dragarrive = rand()%10000;
        if ( (dragarrive==1) && (monst == false) && (drag == nullptr) )
        {   dragst = true;
            drag = new Dragon;
            if (mon!=nullptr)
            {   delete mon;
                mon = nullptr;
            }
        }
 	Event e;
        while (window.pollEvent(e))
        {  
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
            { window.close();
       
           }                     	    
        }
        
        if (Keyboard::isKeyPressed(Keyboard::P)) //If left key is pressed
        {    pause = true;
        }
       /* if (pause==true)
        {
        RenderWindow pwindow(VideoMode(2000, 1000), "Hasan's Space Shooter");
             while (pwindow.isOpen())
             {     if (e.type == Event::Closed) // If cross/close is clicked/pressed
                        pwindow.close();
             
                   pwindow.draw(pbackground);
                   pwindow.display();
                   if (Keyboard::isKeyPressed(Keyboard::Q)) //If left key is pressed
                   {   pwindow.close(); 
                       window.close();
                   }
                   if ( (pause==true) && (Keyboard::isKeyPressed(Keyboard::R)) ) //If left key is pressed
                   {   pwindow.close(); 
                       pause = false;
                   }
             }
             
        }*/
        if ( (pause==true) && (Keyboard::isKeyPressed(Keyboard::R)) ) //If left key is pressed
        {     pause = false;

        }
        if ( (pause==true) && (Keyboard::isKeyPressed(Keyboard::Q)) ) //If left key is pressed
        {     window.close();
        }
        if ( (pause==true) && (Keyboard::isKeyPressed(Keyboard::M)) ) //If left key is pressed
        {     window.close();
              bg_texture.loadFromFile("img/menu_bg.png");
              background.setTexture(bg_texture);
              background.setScale(1, 1.1);
              RenderWindow window(VideoMode(640, 850), "Hasan's Space Shooter");
         
              while (window.isOpen())
              {
                    Event e;
                    while (window.pollEvent(e))
                    {  
                         if (e.type == Event::Closed) // If cross/close is clicked/pressed
                               window.close(); //close the game                        	    
                    }
         
                    window.clear();
                    window.draw(background);
         
                    window.display();
                    if (Keyboard::isKeyPressed(Keyboard::Enter)) //If left key is pressed
                    {    window.close();
                         Game g; 
                         g.start_game();
                    } 
                    if (Keyboard::isKeyPressed(Keyboard::I)) //If left key is pressed
                    {    bg_texture.loadFromFile("img/instructions_bg.png");
                         background.setTexture(bg_texture);
                         background.setScale(1.1, 1.1);
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Q)) //If left key is pressed
                    {    window.close();
                    }
                    if (Keyboard::isKeyPressed(Keyboard::M))
                    {   bg_texture.loadFromFile("img/menu_bg.png");
                        background.setTexture(bg_texture);
                        background.setScale(1, 1.1);
                    }
                    if (Keyboard::isKeyPressed(Keyboard::H))
                    {   bg_texture.loadFromFile("img/highscores_bg.png");
                        background.setTexture(bg_texture);
                        background.setScale(1, 1.1);
                    }
         
         }
        }
        if(pause==false)
        {
	if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
        {    p->move("l");    // Player will move to left
	     p->tex.loadFromFile("img/player_ship.png");
	}	
	if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
        {   p->move("r");  //player will move to right
            p->tex.loadFromFile("img/player_ship.png");
        }
	if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
        {    p->move("u");    //playet will move upwards
	     p->tex.loadFromFile("img/player_ship.png");
	}
	if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
        {    p->move("d");  //player will move downwards
             p->tex.loadFromFile("img/player_ship.png");
        }
        if ( (Keyboard::isKeyPressed(Keyboard::Up)) && (Keyboard::isKeyPressed(Keyboard::Left)) )
        {    p->tex.loadFromFile("img/player_ship_diagonalUL.png"); 
	}
	if ( (Keyboard::isKeyPressed(Keyboard::Up)) && (Keyboard::isKeyPressed(Keyboard::Right)) )
        {    p->tex.loadFromFile("img/player_ship_diagonalUR.png"); 
	}
	if ( (Keyboard::isKeyPressed(Keyboard::Down)) && (Keyboard::isKeyPressed(Keyboard::Right)) )
        {    p->tex.loadFromFile("img/player_ship_diagonalUL.png"); 
	}
	if ( (Keyboard::isKeyPressed(Keyboard::Down)) && (Keyboard::isKeyPressed(Keyboard::Left)) )
        {    p->tex.loadFromFile("img/player_ship_diagonalUR.png"); 
	}
	if (Keyboard::isKeyPressed(Keyboard::Q)) //If left key is pressed
        {    window.close();
        }
        if ( (monst == false) && (dragst == false)/* && (newenemy == true)*/)
        {
	if((int)e1timer%4==0)
        {   en1fire = 1;
        }
        if (en1fire==1)
        {   for(int i=0; i<temp1; i++)
            {  en1[i].fire();
            }
            en1fire = 0;
        }
        if((int)e2timer%5==0)
        {   en2fire = 1;
        }
        if (en2fire==1)
        {   for(int i=0; i<temp2; i++)
            {  en2[i].fire();
            }
            en2fire = 0;
        }
        if((int)e3timer%7==0)
        {   en3fire = 1;
        }
        if (en3fire==1)
        {   for(int i=0; i<temp3; i++)
            {  en3[i].fire();
            }
            en3fire = 0;
        }
        }
        if (Keyboard::isKeyPressed(Keyboard::Space)) // If down key is pressed
        {   bfire=1;
        }
        
        if (bfire==1)
        {   p->fire(1);
            bfire=0;
        }
        if(bfire==2)
        {   p->fire(2);
            p->bul->tex.loadFromFile("img/PNG/Lasers/laserBlue01UL.png");
            bfire=0;
        }
      
      
	}
	////////////////////////////////////////////////
	/////  Call your functions here            ////
	//////////////////////////////////////////////

	window.clear(Color::Black); //clears the screen
	window.draw(background);  // setting background
	window.draw(p->sprite);   // setting player on screen
	
	if ( (monst == true) && (dragst == false) && (mon!=nullptr))
	{
	window.draw(mon->sprite);
	mon->move();
	if ( ((int)montimer % 5) < 3) 
	{   mon->fire();
	    window.draw(mon->beam->sprite);
        }
        else
        {   mon->beam->move();
        }
        }
        
        if ( (dragst == true) && (monst == false) && (drag!=nullptr))
	{
	window.draw(drag->sprite);
	drag->move();
	if ( ((int)dragtimer2) % 2 ==0)
	{  dbcheck = 1;
	}
	if (dbcheck)
	{   drag->fire();
	    dragtimer2 += 1;
	}
	if ( (drag->Dbul != nullptr))
	{   window.draw(drag->Dbul->sprite);
	    drag->Dbul->move(p->x2);
	    
	}
	}
        if ( (monst == false) && (dragst == false)/* && (newenemy == true)*/)
        {
        for(int i=0; i<temp1; i++)
        {   if (en1[i].alive == true)
             window.draw(en1[i].sprite);
        }  
        for(int i=0; i<temp2; i++)
        {   if (en2[i].alive == true)
            window.draw(en2[i].sprite);
        }
        for(int i=0; i<temp3; i++)
        {   if (en3[i].alive == true)
            window.draw(en3[i].sprite);
        }
	
	for(int i=0; i<temp1; i++)
        {  if (en1[i].alive == true)
           {
           if ( (en1[i].bombnum!=0) && (en1[i].scored==false) )
           {  window.draw(en1[i].bomb[0].sprite);
              en1[i].bomb[0].move();
           }
           }
        }
        
	for(int i=0; i<temp2; i++)
        {  if (en2[i].alive == true)
           {
           if ( (en2[i].bombnum!=0) && (en2[i].scored==false) )
           {  window.draw(en2[i].bomb[0].sprite);
              en2[i].bomb[0].move();
           }
           }
        }
        for(int i=0; i<temp3; i++)
        {  if (en3[i].alive == true)
           {
           if ( (en3[i].bombnum!=0) && (en3[i].scored==false) )
           {  window.draw(en3[i].bomb[0].sprite);
              en3[i].bomb[0].move();
           }
           }
        }
        }
        bool enemycheck = true;
        for(int i=0; i<temp1; i++)
        {   if (en1[i].alive == true)
                enemycheck = false;
        }  
        for(int i=0; i<temp2; i++)
        {   if (en2[i].alive == true)
                enemycheck = false;
        }
        for(int i=0; i<temp3; i++)
        {   if (en3[i].alive == true)
                enemycheck = false;
        }
        if (enemycheck == true)
        {   newenemy = true;
            for(int i=0; i<temp1; i++)
            {    en1[i].alive = true;
            }  
            for(int i=0; i<temp2; i++)
            {    en2[i].alive = true;
            }
            for(int i=0; i<temp3; i++)
            {    en3[i].alive = true;
            }
        }
        if(p->bul!=nullptr)
        {  for (int i=0;i<p->bulnum;i++)
           {window.draw(p->bul[i].sprite);
            p->bul[i].move();
             
           }
        }
        bool col = false;
        bool col2 = false;
        bool col3 = false;
        if ( (monst == false) && (dragst == false) ) 
        {
        for(int i=0; i<temp1; i++)
        {   for (int j=0;j<p->bulnum;j++)
            {    //if (en1[i].scored == false)
                 {
                 col = en1[i].checkcollision(p->bul[j].x,p->bul[j].y);
                 if (col)
                 {    if (firepu == false)
                      p->deletebul(j);
                      if (en1[i].scored == false)
                          score += (10*level);
                      en1[i].scored = true;
                 }
                 col = false;
                 }
            }
        }
        for(int i=0; i<temp2; i++)
        {   for (int j=0;j<p->bulnum;j++)
            {    //if (en2[i].scored == false)
                 {
                 col2 = en2[i].checkcollision(p->bul[j].x,p->bul[j].y);
                 if (col2)
                 {    if (firepu == false)
                      p->deletebul(j);
                      if (en2[i].scored == false)
                          score += (20*level);
                      en2[i].scored = true;
                 }
                 col2 = false;
                 }
            }
        }
        for(int i=0; i<temp3; i++)
        {   for (int j=0;j<p->bulnum;j++)
            {    //if (en3[i].scored == false)
                 {
                 col3 = en3[i].checkcollision(p->bul[j].x,p->bul[j].y);
                 if (col3)
                 {    if (firepu == false)
                      p->deletebul(j);
                      if (en3[i].scored == false)
                          score += (30*level);
                      en3[i].scored = true;
                 }
                 col3 = false;
                 }
            }
        }
        }
        if (montimer2 > 10)
        {   if (monst==true)
            {   montimer2 = 0;
                monst = false;
                delete mon;
                mon = nullptr;
                score+=40;
            }
            

        }
        if (dragtimer > 10)
        {   if (dragst==true)
            {   dragtimer = 0;
                dragst = false;
                delete drag;
                drag = nullptr;
                score+=40;
            }
        }
        
        bool hit = false;
        for(int i=0; i<temp1; i++)
        {   if ( (en1[i].bomb!=nullptr) && (en1[i].bomb->hitdone == false) )
            {   hit = p->playerbombcollision(en1[i].bomb->x,en1[i].bomb->y);
                if (hit)
                {  // delete en1[i].bomb;
                    hit = false;
                    en1[i].bomb->hitdone = true;
                }
            }
        }  
        for(int i=0; i<temp2; i++)
        {   if ( (en2[i].bomb!=nullptr) && (en2[i].bomb->hitdone == false) )
            {   hit = p->playerbombcollision(en2[i].bomb->x,en2[i].bomb->y);
                if (hit)
                {  // delete en2[i].bomb;
                    hit = false;
                    en2[i].bomb->hitdone = true;
                }
            }
        }
        for(int i=0; i<temp3; i++)
        {   if ( (en3[i].bomb!=nullptr) && (en3[i].bomb->hitdone == false) ) 
            {   hit = p->playerbombcollision(en3[i].bomb->x,en3[i].bomb->y);
                if (hit)
                {  // delete en3[i].bomb;
                    hit = false;
                    en3[i].bomb->hitdone = true;
                }
            }
        }
        
        if ( (drag!=nullptr) && (drag->Dbul!=nullptr) && (drag->Dbul->hitdone==false)) 
        {   hit = p->playerdragoncollision(drag->Dbul->x2,drag->Dbul->y2);
            if (hit)
            {  hit = false;
               drag->Dbul->hitdone = true;
            }
        }
        if ( (mon!=nullptr) && (mon->beam!=nullptr) && (mon->beam->hitdone==false)) 
        {   hit = p->playermonstercollision(mon->beam->x2,mon->beam->y2);
            if (hit)
            {  hit = false;
               mon->beam->hitdone = true;
            }
        }
        
        if ( (LPU != nullptr) && (LPU->used == false) )
        {   hit = p->playeraddoncollision(LPU->x2,LPU->y2);
            if (hit)
            {  p->lives++;
               hit = false;
               LPU->used = true;
            }
        }
        if ( (DNG != nullptr) && (DNG->used == false) )
        {   hit = p->playeraddoncollision(DNG->x2,DNG->y2);
            if (hit)
            {  p->lives--;
               hit = false;
               DNG->used = true;
            }
        }
        if ( (FRE != nullptr) && (FRE->used == false) )
        {   hit = p->playeraddoncollision(FRE->x2,FRE->y2);
            if (hit)
            {  hit = false;
               FRE->used = true;
               firepu = true;
            }
        }
     /*   if (dragst == true)
        {  drag->fire();
           
        }*/
        
        if(pause==true)
        {    window.draw(pbackground);
             window.display();
        }
        sf::Font scorefont;                                           //Declaring the downloaded font as font for display
        scorefont.loadFromFile("scorefont.ttf");
     
        sf::Text scoreheading;                                        //Deciding the details for displaying the text score
        scoreheading.setFont(scorefont);
        scoreheading.setString("SCORE: ");
        scoreheading.setPosition({1600,10});
        window.draw(scoreheading);
        
        sf::Text scorenum(std::to_string(score), scorefont);          //Details for displaying the actual score value
        scorenum.setPosition({1720,10});
        window.draw(scorenum);
        
        sf::Text levelheading;                                        //Deciding the details for displaying the text score
        levelheading.setFont(scorefont);
        levelheading.setString("LEVEL: ");
        levelheading.setPosition({1600,140});
        window.draw(levelheading);
        
        sf::Text levelnum(std::to_string(level), scorefont);          //Details for displaying the actual score value
        levelnum.setPosition({1690,140});
        window.draw(levelnum);
        
        sf::Text livesheading;                                        //Deciding the details for displaying the text score
        livesheading.setFont(scorefont);
        livesheading.setString("Lives: ");
        livesheading.setPosition({1600,80});
        window.draw(livesheading);
        
        sf::Text livesnum(std::to_string(p->lives), scorefont);          //Details for displaying the actual score value
        livesnum.setPosition({1690,80});
        window.draw(livesnum);
        if ( (LPU!=nullptr) && (LPU->used == false) )
        {
           window.draw(LPU->sprite);
           LPU->move();
        }
        if ( (DNG!=nullptr) && (DNG->used == false) )
        {
           window.draw(DNG->sprite);
           DNG->move();
        }
        if ( (FRE!=nullptr) && (FRE->used == false) )
        {
           window.draw(FRE->sprite);
           FRE->move();
        }
        if ( (FRE!=nullptr) )
        {   if (firepu == true) 
            {  fireduration += time;
            }
        }
        if (fireduration>5)
        {  fireduration = 0;
           FRE->used = false;
           firepu = false;
        }
     //   if (timer2/20 > level)
     //       level++;
        if (p->lives <= 0)
        {    window.close();
        }
	window.display();  //Displying all the sprites

    }
        

}


};

