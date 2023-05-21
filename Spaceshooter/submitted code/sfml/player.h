#include <SFML/Graphics.hpp>
#include <string.h>
#include <cmath>
using namespace sf;
class Bullet
{
public:
	Texture bul, lr, ll;
	Texture ru, rd, lu, ld;
	Texture fr, fl, fu;
	Sprite bullet;
	float *px;
	float *py;
	int num_b;
	int *direction;
	float speed = 0.2;

	Bullet()
	{
		bul.loadFromFile("img/PNG/Lasers/laserBlue06.png");
		lr.loadFromFile("img/PNG/Lasers/laser06R.png");
		ll.loadFromFile("img/PNG/Lasers/laser06L.png");
		ru.loadFromFile("img/PNG/Lasers/rightup.png");
		rd.loadFromFile("img/PNG/Lasers/rightdown.png");
		lu.loadFromFile("img/PNG/Lasers/leftup.png");
		ld.loadFromFile("img/PNG/Lasers/leftdown.png");
		fr.loadFromFile("img/PNG/Lasers/farrr.png");
		fl.loadFromFile("img/PNG/Lasers/farrl.png");
		fu.loadFromFile("img/PNG/Lasers/farru.png");
		bullet.setTexture(bul);
		bullet.setScale(1, 1);
		px = new float[0];
		py = new float[0];
		direction = new int[0];
		num_b = 0;
	}
	void shootbullet(float x, float y, int hehe = -1)
	{

		int *t = new int[num_b + 1];
		for (int i = 0; i < num_b; i++)
		{
			*(t + i) = *(direction + i);
		}
		if (hehe != -1)
		{
			if (hehe == 0)
			{
				*(t + num_b) = 0;
				x += 0;
				y -= 0;
			}
			else if (hehe == 1)
			{
				*(t + num_b) = 1;
				x += 32;
				y -= 20;
			}
			else if (hehe == 2)
			{
				*(t + num_b) = 2;
				x += 40;
				y -= 0;
			}
			else if (hehe == 3)
			{
				*(t + num_b) = 3;
				x += 35;
				y -= 10;
			}
			else if (hehe == 4)
			{
				*(t + num_b) = 4;
				x += 45;
				y -= 0;
			}
			else if (hehe == 5)
			{
				*(t + num_b) = 5;
				x += 10;
				y -= 10;
			}
			else if (hehe == 6)
			{
				*(t + num_b) = 6;
				x += -8;
				y -= 0;
			}
		}
		else
		{
			if ((Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right)) || (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Left)))
			{
				*(t + num_b) = 2;
				x += 68;
				y -= 20;
			}
			else if ((Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Right)) || (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left)))
			{
				*(t + num_b) = 0;
				x += -18;
				y -= 20;
			}
			else
			{

				*(t + num_b) = 1;
				x += 32;
				y -= 20;
			}
		}
		direction = t;
		float *temp = new float[num_b + 1];
		for (int i = 0; i < num_b; i++)
		{
			*(temp + i) = *(px + i);
		}
		*(temp + num_b) = x;
		px = temp;
		float *temp1 = new float[num_b + 1];
		for (int i = 0; i < num_b; i++)
		{
			*(temp1 + i) = *(py + i);
		}
		*(temp1 + num_b) = y;
		py = temp1;
		num_b++;
	}
	float givex(int i)
	{
		return *(px + i);
	}
	float givey(int i)
	{
		return *(py + i);
	}
	void bulletsmove()
	{

		for (int i = 0; i < num_b; i++)
		{
			// cout<<"x: "<<*px<<" y: "<<*py<<endl;
			*(py + i) += -speed;
			if (*(direction + i) == 0)
			{
				*(px + i) += -speed;
			}
			else if (*(direction + i) == 2)
			{
				*(px + i) += speed;
			}
			else if (*(direction + i) == 3)
			{
				*(px + i) += speed * 0.4;
			}
			else if (*(direction + i) == 4)
			{
				*(px + i) += speed * 1.5;
			}
			else if (*(direction + i) == 5)
			{
				*(px + i) += -speed * 0.4;
			}
			else if (*(direction + i) == 6)
			{
				*(px + i) += -speed * 1.5;
			}
		}
	}
	void removebuls(int i = -1)
	{
		if (i != -1)
		{
			int *t = new int[num_b - 1];
			for (int j = 0; j < i; j++)
			{
				*(t + j) = *(direction + j);
			}
			for (int j = i + 1; j < num_b; j++)
			{
				*(t + j - 1) = *(direction + j);
			}
			direction = t;
			float *temp1 = new float[num_b - 1];
			for (int j = 0; j < i; j++)
			{
				*(temp1 + j) = *(py + j);
			}
			for (int j = i + 1; j < num_b; j++)
			{
				*(temp1 + j - 1) = *(py + j);
			}
			float *temp2 = new float[num_b - 1];
			for (int j = 0; j < i; j++)
			{
				*(temp2 + j) = *(px + j);
			}
			for (int j = i + 1; j < num_b; j++)
			{
				*(temp2 + j - 1) = *(px + j);
			}
			py = temp1;
			px = temp2;
			num_b--;
		}
		else
		{
			for (int i = 0; i < num_b; i++)
			{
				if (*(py + i) <= -60)
				{
					int *t = new int[num_b - 1];
					for (int j = 0; j < i; j++)
					{
						*(t + j) = *(direction + j);
					}
					for (int j = i + 1; j < num_b; j++)
					{
						*(t + j - 1) = *(direction + j);
					}
					direction = t;
					float *temp1 = new float[num_b - 1];
					for (int j = 0; j < i; j++)
					{
						*(temp1 + j) = *(py + j);
					}
					for (int j = i + 1; j < num_b; j++)
					{
						*(temp1 + j - 1) = *(py + j);
					}
					float *temp2 = new float[num_b - 1];
					for (int j = 0; j < i; j++)
					{
						*(temp2 + j) = *(px + j);
					}
					for (int j = i + 1; j < num_b; j++)
					{
						*(temp2 + j - 1) = *(px + j);
					}
					py = temp1;
					px = temp2;
					num_b--;
					break;
				}
			}
		}
	}
};
//
class Bomb
{
public:
	float *bx;
	float *by;
	int num_b;
	float speedb;
	Texture bb;
	Sprite bomb;
	Bomb(string png = "", int type = 0, float sp = 0.3)
	{
		bx = new float[0];
		by = new float[0];
		num_b = 0;
		speedb = sp;
		bb.loadFromFile(png);
		bomb.setTexture(bb);
	}
	void addbomb(float x, float y)
	{
		float *tempx = new float[num_b + 1];
		for (int i = 0; i < num_b + 1; i++)
		{
			*(tempx + i) = *(bx + i);
		}
		*(tempx + num_b) = x;
		bx = tempx;
		float *tempy = new float[num_b + 1];
		for (int i = 0; i < num_b + 1; i++)
		{
			*(tempy + i) = *(by + i);
		}
		*(tempy + num_b) = y;
		by = tempy;
		num_b++;
	}
	//
	void removebomb(int j = -1)
	{
		if (j != -1)
		{
			float *tempx = new float[num_b - 1];
			for (int i = 0; i < j; i++)
			{
				*(tempx + i) = *(bx + i);
			}
			for (int i = j + 1; i < num_b; i++)
			{
				*(tempx + i - 1) = *(bx + i);
			}
			bx = tempx;
			float *tempy = new float[num_b - 1];
			for (int i = 0; i < j; i++)
			{
				*(tempy + i) = *(by + i);
			}
			for (int i = j + 1; i < num_b; i++)
			{
				*(tempy + i - 1) = *(by + i);
			}
			by = tempy;
			num_b--;
		}
		else
		{
			for (int k = 0; k < num_b; k++)
			{
				if (*(by + k) > 790)
				{
					float *tempx = new float[num_b - 1];
					for (int i = 0; i < k; i++)
					{
						*(tempx + i) = *(bx + i);
					}
					for (int i = k + 1; i < num_b; i++)
					{
						*(tempx + i - 1) = *(bx + i);
					}
					bx = tempx;
					float *tempy = new float[num_b - 1];
					for (int i = 0; i < k; i++)
					{
						*(tempy + i) = *(by + i);
					}
					for (int i = k + 1; i < num_b; i++)
					{
						*(tempy + i - 1) = *(by + i);
					}
					by = tempy;
					num_b--;
					break;
				}
			}
		}
	}
	//
	float givex(int i) { return *(bx + i); }
	float givey(int i) { return *(by + i); }
};
//
class ExpAni
{
public:
	Sprite explosion;
	Texture EX1;
	Texture EX2;
	Texture EX3;
	Texture EX4;
	int num_exp;
	Clock *clk;
	float *expx;
	float *expy;
	string e1 = "img/e1.png";
	string e2 = "img/e2.png";
	string e3 = "img/e3.png";
	string e4 = "img/e4.png";
	ExpAni()
	{
		EX1.loadFromFile(e1);
		EX2.loadFromFile(e2);
		EX3.loadFromFile(e3);
		EX4.loadFromFile(e4);
		explosion.setTexture(EX1);
		explosion.setScale(0.45, 0.45);
		num_exp = 0;
		clk = new Clock[0];
		expx = new float[0];
		expy = new float[0];
	}
	float givex(int i) { return *(expx + i); }
	float givey(int i) { return *(expy + i); }

