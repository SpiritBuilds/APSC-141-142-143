#include <stdio.h>

int main(){
	int num;
	printf("Enter number: ");
	scanf("%d", &num);
	printf("%d^2 = %d\n", num, num*num);
	return 0;
}