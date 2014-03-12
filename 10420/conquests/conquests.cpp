#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LOCAL
#define MAXLine 2100
#define MAXN  100
char country[MAXLine][MAXN];
char sort[MAXLine][MAXN];
char tempt[MAXN];
int times[MAXLine];

int compare(const void * a, const void * b)
{
	return memcmp(a, b, strlen((char *)a));
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	int n;
	scanf("%d", &n);
	getchar();
	memset(times, 0, sizeof(times));
	int i, iter = 0;
	for (i = 0; i < n; i++)
	{
		memset(tempt, 0, sizeof(tempt));
		scanf("%s", tempt);
		int j, ok = 1;
		for(j = 0; j < iter; j++)
		{
			if (!memcmp(tempt, &country[j][0], sizeof(tempt)))
			{
				times[j]++;
				ok = 0;
				break;
			}
		}
		if(ok)
		{
			memcpy(&country[iter][0], tempt, sizeof(tempt));
			times[iter]++;
			iter++;
		}
		fgets(tempt, MAXN, stdin);
	}
	memcpy(sort, country, sizeof(country));
	qsort(sort, iter, MAXN*sizeof(char), compare);
	for (i = 0; i < iter; i++)
	{
		printf("%s", sort[i]);
		int flag = 0, j;
		for (j = 0; j < iter; j++)
		{
			if(!memcmp(country[j], sort[i], strlen(sort[i])))
			{
				flag = times[j];
				break;
			}
		}
		printf(" %d\n", flag);
	}
	return 0;
}