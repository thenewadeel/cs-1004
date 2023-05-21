#include <SFML/Graphics.hpp>
#include <iomanip>
#include <fstream>
using namespace std;
class Menu
{
public:
    Sprite menu;
    Texture newp, namep, highp, insp, endp, resp;
    bool newg, namein;
    int dec;
    string stf[4];
    string inf[4];
    string playername;
    int size;
    Font minecraft;
    Text p1, p2, p3, p4, s1, s2, s3, s4, pn;
    int sc;
    string *fst;
    string *fin;

    Menu()
    {
        srand(time(0));
        fst = new string[0];
        fin = new string[0];
        playername = "player" + to_string(rand() % 1000);
        size = 0;
        sc = 0;
        minecraft.loadFromFile("fonts/Minecraft.ttf");
        p1.setFont(minecraft);
        p1.setCharacterSize(16);
        p1.setPosition(270, 200);
        p1.setFillColor(Color::White);

        p2.setFont(minecraft);
        p2.setCharacterSize(16);
        p2.setPosition(270, 250);
        p2.setFillColor(Color::White);

        p3.setFont(minecraft);
        p3.setCharacterSize(16);
        p3.setPosition(270, 300);
        p3.setFillColor(Color::White);

        p4.setFont(minecraft);
        p4.setCharacterSize(16);
        p4.setPosition(270, 350);
        p4.setFillColor(Color::White);

        s1.setFont(minecraft);
        s1.setCharacterSize(16);
        s1.setPosition(270, 220);
        s1.setFillColor(Color::White);

        s2.setFont(minecraft);
        s2.setCharacterSize(16);
        s2.setPosition(270, 270);
        s2.setFillColor(Color::White);

        s3.setFont(minecraft);
        s3.setCharacterSize(16);
        s3.setPosition(270, 320);
        s3.setFillColor(Color::White);

        s4.setFont(minecraft);
        s4.setCharacterSize(16);
        s4.setPosition(270, 370);
        s4.setFillColor(Color::White);

        pn.setFont(minecraft);
        pn.setCharacterSize(80);
        pn.setPosition(200, 270);
        pn.setFillColor(Color::White);
        pn.setString("");
        dec = 0;
        newg = 1;
        namein = 0;
        for (int i = 0; i < 4; i++)
        {
            stf[i] = "";
            inf[i] = "";
        }
        newp.loadFromFile("img/PNG/screens/newp.png");
        namep.loadFromFile("img/PNG/screens/namep.png");
        highp.loadFromFile("img/PNG/screens/highp.png");
        insp.loadFromFile("img/PNG/screens/insp.png");
        endp.loadFromFile("img/PNG/screens/endp.png");
        resp.loadFromFile("img/PNG/screens/resp.png");
        menu.setTexture(newp);
    }

    void givefiles(int score)
    {
        fstream scorefile;
        scorefile.open("scores.txt", ios::in);
        string temp;
        int c = 0;
        while (getline(scorefile, temp))
        {
            c++;
        }
        scorefile.close();
        size = c;
        fst = new string[c / 2 + 1];
        fin = new string[c / 2 + 1];
        size++;
        size++;
        scorefile.open("scores.txt", ios::in);
        c = 0;
        bool chec = 0;

        while (getline(scorefile, fst[c]))
        {

            getline(scorefile, temp);

            if (stoi(temp) < score && chec == 0)
            {

                string tm = fst[c];
                fst[c] = playername;
                fin[c] = to_string(score);
                c++;
                fst[c] = tm;
                fin[c] = temp;
                chec = 1;
            }
            else if (c == size / 2 - 2 && chec == 0)
            {
                fin[c] = temp;
                c++;
                fst[c] = playername;
                fin[c] = to_string(score);
            }
            else
            {
                fin[c] = temp;
            }

            c++;
        }
        scorefile.close();

        scorefile.open("scores.txt", ios::out);
        for (int i = 0; i < size / 2; i++)
        {
            scorefile << fst[i];
            scorefile << endl;
            scorefile << fin[i];
            if (i != size / 2 - 1)
            {
                scorefile << endl;
            }
        }
        scorefile.close();
    }