	void addexp(float x, float y)
	{
		Clock *tempc = new Clock[num_exp + 1];
		float *tempx = new float[num_exp + 1];
		float *tempy = new float[num_exp + 1];

		for (int i = 0; i < num_exp; i++)
		{

			*(tempc + i) = *(clk + i);

			*(tempx + i) = *(expx + i);
			*(tempy + i) = *(expy + i);
		}
		tempc[num_exp].restart();
		// cout<<"New clock: "<<tempc[num_exp].getElapsedTime().asSeconds()<<endl;
		for (int i = 0; i < num_exp + 1; i++)
		{
			// cout<<"Clock "<<i+1<<": "<<(tempc+i)->getElapsedTime().asSeconds()<<endl;
		}

		clk = tempc;
		*(tempx + num_exp) = x;
		*(tempy + num_exp) = y;
		expx = tempx;
		expy = tempy;
		num_exp++;
	}
	void remove_exp(int k)
	{
		Clock *tempc = new Clock[num_exp - 1];
		float *tempx = new float[num_exp - 1];
		float *tempy = new float[num_exp - 1];
		for (int i = 0; i < k; i++)
		{
			*(tempc + i) = *(clk + i);
			*(tempx + i) = *(expx + i);

			*(tempy + i) = *(expy + i);
		}
		for (int i = k + 1; i < num_exp; i++)
		{
			*(tempc + i - 1) = *(clk + i);
			*(tempx + i - 1) = *(expx + i);
			*(tempy + i - 1) = *(expy + i);
		}
		clk = tempc;
		expx = tempx;
		expy = tempy;
		num_exp--;
	}
	void runexp()
	{
		for (int i = 0; i < num_exp; i++)
		{

			if ((*(clk + i)).getElapsedTime().asSeconds() <= 0.1)
			{
				explosion.setTexture(EX1);
			}
			else if ((*(clk + i)).getElapsedTime().asSeconds() <= 0.2)
			{
				explosion.setTexture(EX2);
			}
			else if ((*(clk + i)).getElapsedTime().asSeconds() <= 0.3)
			{
				explosion.setTexture(EX3);
			}
			else if ((*(clk + i)).getElapsedTime().asSeconds() <= 0.4)
			{
				explosion.setTexture(EX4);
			}
			else if ((*(clk + i)).getElapsedTime().asSeconds() <= 0.5)
			{
				remove_exp(i);
			}
		}
	}
};
//
class Enemy
{
public:
	Texture en;
	Sprite enemy;
	float *ex;
	float *ey;
	int num_e;
	float speed;
	bool move, locked;
	ExpAni *exp;
	Bomb *BM;
	int type;
	Enemy(string local = "", string bomb_img = "", int ty = 0, float sp = 0.3)
	{
		move = 0;
		en.loadFromFile(local);
		enemy.setTexture(en);
		exp = new ExpAni;
		enemy.setScale(0.75, 0.75);
		if (ty == 12)
		{
			enemy.setScale(0.85, 0.85);
		}
		if (ty == 13)
		{
			enemy.setScale(1.05, 1.05);
			
		}
		ex = new float[0];
		BM = new Bomb(bomb_img, ty, sp);
		ey = new float[0];
		locked = 0;
		num_e = 0;
		speed = 0.02;
		type = ty;
	}
	void addenemy()
	{
		float *temp = new float[num_e + 1];
		for (int i = 0; i < num_e; i++)
		{
			*(temp + i) = *(ex + i);
		}
		*(temp + num_e) = 100.0 * (num_e);
		ex = temp;
		float *temp1 = new float[num_e + 1];
		for (int i = 0; i < num_e; i++)
		{
			*(temp1 + i) = *(ey + i);
		}
		*(temp1 + num_e) = 100.0;
		ey = temp1;
		num_e++;
	}
	float givex(int i)
	{
		return *(ex + i);
	}
	float givey(int i)
	{
		return *(ey + i);
	}
	void removeenemy(int i)
	{
		if (type < 12)
		{
			float *temp1 = new float[num_e - 1];
			for (int j = 0; j < i; j++)
			{
				*(temp1 + j) = *(ey + j);
			}
			for (int j = i + 1; j < num_e; j++)
			{
				*(temp1 + j - 1) = *(ey + j);
			}
			float *temp2 = new float[num_e - 1];
			for (int j = 0; j < i; j++)
			{
				*(temp2 + j) = *(ex + j);
			}
			for (int j = i + 1; j < num_e; j++)
			{
				*(temp2 + j - 1) = *(ex + j);
			}
			ey = temp1;
			ex = temp2;
			num_e--;
		}
	}

