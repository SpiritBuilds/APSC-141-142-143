#include <stdio.h>
#include <math.h>

int main() {
	int radius;
	printf("Enter radius: ");
	scanf("%d", & radius);
	float area = M_PI * pow(radius, 2);
	printf("Circle of radius %d has an area of %.2f\n", radius, area);
	return 0;
}