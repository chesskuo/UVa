// ----------
// UVa 539 - The Settlers of Catan
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=480
// https://www.udebug.com/UVa/539
// ----------

#include <bits/stdc++.h>

using namespace std;

int n, m;
bool edge[30][30];
int maxn;

void dfs(int begin, int tmp)
{
	for(int i=0; i<n; i++)
	{
		if(edge[begin][i])
		{
			edge[begin][i] = edge[i][begin] = false;
			dfs(i, tmp+1);
			edge[begin][i] = edge[i][begin] = true;
		}
	}

	maxn = max(maxn, tmp);
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	while(scanf("%d %d", &n, &m) && (n || m))
	{
		memset(edge, false, sizeof(edge));
		maxn = 0;

		int a, b;

		for(int i=0; i<m; i++)
		{
			scanf("%d %d", &a, &b);
			edge[a][b] = true;
			edge[b][a] = true;
		}

		clock_t tmp = clock();

		for(int i=0; i<n; i++)
			dfs(i, 0);

		//printf("using %lf seconds\n", (double)(clock() - tmp)/CLOCKS_PER_SEC);

		printf("%d\n", maxn);
	}

	return 0;
}
