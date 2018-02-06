// Lab 10 DS4Talker Skeleton Code

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <ncurses/ncurses.h>
#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 1   // set to 0 to disable debug output

// reads words from the file
// into wl and trims the whitespace off of the end
// DO NOT MODIFY THIS FUNCTION
int readWords(char* wl[MAXWORDS], char* filename); 

//modifies s to trim white space off the right side
// DO NOT MODIFY THIS FUNCTION
void trimws(char* s);
//void mvprintw(int row, int col, char* format, arg1, arg2, arg3);
void draw_character(int x, int y, char use);

int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	int wordCount;
	int i;
	int time, triangle, circle, xbutton, square, joyPressR, joyPressL, options, share, R2, L2, R1, L1, Lj1, Lj2, Rj1, Rj2;
	int time3;
	int rows = 0, cols = 0, yVal = 0, xVal = 0, yCurr = 0, xCurr = 0, xOld = 0, yOld = 0;
	int rowCount;
	wordCount = readWords(wordlist, argv[1]);
	rowCount = wordCount/5;
	int lengthOfLast = 0;
	int lengthOfSentence = 0;
	int capitalizeNext = 0;

	if (DEBUG) {
		printf("Read %d words from %s \n",wordCount, argv[1]);
		for (i = 0; i< wordCount; i++) {
			printf("%s,", wordlist[i]);

			}
		printf("\n");
		}
		
	initscr();
	refresh();
	
	for(i = 0; i < wordCount; i++)
	{
		mvprintw(yVal, xVal, "%15s", wordlist[i]);
		refresh();
		xVal += 15;
			
		if(xVal >= 75)
		{
			yVal++;
			xVal = 0;
		}
	}	
	if(wordCount%rowCount != 0)
	{
		++rowCount;
	}

	do
	{
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", 
				&time, &triangle, &circle, &xbutton, &square, &joyPressR, &joyPressL, &options, &share, &R2, &L2, &R1, &L1, &Lj1, &Lj2, &Rj1, &Rj2);
		if(time - time3 < 300)
		{
			continue;
		}
		
		draw_character(xOld, yOld, ' ');
		
		if((Rj1 > 100) && (yCurr < rowCount - 1))
		{
			xCurr += 15;
		}
		if((Rj1 < -100) && (xCurr > rowCount - 1))
		{
			xCurr -= 15;
		}
		if((Rj2 > 100) && (yCurr < rowCount - 1))
		{
			yCurr++;
		}
		if((Rj2 < -100) && (xCurr > rowCount - 1))
		{
			yCurr--;
		}
		time3 = time;
		xOld = xCurr;
		yOld = yCurr;
		draw_character(xCurr, yCurr, '-');
		
		if(triangle) //Add selected word with appended space
		{
				int indexToUse = yCurr*5 + xCurr/15;
				lengthOfLast = strlen(wordlist[indexToUse])+1;
				
				char toAdd[12];
				strcpy(toAdd, wordlist[indexToUse]);
				if(capitalizeNext)
				{
					toAdd[0] -= 0x20;
				}
				mvprintw(rowCount+2, lengthOfSentence, "%s", toAdd);
				lengthOfSentence += lengthOfLast;
		}
		else if(xbutton) //Remove the last item
		{
			int indexToUse = yCurr*5 + xCurr/15;
			lengthOfSentence -= lengthOfLast;
		}
		else if(square) //Add selected word without a space
		{
			int indexToUse = yCurr*5 + xCurr/15;
			lengthOfLast = strlen(wordlist[indexToUse]);
			char toAdd[12];
			strcpy(toAdd, wordlist[indexToUse]);
			if(capitalizeNext)
			{
					toAdd[0] -= 0x20;
			}
			mvprintw(rowCount+2, lengthOfSentence, "%s", toAdd);
			lengthOfSentence += lengthOfLast;
			
		}
		else if(circle) //Add selected word with capitalized first letter
		{
			if(capitalizeNext)
			{
				capitalizeNext = 0;
				mvprintw(rowCount+1, 0,"    ");
			}
			else 
			{
				capitalizeNext = 1;
				mvprintw(rowCount+1, 0,"CAP");
			}
		
		} 
	}
	
	while(1);
    return 0;
}

// DO NOT MODIFY THIS FUNCTION
void trimws(char* s) {
        int len = strlen(s) ;
        int x;
        if (len ==0) return;
        x = len-1;
        while (isspace(s[x]) && (x>=0)) {
                s[x] = '\0';
                x--;
                }
        }


// DO NOT MODIFY THIS FUNCTION
int readWords(char* wl[MAXWORDS], char* filename) {
	int numread =0;
	char line[WORDLEN];
	char *p;
	FILE* fp = fopen(filename,"r");
	while (!feof(fp)) {
		p  =fgets(line, WORDLEN, fp);
		if (!feof(fp) && p !=NULL) {
			trimws(line);
			wl[numread] = (char *)  malloc(strlen(line)+1);
			strcpy(wl[numread], line);
			numread++;
			}
		} 
	fclose(fp);
	return numread;	
	}
	
void draw_character(int x, int y, char use)
{
	mvaddch(y,x,use);    
	refresh();
}
//gcc -o lab10 lab10.c -lncurses
//./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -b -j -bt | ./lab10 RawData.txt
