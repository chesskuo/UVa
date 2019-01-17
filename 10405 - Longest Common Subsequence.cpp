// ----------
// UVa 10405 - Longest Common Subsequence
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1346
// https://www.udebug.com/UVa/10405
// ----------

#include <bits/stdc++.h>

using namespace std;

int lcs[1001][1001];

int main()
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	string a, b;

	while(getline(cin, a))
	{
		getline(cin, b);

		int lena = a.length();
		int lenb = b.length();

		for(int i=0; i<=lena; i++)
			lcs[i][0] = 0;
		for(int i=0; i<=lenb; i++)
			lcs[0][i] = 0;

		for(int i=1; i<=lena; i++)
			for(int j=1; j<=lenb; j++)
			{
				if(a[i-1] == b[j-1])
					lcs[i][j] = lcs[i-1][j-1] + 1;
				else
					lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
			}

		printf("%d\n", lcs[lena][lenb]);
	}

	return 0;
}
