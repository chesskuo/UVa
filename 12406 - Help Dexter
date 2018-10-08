// ----------
// UVa 12406 - Help Dexter
// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3837
// https://www.udebug.com/UVa/12406
// ----------

#include <cstdio>
#include <cmath>

using namespace std;

int p, q;
long long min, max;

void dfs(int now, long long sum)
{
	if(now == p)
	{
		if(sum % q == 0)
		{
			if(sum < min)
				min = sum;
			if(sum > max)
				max = sum;
		}

		return;
	}

	dfs(now+1, sum*10+1);
	dfs(now+1, sum*10+2);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	int T;

	scanf("%d", &T);

	for(int t=0; t<T; t++)
	{
		scanf("%d %d", &p, &q);

		q = pow(2, q);
		min = 1e17;
		max = 0;

		dfs(0, 0);

		if(min == 1e17 && max == 0)
			printf("Case %d: impossible\n", t+1);
		else if(min == max)
			printf("Case %d: %lld\n", t+1, min);
		else
			printf("Case %d: %lld %lld\n", t+1, min, max);
	}

	return 0;
}
