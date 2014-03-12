#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LOCAL
#define N 6
char color[N];
char judge[N];
char tempt[2*N];

int IsSame(int a, int b) // 1 6/ 3 4/ 2 5
{
	int re_a = 7 - a, re_b = 7 - b;
	if (color[a - 1] == judge[b - 1])
	{
		if (color[re_a - 1] == judge[re_b - 1])
			return 1;
		else
			return 0;
	}
	else
	{
		if (color[a - 1] == judge[re_b - 1])
		{
			if (color[re_a - 1] == judge[b - 1])
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
}

int IsRotate(int a, int b)
{
	int re_a = 7 - a, re_b = 7 - b, t;
	char c1[4], c2[4];
	int i, j = 0;
	for (i = 0; i < 6; i++)
	{
		if((i == a - 1)||(i == re_a - 1))
			continue;
		c1[j++] = color[i];
	}
	j = 0;
	for (i = 0; i < 6; i++)
	{
		if((i == b - 1)||(i == re_b - 1))
			continue;
		c2[j++] = judge[i];
	}
	t = c1[2]; c1[2] = c1[3]; c1[3] = t;
	t = c2[2]; c2[2] = c2[3]; c2[3] = t;
	for (i = 0; i < 4; i++)
	{
		if ((c1[(0+i)%4] == c2[0])&&(c1[(1+i)%4] == c2[1])&&(c1[(2+i)%4] == c2[2])&&(c1[(3+i)%4] == c2[3]))
			return 1;
	}
	return 0;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	while(scanf("%s", tempt) != EOF)
	{
		memcpy(color, tempt, N*sizeof(char));
		memcpy(judge, tempt+N, N*sizeof(char));
		int k, m, flag = 0;
		for (k = 1; k < 4; k++)
		{
			for (m = 1; m < 4; m++)
			{
				if (IsSame(k, m)&&IsRotate(k, m))
				{
					printf("TRUE\n");
					flag = 1;
					break;
				}
			}
			if (flag)
				break;
		}
		if (!flag)
			printf("FALSE\n");
	}
	return 0;
}