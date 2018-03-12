#include <stdio.h>
#include <limits.h> // INT_MAX
#include <stdlib.h>
#include <stdbool.h> // true

int mulOvf(int *a, int b)
{
    if (*a > INT_MAX / b)
        return -1;
    else {
        *a = *a * b;
        return 0;
    }
}

int main()
{
	int *res = (int *)malloc(sizeof(int)); // multiplicand
	*res = 1;
	int y = 2; // multiplier
	int flag = 0; // flag for detecting overflow
	int count = 0; // loop counter

	while(true)
	{
		// if overflow occurs, break the loop
		if(flag == -1)
			break;

		flag = mulOvf(res, y);
		printf("%d \n", *res);
		count++;
	}

	printf("the max machine epsilon is about 2 power of %d \n", count);

	return 0;
}

