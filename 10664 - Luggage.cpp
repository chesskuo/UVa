// ----------
// UVa 10664 - Luggage
// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1605
// https://www.udebug.com/UVa/10664
// ----------

#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	int times;

	scanf("%d", &times);

	for(int t=0; t<times; t++)
	{
		int arr[20];
		int index = 0;
		int total = 0;

		while(scanf("%d", &arr[index++]))
		{
			total += arr[index-1];

			if(getchar() == '\n')
				break;
		}


		if(total % 2)
			printf("NO\n");
		else
		{
			total /= 2;

			int bag[202]={0};

			for(int i=0; i<=total; i++)
				f[i] = 0;

			bag[0] = 1;

			for(int i=0; i<index; i++)
				for(int j=total; j>=arr[i]; j--)
					if(bag[j-arr[i]])
						bag[j] = 1;
			
			if(bag[total] == 0)
				printf("NO\n");
			else
				printf("YES\n");
		}
	}

	return 0;
}
