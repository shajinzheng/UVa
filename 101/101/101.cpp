#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LOCAL
#define MAXN 50
typedef struct BlockNode
{
	int val;
	int IsMoved;
	struct BlockNode * next;
}Block;
Block s[MAXN];
int num;

int findBlock(int n)
{
	int r = 0;
	if (s[n].IsMoved == 0)
		r = n;
	else
	{
		int j;
		for (j = 0; j < num; j++)
		{
			if (s[j].IsMoved == 0)
			{
				Block * t = &s[j];
				while (t != NULL)
				{
					if (n == t->val)
						r = j;
					t = t->next;
				}
			}
		}
	}
	return r;
}

void clear(Block * t)
{
	if (t == NULL)
		return;
	clear(t->next);
	s[t->val].IsMoved = 0;
	free(t);
}

void action(int a, int b, int type)
{
	int IsLegal = 1;
	int now_b = findBlock(b), now_a = findBlock(a);
	if ((a == b)||(now_a == now_b))
		return;
	
	Block * block_a = (Block *) malloc(sizeof(Block)); 
	block_a->IsMoved = 1;
	Block * tmpt = (Block *) malloc(sizeof(Block)), * tmpt_a;

	if (type == 0)
	{
		tmpt = &s[now_a];
		block_a->next = NULL;
		block_a->val = tmpt->val;
		tmpt = &s[now_a];
		if (tmpt->val == a)
		{
			clear(tmpt->next);
			tmpt->next = NULL;
			s[now_a].IsMoved = 1;
		}
		else
		{
			while (tmpt->next->val != a)
				tmpt = tmpt->next;
			clear(tmpt->next);
			s[a].IsMoved = 1;
			tmpt->next = NULL;
		}
		
		tmpt = &s[now_b];
		while (tmpt->val != b)
			tmpt = tmpt->next;
		clear(tmpt->next);
		tmpt->next = block_a;
		return;
	}

	if (type == 1)
	{
		
		tmpt = &s[now_a];
		block_a->next = NULL;
		block_a->val = tmpt->val;
		if (tmpt->val == a)
		{
			clear(tmpt->next);
			tmpt->next = NULL;
			s[now_a].IsMoved = 1;
		}
		else
		{
			while (tmpt->next->val != a)
				tmpt = tmpt->next;
			clear(tmpt->next);
			s[a].IsMoved = 1;
			tmpt->next = NULL;
		}
		
		tmpt = &s[now_b];
		while (tmpt->next != NULL)
			tmpt = tmpt->next;
		tmpt->next = block_a;
		return;
	}

	if (type == 2)
	{
		
		tmpt = &s[now_a];
		if (tmpt->val == a)
		{
			block_a->next = tmpt->next;
			block_a->val = tmpt->val;
			tmpt->next = NULL;
			s[now_a].IsMoved = 1;
			tmpt_a = block_a;
		}
		else
		{
			while (tmpt->next->val != a)
				tmpt = tmpt->next;
			tmpt_a = tmpt->next; tmpt->next = NULL;
		}
		
		tmpt = &s[now_b];
		while (tmpt->val != b)
			tmpt = tmpt->next;
		clear(tmpt->next);
		
		tmpt -> next = tmpt_a;
		return;
	}

	if (type == 3)
	{
		
		tmpt = &s[now_a];
		if (tmpt->val == a)
		{
			block_a->next = tmpt->next;
			block_a->val = tmpt->val;
			tmpt->next = NULL;
			s[now_a].IsMoved = 1;
			tmpt_a = block_a;
		}
		else
		{
			while (tmpt->next->val != a)
				tmpt = tmpt->next;
			tmpt_a = tmpt->next; tmpt->next = NULL;
		}
		
		tmpt = &s[now_b];
		while (tmpt->next != NULL)
			tmpt = tmpt->next;
		
		tmpt->next = tmpt_a;
		return;
	}

}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int i, type; 
	char c1[10], c2[10];
	int a, b;
	scanf("%d", &num);
	
	for (i = 0; i < num; i++)
	{
		s[i].val = i;
		s[i].IsMoved = 0;
		s[i].next = NULL;
	}
	scanf("%s", c1);
	while(strcmp(c1, "quit"))
	{
		
		scanf("%d", &a);
		scanf("%s", c2);
		scanf("%d", &b);
		if (!strcmp(c1, "move"))
		{
			if (!strcmp(c2, "onto"))
				type = 0;
			else
				type = 1;
		}
		else
		{
			if (!strcmp(c2, "onto"))
				type = 2;
			else
				type = 3;
		}
		action(a, b, type);
		scanf("%s", c1);
	}
	
	for (i = 0; i < num; i++)
	{
		printf("%d:", i);
		if (s[i].IsMoved == 0)
		{
			Block * sha = &s[i];
			while (sha != NULL)
			{
				printf(" %d", sha->val);
				sha = sha->next;
			}
		}
		printf("\n");
	}
	return 0;
}