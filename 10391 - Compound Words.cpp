// ----------
// UVa 10391 - Compound Words
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1332
// https://www.udebug.com/UVa/10391
// ----------

#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <set>

using namespace std;

int main()
{
	#ifdef DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	set<string> dic, ans;
	string str;

	while(cin >> str)
		dic.insert(str);

	for(set<string>::iterator it=dic.begin(); it!=dic.end(); it++)
	{
		set<string>::iterator it2 = it;

		while(++it2 != dic.end())
		{
			int x = (*it).length(), y = (*it2).length();

			if(x < y && (*it) == (*it2).substr(0, x))
			{
				string r = (*it2).substr(x, y-x);

				if(dic.count(r) == 1)
					ans.insert(*it2);
			}
		}
	}

	for(set<string>::iterator it=ans.begin(); it!=ans.end(); it++)
		cout << *it << "\n";

	return 0;
}
