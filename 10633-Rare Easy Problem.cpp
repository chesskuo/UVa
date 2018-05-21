/*******************************************************************************************************
* UVa 10633 - Rare Easy Problem                                                                        *
* https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1574 *
* https://www.udebug.com/UVa/10633                                                                     *
*******************************************************************************************************/
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	unsigned long long int input;

	while(scanf("%llu", &input) != EOF)
	{
		if(input == 0)
			break;

		if(10*input%9 == 0)
			printf("%llu %llu\n", 10*input/9-1, 10*input/9);
		else
			printf("%llu\n", 10*input/9);
	}

	return 0;
}
