// ----------
// UVa 11389 - The Bus Driver Problem
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2384
// https://www.udebug.com/UVa/11389
// ----------

#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	int n, d, r;

	while(scanf("%d %d %d", &n, &d, &r) && (n != 0 || d != 0  || r != 0) )
	{
		int mor[n];
		int eve[n];
		
		for(int i=0; i<n; i++)
			scanf("%d", &mor[i]);
		for(int i=0; i<n; i++)
			scanf("%d", &eve[i]);

		sort(mor, mor+n);
		sort(eve, eve+n, greater<int>());

		int money = 0;

		for(int i=0; i<n; i++)
		{
			int tmp = mor[i] + eve[i];

			if(tmp > d)
				money += (tmp-d)*r;
		}

		printf("%d\n", money);
	}
	return 0;
}
