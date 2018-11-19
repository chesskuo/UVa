// ----------
// UVa 11389 - The Bus Driver Problem
// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2384
// https://www.udebug.com/UVa/11389
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
#include <set>

using namespace std;

int main()
{
	#ifdef DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	int n, d, r;

	while(scanf("%d %d %d", &n, &d, &r) && (n || d || r))
	{
		int morning[n], night[n];

		for(int i=0; i<n; i++)
			scanf("%d", &morning[i]);

		for(int i=0; i<n; i++)
			scanf("%d", &night[i]);


		sort(morning, morning+n);
		sort(night, night+n);

		int total = 0;

		for(int i=0; i<n; i++)
		{
			if(morning[i] + night[n-1-i] > d)
				total += ((morning[i] + night[n-1-i]) - d) * r;
		}

		printf("%d\n", total);
	}
	
	return 0;	
}
