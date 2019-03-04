// ----------
// 10276 - Hanoi Tower Troubles Again!
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=1217
// https://www.udebug.com/UVa/10276
// ----------

#include <bits/stdc++.h>

using namespace std;

int table[55];

void build()
{
	int tmp = 2;

	table[1] = 1;
	for(int i=2; i<=50; i++)
	{
		table[i] = table[i-1] + tmp;

		if(i%2 == 0)
			tmp += 2;
	}
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	build();

	int times;

	scanf("%d", &times);

	for(int t=0; t<times; t++)
	{
		int n;

		scanf("%d", &n);

		printf("%d\n", table[n]);
	}

	return 0;
}
