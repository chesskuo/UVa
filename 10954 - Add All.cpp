// ----------
// 10954 - Add All
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1895
// https://www.udebug.com/UVa/10954
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

int main()
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	int n;

	while(scanf("%d", &n) && n != 0)
	{
		priority_queue<int , vector<int>, greater<int> > pq;
		int num;

		for(int i=0; i<n; i++)
		{
			scanf("%d", &num);
			pq.push(num);
		}

		int tmp;
		int cnt = 0;

		while(pq.size() != 1)
		{
			tmp = pq.top();
			pq.pop();

			tmp += pq.top();
			pq.pop();

			pq.push(tmp);

			cnt += tmp;
		}

		printf("%d\n", cnt);
	}

	return 0;
}
