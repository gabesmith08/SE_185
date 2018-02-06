 // SE 185 Lab 6 - DS4 Drop | Richard Smith - Section E

#include <stdio.h>
#include <math.h>
#define TRUE 1
#include <stdbool.h>
#define PERIOD_TIME 1000
#define EXCLAMATION_TIME 1000

// MAG PROTOTYPE
double mag(double xVar, double yVar, double zVar);

// TOLERANCE PROTOTYPE
int Close_To(double tolerance, double point, double value);


int main(void) {
	
	int  i, t, b1, b2, b3, b4;
	double xVar, yVar, zVar; 	
	double tolerance, point, value, x0, v, g, x1, tRest, tFall, tTotal;

	
	printf("Ok, I'm now receiving data.\nI'm Waiting");
		
	while (0.30 > (mag(xVar, yVar, zVar))) { // used the number 0.30 to allow a little free movement in the hands before the actual drop.
		scanf("%d, %lf, %lf, %lf", &t, &xVar, &yVar, &zVar);
		if (t % PERIOD_TIME < 80) { // output for time in the 2 story drop is random from 90 ms and up so I chose 80.
			printf(".");
		}
		tRest = t;
		
	fflush(stdout);
	}

	printf("\n\n     Help me! I'm falling");
	
	while (((mag(xVar, yVar, zVar)) > 0.30) && ((mag(xVar, yVar, zVar)) < 1.1)) { 
		scanf("%d, %lf, %lf, %lf", &t, &xVar, &yVar, &zVar);
		if (t % EXCLAMATION_TIME < 80) { // still 80 since the output records time randomly from 90 and up.
			printf("!");
		}
		tTotal = t;
		
		
		
	
		
		
	fflush(stdout);
	}

		/*	
			v = initial velocity (0) and t is the fall time. x0 is the location before and x1 is the location after the fall
			x1 = x0 + vt + (1/2) gt2
			g = 9.8 m/sec^2
		*/

	// Little function  to find amount of time and distance in the fall
	x0 = 0.0;
	v = 0.0;
	tFall = (tTotal - tRest) / 1000;
	g = 9.8;
	x1 = (x0 + (v * tFall) + 0.5 * g * (tFall * tFall));
		printf("\n\n          Ouch! I fell %6.3lf meters in %6.3lf seconds.\n\n", x1, tFall);
	
  
	return 0;
}

// finds magnitude of the three numbers that the ps4 controller puts out.
double mag (double xVar, double yVar, double zVar) { 
double magVar;
	magVar = sqrt(pow(xVar, 2) + pow(yVar , 2) + pow(zVar , 2)); 
	return magVar;
	
}

// function that sets up return if the input is close to tolerance.
int Close_To (double tolerance, double point, double value) {
	if ((value >= (point - tolerance)) && (value <= (point + tolerance))) {
		return true;
	}
	else {
		return false;
	}
}
