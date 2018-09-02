// ----------
// UVa 488 - Triangle Wave
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=429
// https://www.udebug.com/UVa/488
// ----------

#include <cstdio>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	int times;
	bool check=false;

	scanf("%d", &times);

	for(int i=0; i<times; i++)
	{
		int high, again;

		scanf("%d %d", &high, &again);

		for(int j=0; j<again; j++)
		{
			if(check == true)
				printf("\n");

			for(int k=1; k<=high; k++)
			{
				for(int l=0; l<k; l++)
					printf("%d", k);
				printf("\n");
			}
			for(int k=high-1; k>=1; k--)
			{
				for(int l=0; l<k; l++)
					printf("%d", k);
				printf("\n");
			}

			check = true;
		}
	}

	return 0;
}
