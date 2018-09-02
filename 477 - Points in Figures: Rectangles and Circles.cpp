// ----------
// UVa 477 - Points in Figures: Rectangles and Circles
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=418
// https://www.udebug.com/UVa/477
// ----------

#include <cstdio>

using namespace std;

class Figure
{
public:
	virtual float getp1(short i) {return 0;}
	virtual float getp2(short i) {return 0;}
	virtual float getp(short i) {return 0;}
	virtual float getr() {return 0;};
};

class Rectangle : public Figure
{
public:
	Rectangle()
	{
		p1[0] = 0; p1[1] = 0;
		p2[0] = 0; p2[1] = 0;
	}
	Rectangle(float a, float b, float c, float d)
	{
		p1[0] = a; p1[1] = b;
		p2[0] = c; p2[1] = d;
	}

	float getp1(short i) {return p1[i];}
	float getp2(short i) {return p2[i];}

private:
	float p1[2], p2[2];
};

class Circle : public Figure
{
public:
	Circle()
	{
		p[0] = 0; p[1] = 0;
		radius = 0;
	}
	Circle(float a, float b, float c)
	{
		p[0] = a; p[1] = b;
		radius = c;
	}

	float getp(short i) {return p[i];}
	float getr() {return radius;};

private:
	float p[2], radius;
};

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	char key, type[10];
	Figure* fig[10];
	short count=0, pct=1;
	float pt[2];

	// create figure
	while((key=getchar()) != '*')
	{
		float a, b, c, d;

		if(key == 'r')
		{
			scanf("%f %f %f %f ", &a, &b, &c, &d);
			fig[count] = new Rectangle(a, b, c, d);
			type[count] = 'r';
		}
		else if(key == 'c')
		{
			scanf("%f %f %f ", &a, &b, &c);
			fig[count] = new Circle(a, b, c);
			type[count] = 'c';
		}

		count++;
	} // end create

	// point scan
	while(scanf("%f %f\n", &pt[0], &pt[1]))
	{
		if(pt[0] == 9999.9f && pt[1] == 9999.9f)
			break;

		bool check[count]={false}, io=true;

		for(short i=0; i<count; i++)
		{
			switch (type[i])
			{
				case 'r':
					if(pt[0]>fig[i]->getp1(0) && pt[0]<fig[i]->getp2(0) && pt[1]<fig[i]->getp1(1) && pt[1]>fig[i]->getp2(1))
						check[i] = true;
					break;

				case 'c':
				{
					float x, y, z;

					x = pt[0] - fig[i]->getp(0);
					x *= x;

					y = pt[1] - fig[i]->getp(1);
					y *= y;

					z = fig[i]->getr() * fig[i]->getr();

					//printf("%.1f %.1f %.1f\n", x, y, z);

					if(x+y < z)
						check[i] = true;

					break;
				}
			} // end switch
		} // end for

		// output
		for(short i=0; i<count; i++)
		{
			if(check[i] == true)
			{
				printf("Point %hi is contained in figure %hi\n", pct, i+1);
				io = false;
			}
		}

		if(io == true)
			printf("Point %hi is not contained in any figure\n", pct);
		// end output

		pct++;
	} // end point scan

	return 0;
}
