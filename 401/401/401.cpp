#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *ori = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
char *rev = "A000300HIL0JM0O0002TUVWXY51SE0Z0080";

int IsPalindrome(char s[])
{
	int len = strlen(s);
	int i;
	for (i = 0; i < len; i++)
	{
		if (s[i] != s[len-1-i])
			return 0;
	}
	return 1;
}

int IsMirrPalin(char s[])
{
	int len = strlen(s);
	int i;
	for (i = 0; i < len; i++)
	{
		char *t = strchr(ori, s[i]);
		int idx = t - ori;
		if (rev[idx] != s[len-1-i])
			return 0;
	}
	return 1;

}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char s[20];
	while (scanf("%s", s) == 1)
	{
		if (IsMirrPalin(s)&&IsPalindrome(s))
			printf("%s -- is a mirrored palindrome.\n", s);
		else if(IsPalindrome(s))
			printf("%s -- is a regular palindrome.\n", s);
		else if(IsMirrPalin(s))
			printf("%s -- is a mirrored string.\n", s);
		else
			printf("%s -- is not a palindrome.\n", s);
		printf("\n");
	}
	return 0;
}