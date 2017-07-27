#include<cstdio>
#include<stack>

using namespace std;

stack<char>ans;
unsigned int i, cmd;

inline unsigned int read()
{
	unsigned int x = 0;
	char ch;
	for(ch = getchar(); ch < '0' || ch > '9'; ch = getchar());
	for(; ch >= '0' && ch <= '9'; ch = getchar())
		x = x * 10 + ch -'0';
	return x;
}

int main()
{
	char ch;
	i = read();
	cmd = read();
	if(i == 0) putchar('0'); //为零时若不处理，会输出空字符串！
	for(; i != 0; i /= cmd)
	{
		ch = i % cmd + '0';
		if(ch >= '0' && ch <= '9') ans.push(ch);
		else ans.push(ch + 7);
	}
	while(!ans.empty())
	{
		putchar(ans.top());
		ans.pop();
	}
	//其实手写一个数组定容栈就行，不过我懒……
	putchar('\n');
	return 0;
}
	
