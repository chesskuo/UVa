// ----------
// 686 - Goldbach's Conjecture (II)
// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=627
// https://www.udebug.com/UVa/686
// ----------

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

bool table[32769];

void prime_table()
{
	table[0] = false;
	table[1] = false;

	for(int i=2; i<=32768; i++)
		if(table[i])
		{
			for(int j=i*i; j<=32768; j+=i)
				table[j] = false;
		}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	memset(table, 1, sizeof(table));
	prime_table();

	int input;

	while(~scanf("%d", &input) && input)
	{
		int count = 0;
		int l = input/2, r = input/2;

		while(r <= input || l == 2)
		{
			if(table[l] == true && table[r] == true)
				count++;

			l--;
			r++;
		}

		printf("%d\n", count);
	}

	return 0;
}
