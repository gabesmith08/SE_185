//SE 185 Lab 5 Wrapper Program, RICHARD SMITH Sec E


#include <stdio.h>

#include <math.h>

#define TRUE 1

#include <stdbool.h>


// Mag Function Prototype
double mag(double xVar, double yVar, double zVar); 

// Tolerance function Prototype
int Close_To(double tolerance, double point, double value);

// Function that finds orientation Prototype
double Orientaion(double x, double y, double z);



int main(void) {
	int t, b1, b2, b3, b4;
	double ax, ay, az, gx, gy, gz; 
	double oldMag = 0.0;
	

	while (b1 != 1) {
		scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );
		
		if(!(Close_To(.4, oldMag, mag(ax, ay, az)))){ 
			Orientaion(gx, gy, gz);
			//printf("Echoing output: %d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n", t, ax, ay, az, gx, gy, gz, b1, b2, b3, b4);
			//printf("At %d ms, the acceleration's magnitude was: %f\n", t, mag(ax, ay, az));  
		} 
		oldMag = mag(ax, ay, az); // takes in all oldMag values
	}
    return 0;
}

// finds the magnitude of the three numbers that the ps4 controller puts out.
double mag(double xVar, double yVar, double zVar) {
	double magVar = 0.0;
	magVar = sqrt(pow(xVar, 2) + pow(yVar , 2) + pow(zVar , 2)); 
	return magVar;
	
}

// funtion that sets up the return if input is close to the tolerance.
int Close_To(double tolerance, double point, double value) {
	if ((value <= (point + tolerance)) && (value >= (point - tolerance))) {
		return true;
	}
	else {
		return false;
	}
}


// Orientation of controller function.
double Orientaion(double x, double y, double z) {
	
	if (Close_To(.30, -1, x)){
		printf("Left\n ");
	}
	else if(Close_To(.30, 1, x)){
		printf("Right\n ");
	}
	else if(Close_To(.15, 1, y)){
		printf("Top\n ");
	}
	else if(Close_To(.15, -1, y)){
		printf("Bottom\n ");		
	}
	else if(Close_To(.20, -1, z)){
		printf("Front\n ");		
	}
	else if(Close_To(.20, 1, z)){
		printf("Back\n ");		
	}
	
	return 0;
}


