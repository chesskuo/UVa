// ----------
// UVa 10209 - Is This Integration ?
// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1150
// https://www.udebug.com/UVa/10209
// ----------

#include <cstdio>
#define _USE_MATH_DEFINES
#include <cmath>

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	double r;

	// 利用半圓減掉中間的竹筍會得到鐮刀
	// 我們稱此種方式為"大正減鐮刀"
	while(scanf("%lf", &r) != EOF)
	{
		printf("%.3lf ", (1-sqrt(3)+(M_PI/3))*r*r);
		printf("%.3lf ", ((M_PI/12)+(sqrt(3)/2)-1)*r*r*4);
		printf("%.3lf\n", (4-sqrt(3)-(2*M_PI/3))*r*r);
	}

	return 0;
}
