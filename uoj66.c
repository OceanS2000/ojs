#include<stdio.h>

int happiness(int n)
{
	int exptwo[32], i, hap = 0;
	for(i = 0; i < 32; i++)
	{
		if(i == 0){exptwo[i] = 1; continue;}
		exptwo[i] = 2*exptwo[i - 1];
	}
	for(i = 0; i < 32 && n > 0; i++)
	{
		if(n % 2 != 0) hap += (exptwo[i] - 1);
		n /= 2;
	}
	return hap;
}

int main()
{
	int n, i, max, hap;
	scanf("%d", &max);
	for(i = 0; i < max; i++)
	{
		scanf("%d", &n);
		hap = happiness(n);
		printf("%d\n",hap);
	}
	return 0;
}
