// ----------
// UVa 11503 - Virtual Friends
// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2498
// https://www.udebug.com/UVa/11503
// ----------

#include <bits/stdc++.h>

using namespace std;

#define SIZE 100005

int arr[SIZE];

void init(int n)
{
	for(int i=0; i<n; i++)
		arr[i] = -1;
}

int find(int x)
{
	return arr[x] < 0 ? x : (arr[x] = find(arr[x]));
}

void Union(int x, int y)
{
	x = find(x);
	y = find(y);

	if(x == y)
		return;

	if(arr[x] <= arr[y])
	{
		arr[x] += arr[y];
		arr[y] = x;
	}
	else
	{
		arr[y] += arr[x];
		arr[x] = y;
	}
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(NULL);

// ----------------------------------------

	int cas;

	cin >> cas;

	for(int t=0; t<cas; t++)
	{
		init(SIZE);

		int group;
		string a, b;
		map<string, int> m;
		int index = 1;

		cin >> group;

		for(int i=0; i<group; i++)
		{
			cin >> a >> b;

			if(m[a] == 0)
				m[a] = index++;
			if(m[b] == 0)
				m[b] = index++;

			Union(m[a], m[b]);

			cout << -arr[find(m[a])] << '\n';
		}
	}

	exit(0);
}
