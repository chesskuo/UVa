// ----------
// UVa 11059 - Maximum Product
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2000
// https://www.udebug.com/UVa/11059
// ----------

#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	int n;
	int cas = 1;

	while(~scanf("%d", &n))
	{
		long long num[n];

		for(int i=0; i<n; i++)
			scanf("%lld", &num[i]);

		long long out = 0;

		for(int i=0; i<n; i++)
		{
			long long tmp = 1;

			for(int j=i ; j<n; j++)
				out = max(out , tmp*=num[j]);
		}

		printf("Case #%d: The maximum product is %lld.\n\n", cas++, out);
	}
	return 0;
}
