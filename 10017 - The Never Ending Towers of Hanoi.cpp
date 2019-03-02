// ----------
// UVa 10017 - The Never Ending Towers of Hanoi
// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=958
// https://www.udebug.com/UVa/10017
// ----------

#include <bits/stdc++.h>

using namespace std;

int n, m;
int times;

vector<int> v[3];

void print()
{
	for(int i=0; i<3; i++)
	{
		printf("%c=>", i+65);
		if(v[i].empty())
			printf("\n");
		else
		{
			printf("   ");
			for(size_t j=0; j<v[i].size(); j++)
				printf("%d%c", v[i][j], j == v[i].size()-1 ? '\n':' ');
		}
	}

	printf("\n");
}

void hanoi(int num, int from, int tmp, int to)
{
	if(times == m)
		return;

	if(num == 1)
	{
		v[to].push_back(v[from].back());
		v[from].pop_back();
		print();
		times++;
	}
	else
	{
		hanoi(num-1, from, to, tmp);
		if(times == m)
			return;
		hanoi(1, from, tmp, to);
		hanoi(num-1, tmp, from, to);
	}
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	int cas = 1;

	while(scanf("%d %d", &n, &m) && (n || m))
	{
		for(int i=0; i<3; i++)
			v[i].clear();

		times = 0;

		for(int i=n; i>=1; i--)
			v[0].push_back(i);

		printf("Problem #%d\n", cas++);
		printf("\n");

		print();

		hanoi(n, 0, 1, 2);
	}	

	return 0;
}