	virtual void sendenemydata() = 0;
	virtual void move_enemy(float x = 0.0) { ; }
	virtual void movebomb(){};
	virtual void addbomb(float x, float y){};
};
class Dragon : public Enemy
{
	int direction;

	Texture dleft, dright;

public:
	Dragon(string L = "img/dragon1.png", string B = "img/PNG/Lasers/laserRed09.png", int ty = 13, float sp = 0.5) : Enemy(L, B, ty, sp)
	{
		direction = 1;

		dleft.loadFromFile("img/dragon2.png");
		dright.loadFromFile("img/dragon3.png");
	}
	virtual void sendenemydata()
	{
		num_e = 1;
		ex = new float[1];
		ey = new float[1];
		*(ex) = 0;
		*(ey) = -200;
	}
	virtual void movebomb()
	{
		if (direction == 0)
		{
			for (int i = 0; i < BM->num_b; i++)
			{
				BM->bx[i] += -BM->speedb / 2;
				BM->by[i] += BM->speedb;
			}
		}
		else if (direction == 1)
		{

			for (int i = 0; i < BM->num_b; i++)
			{
				BM->by[i] += BM->speedb;
			}
		}
		else if (direction == 2)
		{
			for (int i = 0; i < BM->num_b; i++)
			{
				BM->bx[i] += BM->speedb / 2;
				BM->by[i] += BM->speedb;
			}
		}
	}
	virtual void move_enemy(float x = 0.0)
	{
		if (x < 260 && locked == 0)
		{
			enemy.setTexture(dleft);
			direction = 0;
		}
		else if (x >= 260 && x < 520 && locked == 0)
		{
			enemy.setTexture(en);
			direction = 1;
		}
		else if (x >= 520 && locked == 0)
		{
			enemy.setTexture(dright);
			direction = 2;
		}
	}
	virtual void addbomb(float x, float y)
	{
		if (direction == 0 && locked == 1)
		{
			BM->addbomb(255, 460);
		}
		else if (direction == 1 && locked == 1)
		{

			BM->addbomb(370, 480);
		}
		else
		{
			BM->addbomb(485, 460);
		}
	}
};
class Monster : public Enemy
{
public:
	bool left;
	Monster(string L = "img/mnster.png", string B = "img/PNG/Lasers/laserRed15.png", int ty = 12, float sp = 0.7) : Enemy(L, B, ty, sp)
	{
		left = 0;
		speed = 0.08;
	}
	virtual void sendenemydata()
	{
		num_e = 1;
		ex = new float[1];
		ey = new float[1];
		*(ex) = 200;
		*(ey) = 60;
	}
	virtual void movebomb()
	{
		for (int i = 0; i < BM->num_b; i++)
		{
			BM->by[i] += BM->speedb;
		}
	}
	virtual void addbomb(float x, float y)
	{
		x += 120;
		y += 230;
		BM->addbomb(x, y);
		x -= 10;
		BM->addbomb(x, y);
		y += 40;
		x += 40;
		BM->addbomb(x, y);
		x -= 10;
		BM->addbomb(x, y);
		x -= 60;
		BM->addbomb(x, y);
		x += 10;
		BM->addbomb(x, y);
	}
	virtual void move_enemy(float x = 0.0)
	{
		if (left == 0)
		{
			*(ex) += speed;
		}
		else
		{
			*(ex) += -speed;
		}
		if (givex(0) >= 550)
		{
			left = 1;
		}
		else if (givex(0) <= -20)
		{
			left = 0;
		}
	}
};
class Invader : public Enemy
{
public:
	Invader(int t = 0, string L = "", string B = "", int ty = 0,float sp=0.11) : Enemy(L, B, ty,sp)
	{
		// type = t;
	}
	virtual void editenemy(int num, float *x, float *y)
	{
		num_e = num;
		float *temp1 = new float[num];
		for (int i = 0; i < num; i++)
		{
			*(temp1 + i) = *(x + i);
		}
		ex = temp1;
		float *temp2 = new float[num];
		for (int i = 0; i < num; i++)
		{
			*(temp2 + i) = *(y + i);
		}
		ey = temp2;
	}
	virtual void move_enemy(float x = 0.0)
	{
		if (type == 0 || type == 9)
		{
			for (int i = 0; i < num_e; i++)
			{
				if (*(ey + i) <= 130 && *(ex + i) < 700)
				{
					*(ex + i) += speed;
				}
				else if (*(ey + i) >= 330 && *(ex + i) > 0)
				{
					*(ex + i) += -speed;
				}
				else if (*(ex + i) <= 0 && *(ey + i) >= 130)
				{
					*(ey + i) += -speed;
				}
				else if (*(ex + i) >= 700 && *(ey + i) <= 330)
				{
					*(ey + i) += speed;
				}
			}
		}
		else if (type == 1 || type == 10)
		{
			for (int i = 0; i < num_e; i++)
			{
				if (*(ex + i) != 350 || *(ey + i) != 230)
				{
					if (*(ex + i) > 200 && *(ey + i) >= 330)
					{
						*(ex + i) += -speed;
					}
					else if (*(ey + i) > 30 && *(ex + i) < 350)
					{
						*(ex + i) += speed / 2;
						*(ey + i) += -speed;
					}
					else if (*(ey + i) >= 30 && *(ex + i) >= 350)
					{
						*(ex + i) += speed / 2;
						*(ey + i) += speed;
					}
				}
			}
		}
		else if (type == 2 || type == 3 || type == 6 || type == 11)
		{
			for (int i = 0; i < num_e; i++)
			{
				float s = speed / 100;
				double x = *(ex + i);
				double y = *(ey + i);
				double ang = 0.0;
				if (y <= 230 && x > 350)
				{
					x = x - 350;
					y = 230 - y;
					ang = atan(y / x);
					double hyp = (y / sin(ang));
					ang += s;

					if (y == 0)
					{
						hyp = x;
					}
					y = hyp * sin(ang);
					x = hyp * cos(ang);

					*(ex + i) = 350 + x;
					*(ey + i) = 230 - y;
				}
				else if (y < 230 && x <= 350)
				{
					x = 350 - x;
					y = 230 - y;
					ang = atan(y / x);
					double hyp = (y / sin(ang));
					ang -= s;

					if (y == 0)
					{
						hyp = x;
					}
					y = hyp * sin(ang);
					x = hyp * cos(ang);

					*(ex + i) = 350 - x;
					*(ey + i) = 230 - y;
				}
				else if (y >= 230 && x < 350)
				{
					x = 350 - x;
					y = y - 230;
					ang = atan(y / x);
					double hyp = (y / sin(ang));
					ang += s;

					if (y == 0)
					{
						hyp = x;
					}
					y = hyp * sin(ang);
					x = hyp * cos(ang);

					*(ex + i) = 350 - x;
					*(ey + i) = 230 + y;
				}
				else if (y > 230 && x >= 350)
				{
					x = x - 350;
					y = y - 230;
					ang = atan(y / x);
					double hyp = (y / sin(ang));
					ang -= s;

					if (y == 0)
					{
						hyp = x;
					}
					y = hyp * sin(ang);
					x = hyp * cos(ang);

					*(ex + i) = 350 + x;
					*(ey + i) = 230 + y;
				}
			}
		}
		else if (type == 4 || type == 7)
		{
			for (int i = 0; i < num_e; i++)
			{
				if (*(ex + i) < 350 && *(ey + i) <= 230)
				{
					*(ex + i) += speed;
					*(ey + i) -= speed;
				}
				else if (*(ex + i) >= 350 && *(ey + i) < 230)
				{
					*(ex + i) += speed;
					*(ey + i) += speed;
				}
				else if (*(ex + i) <= 350 && *(ey + i) > 230)
				{
					*(ex + i) -= speed;
					*(ey + i) -= speed;
				}
				else if (*(ex + i) > 350 && *(ey + i) >= 230)
				{
					*(ex + i) -= speed;
					*(ey + i) += speed;
				}
			}
		}
		else if (type == 5 || type == 8)
		{
			for (int i = 0; i < num_e; i++)
			{
				if (move == 0)
				{
					*(ex + i) += speed;
				}
				else
				{
					*(ex + i) -= speed;
				}
				float highest = 0.0, lowest = 900;
				int ht = 0, lt = 0;
				for (int j = 0; j < num_e; j++)
				{
					if (*(ex + j) > highest)
					{
						highest = *(ex + j);
						ht = j;
					}
					if (*(ex + j) < lowest)
					{
						lowest = *(ex + j);
						lt = j;
					}
				}
				if (*(ex + ht) >= 690)
				{
					move = 1;
				}
				else if (*(ex + lt) <= 10)
				{
					move = 0;
				}
			}
		}
	}
	virtual void addbomb(float x, float y)
	{
		x += 32;
		y += 20;
		BM->addbomb(x, y);
	}
	virtual void movebomb()
	{
		for (int i = 0; i < BM->num_b; i++)
		{
			BM->by[i] += BM->speedb;
		}
	}
};

