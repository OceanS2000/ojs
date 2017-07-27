#include<stdio.h>

char a[40];
int length = 0;

inline void del(char ch)
{
	int i;
	for(i = 0; a[i] != ch; i++);
	for(; a[i] != '\0'; i++)
		a[i] = a[i + 1];
}

inline void ins(char pl, char it)
{
	int i, j;
	for(i = 39; a[i] != pl; i--);
	for(j = length; j > i; j--)
		a[j] = a[j - 1];
	a[i] = it;
}

inline void rpl(char pl, char it)
{
	int i = 0;
	while(i < length)
	{
		for(i = 0; a[i] != pl && i < length; i++);
		if(i != length) a[i] = it;
	}
}

int main()
{
	char ch, a1, a2;
	int i = 0;
	for(ch = getchar(); ch != '\n'; ch = getchar())
	{
		a[i] = ch;
		i++;
		length++;
	}
	ch = getchar();
	if(ch == 'D') 
	{
		scanf(" %c", &a1);
		del(a1);
	}
	if(ch == 'I') 
	{
		scanf(" %c %c", &a1, &a2);
		ins(a1, a2);
	}
	if(ch == 'R') {
		scanf(" %c %c", &a1, &a2);
		rpl(a1, a2);
	}
	printf("%s\n", a);
	return 0;
}


