#include<cstdio>
using namespace std;

int score[5][5] = {{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int a[210], b[210], sa = 0, sb = 0;

inline int readint()
{
	int x = 0, sign = 1;
	char ch = getchar();
	for(;ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') sign = -1;
	for(;ch >='0' && ch <='9'; ch = getchar()) x = x * 10 + ch - '0';
	return x * sign;
}

int main()
{
	int n = readint(), maxa = readint(), maxb = readint();
	for(int i = 0; i < maxa; i++)
		a[i] = readint();
	for(int i = 0; i < maxb; i++)
		b[i] = readint();
	for(int i = 0; i < n; i++)
	{
		sa += score[a[i % maxa]][b[i % maxb]];
		sb += score[b[i % maxb]][a[i % maxa]];
	}
	printf("%d %d\n", sa, sb);
	return 0;
}

