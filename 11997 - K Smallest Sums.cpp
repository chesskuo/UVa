// ----------
// UVa 11997 - K Smallest Sums
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3148
// https://www.udebug.com/UVa/11997
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

struct p_queue
{
	int val, pos;

	// Priority Queue 用 "<" 來判斷排序依據
	// 預設為由大到小 但我們需要小到大
	bool operator<(const p_queue &r) const
	{
		return val > r.val;
	}
};

int main()
{
	#ifdef DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	int k;

	while(~scanf("%d", &k))
	{
		int arr[k];

		// 先輸入第一行當底
		for(int i=0; i<k; i++)
			scanf("%d", &arr[i]);

		sort(arr, arr+k);

		// 陸續處理之後k-1行
		for(int t=1; t<k; t++)
		{
			int arr2[k];
			priority_queue<p_queue> pq;

			for(int i=0; i<k; i++)
				scanf("%d", &arr2[i]);
			
			sort(arr2, arr2+k);

			// 先將第一格放進queue當作之後掃整串的底
			for(int i=0; i<k; i++)
				pq.push({arr[i]+arr2[0], 0});

			// 做k次將兩行完整合併出最小
			for(int i=0; i<k; i++)
			{
				p_queue tmp = pq.top();
				pq.pop();

				arr[i] = tmp.val;
				printf("%d\n", arr[i]);

				if(tmp.pos + 1 < k)
					pq.push({tmp.val - arr2[tmp.pos] + arr2[tmp.pos + 1], tmp.pos + 1});
			}
		}

		// for(int i=0; i<k; i++)
		// {
		// 	if(i == 0)
		// 		printf("%d", arr[i]);
		// 	else
		// 		printf(" %d", arr[i]);
		// }
		// printf("\n");
	}

	return 0;
}
