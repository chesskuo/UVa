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
			int dp[21][4001] = {0};
			total /= 2;

			dp[0][0] = 1;

			for(int i=0; i<=total; i++)
			{
				for(int j=1; j<index; j++)
					if(i == 0)
						dp[j][i] = 1;
					else
						dp[j][i] = (dp[j-1][i] | dp[j-1][i - arr[j]]);
			}

			if(dp[index-1][total])
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	return 0;
}
