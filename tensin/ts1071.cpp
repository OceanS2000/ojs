#include<cstdio>
#define ROLL(num, sco) ((num)<<8|(sco))
#define UNROLL(i, flag)(flag?i>>8:i&127)
inline int read()
{
	int x = 0, sign = 1;
	char ch = getchar();
	for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') sign = -1;
	for(; ch >='0' && ch <='9'; ch = getchar()) x = x * 10 + ch - '0';
	return x * sign;
}

int s[5001], aux[5001];

void merge(int lo, int mid, int hi, bool f)
{
	int i = lo, j = mid + 1, k;
	for(k = lo; k <= hi; k++)
		aux[k] = s[k];
	for(k = lo; k <= hi; k++)
	{
		if (i > mid)                      s[k] = aux[j++];
		else if (j > hi)                  s[k] = aux[i++];
		else if (UNROLL(aux[i],f) > UNROLL(aux[j],f)) s[k] = aux[i++];
		else                              s[k] = aux[j++];
	}
}

void sortr(int lo, int hi)
{
	if(lo >= hi) return;
	int mid = lo + (hi - lo)/ 2;
	sortr(lo, mid);
	sortr(mid + 1, hi);
	merge(lo, mid, hi, false);
}

void sortl(int lo, int hi)
{
	if(lo >= hi) return;
	int mid = lo + (hi - lo)/ 2;
	sortl(lo, mid);
	sortl(mid + 1, hi);
	merge(lo, mid, hi, true);
}


int main()
{
	int n = read(), m = read(), i, line;
	m = m + m / 2;
	for(i = 1; i <= n; i++)
		s[i] = ROLL(read(),read());
	sortl(1, n);
	sortr(1, n);
	line = UNROLL(s[m],false);
	for(; UNROLL(s[m],false) == line; m++);
	m--;
	printf("%d %d\n",line,m);
	for(i = 1 ; i <= m; i++)
		printf("%d %d\n", UNROLL(s[i],true), UNROLL(s[i],false));
	return 0;
}

