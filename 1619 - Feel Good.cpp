// ----------
// UVa 1619 - Feel Good
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4494
// https://www.udebug.com/UVa/1619
// ----------

#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

#define maxn 100005

long long sum[maxn];
int num[maxn], l[maxn], r[maxn], n;

int main()
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	int cas = 0;

	while(scanf("%d", &n) != EOF)
	{
		if(cas)
			printf("\n");

		cas++;

		memset(num, -1, sizeof(num));
		sum[0] = 0;

		// scan and init all
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &num[i]);

			sum[i] = sum[i-1] + num[i];
			l[i] = i;
			r[i] = i;
		}

		for(int i=1; i<=n; i++)
			while(num[l[i] - 1] >= num[i])
				l[i] = l[l[i] - 1];

		for(int i=n; i>=1; i--)
			while(num[r[i] + 1] >= num[i])
				r[i] = r[r[i] + 1];

		// range max
		long long out = 0;
		int ll = 1;
		int rr = 1;

		for(int i=1; i<=n; i++)
		{
			long long tmp  = num[i] * (sum[r[i]] - sum[l[i] - 1]);

			if(tmp > out || (tmp == out && rr - ll > r[i] - l[i]))
			{
				out = tmp;
				ll = l[i];
				rr = r[i];
			}
		}

		printf("%lld\n", out);
		printf("%d %d\n", ll, rr);
	}

	return 0;
}
