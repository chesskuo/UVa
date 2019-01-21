// ----------
// UVa 10035 - Primary Arithmetic
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=976
// https://www.udebug.com/UVa/10035
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

	while(cin >> a >> b && (a != 0 || b != 0))
	{
		int cnt = 0;
		int c = 0;

		while(a != 0 || b != 0)
		{
			if(a%10 + b%10 + c >= 10)
			{
				cnt++;
				c = 1;
			}
			else
				c = 0;

			a /= 10;
			b /= 10;
		}

		if(cnt == 0)
			printf("No carry operation.\n");
		else if(cnt == 1)
			printf("1 carry operation.\n");
		else
			printf("%d carry operations.\n", cnt);
	}
	return 0;
}
