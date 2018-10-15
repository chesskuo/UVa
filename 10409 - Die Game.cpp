// ----------
// UVa 10409 - Die Game
// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1350
// https://www.udebug.com/UVa/10409
// ----------

#include <cstdio>
#include <cstring>

using namespace std;

int	top, front, left, tmp;


void north()
{
	tmp = front;
	front = top;
	top = 7 - tmp;
}

void south()
{
	tmp = top;
	top = front;
	front = 7 - tmp;
}

void east()
{
	tmp = top;
	top = left;
	left = 7 - tmp;
}

void west()
{
	tmp = left;
	left = top;
	top = 7 - tmp;
}

int main()
{
	#ifdef DEBUG
	freopen("input.in", "r", stdin);
	#endif

	int num;

	while(scanf("%d", &num) && num != 0)
	{
		top = 1, front = 2, left = 3;

		char direc[6];

		for(int t=0; t<num; t++)
		{
			getchar();
			scanf("%5[^\n]", direc);

			if(direc[0] == 'n')
				north();			
			else if(direc[0] == 's')
				south();
			else if(direc[0] == 'e')
				east();
			else if(direc[0] == 'w')
				west();
		}

		printf("%d\n", top);
	}

	return 0;
}
