// Richard Smith, se185 E, 9/17/2016
// LAB2-0.c : Defines the entry point for the console application.

#include<stdio.h>
#include<math.h>

int main(int argc, char* argv []){

int intAnswer = 0;
double doubleAnswer = 0.0;

intAnswer = (6427 + 1725);
printf("The answer to problem a is %d\n", intAnswer);

intAnswer = (6971 * 3925) - 95;
printf("The answer to problem b is %d\n", intAnswer);

doubleAnswer = (79 + 12) / 5;
printf("The answer to problem c is %.2lf\n", doubleAnswer);

doubleAnswer = (3640.0 / 107.9);
printf("The answer to problem d is %.2lf\n", doubleAnswer);

intAnswer = (22 / 3) * 3;
printf("The answer to problem e is %d\n", intAnswer);

intAnswer = 22 / (3 * 3);
printf("The answer to problem f is %d\n", intAnswer);

doubleAnswer = 22 / (3 * 3);
printf("The answer to problem g is %.2lf\n", doubleAnswer);

doubleAnswer = 22 / 3 * 3;
printf("The answer to problem h is %.2lf\n", doubleAnswer);

doubleAnswer = (22.0 / 3) * 3.0;
printf("The answer to problem i is %.2lf\n", doubleAnswer);

intAnswer = 22.0 / (3 * 3.0);
printf("The answer to problem j is %d\n", intAnswer);

doubleAnswer = 22.0 / 3.0 * 3.0;
printf("The answer to problem k is %.2lf\n", doubleAnswer);

	printf("\n"); // Create space between simple problems and formula problems

	// Circle Area Problem code:
	
double cirCum = 23.567; // constant circumference of the circle
double raDius = cirCum / (2 * 3.14); // divide the circumference by 2 * pi to find radius
double areaOfCircle = pow(raDius,2) * 3.14; // square the radius and multiply by pi to find circle area
printf("The area of a circle with the circumference of %.2lf", cirCum);
printf(" is about %.2lf.\n", areaOfCircle);

	printf("\n");
	
	// Converting Feet to Meters Code:
		//1 Ft = 0.3048 meters
int initialFeet = 16;
double totalMeters = (initialFeet * .3048);
printf("%d feet", initialFeet);
printf(" equals about %.2lf meters.\n", totalMeters);

	printf("\n");
	
	// Temperature Conversion Code:
		//Tc = (Tf- 32) / 1.8)
int degreesF = 76;
double degreesC = (degreesF - 32) / 1.8;
printf("%d degrees fahrenheit equals about ", degreesF);
printf("%.2lf degrees centigrade.", degreesC);

return 0;
}