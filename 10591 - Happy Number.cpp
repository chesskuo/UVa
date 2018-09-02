// ----------
// UVa 10591 - Happy number
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1532
// https://www.udebug.com/UVa/10591
// ----------

#include <iostream>
#include <cstdio>

using namespace std;

long long int turtle(long long int num)
{
	long long int tmp = num;

	while(true)
	{
		long long int tmp2=tmp;
		tmp = 0;

		while(tmp2 > 0)
		{
			tmp = tmp + (tmp2%10) * (tmp2%10);
			tmp2 = tmp2 / 10;
		}

		return  tmp;
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	long long int input;
	int times;
	bool check;

	scanf("%d", &times);

	for(int i=0; i<times; i++)
	{
		scanf("%lld", &input);

		long long int temp1=input;
		long long int temp2=input;
		
		while(true)
		{
			temp1 = turtle(temp1);
			temp2 = turtle(turtle(temp2));
			
			if(temp1==1 || temp2==1)
			{
				check = true;
				break;
			}
			else if(temp1 == temp2)
			{
				check = false;
				break;
			}
		}

		if(check == true)
			printf("Case #%d: %lld is a Happy number.\n", i+1, input);
		else
			printf("Case #%d: %lld is an Unhappy number.\n", i+1, input);
	}

	return 0;
}
