// ----------
// UVa 11491 - Erasing and Winning
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2486
// https://www.udebug.com/UVa/11491
// ----------

#include <cstdio>
#include <cstring>

using namespace std;

int out[100005];

int main()
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	int n, d;

	while(scanf("%d %d", &n, &d) && n != 0 && d != 0)
	{
		getchar();

		int r = n - d; // the rightest side
		int cnt = 0;

		for(int i=0; i<n; i++)
		{
			int num = getchar() - '0';

			// cnt cannot be 0
			// (cnt + n - i) is to check if length enough
			// input must bigger than its previous
			while((cnt != 0) && (cnt + n - i > r) && (num > out[cnt-1]))
				cnt--;

			// if length is not over
			if(cnt < r)
				out[cnt++] = num;
		}

		for(int i=0; i<r; i++)
			printf("%d", out[i]);
		printf("\n");
	}

	return 0;
}
