#include <stdio.h>

#define RED   "\x1B[37;41;1m"
#define GRN   "\x1B[37;42;1m"
#define YEL   "\x1B[37;43;1m"
#define BLU   "\x1B[37;44;1m"
#define MAG   "\x1B[37;45;1m"
#define CYN   "\x1B[37;46;1m"
#define WHT   "\x1B[37;47;1m"
#define BLA   "\x1B[37;40;1m"
#define RED2   "\x1B[31;40;1;7m"
#define GRN2   "\x1B[32;40;1;7m"
#define YEL2   "\x1B[33;40;1;7m"
#define BLU2   "\x1B[34;40;1;7m"
#define MAG2   "\x1B[35;40;1;7m"
#define CYN2   "\x1B[36;40;1;7m"
#define WHT2   "\x1B[37;40;1;7m"
#define BLA2   "\x1B[30;40;1;7m"
#define RESET "\x1B[0m"

int main()
{
  printf(RED "red " RED2 "red" RESET "\n");
  printf(GRN "green " GRN2 "green" RESET "\n");
  printf(YEL "yellow " YEL2 "yellow" RESET "\n");
  printf(BLU "blue " BLU2 "blue" RESET "\n");
  printf(MAG "magenta " MAG2 "magenta" RESET "\n");
  printf(CYN "cyan " CYN2 "cyan" RESET "\n");
  printf(WHT "white " WHT2 "white" RESET "\n");
  printf(BLA "black " BLA2 "black" RESET "\n");


  return 0;
}
