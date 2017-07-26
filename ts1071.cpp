#include<cstdio>

inline int read()
{
	int x = 0, sign = 1;
	char ch = getchar();
	for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') sign = -1;
	for(; ch >='0' && ch <='9'; ch = getchar()) x = x * 10 + ch - '0';
	return x * sign;
}

struct Node
{
	int num, sco;
}s[5001], aux[5001];

void merger(int lo, int mid, int hi)
{
	int i = lo, j = mid + 1, k;
	for(k = lo; k <= hi; k++)
		aux[k] = s[k];
	for(k = lo; k <= hi; k++)
	{
		if (i > mid)                      s[k] = aux[j++];
		else if (j > hi)                  s[k] = aux[i++];
		else if (aux[i].sco > aux[j].sco) s[k] = aux[i++];
		else                              s[k] = aux[j++];
	}
}

void sortr(int lo, int hi)
{
	if(lo >= hi) return;
	int mid = lo + (hi - lo)/ 2;
	sortr(lo, mid);
	sortr(mid + 1, hi);
	merger(lo, mid, hi);
}

void mergel(int lo, int mid, int hi)
{
	int i = lo, j = mid + 1, k;
	for(k = lo; k <= hi; k++)
		aux[k] = s[k];
	for(k = lo; k <= hi; k++)
	{
		if (i > mid)                      s[k] = aux[j++];
		else if (j > hi)                  s[k] = aux[i++];
		else if (aux[i].num < aux[j].num) s[k] = aux[i++];
		else                              s[k] = aux[j++];
	}
}

void sortl(int lo, int hi)
{
	if(lo >= hi) return;
	int mid = lo + (hi - lo)/ 2;
	sortl(lo, mid);
	sortl(mid + 1, hi);
	mergel(lo, mid, hi);
}


int main()
{
	int n = read(), m = read(), i, line;
	m = m + m / 2;
	for(i = 1; i <= n; i++)
	{
		s[i].num = -1 * read();
		s[i].sco = read();
	}
	sortl(1, n);
	sortr(1, n);
	line = s[m].sco;
	for(;s[m].sco == line; m++);
	m -= 1;
	printf("%d %d\n",line,m);
	for(i = 1 ; i <= m; i++)
		printf("%d %d\n", -1 * s[i].num,s[i].sco);
	return 0;
}

