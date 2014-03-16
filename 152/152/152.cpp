#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define  LOCAL
#define MAXM 6000
double tree[MAXM][3];
int results[10];
double delta;

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("a.txt", "w", stdout);
#endif
	int iter = 0;
	memset(results, 0, 10*sizeof(int));
	scanf("%lf%lf%lf", &tree[iter][0], &tree[iter][1], &tree[iter][2]);
	iter++;
	while(1)// 将全部的tree读进来
	{
		if (tree[iter - 1][0] + tree[iter - 1][1] + tree[iter - 1][2] < 1e-9)
			break;
		scanf("%lf%lf%lf", &tree[iter][0], &tree[iter][1], &tree[iter][2]);
		iter++;
	}
	int i, j;
	for (i = 0; i < iter; i++)//双重循环对于每一个tree，找到离它最近的tree的距离
	{
		double closest = 100000000;
		for (j = 0; j < iter; j++)
		{
			if (i != j)
			{
				delta = sqrt((tree[i][0] - tree[j][0]) * (tree[i][0] - tree[j][0]) + (tree[i][1] - tree[j][1]) * (tree[i][1] - tree[j][1]) + (tree[i][2] - tree[j][2]) * (tree[i][2] - tree[j][2]));
				closest = (closest > delta)?delta:closest;
			}
		}
		int idx = floor(closest);
		if ((idx >= 0)&&(idx <= 9))
			results[idx]++;
	}
	for (i = 0; i < 10; i++)
		printf("%4d", results[i]); //注意不能写成printf("   %d", results[i]);是不对的
	printf("\n");
	return 0;
}