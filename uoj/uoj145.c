#include<stdio.h>

int board[39<<6|39];

#define ROLL(x, y) ((x)<<6|(y))

inline int ins(int i,int n)
{
	int zx = i>>6, zy = i&63;
	if(zx == 0)
	{
		if(zy == n)return ROLL(1, n);
		else       return ROLL(n, zy + 1);
	}
	else
	{
		if(zy == n)return ROLL(zx - 1, 0);
		else
		{
			if(board[ROLL(zx-1,zy+1)] == 0) return ROLL(zx-1,zy+1);
			else                            return ROLL(zx+1,zy);
		}
	}
}

int main()
{
	int n, i = 1, j;
	scanf("%d",&n);
	int np = ROLL(0, n/2), op;
	for(; i <= n * n; i++)
	{
		board[np] = i;
		op = np;
		np = ins(op, n - 1);
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d",board[ROLL(i,j)]);
			if(j < n-1)putchar(' ');
		}
		printf("\n");
	}
	return 0;
}

