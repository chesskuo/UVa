// ----------
// UVa 494 - Kindergarten Counting Game
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=435
// https://www.udebug.com/UVa/494
// ----------

#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	char input[1001];

	while(scanf("%1000[^\n]", input) != EOF)
	{
		getchar();

		size_t count=0, flag;

		for(size_t i=0; i<strlen(input); i++)
		{
			if((input[i]>=65 && input[i]<=90)|| (input[i]>=97 && input[i]<=122))
				flag = 1;
			else
			{
				count += flag;
				flag = 0;
			}
		}

		printf("%lu\n", count);
	}

	return 0;
}
