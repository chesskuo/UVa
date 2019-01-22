// ----------
// UVa 10062 - Tell me the frequencies!
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1003
// https://www.udebug.com/UVa/10062
// ----------

#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	string a;
	int cas = 0;

	while(getline(cin, a))
	{
		if(cas > 0)
			printf("\n");
		cas++;

		map<char, int> m;
		int maxn = 0;

		for(int i=0; i<a.length(); i++)
		{
			m[a[i]]++;

			if(m[a[i]] > maxn)
				maxn = m[a[i]];
		}

		for(int i=1; i<=maxn; i++)
			for(int j=128; j>=32; j--)
				if(m[j] == i)
					printf("%d %d\n", j, m[j]);
	}

	return 0;
}
