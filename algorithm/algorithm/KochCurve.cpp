#include "pch.h"

#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>

struct Position { double x, y;  };

void Koch(int n, Position left, Position right) {
	if (n == 0) return;
	Position firstThird, thirdThird, secondThird;
	double th = M_PI * 60.0 / 180.0;

	firstThird.x = (2.0 * left.x + right.x) / 3.0;
	firstThird.y = (2.0 * left.y + right.y) / 3.0;
	thirdThird.x = (left.x + 2.0 * right.x) / 3.0;
	thirdThird.y = (left.y + 2.0 * right.y) / 3.0;

	secondThird.x = (thirdThird.x - firstThird.x) * cos(th) - (thirdThird.y - firstThird.y) * sin(th) + firstThird.x;
	secondThird.y = (thirdThird.x - firstThird.x) * sin(th) + (thirdThird.y - firstThird.y) * cos(th) + firstThird.y;

	Koch(n - 1, left, firstThird);
	printf("%.8f %.8f\n", firstThird.x, firstThird.y);

	Koch(n - 1, firstThird, secondThird);
	printf("%.8f %.8f\n", secondThird.x, secondThird.y);

	Koch(n - 1, secondThird, thirdThird);	
	printf("%.8f %.8f\n", thirdThird.x, thirdThird.y);

	Koch(n - 1, thirdThird, right);
}

void KochCurve() {
	Position left, right;
	int n;

	scanf_s("%d", &n);

	left.x = 0;
	left.y = 0;
	right.x = 100;
	right.y = 0;

	printf("%.8f %.8f\n", left.x, left.y);
	Koch(n, left, right);
	printf("%.8f %.8f\n", right.x, right.y);

	return;
}
