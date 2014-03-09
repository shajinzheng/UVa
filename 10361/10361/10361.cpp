#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXN 120
#define NumOfParts 5
char line[MAXN];
char parts[NumOfParts][MAXN];
#define sha
int main()
{
	#ifdef sha
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int NumOfPoem;
	scanf("%d", &NumOfPoem);
	getchar();
	int i;
	for (i = 0; i < NumOfPoem; i++)
	{
		memset(line, 0, sizeof(line));
		fgets(line, MAXN, stdin);
		char * pre = line, *ptr = line;
		int t = NumOfParts - 1;
		while(t--)
		{
			ptr = (t%2 == 0)?(strchr(pre, '>')):(strchr(pre, '<'));
			memset(&parts[NumOfParts-2-t][0], 0, sizeof(parts[NumOfParts-2-t]));
			memcpy(&parts[NumOfParts-2-t][0], pre, (ptr-pre)*sizeof(char));
			pre = ptr + 1;
		}
		memset(&parts[NumOfParts-1][0], 0, sizeof(parts[NumOfParts-1]));
		memcpy(&parts[NumOfParts-1][0], pre, (line+strlen(line)-pre-1)*sizeof(char));
		memset(line, 0, sizeof(line));
		fgets(line, MAXN, stdin);
		char * s = strchr(line, '.');
		*s = '\0';
		printf("%s%s%s%s%s\n", parts[0], parts[1], parts[2], parts[3], parts[4]);
		printf("%s%s%s%s%s", line, parts[3], parts[2], parts[1], parts[4]);
		printf("\n");
	}
	return 0;
}