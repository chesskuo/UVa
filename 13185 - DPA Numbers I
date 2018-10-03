// ----------
// UVa 13185 - DPA Numbers I
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5096
// https://www.udebug.com/UVa/13185
// ----------

#include <cstdio>

using namespace std;

short count(short n)
{
	short total = 0;

	for(short i=1; i<n; i++)
		if(n % i == 0)
			total += i;

	return total;
}

int main()
{
	#ifdef DEBUG
	freopen("input.in", "r", stdin);
	#endif

	short times;

	scanf("%hi", &times);

	for(short t=0; t<times; t++)
	{
		short n;

		scanf("%hi", &n);

		short total = count(n);

		if(total == n)
			printf("perfect\n");
		else if(total < n)
			printf("deficient\n");
		else
			printf("abundant\n");
	}

	return 0;
}
