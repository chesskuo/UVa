// ----------
// UVa 1481 - Genome Evolution
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4227
// https://www.udebug.com/UVa/1481
// ----------

#include <bits/stdc++.h>

using namespace std;

#define MAX 3001

int main()
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	int n;

	while(~scanf("%d", &n) && n != 0)
	{
		int a[MAX], index[MAX];

		for(int i=0; i<n; i++)
			scanf("%d", &a[i]);

		for(int i=0; i<n; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			index[tmp] = i;
		}

		int cnt = 0;

		for(int i=0; i<n; i++)
		{
			int maxi = index[a[i]];
			int mini = index[a[i]];
			int len = 1;

			for(int j=i+1; j<n; j++)
			{
				maxi = max(maxi, index[a[j]]);
				mini = min(mini, index[a[j]]);

				len++;

				if(maxi - mini + 1 == len)
					cnt++;
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}
