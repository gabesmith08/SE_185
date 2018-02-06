/* SE 185 Lab 4 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1

/* Put your function prototypes here */
 double mag(double ax, double ay, double az);
int minutes(int t);
int seconds(int t);
int millis(int t);

int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
	int t;
	double  ax, ay, az; 	


	while (TRUE) {
		scanf("%d,%lf,%lf,%lf", &t, &ax, &ay, &az);	

/* CODE SECTION 0 */
		printf("Echoing output: %08.3lf, %07.4lf, %07.4lf, %07.4lf\n", (double)t / 1000, ax, ay, az);

 	//CODE SECTION 1
		printf("At %d ms, the acceleration's magnitude was: %lf\n", 
			t, mag(ax, ay, az)); 
 
		//Uses a function named mag
 	//CODE SECTION 2
		printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n", 
		minutes(t), seconds(t), millis(t), mag(ax,ay,az)); 

	}

return 0;
}

/* Put your functions here */

double mag(double ax, double ay, double az) {

	return sqrt(pow(ax,2) + pow(ay, 2) + pow(az, 2));

}

int minutes(int t) {
	
	return (t / 60000);
	
}

int seconds(int t) {
	
	return (t / 1000);
	
}


int millis(int t) {
	
	return (t % 1000);
	
}


