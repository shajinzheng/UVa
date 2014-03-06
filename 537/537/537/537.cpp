#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define LOCAL
#define MAXN 200
char cas[MAXN];
char value[MAXN];
char CharConcept[] = "PUI"; 
char unit[] = "WVA";
char prefix[] = "mkM";
int used[3];
double concept[3];
int power[3] = {-3, 3, 6};
int main()
{
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int NumOfCase;
	scanf("%d", &NumOfCase);
	getchar();
	int i;
	for (i = 0; i < NumOfCase; i++)
	{
		concept[0] = concept[1] = concept[2] = 0;
		used[0] = used[1] = used[2] = 0;
		fgets(cas, MAXN, stdin);
		char * ptr1, * ptr2, *t;
		double val;
		int num = 2;
		ptr1 = strchr(cas, '=');
		ptr2 = strchr(ptr1+1, '=');
		while(num--)
		{
			int iter = 0;
			memset(value, 0, sizeof(value));
			t = (num == 1)?ptr1:ptr2;
			t += 1;
			while ((!strchr(&prefix[0], *t))&&(!(strchr(&unit[0], *t))))
			{
				value[iter++] = *t;
				t++;
			}
			if (!strchr(&prefix[0], *t))
			{
				switch(*t)
				{
				case 'W': concept[0] = atof(value); used[0] = 1; break;
				case 'V': concept[1] = atof(value); used[1] = 1; break;
				case 'A': concept[2] = atof(value); used[2] = 1; break;
				}
			}
			else
			{
				int p;
				switch(*t)
				{
				case 'm': p = power[0]; break;
				case 'k': p = power[1]; break;
				case 'M': p = power[2]; break;
				}
				double sha, jin;
				switch(*(t+1))
				{
				case 'W': concept[0] = atof(value)*pow(10.0, p); used[0] = 1; break;
				case 'V': concept[1] = atof(value)*pow(10.0, p); used[1] = 1; break;
				case 'A': concept[2] = atof(value)*pow(10.0, p); used[2] = 1; break;
				}
				
			}
		}
		printf("Problem #%d\n", i+1);
		int k = 0;
		while (used[k] != 0)
			k++;
		switch (k)
		{
		case 0: concept[0] = concept[1]*concept[2]; break;
		case 1: concept[1] = concept[0]/concept[2]; break;
		case 2: concept[2] = concept[0]/concept[1]; break;
		}
		printf("%c=%.2f%c\n", CharConcept[k], concept[k], unit[k]);
		printf("\n");
	}
	return 0;
}