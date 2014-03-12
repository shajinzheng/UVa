#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LOCAL
#define MAXN 20000
int marble[MAXN];
int query[MAXN];

int compare(const void * a, const void * b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	int times = 0, n, q;
	scanf("%d", &n); scanf("%d", &q);
	while ((n != 0)&&(q != 0))
	{
		times++;
		printf("CASE# %d:\n", times);
		int i, j;
		for (i = 0; i < n; i++)
			scanf("%d", &marble[i]);
		for (i = 0; i < q; i++)
			scanf("%d", &query[i]);
		qsort(marble, n, sizeof(int), compare);
		for (i = 0; i < q; i++)
		{
			int found = 0;
			for (j = 0; j < n; j++)
			{
				if(marble[j] == query[i])
				{
					found = 1;
					break;
				}
			}
			if(found)
				printf("%d found at %d\n", query[i], j+1);
			else
				printf("%d not found\n", query[i]);
		}
		scanf("%d", &n); scanf("%d", &q); getchar();
	}
	return 0;
}