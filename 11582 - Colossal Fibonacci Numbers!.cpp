// ----------
// UVa 11582 - Colossal Fibonacci Numbers!
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2629
// https://www.udebug.com/UVa/11582
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

const int maxn = 1000 + 5;

int fib[maxn][maxn*6];
int quan[maxn];

int pow_mod(unsigned long long a, unsigned long long b, int n)
{
	if(b == 0)
		return 1;

	int tmp = pow_mod(a, b/2, n);

	tmp = tmp * tmp % n;

	if(b % 2)
		tmp = tmp * a % n;

	return tmp;
}

void init()
{
	// i == n
	// n <= 1000
	for(int i=2; i<=1000; i++) 
	{
		fib[i][0] = 0;
		fib[i][1] = 1;

		for(int j=2; ;j++)
		{
			// build fib
			fib[i][j] = (fib[i][j-1] + fib[i][j-2]) % i;

			// find circulation
			if(fib[i][j-1] == 0 && fib[i][j] == 1)
			{
				quan[i] = j - 1;
				break;
			}
		}
	}
}

int main()
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	init();

	int times;

	scanf("%d", &times);

	for(int t=0; t<times; t++)
	{
		unsigned long long a, b;
		int n;

		scanf("%llu %llu %d", &a, &b, &n);

		if(a == 0 || n == 1)
			printf("0\n");
		else
		{
			int p = pow_mod(a % quan[n], b, quan[n]);
			printf("%d\n", fib[n][p]);
		}
	}


	return 0;
}
