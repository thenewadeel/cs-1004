class MyArraySprite
{
	Sprite *p;
	int NoOfElements;
public:	
	int size;
	MyArraySprite()
	{
		p = 0;
		size = 0;
		NoOfElements = 0;
	}
	~MyArraySprite()
	{
		delete[] p;
	}
	void push_back(Sprite sp)
	{
		if(NoOfElements ==  0)
		{
			p = new Sprite[1];
			p[0] = sp;
			NoOfElements++;
			size++;
		}
		else
		{
			Sprite * s1;
			size++;
			s1 = new Sprite[size];
			for(int i = 0; i < NoOfElements; i++)
				s1[i] = p[i];
			s1[size - 1] = sp;
			delete[] p;
			p = new Sprite[size];
			for(int i = 0; i < size; i++)
				p[i] = s1[i];
			NoOfElements++;
			delete[] s1;
		}
	}
	void erase(int i)
	{
		if(i < NoOfElements)
		{
			Sprite * s1;
			s1 = new Sprite[NoOfElements - 1];
			for(int k = 0; k < i;k++)
				s1[k] = p[k];
			for(int k = i + 1; k < NoOfElements;k++)
				s1[k-1] = p[k];
			delete[] p;
			NoOfElements--;
			p = new Sprite[NoOfElements];
			for(int k = 0; k < NoOfElements;k++)
				p[k] = s1[k];
			size = NoOfElements;
			delete[] s1;
		}
	}
	void update(int i, Sprite s)
	{
		if(i < NoOfElements && p != 0)
		{
			p[i] = s;
		}
	}
	Sprite get(int i)
	{
		Sprite s;
		if(i < NoOfElements && p != 0)
			return p[i];
		else
			return s;
	}	
	void clear()
	{
		delete[] p;
		p = 0;
		size = 0;
		NoOfElements = 0;	
	}
};
class MyArrayCircle
{
	CircleShape *p;
	int NoOfElements;
public:	
	int size;
	MyArrayCircle()
	{
		p = 0;
		size = 0;
		NoOfElements = 0;
	}
	~MyArrayCircle()
	{
		delete[] p;
	}
	void push_back(CircleShape sp)
	{
		if(NoOfElements ==  0)
		{
			p = new CircleShape[1];
			p[0] = sp;
			NoOfElements++;
			size++;
		}
		else
		{
			CircleShape * s1;
			size++;
			s1 = new CircleShape[size];
			for(int i = 0; i < NoOfElements; i++)
				s1[i] = p[i];
			s1[size - 1] = sp;
			delete[] p;
			p = s1;
			NoOfElements++;
		}
	}
	void erase(int i)
	{
		if(i < NoOfElements)
		{
			CircleShape * s1;
			s1 = new CircleShape[NoOfElements - 1];
			for(int k = 0; k < i;k++)
				s1[k] = p[k];
			for(int k = i + 1; k < NoOfElements;k++)
				s1[k-1] = p[k];
			delete[] p;
			NoOfElements--;
			p = new CircleShape[NoOfElements];
			for(int k = 0; k < NoOfElements;k++)
				p[k] = s1[k];
			size = NoOfElements;
			delete[] s1;
		}
	}
	void update(int i, CircleShape s)
	{
		if(i < NoOfElements && p != 0)
		{
			p[i] = s;
		}
	}
	CircleShape get(int i)
	{
		CircleShape s;
		if(i < NoOfElements && p != 0)
			return p[i];
		else
			return s;
	}	
	void clear()
	{
		delete[] p;
		p = 0;
		size = 0;
		NoOfElements = 0;	
	}
};
