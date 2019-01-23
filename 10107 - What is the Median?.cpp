// ----------
// UVa 10107 - What is the Median?
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1048
// https://www.udebug.com/UVa/10107
// ----------

#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	long long arr[10000];
	int index = 0;

	while(~scanf("%lld", &arr[index++]))
	{
		sort(arr, arr+index);

		if(index % 2)
			printf("%lld\n", arr[(index-1)/2]);
		else
			printf("%lld\n", (arr[index/2-1]+arr[index/2])/2);
	}

	return 0;
}