class InAlpha : public Invader
{
public:
	float *aix1;
	float *aiy1;
	int num_ai1;
	float *aix2;
	float *aiy2;
	int num_ai2;
	float *aix3;
	float *aiy3;
	int num_ai3;
	InAlpha() : Invader(1, "img/enemy_1.png", "img/PNG/Lasers/laserRed06.png", 0)
	{

		// 1
		num_ai1 = 18;
		aix1 = new float[num_ai1];
		aiy1 = new float[num_ai1];
		for (int i = 0; i < 8; i++)
		{
			*(aix1 + i) = 100 * i;
			*(aiy1 + i) = 130;
		}
		*(aix1 + 8) = 0;
		*(aiy1 + 8) = 230;
		*(aix1 + 9) = 700;
		*(aiy1 + 9) = 330;
		for (int i = 10; i < num_ai1; i++)
		{
			*(aix1 + i) = 100 * (i - 10);
			*(aiy1 + i) = 330;
		}
		// 2
		num_ai2 = 9;
		aix2 = new float[num_ai2];
		aiy2 = new float[num_ai2];
		for (int i = 0; i < 4; i++)
		{
			*(aix2 + i) = 100 * (i + 2);
			*(aiy2 + i) = 330;
		}
		int pre = 200;
		int prey = 330;
		for (int i = 4; i < 7; i++)
		{
			*(aix2 + i) = pre + 50;
			pre += 50;
			*(aiy2 + i) = prey - 100;
			prey -= 100;
		}
		pre = 500;
		prey = 330;
		for (int i = 7; i < num_ai2; i++)
		{
			*(aix2 + i) = pre - 50;
			pre -= 50;
			*(aiy2 + i) = prey - 100;
			prey -= 100;
		}
		// 3
		num_ai3 = 9;
		aix3 = new float[num_ai3];
		aiy3 = new float[num_ai3];
		for (int i = 0; i < 5; i++)
		{
			*(aix3 + i) = 350;
			*(aiy3 + i) = (i)*100 + 30;
		}
		*(aix3 + 5) = 150;
		*(aiy3 + 5) = 230;
		*(aix3 + 6) = 250;
		*(aiy3 + 6) = 230;
		*(aix3 + 7) = 450;
		*(aiy3 + 7) = 230;
		*(aix3 + 8) = 550;
		*(aiy3 + 8) = 230;
	}
	void sendenemydata()
	{

		if (type == 0)
		{
			editenemy(num_ai1, aix1, aiy1);
		}
		else if (type == 1)
		{
			editenemy(num_ai2, aix2, aiy2);
		}
		else if (type == 2)
		{
			editenemy(num_ai3, aix3, aiy3);
		}
	}
};
class InBeta : public Invader
{
public:
	float *aix1;
	float *aiy1;
	int num_ai1;
	float *aix2;
	float *aiy2;
	int num_ai2;
	float *aix3;
	float *aiy3;
	int num_ai3;
	InBeta() : Invader(5, "img/enemy_2.png", "img/PNG/Lasers/laserRed02.png", 4,0.17)
	{
		enemy.setScale(0.6, 0.6);
		// 1
		num_ai1 = 9;
		aix1 = new float[num_ai1];
		aiy1 = new float[num_ai1];
		*(aix1 + 0) = 150;
		*(aiy1 + 0) = 230;

		*(aix1 + 1) = 550;
		*(aiy1 + 1) = 230;

		*(aix1 + 2) = 350;
		*(aiy1 + 2) = 30;

		*(aix1 + 3) = 350;
		*(aiy1 + 3) = 430;

		*(aix1 + 4) = 350;
		*(aiy1 + 4) = 230;

		*(aix1 + 5) = (350 + 200 * sin(M_PI / 4));
		*(aiy1 + 5) = (230 - 200 * sin(M_PI / 4));

		*(aix1 + 6) = (350 - 200 * sin(M_PI / 4));
		*(aiy1 + 6) = (230 - 200 * sin(M_PI / 4));

		*(aix1 + 7) = (350 - 200 * sin(M_PI / 4));
		*(aiy1 + 7) = (230 + 200 * sin(M_PI / 4));

		*(aix1 + 8) = (350 + 200 * sin(M_PI / 4));
		*(aiy1 + 8) = (230 + 200 * sin(M_PI / 4));
		// 2
		num_ai2 = 8;
		aix2 = new float[num_ai2];
		aiy2 = new float[num_ai2];
		*(aix2 + 0) = 150;
		*(aiy2 + 0) = 230;

		*(aix2 + 1) = 550;
		*(aiy2 + 1) = 230;

		*(aix2 + 2) = 350;
		*(aiy2 + 2) = 30;

		*(aix2 + 3) = 350;
		*(aiy2 + 3) = 430;

		*(aix2 + 4) = 250;
		*(aiy2 + 4) = 130;

		*(aix2 + 5) = 450;
		*(aiy2 + 5) = 130;

		*(aix2 + 6) = 250;
		*(aiy2 + 6) = 330;

		*(aix2 + 7) = 450;
		*(aiy2 + 7) = 330;
		// 3
		num_ai3 = 12;
		int temp = 150;
		aix3 = new float[num_ai3];
		aiy3 = new float[num_ai3];
		for (int i = 0; i < 5; i++)
		{
			*(aix3 + i) = temp;
			temp += 50;
			*(aiy3 + i) = 130 + (i * 100);
		}
		temp = 400;
		for (int i = 5; i < 9; i++)
		{
			*(aix3 + i) = temp;
			temp += 50;
			*(aiy3 + i) = 430 - ((i - 5) * 100);
		}
		*(aix3 + 9) = 350;
		*(aiy3 + 9) = 130;
		*(aix3 + 10) = 250;
		*(aiy3 + 10) = 30;
		*(aix3 + 11) = 450;
		*(aiy3 + 11) = 30;
	}
	void sendenemydata()
	{
		if (type == 3)
		{
			editenemy(num_ai1, aix1, aiy1);
		}
		else if (type == 4)
		{

			editenemy(num_ai2, aix2, aiy2);
		}
		else if (type == 5)
		{
			editenemy(num_ai3, aix3, aiy3);
		}
	}
};
//
class InGamma : public Invader
{
public:
	float *aix1;
	float *aiy1;
	int num_ai1;
	float *aix2;
	float *aiy2;
	int num_ai2;
	float *aix3;
	float *aiy3;
	int num_ai3;

