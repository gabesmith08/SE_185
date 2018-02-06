// WII-MAZE Skeleton code written by Jason Erbskorn 2007
// Edited for ncurses 2008 Tom Daniels
// Updated for Esplora 2013 TeamRursch185
// Updated for DualShock 4 2016 Rursch
// RICHARD SMITH SEC E


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
	int difficulty = 0;
	double Xg, Yg, Zg;
	int t, time;
	int x_mag;
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
		scanf("%d, %lf, %lf, %lf", &t, &Xg, &Yg, &Zg);
		// Read data, update average
		
		// Is it time to move?  if so, then move avatar
		
		
		if (t > (time + 1100)) {	//time delay for Avatar to move 
			
			draw_character(X_Avatar, Y_Avatar, AVATAR);
			draw_character(X_Avatar, Y_Avatar - 1, EMPTY_SPACE); // makes avatar move down one space and then deletes previous avatar
			Y_Avatar++;
			time = t;
				if (calc_roll(Xg) == 1) {	//turns avatar right
				X_Avatar = (X_Avatar + 1);
				
			}
				if (calc_roll(Xg) == -1) {	//turns avatar left
				X_Avatar = (X_Avatar - 1);
				
			}
		}
			
		
	} while(1); // Change this to end game at right time 
		
		if (draw_character(X_Avatar, Y_Avatar, AVATAR) == WALL)	{
			printf("You Lose!\n");
		}
		
		 endwin();
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

//creates random maze with difficulty based off of the typed in window value
 void generate_maze(int difficulty) {
	int i = 0;
	int j = 0;
    for (i=0; i < NUMCOLS; ++i) {
        for (j=0; j < NUMROWS; j++) {
            MAZE[i][j] = rand() % 100;
			MAZE[i][j] -= difficulty;
			if(MAZE[i][j] < 0) {
				draw_character(i,j,WALL);
			}
			if(MAZE[i][j] >= 0) {
				draw_character(i,j,EMPTY_SPACE);
			}
		}
	}
}

//centers avatar
void draw_maze(void) {
	int i = 0;
	int j = 0;
	for(i = 0; i < NUMCOLS; ++i) {
		for(j = 0; j < NUMROWS; ++j) {
			if (i == 50 && j == 0) {
				draw_character (i,j,AVATAR);
			}
		}
	}
}

//steers avatar
float calc_roll(float x_mag) {
	
	
	if (x_mag > 1.0){
		x_mag = 1.0;
	}
	else if (x_mag < -1.0){
			 x_mag = -1.0;
	}
	
	return x_mag;
}


