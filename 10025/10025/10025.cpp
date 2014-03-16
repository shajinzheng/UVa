#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LOCAL
double num;
int lines;

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	scanf("%d", &lines);
	int i;
	for (i = 0; i < lines; i++)
	{
		if (i != 0)
			printf("\n\n");
		scanf("%lf", &num);
		num = (num > 0)?num:(0 - num);
		int n = 1, flag = 0;
		while(n*(n+1)/2 < num)
			n++;
		if (n*(n+1)/2 == num)
		{
			printf("%d", n);
			continue;
		}
		while(!flag)
		{
			int t = n*(n+1)/2 - num;
			if (t%2 != 0)
			{
				n++;
				continue;
			}
			int res = (n*(n+1)/2 - num)/2;
			int j;
			for (j = 1; j <= n; j++)
			{
				if ((res >= j)&&(res <= n))
				{
					flag = 1;
					break;
				}
				else
					res = res - j;
			}
			n++;
		}
		printf("%d", n - 1);
	}
	return 0;
}