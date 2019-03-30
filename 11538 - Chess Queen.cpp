// ----------
// 11538 - Chess Queen
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2533
// https://www.udebug.com/UVa/11538
// ----------

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(NULL);

// ----------------------------------------

	unsigned long long m, n;

	while(scanf("%llu %llu", &m, &n) && (m || n))
	{
		unsigned long long tmpm = m;
		unsigned long long tmpn = n;
		m = max(tmpm, tmpn);
		n = min(tmpm, tmpn);

		unsigned long long out = n * m * (m + n - 2) + (2 * n * (n - 1) * (3 * m - n - 1) / 3);

		printf("%llu\n", out);
	}

	exit(0);
}
