// ----------
// UVa 686 - Goldbach's Conjecture (II)
// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=627
// https://www.udebug.com/UVa/686
// ----------

#include <cstdio>

using namespace std;

bool prime(int in)
{
	for(int i=2; i<in; i++)
	{
		if(in%i == 0)
			return false;
	}

	return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	int num;

	while(scanf("%d", &num) && num!=0)
	{
		int tmp1, tmp2, count=0;

		tmp1 = tmp2 = num/2;

		while(tmp1 != 1)
		{
			if(prime(tmp1)==true && prime(tmp2)==true)
				count++;

			tmp1 -= 1;
			tmp2 += 1;
		}

		printf("%d\n", count);
	}

	return 0;
}
