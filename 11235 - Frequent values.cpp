// ----------
// UVa 11235 - Frequent values
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2176
// https://www.udebug.com/UVa/11235
// ----------

#include <bits/stdc++.h>

using namespace std;

#define SIZE 100005

int n, q;
int arr[SIZE];
int fre[SIZE], r[SIZE], l[SIZE];
int st[SIZE*4];

void build()
{
	// arr
	for(int i=1; i<=n; i++)
			scanf("%d", &arr[i]);
	
	// left	
	int tmp = arr[1];
	l[0] = 1;
	for(int i=1; i<=n; i++)
	{
		if(arr[i] != tmp)
		{
			l[i] = i;
			tmp = arr[i];
		}
		else
			l[i] = l[i-1];
	}

	// right & fre
	tmp = arr[n];
	r[n+1] = n;
	for(int i=n; i>=1; i--)
	{
		if(arr[i] != tmp)
		{
			r[i] = i;
			tmp = arr[i];
		}
		else
			r[i] = r[i+1];

		fre[i] = r[i] - l[i] + 1;
	}	
}

void st_build(int now, int ls, int rs)
{
	if(ls == rs)
		st[now] = fre[ls];
	else
	{
		st_build(now*2, ls, (ls+rs)/2);
		st_build(now*2+1, (ls+rs)/2+1, rs);

		st[now] = max(st[now*2], st[now*2+1]);
	}
}

int query(int now, int ls, int rs, int begin, int end)
{
	int mid = (begin+end)/2;
	int ret = 0;

	if(ls <= begin && rs >= end)
		return st[now];
	
	if(ls < mid)
		ret = max(ret, query(now*2, ls, rs, begin, mid));
	
	if(rs > mid)
		ret = max(ret, query(now*2+1, ls, rs, mid+1, end));

	return ret;
}

void find(int ls, int rs)
{
	int quan = 0;

	if(arr[ls] != arr[rs])
	{
		if(ls > l[ls])
		{
			quan = r[ls] - ls + 1;
			ls = r[ls] + 1;
		}

		if(rs < r[rs])
		{
			quan = max(quan, rs - l[rs] + 1);
			rs = l[rs] - 1;
		}

		if(ls < rs)
		{
			quan = max(quan, query(1, ls, rs, 1, n));
		}

	}
	else
		quan = rs - ls + 1;

	printf("%d\n", quan);
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

	while(scanf("%d", &n) && n)
	{
		scanf("%d", &q);

		build();
		st_build(1, 1, n);

		int ls, rs;

		for(int i=0; i<q; i++)
		{
			scanf("%d %d", &ls, &rs);
			find(ls, rs);
		}

	}

	exit(0);
}
