// ----------
// UVa 10071 - Back to High School Physics
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1012
// https://www.udebug.com/UVa/10071
// ----------

#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	int v, t;

	while(~scanf("%d %d", &v, &t))
		printf("%d\n", 2*v*t);
	
	return 0;
}
