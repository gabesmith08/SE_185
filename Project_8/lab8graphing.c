// SE 185 Lab 8
// Richard Smith sec E

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define MAXPOINTS 10000

// compute the average of the first num_items of buffer
double avg(double buffer[], int num_items);

//update the max and min of the first num_items of array
void maxmin(double array[], int num_items, double* max, double* min);

//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.
void updatebuffer(double buffer[], int length, double new_item);


int main(int argc, char* argv[]) {
	

	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	int lengthofavg = 0;
	if (argc>1) {
		sscanf(argv[1], "%d", &lengthofavg );
		printf("You entered a buffer length of %d\n", lengthofavg);
	}
	else {
		printf("Enter a length on the command line\n");
		return -1;
	}
	if (lengthofavg <1 || lengthofavg >MAXPOINTS) {
		printf("Invalid length\n");
		return -1;
	}
		
	int buttonT = 0;
	int buttonC = 0;
	int buttonX = 0;
	int buttonS = 0;
	double Xg = 0;
	double Yg = 0;
	double Zg = 0;
	double x_Avg = 0;
	double y_Avg = 0;
	double z_Avg = 0;
	double x_Min = 0;
	double x_Max = 0;
	double y_Min = 0;
	double y_Max = 0;
	double z_Min = 0;
	double z_Max = 0;
	int i;
	
	do {
	
		scanf("%lf, %lf, %lf, %d, %d, %d, %d", &Xg, &Yg, &Zg, &buttonT, &buttonC, &buttonX, &buttonS);
	
		updatebuffer(x, lengthofavg, Xg);
		updatebuffer(y, lengthofavg, Yg);
		updatebuffer(z, lengthofavg, Zg);
		x_Avg = avg(x, lengthofavg);
		y_Avg = avg(y, lengthofavg);
		z_Avg = avg(z, lengthofavg);
		maxmin(x, lengthofavg, &x_Max, &x_Min);
		maxmin(y, lengthofavg, &y_Max, &y_Min);
		maxmin(z, lengthofavg, &z_Max, &z_Min);

		printf("%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf\n", x_Avg, x_Min, x_Max, y_Avg, y_Min, y_Max, z_Avg, z_Min, z_Max);
		fflush(stdout);
	}
	while (buttonS == 0);
	return 0;
}

/* computes the average of first num_items of buffer */
double avg(double buffer[], int num_items) {
	int i;
	double sum = 0;
	double average = 0;
	for (i = 0; i < num_items; i++){
		sum = sum + buffer[i];
	}
	average = (sum / num_items);
	return average;
}

/* updates max and min of first num_items of array */
void maxmin(double array[], int num_items, double* max, double* min) {
	*max = array[0];
	*min = array[0];
	int i;
	for (i = 0; i < num_items; i++) {
		if (array[i] > *max) {
			*max = array[i];
		}
		if (array[i] < *min) {
			*min = array[i];
		}
	}
}

/*shifts length  by -1 elements of the buffer and puts 
new_item into the new slot. */
void updatebuffer(double buffer[], int length, double new_item) {
	int i;
	for (i = 0; i < (length - 1); i++){
		buffer[i] = buffer[i+1];
	}
	buffer[length - 1] = new_item;
}
