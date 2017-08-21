/*
ID: oceans21
LANG: C
TASK: beads
*/
#include<stdio.h>
#define MAXN 400

char necklace[MAXN];
int len;

static inline int mod(int n, int m)
{
    while(n < 0)
        n += m;
    return n % m;
}

int count(int p, int dir)
{
    char color = 'w';
    int i, n;
    i = dir>0?p%len:mod(p-1, len);
    for(n = 0; n < len; n++)
    {
        if(color == 'w' && necklace[i] != 'w')
            color = necklace[i];
        if (color != 'w' && necklace[i] != 'w' && necklace[i] != color)
            break;
    }
    return n;
}

int main()
{
#ifdef DEBUG
	FILE *in = stdin;
	FILE *out = stdout;
#else
	FILE *in = fopen("beads.in", "r");
	FILE *out = fopen("beads.out", "w");
#endif
    fscanf(in, "%d %s", &len, necklace);
    
    int m = 0, i, n;
    for(i = 0; i < len; i++)
    {
        n = count(i, 1) + count(i, -1);
        if(n > m)
            m = n;
    }

    if(m > len)
        m = len;

    fprintf(out,"%d\n", m);
    return 0;
}

