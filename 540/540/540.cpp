#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LOCAL

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	
	return 0;
}