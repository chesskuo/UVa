// ----------
// UVa 10082 - WERTYU10082 - WERTYU
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1023
// https://www.udebug.com/UVa/10082
// ----------

#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	char keyboard[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	map<char, int> index;

	for(int i=0; i<strlen(keyboard); i++)
		index[keyboard[i]] = i;

	string str;

	while(getline(cin, str))
	{
		for(int i=0; i<str.length(); i++)
		{
			if(str[i] == ' ')
				printf(" ");
			else
				printf("%c", keyboard[index[str[i]]-1]);
		}
		printf("\n");
	}

	return 0;
}
