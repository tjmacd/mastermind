#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define RED   "\x1B[37;41;1m"
#define GRN   "\x1B[32;40;1;7m"
#define YEL   "\x1B[33;40;1;7m"
#define BLU   "\x1B[37;44;1m"
#define MAG   "\x1B[37;45;1m"
#define CYN   "\x1B[36;40;1;7m"
#define WHT   "\x1B[37;40;1;7m"
#define BLA   "\x1B[37;40;1m"
#define RESET "\x1B[0m"
#define LENGTH 5

void displaySeq(char *seq) {
	for(int i=0; i<LENGTH; i++){
		switch(seq[i])
		{
		case 'R':
			printf(RED " R " RESET);
			break;
		case 'G':
			printf(GRN " G " RESET);
			break;
		case 'B':
			printf(BLU " B " RESET);
			break;
		case 'M':
			printf(MAG " M " RESET);
			break;
		case 'Y':
			printf(YEL " Y " RESET);
			break;
		case 'C':
			printf(CYN " C " RESET);
			break;
		case 'W':
			printf(WHT " W " RESET);
			break;
		case 'K':
			printf(BLA " K " RESET);
			break;
		}
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
		printf("Enter your guess: ");
		scanf("%s", guess);
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

			/*
			printf("\n[ ");
			for(int i=0; i<5; i++){
				printf("%d ", checked[i]);
			}
			printf("]\n");
			*/
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

			/*
			printf("[ ");
			for(int i=0; i<5; i++){
				printf("%d ", checked[i]);
			}
			printf("]\n");
			*/
			printf(" ");
			for(int i=0; i<black; i++){
				printf(BLA "k" RESET);
			}
			for(int i=0; i<white; i++){
				printf(WHT "w" RESET);
			}

			printf("\n");
			if(black == LENGTH){
				displaySeq(seq);
				printf("\n");
				printf("Score: %d\n", count);
				break;
			}
		} else {
			puts("Invalid input");
		}
		count++;
	}

  	return 0;
}
