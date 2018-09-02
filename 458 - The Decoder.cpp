// ----------
// UVa 458 - The Decoder
// https://uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=399
// https://www.udebug.com/UVa/458
// ----------

#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	char input[1000];

	while(gets(input) != NULL)
	{
		for(int i=0; i<strlen(input); i++)
		{
			input[i] -= 7;
			printf("%c", input[i]);
		}

		printf("\n");
	}

	return 0;
}