    void display_start(RenderWindow &window)
    {
        menu.setTexture(newp);
        while (window.isOpen())
        {
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                {

                    dec = 6;
                    return;
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Num1))
            {
                dec = 1;
                newg = 0;
                break;
            }
            if (Keyboard::isKeyPressed(Keyboard::Num2))
            {
                dec = 2;
            }
            if (Keyboard::isKeyPressed(Keyboard::Num3))
            {

                dec = 3;
                break;
            }
            if (Keyboard::isKeyPressed(Keyboard::Num4))
            {
                dec = 4;
                break;
            }
            if (Keyboard::isKeyPressed(Keyboard::Num5))
            {
                dec = 6;

                break;
            }

            window.draw(menu);
            window.display();
        }
    }
    void display_pause(RenderWindow &window)
    {
        menu.setTexture(resp);
        while (window.isOpen())
        {
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                {
                    dec = 6;
                    return;
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Num1))
            {
                dec = 1;
                newg = 0;
                break;
            }
            if (Keyboard::isKeyPressed(Keyboard::Num2))
            {
                dec = 2;
            }
            if (Keyboard::isKeyPressed(Keyboard::Num3))
            {

                dec = 3;
                break;
            }
            if (Keyboard::isKeyPressed(Keyboard::Num4))
            {
                dec = 5;
                break;
            }
            if (Keyboard::isKeyPressed(Keyboard::Num5))
            {
                dec = 6;

                break;
            }

            window.draw(menu);
            window.display();
        }
    }
    void display_high(RenderWindow &window)
    {
        menu.setTexture(highp);
        // cout<<"hehe"<<endl;
        while (window.isOpen())
        {
            Event e;

            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                {
                    dec = 6;
                    return;
                }
            }

            window.draw(menu);
            window.draw(p1);
            window.draw(p2);
            window.draw(p3);
            window.draw(p4);
            window.draw(s1);
            window.draw(s2);
            window.draw(s3);
            window.draw(s4);
            if (Keyboard::isKeyPressed(Keyboard::BackSpace))
            {
                dec = 0;
                if (newg == 0)
                {
                    dec = -1;
                }
                break;
            }

            window.display();
        }
    }
    void display_option(RenderWindow &window)
    {
        menu.setTexture(insp);

        while (window.isOpen())
        {
            Event e;

            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                {
                    dec = 6;
                    return;
                }
            }

            window.draw(menu);
            if (Keyboard::isKeyPressed(Keyboard::BackSpace))
            {
                dec = 0;
                if (newg == 0)
                {
                    dec = -1;
                }
                break;
            }

            window.display();
        }
    }
    int display_menu(RenderWindow &window, int score)

    {
        sc = score;
        if (newg == 1 && dec == 0)
        {
            display_start(window);
        }
        else if (dec == 3)
        {
            display_high(window);
        }
        else if (dec == -1)
        {
            display_pause(window);
        }
        else if (dec == 4)
        {
            display_option(window);
        }
        else if (dec == 5)
        {
            return -1;
        }
        else if (dec == 6)
        {
            givefiles(sc);

            return 20;
        }
        return 1;
    }

    void display_over(RenderWindow &window)
    {
        menu.setTexture(endp);
        givefiles(sc);
        while (window.isOpen())
        {
            Event e;

            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                {
                    window.close();
                }
            }

            window.draw(menu);
            if (Keyboard::isKeyPressed(Keyboard::BackSpace))
            {
                dec = 5;
                break;
            }

            window.display();
        }
    }

    void getfiles()
    {
        fstream scorefile;
        scorefile.open("scores.txt", ios::in);
        int c = 0;
        while (getline(scorefile, stf[c]))
        {
            getline(scorefile, inf[c]);
            c++;
            if (c == 4)
            {
                break;
            }
        }
        p1.setString(stf[0]);
        p2.setString(stf[1]);
        p3.setString(stf[2]);
        p4.setString(stf[3]);

        s1.setString(inf[0]);
        s2.setString(inf[1]);
        s3.setString(inf[2]);
        s4.setString(inf[3]);
        scorefile.close();
    }

    void display_name(RenderWindow &window)
    {
        menu.setTexture(namep);
        Clock ck;
        bool back=0;
        string test = "";
        int hmm=0;
        while (window.isOpen())
        {
            Event e;

            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                {
                    dec = 6;
                    return;
                }
            if (Keyboard::isKeyPressed(Keyboard::BackSpace) && ck.getElapsedTime().asSeconds()>0.2)
            {
                
                string temp2="";
                hmm=hmm-1;
                for(int i=0;i<hmm;i++){
                    temp2+=test[i];
                }
                hmm--;
                test=temp2;
                ck.restart();
                back=1;
            }
                if (e.type == sf::Event::TextEntered)
                {
                    if(back!=1){
                        test += static_cast<char>(e.text.unicode);
                        
                    }
                    else{
                        back=0;
                    }
                    hmm++;
                    
                }
            }
            if(hmm<0){
                hmm=0;
            }
            window.draw(menu);
            pn.setString(test);
            window.draw(pn);
            if (Keyboard::isKeyPressed(Keyboard::Enter) )
            {
                playername=test;
                break;
            }


            window.display();
        }
    }
};
