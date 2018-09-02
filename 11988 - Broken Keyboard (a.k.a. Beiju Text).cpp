// ----------
// UVa 11988 - Broken Keyboard (a.k.a. Beiju Text)
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3139
// https://www.udebug.com/UVa/11988
// ----------

#include <cstdio>
#include <cstring>
#include <list>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	char str[100000];

	while(scanf("%s", str) != EOF)
	{
		list<char> input;
		list<char>::iterator it = input.begin();
		int len = strlen(str);

		for(int i=0; i<len; i++)
		{
			if(str[i] == '[')
			{
				it = input.begin();
			}
			else if(str[i] == ']')
			{
				it = input.end();
			}
			else
			{
				input.insert(it, str[i]);
			}
		}

		for(it=input.begin(); it!=input.end(); it++)
		{
			printf("%c", *it);
		}
		printf("\n");
	}

	return 0;
}
