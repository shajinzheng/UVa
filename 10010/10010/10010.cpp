#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 50
#define MAXM 20
char matrix[MAXN][MAXN];
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

int lower(int c)
{
	if (c < 91)
		c = c - 65 + 97;
	return c;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int NumOfCase, i;
	scanf("%d", &NumOfCase);
	for (i = 0; i < NumOfCase; i++)
	{
		int col, row, j, k, NumOfWord;
		scanf("%d", &row);
		scanf("%d", &col);
		for (j = 0; j < row; j++)
			scanf("%s", matrix[j]);
		scanf("%d", &NumOfWord);
		for (k = 0; k < NumOfWord; k++)
		{
			char words[MAXM];
			int ok = 0;
			scanf("%s", words);
			int ss = 0;
			while((ss < row*col)&&(!ok))
			{
				int row_f = ss / col;
				int col_f = ss % col;
				if(lower(matrix[row_f][col_f]) == lower(words[0]))
				{
					int dir;
					for (dir = 0; dir < 8; dir++)
					{
						int _row = row_f, _col = col_f;
						int _dx = dx[dir];
						int _dy = dy[dir];
						char check[MAXM];
						memset(check, 0, sizeof(check));
						int tempt = 0;
						while ((_row >= 0)&&(_row < row)&&(_col >= 0)&&(_col < col))
						{
							check[tempt++] = matrix[_row][_col];
							_row += _dy;
							_col += _dx;
						}
						int len1 = strlen(words);
						int len2 = strlen(check);
						int s1, s2;
						for (s1 = 0; s1 < len1; s1++)
							words[s1] = lower(words[s1]);
						for (s2 = 0; s2 < len2; s2++)
							check[s2] = lower(check[s2]);
						if(!memcmp(check, words, strlen(words)))
						{
							ok = 1;
							printf("%d %d\n", row_f + 1, col_f + 1);
						}
					}
					
				}
				ss++;
			}	
		}
		if (i != NumOfCase-1)
			printf("\n");
	}
	return 0;
}