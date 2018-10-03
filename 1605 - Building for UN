// ----------
// UVa 1605 - Building for UN
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4480
// https://www.udebug.com/UVa/1605
// ----------

#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	#ifdef DEBUG
	freopen("input.in", "r", stdin);
	#endif

	int n;

	while(~scanf("%d", &n))
	{
		char arr[2][n][n];
		char symbol = 'A';

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				arr[0][i][j] = symbol;
				arr[1][j][i] = symbol;
			}

			if(symbol == 90)
				symbol = 97;
			else
				symbol++;
		}

		printf("2 %d %d\n", n, n);

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				printf("%c", arr[0][i][j]);
			printf("\n");
		}

		printf("\n");

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				printf("%c", arr[1][i][j]);
			printf("\n");
		}
	}

	return 0;
}
