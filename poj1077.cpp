#include<cstdio>
int bound,loc[9][2]={2,2,0,0,0,1,0,2,1,0,1,1,1,2,2,0,2,1};
/*loc二元数组保存终态坐标  x  y------->
 0     1  ...          0|   0 1 ...
(2,2)(0,0)...          1|
                     ...^*/
bool flag;//有解性标记
int step[127];//路径保存
char d[]={'u','d','l','r'};//方向约定：0=up，1=down，2=left，3=right
#define abs(a)         (a>0?a:-(a))
#define min(a,b)       (a>b?b:a)
#define P(i,j)         ((i)<<2|(j))//压缩坐标（i，j）为一个int
#define Manhattan(i,j) if(a[P(i,j)]){\
	                 sum1 += abs((i) - loc[a[P(i,j)]][0]) + abs((j) - loc[a[P(i,j)]][1]);}
//计算曼哈顿距离的函数（宏）
struct D
{
	int position,a[12];//a是盘面数值，position是空位位置
	int H()
	{
		int sum1 = 0;
		for(int i = 0; i < 3;i++)
			for(int j = 0; j < 3; j++)
				Manhattan(i,j);
		return sum1;
	}//计算曼哈顿距离作为ida×的估值函数
}s;

#define ins(x0,y0,dir) {\
	s.position=np=P(x0,y0),s.a[op]=s.a[np],s.a[np]=0,tmp=dfs(x+1,dir);\
	if(flag)    return step[x]=(dir),tmp;\
	if(nxt>tmp) nxt=tmp;\
	s.a[np]=s.a[op],s.a[op]=0;}
/*宏里面不能加注释，这里说。
 第一行根据参数指定的方向（direction）算出np（new position），和op（old）交换，开启下一轮递归
 第二行如果返回结束，那么给路径的相应深度写入方向(x = 深度)毫无可读性:-P
 第三行算出下一轮的maxH？？
 第四行回退，position再次变成op……（没找到解，当然退回去，到dfs里开始下一轮）*/
//两个函数轮回递归好玩么？？
int dfs(int x, int las)
{
	int hv = s.H();
	if (x + hv > bound)
		return x + hv;//超过bound，throw new OutOfBoundException，啊不，回退。
	if (hv == 0)
		return flag = true, x;//H=0,已达最终状态，结束！
	int op = s.position, zx = op>>2, zy = op&3,/*把op展开为0的坐标*/ nxt = 127, tmp, np;
	if(zx > 0 && las != 1) ins(zx - 1, zy, 0);
	if(zy > 0 && las != 3) ins(zx, zy -1 , 2);
	if(zx < 2 && las != 0) ins(zx + 1, zy, 1);
	if(zy < 2 && las != 2) ins(zx, zy + 1, 3);
	return s.position=op,nxt;//四个方向搜索，搜完回退
}

int main()
{
	char ss[10];
	while(scanf("%s", ss) != EOF)
	{
		flag = false;//开始读入初始状态
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
			{
				if(i != 0 || j != 0)
					scanf("%s", ss);
				if(ss[0] == 'x')
					s.position = i<<2|j,s.a[i<<2|j] = 0;
				else    s.a[i<<2|j] = ss[0] - '0';//i<<2|j用位运算将(i,j)压缩为数组a索引
			}//读入数据，循环开始读了1位，因此if人工去掉一位。
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
		if (k) {printf("unsolvable\n");continue;}//可解性计算。详见Wolfram MathWorld对此的讨论
		for(bound = s.H(); !flag; bound = dfs(0, -1));//主循环。为了缩短长度丧心病狂……
		for(int i = 0; i < bound; i++)
			putchar(d[p[i]]);//输出解
		putchar('\n');
	}
	return 0;
}


