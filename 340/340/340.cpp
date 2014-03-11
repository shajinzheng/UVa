#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  LOCAL
#define MAXN 1200
#define MAXM 150
int code[MAXN];
int guess[MAXM][MAXN];
int flagCode[MAXN];
int flagGuess[MAXN];
int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	int n, times = 0;
	scanf("%d", &n);
	while (n != 0) //loop for Game 1/ Game 2
	{
		times++;
		int NumStrong, NumWeak, NumGuess = 0;
		int l;
		for (l = 0; l < n; l++)
			scanf("%d", &code[l]);
		while(1) // loop for every guess in Game1/ Game2
		{
			for (l = 0; l < n; l++)
				scanf("%d", &guess[NumGuess][l]);
			if (guess[NumGuess][0] == 0)
				break;
			NumGuess++;
		}
		printf("Game %d:\n", times);
		int k;
		for (k = 0; k < NumGuess; k++)
		{
			NumStrong = 0; NumWeak = 0;
			memset(flagCode, 0, n*sizeof(int));
			memset(flagGuess, 0, n*sizeof(int));
			int i, j;
			for (i = 0; i < n; i++) // calculate NumStrong
			{
				if (code[i] == guess[k][i])
				{
					flagCode[i] = 1; flagGuess[i] = 1;
					NumStrong++;
				}
			}
			for (i = 0; i < n; i++)// calculate NumWeak
			{
				for (j = 0; j < n; j++)
				{
					if (!flagCode[i]&&!flagGuess[j])
					{
						if (code[i] == guess[k][j])
						{
							flagCode[i] = 1; flagGuess[j] = 1;
							NumWeak++;
						}
					}
				}
			}
			printf("    (%d,%d)\n", NumStrong, NumWeak);
		}
		scanf("%d", &n);
	}
	return 0;
}

