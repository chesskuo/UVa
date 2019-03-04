// ----------
// UVa 10340 - All in All
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1281
// https://www.udebug.com/UVa/10340
// ----------

#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	string s, t;

	while(cin >> s >> t)
	{
		bool out = false;
		int si = 0;

		for(int i=0; i<t.length(); i++)
			if(s[si] == t[i])
				si++;

		if(si == s.length())
			out = true;

		if(out)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}
