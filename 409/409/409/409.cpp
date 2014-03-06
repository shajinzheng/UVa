#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LOCAL
#define MAXN 20
#define MAXM 100
char KeyWords[MAXN][MAXN];
char Excuses[MAXN][MAXM];
int times[MAXN];

int strfind(char kw[], char ex[])
{
	char tempt[MAXM];
	char temptKw[MAXN];
	memcpy(tempt+1, ex, strlen(ex)+1);
	memcpy(temptKw, kw, strlen(kw)-1);
	temptKw[strlen(kw)-1] = 0;
	char * ptr = tempt;
	int l = 0;
	tempt[0] = ' ';
	while(tempt[l])
	{
		tempt[l] = tolower(tempt[l]);
		l++;
	}
	int times = 0;
	while(1)
	{
		if (ptr = strstr(ptr, temptKw))
		{
			if((isalpha(*(ptr-1))==0)&&(isalpha(*(ptr+strlen(temptKw)))==0))
				times++;
			ptr = ptr + 1;
		}
		else 
			break;
	}
	return times;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int set = 0;
	int firsttime = 1;
	while (fgets(KeyWords[0], MAXN, stdin) != NULL)
	{
		set++;
		int NumOfKW = atoi(&KeyWords[0][0]);
		int NumOfEX = atoi(&KeyWords[0][1]);
		memset(&KeyWords[0][0], 0, sizeof(KeyWords[0]));
		int i,j;
		for (i = 0; i<NumOfKW; i++)
		{
			memset(&KeyWords[i][0], 0, sizeof(KeyWords[0]));
			fgets(KeyWords[i], MAXN, stdin);
		}
		for (j = 0; j<NumOfEX; j++)
		{
			memset(&Excuses[j][0], 0, sizeof(Excuses[0]));
			fgets(Excuses[j], MAXM, stdin);
		}
		for (i = 0; i < NumOfEX; i++)
		{
			times[i] = 0;
			for (int j = 0; j < NumOfKW; j++)
				times[i] += strfind(&KeyWords[j][0], &Excuses[i][0]);
		}
		int max = 0;
		for (i = 0; i < NumOfEX; i++)
			max = (max-times[i]>0)?max:times[i];
		printf("Excuse Set #%d\n", set);
		int t = 0;
		for (i = 0; i < NumOfEX; i++)
		{
			if (times[i] == max)
				t++;
		}
		for (i = 0; i < NumOfEX; i++)
		{
			if (times[i] == max)
				printf("%s", Excuses[i]);
		}
		printf("\n");
	}
	return 0;
}