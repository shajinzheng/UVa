#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define  LOCAL
#define MAXN 1200
char code[MAXN];
char guess[MAXN];
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
		int NumStrong, NumWeak;
		getchar();
		fgets(code, MAXN, stdin);
		printf("Game %d:\n", times);
		while(1) // loop for every guess in Game1/ Game2
		{
			NumStrong = 0; NumWeak = 0;
			memset(flagCode, 0, n*sizeof(int));
			memset(flagGuess, 0, n*sizeof(int));
			fgets(guess, MAXN, stdin);
			if (guess[0] == '0')
				break;
			int i, j;
			for (i = 0; i < n; i++) // calculate NumStrong
			{
				if (code[2*i] == guess[2*i])
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
						if (code[2*i] == guess[2*j])
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