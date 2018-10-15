// ----------
// UVa 352 - The Seasonal War
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=288
// https://www.udebug.com/UVa/352
// ----------

#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char photo[25][25];

void dfs(int i, int j, int n)
{
	photo[i][j] = '0';

	if(photo[i-1][j] == '1' && i-1 >= 0)
		dfs(i-1, j, n);
	if(photo[i+1][j] == '1' && i+1 < n)
		dfs(i+1, j, n);
	if(photo[i][j-1] == '1' && j-1 >= 0)
		dfs(i, j-1, n);
	if(photo[i][j+1] == '1' && j+1 < n)
		dfs(i, j+1, n);
	if(photo[i-1][j-1] == '1' && i-1 >= 0 && j-1 >= 0)
		dfs(i-1, j-1, n);
	if(photo[i-1][j+1] == '1' && i-1 >= 0 && j+1 < n)
		dfs(i-1, j+1, n);
	if(photo[i+1][j-1] == '1' && i+1 < n && j-1 >= 0)
		dfs(i+1, j-1, n);
	if(photo[i+1][j+1] == '1' && i+1 < n && j+1 < n)
		dfs(i+1, j+1, n);
}

int main()
{
	#ifdef DEBUG
	freopen("input.in", "r", stdin);
	#endif

	int size, ph_num = 0;

	while(~scanf("%d", &size))
	{
		getchar();
		memset(photo, 0, sizeof(photo));

		for(int i=0; i<size; i++)
		{
			for(int j=0; j<size; j++)
				scanf("%c", &photo[i][j]);
			getchar();
		}

		int count = 0;

		for(int i=0; i<size; i++)
			for(int j=0; j<size; j++)
				if(photo[i][j] == '1')
				{
					dfs(i, j, size);

					count++;
				}

		printf("Image number %d contains %d war eagles.\n", ++ph_num, count);
	}

	return 0;
}
