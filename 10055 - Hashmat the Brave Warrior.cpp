// ----------
// UVa 10055 - Hashmat the Brave Warrior
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=996
// https://www.udebug.com/UVa/10055
// ----------

#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	long long a, b;

	while(~scanf("%lld %lld", &a, &b))
	{
		printf("%lld\n", abs(a-b));
	}

	return 0;
}
