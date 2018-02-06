// SE 185 lab7.c
// Richard Smith sec E


#include <stdio.h>
#include <math.h>
#define PI 3.141592653589

//NO GLOBAL VARIABLES ALLOWED


//PRE: Arguments must point to double variables or int variables as appropriate
//This function scans a line of DS4 data, and returns
//  True when left button is pressed
//  False Otherwise
//POST: it modifies its arguments to return values read from the input line.
int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_X, int* Button_S, int* Button_C);

// PRE: -1.0 <= x_mag <= 1.0
// This function computes the roll of the DS4 in radians
// if x_mag outside of -1 to 1, treat it as if it were 1 or -1
// POST: -PI/2 <= return value <= PI/2
double roll(double x_mag);

// PRE: -1.0 <= y_mag <= 1.0
// This function computes the pitch of the DS4 in radians
// if y_mag outside of -1 to 1, treat it as if it were 1 or -1
// POST: -PI/2 <= return value <= PI/2
double pitch(double y_mag);


// PRE: -PI/2 <= rad <= PI/2
// This function scales the roll value to fit on the screen
// POST: -39 <= return value <= 39
int scaleRadsForScreen(double rad);

// PRE: num >= 0
// This function prints the character use to the screen num times
// This function is the ONLY place printf is allowed to be used
// POST: nothing is returned, but use has been printed num times
void print_chars(int num, char use);

//PRE: -39 <= number <=39
// Uses print_chars to graph a number from -39 to 39 on the screen.
// You may assume that the screen is 80 characters wide.
void graph_line(int number);

int main()
{
	double x, y, z;			// magnitude values of x, y, and z
	int b_Up, b_Down, b_Left, b_Right;	// variables to hold the button statuses
	double roll_rad, pitch_rad;		// value of the roll measured in radians
	int scaled_value; 	// value of the roll adjusted to fit screen display
	int state = 1;
	double roll_pitch = 0;
	int scale = 0;
	int time = 0;
	
	
	
	do
	{
		
		// Get line of input
		read_line(&x, &y, &z, &time, &b_Up, &b_Left, &b_Down, &b_Right);
		// button set up for roll/pitch
		if (b_Up ==1){
			state = 1;
		}
		else if (b_Down == 1){
			state = 2;
		}
		if(state == 1){
			roll_pitch = roll(x);
		}
		else if (state == 2) {
			roll_pitch = pitch(y);
		}
		
		scale = scaleRadsForScreen(-roll_pitch);
		
		graph_line(scale);
		

		fflush(stdout);
	} while (b_Right == 0); // to stop program when left button is pressed
	return 0;
}

int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_X, int* Button_S, int* Button_C){
	scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", time, g_x, g_y, g_z, Button_T, Button_X, Button_S, Button_C);
	if (*Button_T == 1){
		return 1;
	}
	else{
		return 0;
	}
	
}

double roll(double x_mag){		//computes the roll of the DS4 in radians
	
	if (x_mag > 1.0){
		x_mag = 1.0;
	}
	else if (x_mag < -1.0){
			 x_mag = -1.0;
	}
	
	return asin(x_mag);
}

double pitch(double y_mag){		//computes the pitch of the DS4 in radians
	if (y_mag > 1.0){
		y_mag = 1.0;
	}
	else if (y_mag < -1.0){
			 y_mag = -1.0;
	}
	return asin(y_mag);
}

int scaleRadsForScreen(double rad){		//scales the roll or pitch value to fit on the screen
	return (int) (rad / PI * 39);
}

void print_chars(int num, char use){		//prints the character use to the screen num times
	int i = 0;
	int numChars;
	if (num < 0){
		numChars = 40 + num;
		for(i = 0; i < numChars; i++){
			printf(" ");
		}
		for(i = num; i < 0; i++){
			printf("L");
		}
	}
	else if (num > 0){
		for(i = 0; i < 40; i++){
			printf(" ");
		}
		for (i = num; i > 0; i--){
			printf("%c", use);
		}
		for (i = 0; i < (40 - num); i++){
		printf(" ");
		}
		
	}
	else if (num == 0){
		for(i = 0; i < 39; i++){
			printf(" ");
		}
		printf("0");
	}
	printf("\n");
}

void graph_line(int number){	//graph a number from -39 to 39 on the screen.
	if (number < 0){
		print_chars((number), 'L');
	}
	else if (number > 0){
		print_chars((number), 'R');
	}
	else if (number == 0){
		print_chars(0, '0');
	}
	}
	









