#include <stdio.h>
#include <regex.h>
#include <stdlib.h>

#define RED   "\x1B[37;41;1m"
#define GRN   "\x1B[32;40;1;7m"
#define YEL   "\x1B[33;40;1;7m"
#define BLU   "\x1B[37;44;1m"
#define MAG   "\x1B[37;45;1m"
#define CYN   "\x1B[36;40;1;7m"
#define WHT   "\x1B[37;40;1;7m"
#define BLA   "\x1B[37;40;1m"
#define RESET "\x1B[0m"

int main()
{

	char str[5];

	printf("Enter a string: ");
	scanf("%s", str);

	regex_t regex;
	int reti;


	reti = regcomp(&regex, "[RGYBMCWK]{5}", REG_EXTENDED|REG_NOSUB);
	
	if(reti) {
		fprintf(stderr, "Could not compile regex\n");
		exit(1);
	}

	reti = regexec(&regex, str, 0, NULL, 0);
	printf("%d\n", reti);
	if(!reti) {
		puts("GOOD");
	} else {
		puts("BAD");
	}

	for(int i=0; i<5; i++){
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

  	return 0;
}
