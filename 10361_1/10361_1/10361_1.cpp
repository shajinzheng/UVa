#include<stdio.h>
#include<string.h>
void print(char *str1,char *str2)
{
	int nn1,nn2;
	int n1,n2,n3,n4;
	int leap,i;
	nn1=strlen(str1);
	nn2=strlen(str2);
	leap=0;
	for(i=0;i<nn1;i++)
	{
		if(leap==0)
		{
			if(str1[i]=='<')
				n1=i;
			if(str1[i]=='>')
			{
				n2=i;
				leap=1;
			}
		}
		else
		{
			if(str1[i]=='<')
				n3=i;
			if(str1[i]=='>')
				n4=i;
		}
	}
	for(i=0;i<nn1;i++)
	{
		if(i!=n1&&i!=n2&&i!=n3&&i!=n4)
			printf("%c",str1[i]);
	}
	printf("\n");
	for(i=0;i<nn2;i++)
	{
		if(str2[i]=='.')
		{
			for(i=n3+1;i<n4;i++)
			{
				printf("%c",str1[i]);
			}
			for(i=n2+1;i<n3;i++)
			{
				printf("%c",str1[i]);
			}
			for(i=n1+1;i<n2;i++)
			{
				printf("%c",str1[i]);
			}
			for(i=n4+1;i<nn1;i++)
			{
				printf("%c",str1[i]);
			}
			break;
		}
		else
		{
			printf("%c",str2[i]);
		}
	}
	printf("\n");
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	char str1[10000];
	char str2[10000];
	scanf("%d%*c",&n);
	while(n--)
	{
		gets(str1);
		gets(str2);
		print(str1,str2);
	}
	return 0;
}
