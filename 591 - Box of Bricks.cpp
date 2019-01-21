// ----------
// UVa 591 - Box of Bricks
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=532
// https://www.udebug.com/UVa/591
// ----------

#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	int n;
	int cas = 1;

	while(scanf("%d", &n) && n != 0)
	{
		int arr[n];
		int total = 0;
		int cnt = 0;

		for(int i=0; i<n; i++)
		{
			scanf("%d", &arr[i]);
			total += arr[i];
		}

		total /= n;

		for(int i=0; i<n; i++)
			if(arr[i] > total)
				cnt += (arr[i] - total);

		printf("Set #%d\n", cas++);
		printf("The minimum number of moves is %d.\n\n", cnt); 
	}

	return 0;
}
