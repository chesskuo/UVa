// ----------
// UVa 11716 - Digital Fortress
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2763
// https://www.udebug.com/UVa/11716
// ----------

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	int T, i;
	char str[10000];
	double ha;

	scanf("%d", &T);
	getchar();

	for(int i=0; i<T; i++)
	{
		gets(str);

		ha = sqrt(strlen(str));

		if(ha-(int)ha != 0)
		{
			printf("INVALID\n");
		}
		else
		{
			char out[(int)ha][(int)ha];
			int count=0;

			for(int j=0; j<(int)ha; j++)
				for(int k=0; k<(int)ha; k++)
				{
					out[j][k] = str[count];
					count++;
				}

			for(int j=0; j<(int)ha; j++)
				for(int k=0; k<(int)ha; k++)
				{
					printf("%c", out[k][j]);
				}
			printf("\n");
		}
	}

	return 0;
}
