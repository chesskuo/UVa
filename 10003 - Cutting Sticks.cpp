// ----------
// UVa 10003 - Cutting Sticks
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=944
// https://www.udebug.com/UVa/10003
// ----------

#include <bits/stdc++.h>

using namespace std;

int len;
int n;
int cut[53];
int cost[1001][1001];

int dp(int l, int r)
{
	bool check = false;

	if (cost[l][r] != 1e9)
		return cost[l][r];

	for(int i=0; i<n; i++)
		if(cut[i] > l && cut[i] < r)
		{
			check = 1;
			cost[l][r] = min(cost[l][r], dp(l, cut[i]) + dp(cut[i], r) + r - l);
		}

	if(!check)
		cost[l][r] = 0;

	return cost[l][r];
}

int main()
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	while(scanf("%d", &len) && len != 0)
	{
		scanf("%d", &n);

		for(int i=0; i<n; i++)
			scanf("%d", &cut[i]);

		for(int i=0; i<=1000; i++)
			for(int j=0; j<=1000; j++)
				cost[i][j] = 1e9;

		int out = dp(0, len);

		printf("The minimum cutting is %d.\n", out);
	}

	return 0;
}
