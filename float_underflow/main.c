#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // true
#include <float.h> // FLT_EPSILON

int divUnf(float *a, float b)
{
	if(*a < FLT_EPSILON * b)
		return -1;

	*a = *a / b;
	return 0;
}

int main()
{
	float *res = (float *)malloc(sizeof(float)); // dividend
	*res = 1;
	float y = 2; // divisor
	int flag = 0; // flag for detecting underflow
	int count = 0; // loop counter

	while(true)
	{
		// if underflow occurs
		if(flag == -1)
			break;

		flag = divUnf(res, y);
		printf("%.10f \n", *res);
		count++;
	}

	printf("the min machine epsilon is about 2 power of -%d \n", count);

	return 0;
}

