
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
#include "player.h"
#include "menu.h"
const char title[] = "MineShooter OOP-Project i22-1077";
using namespace sf;

class Game
{
public:
    Sprite background, lays, next, trs; // Game background sprite
    Texture bg_texture, layer;
    Texture dr, ms, ai, bi, gi;
    Texture trd, trm, trai, trbi, trgi;
    Texture lf2, lf3;
    Sprite lfire;
    Player *p; // player
    Enemy *en;
    Menu m;
    bool bullettime, lifehit, lifeon, transition;
    float bt;
    Font minecraft;
    Text Level, Timey, lifey, timey2, scorey;
    int Lev, score, modes, lives, hitting, modes1, sc1;
    // add other game attributes

    Game()
    {
        p = new Player("img/player_ship.png");
        bg_texture.loadFromFile("img/background.jpg");
        layer.loadFromFile("img/sale.png");
        lays.setTexture(layer);
        dr.loadFromFile("img/dragon1.png");
        ms.loadFromFile("img/mnster.png");
        ai.loadFromFile("img/enemy_1.png");
        bi.loadFromFile("img/enemy_2.png");
        gi.loadFromFile("img/enemy_3.png");

        trd.loadFromFile("img/trd.png");
        trm.loadFromFile("img/trm.png");
        trai.loadFromFile("img/trai.png");
        trbi.loadFromFile("img/trbi.png");
        trgi.loadFromFile("img/trgi.png");

        lf2.loadFromFile("img/lf2.png");
        lf3.loadFromFile("img/lf3.png");
        background.setTexture(bg_texture);
        background.setScale(2, 1.5);
        bullettime = true;
        bt = 0.0;
        modes = 0;
        en = new InAlpha;
        Lev = 0;
        transition = 0;
        score = 0;
        sc1 = 0;
        lives = 9;
        hitting = lives;
        lifehit = 0;
        lifeon = 0;
        minecraft.loadFromFile("fonts/Minecraft.ttf");
        Level.setFont(minecraft);
        Level.setCharacterSize(28);
        Level.setPosition(630, 35);
        Level.setFillColor(Color::Black);

        lifey.setFont(minecraft);
        lifey.setCharacterSize(28);
        lifey.setPosition(720, 80);
        lifey.setFillColor(Color::Black);

        timey2.setFont(minecraft);
        timey2.setCharacterSize(28);
        timey2.setPosition(615, 113);
        timey2.setFillColor(Color::Black);

        Timey.setFont(minecraft);
        Timey.setCharacterSize(17);
        Timey.setPosition(700, 155);
        Timey.setFillColor(Color::White);

        scorey.setFont(minecraft);
        scorey.setCharacterSize(28);
        scorey.setPosition(690, 35);
        scorey.setFillColor(Color::White);

        modes1 = 0;
        trs.setPosition(-790, 0);
    }
    void enemy_hit(int k, bool a)
    {
        for (int i = 0; i < en->num_e; i++)
        {
            for (int j = 0; j < p->BUL->num_b; j++)
            {
                //
                // cout<<"enemy y: "<<en->givey(i)<<" bullet y: "<<p->BUL->givey(j)<<endl;
                if (((p->BUL->givex(j) >= en->givex(i) - 0) && (p->BUL->givex(j) <= en->givex(i) + 80)) && ((p->BUL->givey(j) <= en->givey(i) + 30) && (p->BUL->givey(j) >= en->givey(i) + 0)))
                {
                    int x = en->givex(i) + 5;
                    int y = en->givey(i);
                    if (!(k == 1 && a == 1))
                    {
                        p->BUL->removebuls(j);
                    }

                    en->removeenemy(i);
                    if (!(en->type == 12 || en->type == 13))
                    {
                        en->exp->addexp(x, y);
                    }
                    if (en->type < 3)
                    {
                        score += 10 * (Lev + 1);
                    }
                    else if (en->type < 6)
                    {
                        score += 20 * (Lev + 1);
                    }
                    else if (en->type < 12)
                    {
                        score += 30 * (Lev + 1);
                    }
                }
            }
        }
    }
    void player_hit(int k, bool a, bool lh)
    {
        for (int i = 0; i < en->BM->num_b; i++)
        {
            if (((en->BM->bx[i] >= p->sprite.getPosition().x) && (en->BM->bx[i] <= p->sprite.getPosition().x + 60)) && ((en->BM->by[i] <= p->sprite.getPosition().y + 30) && (en->BM->by[i] >= p->sprite.getPosition().y)))
            {

                int x = p->sprite.getPosition().x + 7;
                int y = p->sprite.getPosition().y + 13;

                if (!(k == 0 && a == 1) && lh == 0)
                {
                    en->BM->removebomb(i);
                    lives = lives - 1;
                    en->exp->addexp(x, y);
                }
            }
        }
        for (int i = 0; i < en->num_e; i++)
        {
            if (((p->sprite.getPosition().x >= en->ex[i] && p->sprite.getPosition().x < en->ex[i] + 60) || (p->sprite.getPosition().x + 60 >= en->ex[i] && p->sprite.getPosition().x + 60 < en->ex[i] + 60)) && ((p->sprite.getPosition().y + 60 >= en->ey[i] && p->sprite.getPosition().y + 60 < en->ey[i] + 80) || (p->sprite.getPosition().y >= en->ey[i] && p->sprite.getPosition().y < en->ey[i] + 80)))
            {
                int x1 = en->givex(i) + 5;
                int y1 = en->givey(i);
                en->exp->addexp(x1, y1);
                en->removeenemy(i);
                int x = p->sprite.getPosition().x + 7;
                int y = p->sprite.getPosition().y + 13;

                if (!(k == 0 && a == 1) && lh == 0)
                {
                    lives = lives - 1;
                    en->exp->addexp(x, y);
                }
            }
        }
    }
    int start_game()
    {
        
        srand(time(0));
        RenderWindow window(VideoMode(780, 780), title);
        Clock clock, delay, animation1, m1, m2, invadershoot, spdelay;
        Clock game_timeline, addion, add_del, invinci, invincis;
        int mode = 0, start = 0;
        float timer = 0, shootsp = 5;
        bool anim1 = false, mshoot = 0;
        m.display_name(window);
        bool Fschange = 0,firststart=1;
        float fsch = 0.0;
        float ssp, busp, psp, bsp, esp, asp;
        m.getfiles();
        while (window.isOpen())
        {

            if (score >= 800 && Lev == 0)
            {
                Lev++;
            }
            else if (score > 3000 && Lev == 1)
            {
                Lev++;
            }

            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
            Level.setString(to_string(Lev + 1));
            string minute, seconds;
            if (int(timer) / 60 < 10)
            {
                minute = "0";
            }
            if ((int(timer) % 60) < 10)
            {
                seconds = "0";
            }
            minute = minute + to_string(int(timer) / 60);
            seconds = seconds + to_string(int(timer) % 60);
            Timey.setString(minute + ":" + seconds);
            string scoreys = "";
            if (score < 10)
            {
                scoreys += "000";
            }
            else if (score < 100)
            {
                scoreys += "00";
            }
            else if (score < 1000)
            {
                scoreys += "0";
            }
            scoreys += to_string(score);
            scorey.setString(scoreys);

            lifey.setString(to_string(lives));
            float modetime;
            if (mode < 2)
            {
                modetime = 10;
            }
            else
            {
                modetime = 7.2;
            }
            float tt = modetime - game_timeline.getElapsedTime().asSeconds();
            round(tt);
            string tts = "";
            if (tt < 0)
            {
                tts += "+";
                tt *= -1;
                timey2.setPosition(605, 113);
            }
            else
            {
                timey2.setPosition(615, 113);
            }
            tts += to_string(int(tt) / 10) + to_string(int(tt) % 10);

            tts += "." + to_string(int((tt - int(tt)) * 10));

            timey2.setString(tts);
            if ((game_timeline.getElapsedTime().asSeconds() <= 2 || firststart==1) && start == 0)
            {
                firststart=0;
                modes = modes1;
                modes1 = rand() % 4;
                if (modes < 2)
                {
                    mode = 0;
                    if (Lev == 0)
                    {
                        en = new InAlpha;
                        en->type = rand() % 3;
                        shootsp = 5;
                        trs.setTexture(trai);
                    }
                    else if (Lev == 1)
                    {
                        en = new InBeta;
                        en->type = rand() % 3 + 3;
                        shootsp = 3;
                        trs.setTexture(trbi);
                    }
                    else
                    {
                        en = new InGamma;
                        en->type = rand() % 6 + 6;
                        shootsp = 2;
                        trs.setTexture(trgi);
                    }
                }
                else if (modes == 2)
                {
                    mode = 1;
                    en = new Monster;
                    trs.setTexture(trm);
                }
                else if (modes == 3)
                {
                    mode = 2;
                    en->locked = 0;
                    en = new Dragon;
                    trs.setTexture(trd);
                }
                transition = 1;
                if (modes1 < 2)
                {
                    if (Lev == 0)
                    {
                        next.setTexture(ai, true);
                        next.setScale(0.5, 0.5);
                        next.setPosition(700, 720);
                    }
                    else if (Lev == 1)
                    {
                        next.setTexture(bi, true);
                        next.setScale(0.4, 0.4);
                        next.setPosition(705, 715);
                    }
                    else
                    {
                        next.setTexture(gi, true);
                        next.setScale(0.35, 0.35);
                        next.setPosition(700, 720);
                    }
                }
                else if (modes1 == 2)
                {
                    next.setTexture(ms, true);
                    next.setScale(0.17, 0.17);
                    next.setPosition(700, 720);
                }
                else if (modes1 == 3)
                {
                    next.setTexture(dr, true);
                    next.setScale(0.1, 0.1);
                    next.setPosition(700, 700);
                }
                m1.restart();
                mshoot = 0;
                en->sendenemydata();
                delay.restart();
                invinci.restart();
                invincis.restart();
                start = 1;
            }
            else if (game_timeline.getElapsedTime().asSeconds() > 2 && start == 1)
            {

                if (mode == 0 && game_timeline.getElapsedTime().asSeconds() >= 10 && en->num_e == 0)
                {
                    game_timeline.restart();
                    start = 0;
                }
                else if (mode == 1 && game_timeline.getElapsedTime().asSeconds() >= 10)
                {
                    game_timeline.restart();
                    start = 0;
                    score += 40;
                }
                else if (mode == 2 && game_timeline.getElapsedTime().asSeconds() >= 7.2)
                {
                    game_timeline.restart();
                    start = 0;
                    score += 50;
                }
            }

            // cout<<time<<endl;
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                {
                    window.close();
                    return -1;
                } // If cross/close is clicked/pressed

                // close the game
            }

            if (Keyboard::isKeyPressed(Keyboard::Left))  // If left key is pressed
                p->move("l");                            // Player will move to left
            if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
                p->move("r");                            // player will move to right
            if (Keyboard::isKeyPressed(Keyboard::Up))    // If up key is pressed
                p->move("u");                            // playet will move upwards
            if (Keyboard::isKeyPressed(Keyboard::Down))  // If down key is pressed
                p->move("d");                            // player will move downwards

            if ((Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right)) || (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Left)))
            {
                if (p->Add->action == 1 && p->Add->ty == 0)
                {
                    p->sprite.setTexture(p->pr);
                }
                else if (p->Add->action == 1 && p->Add->ty == 1)
                {
                    p->sprite.setTexture(p->fr);
                }
                else
                {
                    p->sprite.setTexture(p->rotr);
                }
                p->diagonal = true;
            }
            if (!(Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right)) && !((Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Left)) && !(Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Right)) || (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left))))
            {
                if (p->Add->action == 1 && p->Add->ty == 0)
                {
                    p->sprite.setTexture(p->pu);
                }
                else if (p->Add->action == 1 && p->Add->ty == 1)
                {
                    p->sprite.setTexture(p->fu);
                }
                else
                {
                    p->sprite.setTexture(p->tex);
                }

                p->diagonal = false;
            } // player will move downwards

            if ((Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Right)) || (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left)))
            { // If down key is pressed
                if (p->Add->action == 1 && p->Add->ty == 0)
                {
                    p->sprite.setTexture(p->pl);
                }
                else if (p->Add->action == 1 && p->Add->ty == 1)
                {
                    p->sprite.setTexture(p->fl);
                }
                else
                {
                    p->sprite.setTexture(p->rotl);
                }

                p->diagonal = true;
            } // player will move downwards
            if (!(Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Right)) && !(Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left)) && !((Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right)) || (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Left))))
            {
                if (p->Add->action == 1 && p->Add->ty == 0)
                {
                    p->sprite.setTexture(p->pu);
                }
                else if (p->Add->action == 1 && p->Add->ty == 1)
                {
                    p->sprite.setTexture(p->fu);
                }
                else
                {
                    p->sprite.setTexture(p->tex);
                }

                p->diagonal = false;
            } // player will move downwards
            if (bullettime == 0 && timer - bt >= 0.15)
            {
                bullettime = 1;
                bt = 0.0;
            }
            if (Keyboard::isKeyPressed(Keyboard::Space) && bullettime == 1)
            {
                p->fire(p->Add->ty, p->Add->action);

                bt = timer;
                bullettime = 0;
                // cout<<"spacey"<<endl;
            }
            if (Keyboard::isKeyPressed(Keyboard::Enter) && delay.getElapsedTime().asSeconds() >= 0.1)
            {
                en->sendenemydata();
                delay.restart();
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                m.dec = -1;
            }
            if (Fschange == 0)
            {
                ssp = shootsp;
                busp = p->BUL->speed;
                psp = p->speed;
                esp = en->speed;
                bsp = en->BM->speedb;
                asp = p->Add->speed;
            }
            if (Fschange == 1)
            {
                float addedesp = fsch + esp;
                float addedssp = fsch + ssp;
                float addedbusp = fsch + busp;
                float addedpsp = fsch*2 + psp;
                float addedbsp = fsch + bsp;
                float addedasp = fsch + asp;
                if (addedssp != shootsp)
                {
                    ssp = shootsp;
                    shootsp += fsch;
                }
                if (addedbusp != p->BUL->speed)
                {
                    busp = p->BUL->speed;
                    p->BUL->speed += fsch;
                }
                if (addedpsp != p->speed)
                {
                    psp = p->speed;
                    p->speed += fsch*2;
                }

                if (addedesp != en->speed)
                {
                    esp = en->speed;
                    en->speed += fsch;
                }
                if (addedbsp != en->BM->speedb)
                {
                    bsp = en->BM->speedb;
                    en->BM->speedb += fsch;
                }
                if (addedasp != p->Add->speed)
                {
                    asp = p->Add->speed;
                    p->Add->speed += fsch;
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::G) && spdelay.getElapsedTime().asSeconds() >= 0.1)
            {
                fsch += 0.005;
                p->Add->speed = asp + fsch;
                shootsp = ssp + fsch;
                p->BUL->speed = busp + fsch;
                p->speed = psp + fsch*2;
                en->speed = esp + fsch;
                en->BM->speedb = bsp + fsch;
                Fschange = 1;
                spdelay.restart();
            }

            // if (Keyboard::isKeyPressed(Keyboard::F) && spdelay.getElapsedTime().asSeconds() >= 0.1)
            // {
            //     en->sendenemydata();
            //     spdelay.restart();
            // }

            if (Keyboard::isKeyPressed(Keyboard::RShift) && delay.getElapsedTime().asSeconds() >= 0.4)
            {
                int randim = rand() % (en->num_e);
                en->addbomb(en->givex(randim), en->givey(randim));
                delay.restart();
            }

            //////////////////////////////////////////////
            /////  Call your functions here           ////
            //////////////////////////////////////////////

            if (transition == 1)
            {
                if (mode == 0)
                {
                    trs.move(en->speed +0.5, 0);
                }
                else if (mode == 1)
                {
                    trs.move(en->speed +0.3, 0);
                }
                else
                {
                    trs.move(en->speed +0.1, 0);
                }
            }
            if (transition == 1 && trs.getPosition().x > 790)
            {
                transition = 0;
                trs.setPosition(-790, 0);
            }
            // cout<<"hehe"<<endl;
            window.clear(Color::Black); // clears the screen
            window.draw(background);

                if (mode != 2)
                {
                    window.draw(lays);
                    window.draw(Timey);
                    window.draw(scorey);
                    window.draw(Level);
                    window.draw(lifey);
                    window.draw(timey2);
                }

                window.draw(next);

                // setting background
                if (hitting > lives && lifehit == 0)
                {
                    invinci.restart();
                    invincis.restart();
                    hitting = lives;
                    lifehit = 1;
                }
                if (invinci.getElapsedTime().asSeconds() > 2.5 && lifehit == 1)
                {
                    lifehit = 0;
                    lifeon = 0;
                }
                if (lifehit == 1)
                {
                    if (invincis.getElapsedTime().asSeconds() > 0.06)
                    {

                        if (lifeon == 0)
                        {

                            lifeon = 1;
                        }
                        else
                        {
                            lifeon = 0;
                        }
                        invincis.restart();
                    }
                }

                if (lifeon == 0)
                {
                    window.draw(p->sprite);
                }

                // setting player on screen
                // Bullet
                p->Add->addon.setPosition(p->Add->x, p->Add->y);
                window.draw(p->Add->addon);
                if (addion.getElapsedTime().asSeconds() > 3 && p->Add->action == 0 && p->Add->y > 790)
                {

                    int random = rand() % 4;

                    if (random == 0)
                    {
                        p->Add = new Powerup;
                    }
                    else if (random == 1)
                    {
                        p->Add = new Fire;
                    }
                    else if (random == 2)
                    {
                        p->Add = new Danger;
                    }
                    else
                    {
                        p->Add = new Life;
                    }
                    p->Add->x = rand() % 700;
                    addion.restart();
                }
                p->Add->moveaddon();
                if (p->Add->remove_addon(p->sprite.getPosition().x, p->sprite.getPosition().y, score) == 1 && p->Add->ty < 2)
                {
                    p->speed = 0.2;
                    addion.restart();
                    add_del.restart();
                }
                if (p->Add->action == 1)
                {
                    if (p->Add->ty == 0)
                    {
                        p->shield.setPosition(p->sprite.getPosition().x - 12, p->sprite.getPosition().y - 10);
                        window.draw(p->shield);
                        if (addion.getElapsedTime().asSeconds() > 5)
                        {
                            p->Add->action = 0;
                            p->BUL->bullet.setColor(Color::White);
                            addion.restart();
                            p->speed = 0.1;
                        }
                        else if (add_del.getElapsedTime().asSeconds() > 0.15)
                        {
                            p->BUL->bullet.setColor(Color::Red);
                            p->Add->do_action(p->BUL, p->sprite.getPosition().x, p->sprite.getPosition().y, lives);
                            add_del.restart();
                        }
                    }
                    else if (p->Add->ty == 1)
                    {
                        if (addion.getElapsedTime().asSeconds() > 5)
                        {
                            p->Add->action = 0;
                            addion.restart();
                            p->speed = 0.1;
                        }
                    }
                    else if (p->Add->ty == 2)
                    {
                        if ((p->Add->remove_addon(p->sprite.getPosition().x, p->sprite.getPosition().y, score) == 1 || p->Add->remove_addon(p->sprite.getPosition().x, p->sprite.getPosition().y, score) == -1))
                        {
                            p->Add->action = 0;
                            int x11 = p->sprite.getPosition().x + 7;
                            int y11 = p->sprite.getPosition().y + 13;
                            en->exp->addexp(x11, y11);
                            if (lifeon == 0)
                            {
                                p->Add->do_action(p->BUL, p->sprite.getPosition().x, p->sprite.getPosition().y, lives);
                            }
                        }
                    }
                    else if (p->Add->ty == 3)
                    {
                        if ((p->Add->remove_addon(p->sprite.getPosition().x, p->sprite.getPosition().y, score) == 1 || p->Add->remove_addon(p->sprite.getPosition().x, p->sprite.getPosition().y, score) == -1))
                        {
                            hitting++;
                            p->Add->action = 0;
                            p->Add->do_action(p->BUL, p->sprite.getPosition().x, p->sprite.getPosition().y, lives);
                        }
                    }
                }
                if (mode == 0)
                {
                    if (invadershoot.getElapsedTime().asSeconds() > shootsp)
                    {
                        int randim = rand() % (en->num_e);
                        en->addbomb(en->givex(randim), en->givey(randim));
                        invadershoot.restart();
                    }
                }
                p->BUL->bulletsmove();
                en->exp->runexp();
                en->BM->removebomb();
                p->BUL->removebuls();
                en->move_enemy(p->sprite.getPosition().x);
                for (int i = 0; i < en->exp->num_exp; i++)
                {
                    en->exp->explosion.setPosition(en->exp->givex(i), en->exp->givey(i));
                    window.draw(en->exp->explosion);
                }
                for (int i = 0; i < p->BUL->num_b; i++)
                {
                    p->BUL->bullet.setPosition(p->BUL->givex(i), p->BUL->givey(i));
                    if (*(p->BUL->direction + i) == 0)
                    {
                        if (p->Add->ty == 1 && p->Add->action == 1)
                        {
                            p->BUL->bullet.setTexture(p->BUL->fl, true);
                        }
                        else
                        {
                            p->BUL->bullet.setTexture(p->BUL->ll, true);
                        }
                    }
                    else if (*(p->BUL->direction + i) == 1)
                    {
                        if (p->Add->ty == 1 && p->Add->action == 1)
                        {
                            p->BUL->bullet.setTexture(p->BUL->fu, true);
                        }
                        else
                        {
                            p->BUL->bullet.setTexture(p->BUL->bul, true);
                        }
                    }
                    else if (*(p->BUL->direction + i) == 2)
                    {
                        if (p->Add->ty == 1 && p->Add->action == 1)
                        {
                            p->BUL->bullet.setTexture(p->BUL->fr, true);
                        }
                        else
                        {
                            p->BUL->bullet.setTexture(p->BUL->lr, true);
                        }
                    }
                    else if (*(p->BUL->direction + i) == 3)
                    {

                        p->BUL->bullet.setTexture(p->BUL->ru, true);
                    }
                    else if (*(p->BUL->direction + i) == 4)
                    {

                        p->BUL->bullet.setTexture(p->BUL->rd, true);
                    }
                    else if (*(p->BUL->direction + i) == 5)
                    {

                        p->BUL->bullet.setTexture(p->BUL->lu, true);
                    }
                    else if (*(p->BUL->direction + i) == 6)
                    {

                        p->BUL->bullet.setTexture(p->BUL->ld, true);
                    }

                    window.draw(p->BUL->bullet);
                }

                if (mode == 1 && mshoot == 1)
                {

                    if (m2.getElapsedTime().asSeconds() > 2)
                    {
                        m1.restart();
                        mshoot = 0;
                    }
                    if (delay.getElapsedTime().asSeconds() > 0.1)
                    {
                        for (int i = 0; i < en->num_e; i++)
                        {
                            en->addbomb(en->givex(i), en->givey(i));
                        }
                        delay.restart();
                    }
                }
                else if (mode == 2 && mshoot == 1)
                {
                    en->locked = 1;
                    if (delay.getElapsedTime().asSeconds() > 0.1)
                    {

                        en->addbomb(en->givex(0), en->givey(0));

                        delay.restart();
                    }
                }
                if (mshoot == 0 && (mode == 1) && m1.getElapsedTime().asSeconds() >= 2)
                {
                    m2.restart();
                    mshoot = 1;
                }
                else if (mshoot == 0 && (mode == 2) && m1.getElapsedTime().asSeconds() >= 2)
                {
                    mshoot = 1;
                }

                for (int i = 0; i < en->num_e; i++)
                {
                    en->enemy.setPosition(en->givex(i), en->givey(i));
                    window.draw(en->enemy);
                }
                for (int i = 0; i < en->BM->num_b; i++)
                {
                    en->BM->bomb.setPosition(en->BM->givex(i), en->BM->givey(i));
                    window.draw(en->BM->bomb);
                }
                if (en->num_e == 0 && mode == 0)
                {
                    if (en->type < 3)
                    {
                        en->type = rand() % 3;
                    }
                    else if (en->type < 6)
                    {
                        en->type = (rand() % 3) + 3;
                    }
                    else
                    {
                        en->type = (rand() % 6) + 6;
                    }

                    en->sendenemydata();
                    delay.restart();
                }
                enemy_hit(p->Add->ty, p->Add->action);
                player_hit(p->Add->ty, p->Add->action, lifehit);

                en->movebomb();
                if (mode == 2)
                {
                    window.draw(lays);
                    window.draw(Timey);
                    window.draw(scorey);
                    window.draw(Level);
                    window.draw(lifey);
                    window.draw(timey2);
                }
                if (Lev == 1)
                {
                    lfire.setTexture(lf2);
                    window.draw(lfire);
                }
                else if (Lev >= 2)
                {
                    lfire.setTexture(lf3);
                    window.draw(lfire);
                }
                if (lives == 0)
                {
                    m.display_over(window);
                }
                window.draw(trs);
                window.display(); // Displying all the sprites
                            sc1 = m.display_menu(window, score);
                            
            // cout<<"sc1: "<<sc1<<endl;
            if (sc1 == 1)
            {;
            }
            else if (sc1 == -1)
            {
                return 1;
            }
            else if (sc1 == 20)
            {
                return -1;
            }
        }
    }
};
