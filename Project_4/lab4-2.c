/* SE 185 Lab 4 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1
int ButtonsPressed(int triangle, int circle, int x, int square);

int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
	int triangle;
	int  circle, x, square; 	


	while (TRUE) {
		scanf("%d,%d,%d,%d", &triangle, &circle, &x, &square);
		printf("There are %d buttons pressed\n", ButtonsPressed(triangle, circle, x, square));
		fflush(stdout);

	}

return 0;
}

int ButtonsPressed(int triangle, int circle, int x, int square) {
	
	return (triangle + circle + x + square);
	
}


