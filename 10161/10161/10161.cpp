#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cmath>
#define LOCAL
int dx[6] = {0, 1, 0, 1, 0, -1};
int dy[6] = {1, 0, -1, 0, 1, 0};

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	int num;
	scanf("%d", &num);
	while (num != 0)
	{
		num -= 1;
		int iter = 0, x = 1, y = 1, dir, step = 1, dir_x, dir_y, i, j;
		while (1)
		{
			//calculate delta x y
			dir = iter%6;
			dir_x = dx[dir];
			dir_y = dy[dir];
			//update coordinates
			if (num < step)
				step = num;
			x += dir_x * step;
			y += dir_y * step;
			num -= step;
			if (num <= 0)
				break;
			//update step
			iter++;
			i = iter/3;
			j = iter%3;
			step = (j != 0)?(i+1):1;
		}
		printf("%d %d\n", x, y);
		scanf("%d", &num);
	}
	return 0;
}