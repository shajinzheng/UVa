#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define  LOCAL
#define MAXM 5100
double tree[MAXM][3];
int results[10];
double delta;

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	int iter = 0;
	memset(results, 0, 10*sizeof(int));
	scanf("%lf%lf%lf", &tree[iter][0], &tree[iter][1], &tree[iter][2]);
	iter++;
	while(tree[iter - 1][0] != 0)
	{
		scanf("%lf%lf%lf", &tree[iter][0], &tree[iter][1], &tree[iter][2]);
		iter++;
	}
	int i, j;
	for (i = 0; i < iter; i++)
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
		int idx = floor(closest + 0.1);
		if ((idx >= 0)&&(idx <= 9))
			results[idx]++;
	}
	for (i = 0; i < 10; i++)
		printf("    %d", results[i]);
	return 0;
}