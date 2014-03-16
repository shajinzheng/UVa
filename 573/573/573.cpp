#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  LOCAL
float h, u, d, f;// h - height, u - distance climb, d - slide, f - fatigue

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	scanf("%f%f%f%f", &h, &u, &d, &f);
	while (h != 0)
	{
		float speed = u, h_t = 0, delta = u * f/100.0;
		int iter = 0, flagSuccess = 0, flagFail = 0;
		while (1)
		{
			iter++;
			speed = (speed > 0)?speed:0;
			if (h_t + speed > h)
			{
				flagSuccess = 1;
				break;
			}
			else if (h_t + speed - d < 0)
			{
				flagFail = 1;
				break;
			}
			h_t = h_t + speed - d;
			speed -= delta;
		}
		if (flagFail)
			printf("failure on day %d\n", iter);
		if (flagSuccess)
			printf("success on day %d\n", iter);
		scanf("%f%f%f%f", &h, &u, &d, &f);
	}
	return 0;
}