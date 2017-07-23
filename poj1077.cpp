#include<cstdio>
int bound,loc[9][2]={2,2,0,0,0,1,0,2,1,0,1,1,1,2,2,0,2,1};
bool flag;
int p[127];
char d[]={'u','d','l','r'};
#define abs(a)         (a>0?a:-(a))
#define min(a,b)       (a>b?b:a)
#define P(i,j)         ((i)<<2|(j))
#define Manhattan(i,j) if(a[P(i,j)]){\
	                 sum1 += abs((i) - loc[a[P(i,j)]][0]) + abs((j) - loc[a[P(i,j)]][1]);}
struct D
{
	int position,a[12];
	int H()
	{
		int sum1 = 0;
		for(int i = 0; i < 3;i++)
			for(int j = 0; j < 3; j++)
				Manhattan(i,j);
		return sum1;
	}
}s;

#define ins(x0,y0,dir) {\
	s.position=np=P(x0,y0),s.a[op]=s.a[np],s.a[np]=0,tmp=dfs(x+1,dir);\
	if(flag)    return p[x]=(dir),tmp;\
	if(nxt>tmp) nxt=tmp;\
	s.a[np]=s.a[op],s.a[op]=0;}

int dfs(int x, int las)
{
	int hv = s.H();
	if (x + hv > bound)
		return x + hv;
	if (hv == 0)
		return flag = true, x;
	int op = s.position, zx = op>>2, zy = op&3, nxt = 127, tmp, np;
	if(zx > 0 && las != 1) ins(zx - 1, zy, 0);
	if(zy > 0 && las != 3) ins(zx, zy -1 , 2);
	if(zx < 2 && las != 0) ins(zx + 1, zy, 1);
	if(zy < 2 && las != 2) ins(zx, zy + 1, 3);
	return s.position=op,nxt;
}

int main()
{
	char ss[10];
	while(scanf("%s", ss) != EOF)
	{
		flag = false;
		for(int i = 0; i < 12; i += 4)
			for(int j = 0; j < 3; j++)
			{
				if(i != 0 || j != 0)
					scanf("%s", ss);
				if(ss[0] == 'x')
					s.position = i|j,s.a[i|j] = 0;
				else    s.a[i|j] = ss[0] - '0';
			}
		bool k = false;
		for(int i = 0; i < 9; i++)
		{
			if(s.a[P(i / 3, i % 3)] == 0) continue;
			for(int j = 0; j < i; j++)
			{
				if(s.a[P(j / 3, j % 3)] == 0) continue;
				if(s.a[P(j / 3, j % 3)] > s.a[P(i / 3, i % 3)]) k = !k;
			}
		}
		if (k) {printf("unsolvable\n");continue;}
		for(bound = s.H(); !flag; bound = dfs(0, -1));
		for(int i = 0; i < bound; i++)
			putchar(d[p[i]]);
		putchar('\n');
	}
	return 0;
}