	float *aix4;
	float *aiy4;
	int num_ai4;
	float *aix5;
	float *aiy5;
	int num_ai5;
	float *aix6;
	float *aiy6;
	int num_ai6;
	InGamma() : Invader(6, "img/enemy_3.png", "img/PNG/Lasers/laserRed16.png", 6,0.21)
	{
		enemy.setScale(0.5, 0.5);
		// 1
		num_ai1 = 13;
		aix1 = new float[num_ai1];
		aiy1 = new float[num_ai1];
		*(aix1 + 0) = 150;
		*(aiy1 + 0) = 230;

		*(aix1 + 1) = 550;
		*(aiy1 + 1) = 230;

		*(aix1 + 2) = 350;
		*(aiy1 + 2) = 30;

		*(aix1 + 3) = 350;
		*(aiy1 + 3) = 430;

		*(aix1 + 4) = 350;
		*(aiy1 + 4) = 230;

		*(aix1 + 5) = (350 + 200 * sin(M_PI / 4));
		*(aiy1 + 5) = (230 - 200 * sin(M_PI / 4));

		*(aix1 + 6) = (350 - 200 * sin(M_PI / 4));
		*(aiy1 + 6) = (230 - 200 * sin(M_PI / 4));

		*(aix1 + 7) = (350 - 200 * sin(M_PI / 4));
		*(aiy1 + 7) = (230 + 200 * sin(M_PI / 4));

		*(aix1 + 8) = (350 + 200 * sin(M_PI / 4));
		*(aiy1 + 8) = (230 + 200 * sin(M_PI / 4));

		*(aix1 + 9) = 250;
		*(aiy1 + 9) = 230;
		*(aix1 + 10) = 450;
		*(aiy1 + 10) = 230;
		*(aix1 + 11) = 350;
		*(aiy1 + 11) = 130;
		*(aix1 + 12) = 350;
		*(aiy1 + 12) = 330;
		// 2
		num_ai2 = 13;
		aix2 = new float[num_ai2];
		aiy2 = new float[num_ai2];
		*(aix2 + 0) = 150;
		*(aiy2 + 0) = 230;

		*(aix2 + 1) = 550;
		*(aiy2 + 1) = 230;

		*(aix2 + 2) = 350;
		*(aiy2 + 2) = 30;

		*(aix2 + 3) = 350;
		*(aiy2 + 3) = 430;

		*(aix2 + 4) = 250;
		*(aiy2 + 4) = 130;

		*(aix2 + 5) = 450;
		*(aiy2 + 5) = 130;

		*(aix2 + 6) = 250;
		*(aiy2 + 6) = 330;

		*(aix2 + 7) = 450;
		*(aiy2 + 7) = 330;

		*(aix2 + 8) = 350;
		*(aiy2 + 8) = 330;

		*(aix2 + 9) = 350;
		*(aiy2 + 9) = 130;

		*(aix2 + 10) = 450;
		*(aiy2 + 10) = 230;

		*(aix2 + 11) = 250;
		*(aiy2 + 11) = 230;

		*(aix2 + 12) = 350;
		*(aiy2 + 12) = 230;
		// 3
		num_ai3 = 17;
		int temp = 150;
		aix3 = new float[num_ai3];
		aiy3 = new float[num_ai3];
		for (int i = 0; i < 5; i++)
		{
			*(aix3 + i) = temp;
			temp += 50;
			*(aiy3 + i) = 130 + (i * 100);
		}
		temp = 400;
		for (int i = 5; i < 9; i++)
		{
			*(aix3 + i) = temp;
			temp += 50;
			*(aiy3 + i) = 430 - ((i - 5) * 100);
		}
		*(aix3 + 9) = 350;
		*(aiy3 + 9) = 130;
		*(aix3 + 10) = 250;
		*(aiy3 + 10) = 30;
		*(aix3 + 11) = 450;
		*(aiy3 + 11) = 30;

		*(aix3 + 12) = 350;
		*(aiy3 + 12) = 330;
		*(aix3 + 13) = 300;
		*(aiy3 + 13) = 230;
		*(aix3 + 14) = 400;
		*(aiy3 + 14) = 230;
		*(aix3 + 15) = 250;
		*(aiy3 + 15) = 130;
		*(aix3 + 16) = 450;
		*(aiy3 + 16) = 130;

		// 1
		num_ai4 = 24;
		aix4 = new float[num_ai4];
		aiy4 = new float[num_ai4];
		for (int i = 0; i < 8; i++)
		{
			*(aix4 + i) = 100 * i;
			*(aiy4 + i) = 130;
		}
		*(aix4 + 8) = 0;
		*(aiy4 + 8) = 230;
		*(aix4 + 9) = 700;
		*(aiy4 + 9) = 230;
		for (int i = 10; i < num_ai4; i++)
		{
			*(aix4 + i) = 100 * (i - 10);
			*(aiy4 + i) = 330;
		}
		for (int i = 0; i < 6; i++)
		{
			*(aix4 + i + 18) = (i + 1) * 100;
			*(aiy4 + i + 18) = 230;
		}
		// 2
		num_ai5 = 10;
		aix5 = new float[num_ai5];
		aiy5 = new float[num_ai5];
		for (int i = 0; i < 4; i++)
		{
			*(aix5 + i) = 100 * (i + 2);
			*(aiy5 + i) = 330;
		}
		int pre = 200;
		int prey = 330;
		for (int i = 4; i < 7; i++)
		{
			*(aix5 + i) = pre + 50;
			pre += 50;
			*(aiy5 + i) = prey - 100;
			prey -= 100;
		}
		pre = 500;
		prey = 330;
		for (int i = 7; i < num_ai5; i++)
		{
			*(aix5 + i) = pre - 50;
			pre -= 50;
			*(aiy5 + i) = prey - 100;
			prey -= 100;
		}
		*(aix5 + 9) = 350;
		*(aiy5 + 9) = 230;
		// 3
		num_ai6 = 9;
		aix6 = new float[num_ai6];
		aiy6 = new float[num_ai6];
		for (int i = 0; i < 5; i++)
		{
			*(aix6 + i) = 350;
			*(aiy6 + i) = (i)*100 + 30;
		}
		*(aix6 + 5) = 150;
		*(aiy6 + 5) = 230;
		*(aix6 + 6) = 250;
		*(aiy6 + 6) = 230;
		*(aix6 + 7) = 450;
		*(aiy6 + 7) = 230;
		*(aix6 + 8) = 550;
		*(aiy6 + 8) = 230;
	}
	void sendenemydata()
	{
		if (type == 6)
		{
			editenemy(num_ai1, aix1, aiy1);
		}
		else if (type == 7)
		{

			editenemy(num_ai2, aix2, aiy2);
		}
		else if (type == 8)
		{
			editenemy(num_ai3, aix3, aiy3);
		}
		else if (type == 9)
		{
			editenemy(num_ai4, aix4, aiy4);
		}
		else if (type == 10)
		{
			editenemy(num_ai5, aix5, aiy5);
		}
		else if (type == 11)
		{
			editenemy(num_ai6, aix6, aiy6);
		}
	}
};
//

