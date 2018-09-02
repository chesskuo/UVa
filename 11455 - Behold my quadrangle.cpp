// ----------
// UVa 11455 - Behold my quadrangle
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2450
// https://www.udebug.com/UVa/11455
// ----------

#include <cstdio>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	int times;

	scanf("%d", &times);

	for(int i=0; i<times; i++)
	{
		long int input[4];

		for(int j=0; j<4; j++)
			scanf("%ld", &input[j]);

		if(input[0]==input[1] && input[1]==input[2] && input[2]==input[3])
			printf("square\n");
		else if(input[0]==input[2] && input[1]==input[3])
			printf("rectangle\n");
		else if(input[0]==input[1] && input[2]==input[3])
			printf("rectangle\n");
		else if(input[0]==input[3] && input[1]==input[2])
			printf("rectangle\n");
		else
		{
			for(int j=0; j<4-1; j++)
			{
				for(int k=0; k<4-1-j; k++)
					if(input[k] > input[k+1])
					{
						long int tmp;

						tmp = input[k];
						input[k] = input[k+1];
						input[k+1] = tmp;
					}
			}

			long int count=0;

			for(int j=0; j<3; j++)
				count += input[j];

			if(count <= input[3])
				printf("banana\n");
			else
				printf("quadrangle\n");
		}
	}

	return 0;
}
