// ----------
// UVa 673 - Parentheses Balance
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=614
// https://www.udebug.com/UVa/673
// ----------

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(NULL);

// ----------------------------------------

	int times;
	map<char, char> m;

	m['['] = ']';
	m['('] = ')';

	scanf("%d", &times);
	getchar();

	for(int t=0; t<times; t++)
	{
		char tmp[130];
		stack<char> s;
		bool check = true;

		gets(tmp);

		//cout << tmp << '\n';

		for(int i=0; i<strlen(tmp); i++)
		{
			if(tmp[i] == '[' || tmp[i] == '(')
				s.push(tmp[i]);
			else if(tmp[i] == ']' || tmp[i] == ')')
			{
				if(s.empty() || m[s.top()] != tmp[i])
				{
					check = false;
					break;
				}

				s.pop();
			}
		}

		if(!s.empty())
			check = false;

		printf("%s\n", (check) ? "Yes":"No");
	}

	exit(0);
}
