// ----------
// UVa 579 - Clock Hands
// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=520
// https://www.udebug.com/UVa/579
// ----------

#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	int h, m;

	while(scanf("%d:%d", &h, &m) && (h != 0 || m != 0))
	{
		float dh = 30.0 * (h + m/60.0);
		float dm = m * 6;

		float out = abs(dh - dm);

		if(out > 180)
			printf("%.3f\n", 360.0 - out);
		else if(out < 0)
			printf("%.3f\n", 360.0 + out);
		else
			printf("%.3f\n", out);
	}

	return 0;
}
