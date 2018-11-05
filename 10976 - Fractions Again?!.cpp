// ----------
// 10976 - Fractions Again?!
// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1917
// https://www.udebug.com/UVa/10976
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

int main()
{
	#ifdef DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	int k;

	while(~scanf("%d", &k))
	{
		int a = 0;
		int b = k+1;
		int tmp = 1;
		int count = 0;

		while(b <= k*2)
		{
			if(k*b % tmp == 0)
				count++;

			b++;
			tmp++;
		}

		printf("%d\n", count);


		a = 0;
		b = k+1;
		tmp = 1;

		while(b <= k*2)
		{
			if(k*b % tmp == 0)
			{
				a = k * b / tmp;

				printf("1/%d = 1/%d + 1/%d\n", k, a, b);
			}

			b++;
			tmp++;
		}
	}

	return 0;
}
