#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LOCAL
#define MAXN 1000
char encry[MAXN];
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
		scanf("%s", encry);
		int len = strlen(encry);
		if (len <= 2)
			printf("+\n");
		else if((encry[len - 1] == '5')&&(encry[len - 2] == '3'))
			printf("-\n");
		else if((encry[0] == '9')&&(encry[len - 1] == '4'))
			printf("*\n");
		else if((encry[0] == '1')&&(encry[1] == '9')&&(encry[2] == '0'))
			printf("?\n");
	}
	return 0;
}