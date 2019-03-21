// ----------
// UVa 10672 - Marbles on a tree
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1613
// https://www.udebug.com/UVa/10672
// ----------

#include <bits/stdc++.h>

using namespace std;

int box;
int quan[10005];
int child[10005];
int father[10005];
int need[10005];

void build()
{
	memset(quan, 0, sizeof(quan));
	memset(child, 0, sizeof(child));
	memset(father, 0, sizeof(father));
	memset(need, 0, sizeof(need));

	for(int i=1; i<=box; i++)
	{
		int index;
		scanf("%d", &index);
		scanf("%d %d", &quan[index], &child[index]);

		need[index] = quan[index] - 1;

		if(child[index])
			for(int j=1; j<=child[index]; j++)
			{
				int tmp;
				scanf("%d", &tmp);
				father[tmp] = index;
			}
	}
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(NULL);

// ----------------------------------------

	while(scanf("%d", &box) && box)
	{
		build();

		int head = 1;
		int total = 0;

		while(father[head] > 0)
			head = father[head];


		while(child[head] >= 0)
		{
			for(int i=1; i<=box; i++)
			{
				if(!child[i])
				{
					total += abs(need[i]);
					need[father[i]] += need[i];
					child[father[i]]--;
					child[i]--;
				}
			}
		}

		printf("%d\n", total);
	}
	exit(0);
}