class Addon
{
public:
	float x, y, speed;
	bool action;
	int ty;
	Sprite addon;
	Texture add1, add2, add3, add4;

	Addon(int type = 0)
	{
		x = 0;
		y = -80;
		action = 0;
		ty = type;
		speed = 0.15;
		add1.loadFromFile("img/powerup.png");
		add2.loadFromFile("img/fire.png");
		add3.loadFromFile("img/danger.png");
		add4.loadFromFile("img/lives.png");
		if (ty == 0)
		{
			addon.setTexture(add1);
		}
		else if (ty == 1)
		{
			addon.setTexture(add2);
		}
		else if (ty == 2)
		{
			addon.setTexture(add3);
		}
		else
		{
			addon.setTexture(add4);
		}
	}

	virtual void moveaddon()
	{
		y += speed;
	}

	virtual int remove_addon(float px, float py,int& s)
	{
		if ((x >= px - 30 && x <= px + 60) && (y <= py + 30 && y >= py - 20))
		{
			action = 1;
			y = 800;
			speed = 0.0;
			return 1;
		}
		else if (y >= 790)
		{

			speed = 0.0;
			return -1;
		}
		return 0;
	}

	virtual void do_action(Bullet *b, float x , float y,int& L)
	{
	}
};

//
class Powerup : public Addon
{
public:
	Powerup() : Addon(0)
	{
		speed = 0.09;
	}
	void do_action(Bullet *b, float x, float y ,int& L)
	{
		if (action == 1)
		{
			b->shootbullet(x, y, 0);
			b->shootbullet(x, y, 1);
			b->shootbullet(x, y, 2);
			b->shootbullet(x, y, 3);
			b->shootbullet(x, y, 4);
			b->shootbullet(x, y, 5);
			b->shootbullet(x, y, 6);
		}
	}
};
//
class Fire : public Addon
{
public:
	Fire() : Addon(1)
	{
		speed = 0.09;
	}
	void do_action(Bullet *b, float x , float y,int& L)
	{
		;
	}
};
//
class Danger : public Addon
{
public:
	Danger() : Addon(2)
	{
		speed = 0.09;
	}
	void do_action(Bullet *b, float x, float y,int& L)
	{

		L--;

	}
};
//
class Life : public Addon
{
public:
	Life() : Addon(3)
	{
		speed = 0.09;
	}
	void do_action(Bullet *b, float x, float y ,int& L)
	{
		L++;
	}
};
class Player
{
public:
	Texture tex;
	Texture rotr;
	Texture rotl, sh;
	Texture pu,pr,pl,fu,fr,fl;
	Sprite shield;
	bool diagonal;
	Bullet *BUL;
	Addon *Add;
	Sprite sprite;
	float speed = 0.1;
	float x, y, t_x, t_y;
	Player(std::string png_path)
	{
		rotr.loadFromFile("img/rotater.png");
		rotl.loadFromFile("img/rotatel.png");
		sh.loadFromFile("img//PNG/Effects/shield1.png");
		pu.loadFromFile("img/powerpu.png");
		pr.loadFromFile("img/powerpr.png");
		pl.loadFromFile("img/powerpl.png");
		fu.loadFromFile("img/firepu.png");
		fr.loadFromFile("img/firepr.png");
		fl.loadFromFile("img/firepl.png");
		tex.loadFromFile(png_path);
		shield.setTexture(sh);
		shield.setScale(0.75, 0.75);
		sprite.setTexture(tex);

		x = 340;
		y = 700;
		t_x = 0;
		t_y = 0;
		diagonal = 0;
		BUL = new Bullet;
		srand(time(0));
		int random = rand() % 4;
		if (random == 0)
		{
			Add = new Powerup;
		}
		else if (random == 1)
		{
			Add = new Fire;
		}
		else if (random == 2)
		{
			Add = new Danger;
		}
		else
		{
			Add = new Life;
		}
		Add->x = rand() % 700;

		sprite.setPosition(x, y);
		sprite.setScale(0.75, 0.75);
	}
	void fire(int ty = 0,bool a=0)
	{
		int x = 0;
		if (ty == 1 && a==1)
		{
			x = -12;
		}
		BUL->shootbullet(sprite.getPosition().x + x, sprite.getPosition().y);
	}
	void move(std::string s)
	{
		float delta_x = 0, delta_y = 0;
		if (s == "l")
			delta_x = -1.0;
		else if (s == "r")
			delta_x = 1.0;
		if (s == "u")
			delta_y = -1.0;
		else if (s == "d")
			delta_y = 1.0;

		delta_x *= speed;
		delta_y *= speed;

		t_x += delta_x;
		t_y += delta_y;
		// std::cout << "x: " <<sprite.getPosition().x<< endl;
		if (t_x <= -420)
		{
			sprite.move(860, delta_y);
			t_x += 860;
		}
		if (t_x >= 440)
		{
			sprite.move(-860, delta_y);
			t_x += -860;
		}
		if (t_y <= -780)
		{
			sprite.move(delta_x, 860);
			t_y += 860;
		}
		if (t_y >= 80)
		{
			sprite.move(delta_x, -860);
			t_y += -860;
		}

		sprite.move(delta_x, delta_y);
	}
};
