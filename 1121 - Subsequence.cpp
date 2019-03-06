// ----------
// UVa 1121 - Subsequence
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3562
// https://www.udebug.com/UVa/1121
// ----------

#include <bits/stdc++.h>

using namespace std;

int pre[100000+5];

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	int n, s;

	while(~scanf("%d %d", &n, &s))
	{
		memset(pre, 0, sizeof(pre));

		for(int i=1; i<=n; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			pre[i] = tmp + pre[i-1];
		}

		int out = 0;

		for(int i=1; i<=n; i++)
		{
			int now = 0 + i;

			for(int j=now; j<=n; j++)
				if(pre[j] - pre[j-i] >= s)
					out = i;
			
			if(out)
				break;
		}

		printf("%d\n", out);
	}

	exit(0);
}
