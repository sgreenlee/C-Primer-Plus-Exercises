/* Exercise 1

Find out what your system does with integer overflow, floating-point overflow,
and floating point underflow by using the experimental approach; that is,
write programs that have these problems.

*/
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	int int_overflow;
	int MAX_INTEGER = INT_MAX;
	float flt_overflow, flt_underflow;
	float MIN_FLOAT = FLT_MIN;
	float MAX_FLOAT = FLT_MAX;
	
	// artificially create over/underflow
	int_overflow = INT_MAX + 1;
	flt_overflow = FLT_MAX * 2.;
	flt_underflow = FLT_MIN / 2.;
	
	// print results
	printf("Max integer: %d \tMax integer + 1: %d\n", INT_MAX, int_overflow);
	printf("Max float: %f \tMax float * 2: %f\n", FLT_MAX, flt_overflow);
	printf("Min float: %f \tMin float / 2: %f\n", FLT_MIN, flt_underflow);

	return 0;
}
