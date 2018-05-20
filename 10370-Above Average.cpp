/*******************************************************************************************************
* UVa 10370 Above Average                                                                              *
* https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1311 *
* https://www.udebug.com/UVa/10370                                                                     *
*******************************************************************************************************/
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	short times;

	scanf("%hi", &times);

	for(int i=0; i<times; i++)
	{
		short total;

		scanf("%hi", &total);

		float input[total], ave=0, count=0;

		for(int j=0; j<total; j++)
		{
			scanf("%f", &input[j]);
			ave += input[j];
		}

		ave /= total;

		for(int j=0; j<total; j++)
			if(input[j] > ave)
				count++;
		
		printf("%.3f%%\n", count/total*100);
	}
	

	return 0;
}
