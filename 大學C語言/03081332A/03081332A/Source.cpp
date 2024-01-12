#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)

int main() {
	int testcase = 0;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; ++i) {
		long long int a = 0, b = 0, c = 0, d = 0;//a:left b:right c:down d:up
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		long long int x = 0, x1 = 0, x2 = 0, y = 0, y1 = 0, y2 = 0;//range
		scanf("%lld%lld%lld%lld%lld%lld", &x, &y, &x1, &y1, &x2, &y2);
		x1 -= x;
		x2 -= x;
		y1 -= y;
		y2 -= y;
		if ((a > 0 || b > 0) && x2 - x1 == 0)
			printf("No\n");
		else if ((c > 0 || d > 0) && y2 - y1 == 0)
			printf("No\n");
		else if (b > a) {
			if (b - a > abs(x2))
				printf("No\n");
			else  {
				if (d > c) {
					if (d - c > abs(y2)) {
						printf("No\n");
					}
					else
						printf("Yes\n");
				}
				else
					if (c - d > abs(y1)) {
						printf("No\n");
					}
					else
						printf("Yes\n");
			}
		}
		else {
			if (a - b > abs(x1))
				printf("No\n");
			else {
				if (d > c) {
					if (d - c > abs(y2)) {
						printf("No\n");
					}
					else
						printf("Yes\n");
				}
				else
					if (c - d > abs(y1)) {
						printf("No\n");
					}
					else
						printf("Yes\n");
			}
		}
	}
	return 0;
}