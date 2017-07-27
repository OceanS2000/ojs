#include<cstdio>

bool isPrime(int N)
{
	int i;
	if(N <= 1) return false;
	for(i = 2; i * i <= N; i++)
		if(N % i == 0) return false;
	return true;
}

int count[26];

int main()
{
	char ch;
	for(int i = 0; i < 26; i++)
		count[i] = 0;
	for(ch = getchar(); ch >= 'a' && ch <= 'z'; ch = getchar())
		count[ch - 'a']++;
	int minc = 100, maxc = 0;
	for(int i = 0; i < 26; i++)
	{
		if(count[i] < minc && count[i] != 0) minc = count[i];
		if(count[i] > maxc) maxc = count[i];
	}
	int d = maxc - minc;
	if(isPrime(d)) printf("Lucky Word\n%d\n", d);
	else           printf("No Answer\n%d\n", 0);
	return 0;
}
