#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <ncurses.h>

#define LENGTH 5

void displaySeq(char *seq) {
	for(int i=0; i<LENGTH; i++){
		attron(A_BOLD);
		switch(seq[i])
		{
		case 'R':
			attron(COLOR_PAIR(1));
			printw(" R ");
			attroff(COLOR_PAIR(1));
			break;
		case 'G':
			attron(COLOR_PAIR(2) | A_REVERSE);
			printw(" G ");
			attroff(COLOR_PAIR(2));
			break;
		case 'Y':
			attron(COLOR_PAIR(3) | A_REVERSE);
			printw(" Y ");
			attroff(COLOR_PAIR(3));
			break;
		case 'B':
			attron(COLOR_PAIR(4));
			printw(" B ");
			attroff(COLOR_PAIR(4));
			break;
		case 'M':
			attron(COLOR_PAIR(5));
			printw(" M ");
			attroff(COLOR_PAIR(5));
			break;
		case 'C':
			attron(COLOR_PAIR(6) | A_REVERSE);
			printw(" C ");
			attroff(COLOR_PAIR(6));
			break;
		case 'W':
			attron(COLOR_PAIR(7) | A_REVERSE);
			printw(" W ");
			attroff(COLOR_PAIR(7));
			break;
		case 'K':
			attron(COLOR_PAIR(7));
			printw(" K ");
			attroff(COLOR_PAIR(7));
			break;
		}
		attroff(A_BOLD | A_REVERSE);
	}
}

int main()
{

	char guess[LENGTH];
	char colours[8] = "RGYBMCWK";
	

	regex_t regex;
	int reti;


	reti = regcomp(&regex, "[RrGgYyBbMmCcWwKk]{5}", 
					REG_EXTENDED | REG_NOSUB);
	
	if(reti) {
		fprintf(stderr, "Could not compile regex\n");
		exit(1);
	}

	// Init curses
	initscr();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_RED);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_WHITE, COLOR_BLUE);
	init_pair(5, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	keypad(stdscr, TRUE);

	// Generate sequence
	char seq[LENGTH];
	srand(time(NULL));
	for(int i=0; i<LENGTH; i++) {
		int random = rand() % 8;
		seq[i] = colours[random];
	}

	//puts(seq);
	int count = 1;
	while(1){
		// Get guess
		printw("Enter your guess: ");
		refresh();
		getstr(guess);
		// Check input
		reti = regexec(&regex, guess, 0, NULL, 0);
		if(!reti) {
			for(int i=0; i<LENGTH; i++) {
				guess[i] = toupper(guess[i]);
			}
			// Display guess
			displaySeq(guess);

			// Mark guess
			bool checked[LENGTH] = {false};
			int black=0;
			int white=0;
			for(int i=0; i<LENGTH; i++){
				if(guess[i] == seq[i]){
					guess[i] = ' ';
					checked[i] = true;
					black++;
				}
			}

			for(int i=0; i<LENGTH; i++){
				if(guess[i] != ' '){
					for(int j=0; j<LENGTH; j++){
						if(!checked[j] && guess[i] == seq[j]) {
							checked[j] = true;
							white++;
							break;
						}
					}
				}
			}

			printw(" ");
			attron(A_BOLD);
			for(int i=0; i<black; i++){
				attron(COLOR_PAIR(7));
				printw("k");
				attroff(COLOR_PAIR(7));
			}
			for(int i=0; i<white; i++){
				attron(COLOR_PAIR(7) | A_REVERSE);
				printw("w");
				attroff(COLOR_PAIR(7) | A_REVERSE);
			}
			attroff(A_BOLD);

			printw("\n");
			if(black == LENGTH){
				displaySeq(seq);
				printw("\n");
				printw("Score: %d\n", count);
				break;
			}
		} else {
			printw("Invalid input\n");
		}
		refresh();
		count++;
	}
	getch();
	endwin();

  	return 0;
}
