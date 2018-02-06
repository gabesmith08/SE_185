// WII-MAZE Skeleton code written by Jason Erbskorn 2007
// Edited for ncurses 2008 Tom Daniels
// Updated for Esplora 2013 TeamRursch185
// Updated for DualShock 4 2016 Rursch


// Headers
#include <stdio.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>
#include <stdlib.h>

// Mathematical constants
#define PI 3.14159

// Screen geometry
// Use ROWS and COLS for the screen height and width (set by system)
// MAXIMUMS
#define NUMCOLS 100
#define NUMROWS 80

// Character definitions taken from the ASCII table
#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '

// Number of samples taken to form an average for the gyroscope data
// Feel free to tweak this.  You may actually want to use the moving averages
// code you created last week 
#define NUM_SAMPLES 10  

//scans in the controller values


// 2D character array which the maze is mapped into
char MAZE[NUMROWS][NUMCOLS];


// POST: Generates a random maze structure into MAZE[][]
//You will want to use the rand() function and maybe use the output %100.  
//You will have to use the argument to the command line to determine how 
//difficult the maze is (how many maze characters are on the screen).
void generate_maze(int difficulty); 

// PRE: MAZE[][] has been initialized by generate_maze()
// POST: Draws the maze to the screen 
void draw_maze(void);

// PRE: 0 < x < COLS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
void draw_character(int x, int y, char use);

// PRE: -1.0 < x_mag < 1.0
// POST: Returns tilt magnitude scaled to -1.0 -> 1.0
// You may want to reuse the roll function written in previous labs.  
float calc_roll(float x_mag);

// Main - Run with './ds4rd.exe -t -g -b' piped into STDIN
void main(int argc, char* argv[])
{	
	int X_Avatar = 50;
	int Y_Avatar = 0;
	int oldAvtX = 0;
	int newAvtY = 0;
	int difficulty = 0;
	double x, y, z;
	int b_Up, b_Down, b_Left, b_Right;
	sscanf(argv[1], "%d", &difficulty);
	srand((unsigned) difficulty);
	// setup screen    
	initscr();
	refresh();
	generate_maze(difficulty);
	draw_maze();

	// Generate and draw the maze, with initial avatar

	// Read gyroscope data to get ready for using moving averages.    

	// Event loop
	do
	{
		
		// Read data, update average
		
		// Is it time to move?  if so, then move avatar

	} while(1); // Change this to end game at right time 

	
	// Print the win message
	endwin();
	
	printf("YOU WIN!\n");
}



// PRE: 0 < x < COLS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
//THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
//
//    >>>>DO NOT CHANGE THIS FUNCTION.<<<<
void draw_character(int x, int y, char use)
{
	mvaddch(y,x,use);    
	refresh();
}

//FUNCTIONS

 void generate_maze(int difficulty) {
	int column;
	int row;
	int randValue;
	
	for(row = 0; row < NUMROWS; ++row) {
		for(column = 0; column < NUMCOLS; ++column) {
			randValue = rand() %100;
			if (randValue <= difficulty) {
				MAZE[row][column] = WALL;
			}
			else {
				MAZE[row][column] = EMPTY_SPACE;
			}
		}
	}
}

void draw_maze(void) {
	int column;
	int row;
	
	for(row = 0; row < NUMROWS; ++row) {
		
	}
}



