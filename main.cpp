/*******************************************************************************************************
* UVa 10038 - Jolly Jumpers                                                                            *
* https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=979  *
* https://www.udebug.com/UVa/10038                                                                     *
*******************************************************************************************************/
#include <cstdio>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	int n;

	while(scanf("%d", &n) != EOF)
	{
		int num[n]={0};
		int minus[n-1]={0};
		bool check=true;

		for(int i=0; i<n; i++)
			scanf("%d", &num[i]);

		for(int j=0; j<n-1; j++)
		{
			if(num[j+1] < num[j])
				minus[j] = num[j] - num[j+1];
			else
				minus[j] = num[j+1] - num[j];
		}

		for(int j=0; j<n-1-1; j++)
			for(int k=0; k<n-1-1; k++)
			{
				int tmp;

				if(minus[k] > minus[k+1])
				{
					tmp = minus[k];
					minus[k] = minus[k+1];
					minus[k+1] = tmp;
				}
			}

		for(int j=0; j<n-1; j++)
			if(minus[j] != j+1)
			{
				check = false;
				break;
			}

		if(check == false)
			printf("Not jolly\n");
		else if(check == true)
			printf("Jolly\n");
	}

	return 0;
}