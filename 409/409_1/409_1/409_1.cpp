#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define LOCAL
int Find(char a[],char b[])
{
	if(strcmp(a,b)==0)
		return 1;
	else
		return 0;
}        
int main()
{
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	char c,keyword[25][50],exword[50],excuse[25][3000],set=0;
	int i,j=0,k=0,flag=0,max[25],K=0,E=0,aux=0,ok=0;
	while(scanf("%d%d",&K,&E)==2)
	{
		set++;
		flag=0;
		aux=0;
		getchar();
		for(i=0;i<E;i++)
		{
			memset(excuse[i],'\0',sizeof(excuse[i]));
			memset(keyword[i],'\0',sizeof(keyword[i]));
			max[i]=0;
		}    
		memset(exword,'\0',sizeof(exword));
		for(i=0;i<K;i++)
		{
			gets(keyword[i]);
		}
		for(i=0;i<E;i++)
		{
			gets(excuse[i]);
		}   
		for(i=0;i<E;i++)
		{
			for(j=0;j<=strlen(excuse[i]);j++)
			{
				if(isalpha(excuse[i][j]))
				{
					exword[aux++]=tolower(excuse[i][j]);
				}
				else
				{
					ok=1;
				}
				if(ok)
				{
					for(k=0;k<K;k++)
						max[i]+=Find(keyword[k],exword);   
					memset(exword,'\0',sizeof(exword)); 
					aux=0;
					ok=0;
				}    
			}
		}               
		for(i=0;i<E;i++)
		{
			if(max[i]>flag)
			{
				flag=max[i];
			}      
		}  
		printf("Excuse Set #%d\n",set);  
		for(i=0;i<E;i++)
		{
			if(max[i]==flag)
			{
				puts(excuse[i]);
			}    
		} 
		printf("\n");
	}    
	return 0;
}
