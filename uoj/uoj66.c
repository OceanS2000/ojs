#include<stdio.h>

inline int happiness(int n)
{
	int hap = n;
	while(n != 0)
	{
		if(n % 2 != 0) hap--;
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
