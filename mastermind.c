#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <ctype.h>

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


int main()
{

	char str[LENGTH];
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
	for(int i=0; i<LENGTH; i++) {
		int random = rand() % 8;
		seq[i] = colours[random];
	}

	puts(seq);

	while(1){
		printf("Enter your guess: ");
		scanf("%s", str);

		reti = regexec(&regex, str, 0, NULL, 0);
		if(!reti) {
			for(int i=0; i<LENGTH; i++) {
				str[i] = toupper(str[i]);
			}
			for(int i=0; i<LENGTH; i++){
				switch(str[i])
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
			printf("\n");
		} else {
			puts("Invalid input");
		}
	}

  	return 0;
}
