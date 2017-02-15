#include <stdio.h>

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
  printf(RED " R " RESET "\n");
  printf(GRN " G " RESET "\n");
  printf(YEL " Y " RESET "\n");
  printf(BLU " B " RESET "\n");
  printf(MAG " M " RESET "\n");
  printf(CYN " C " RESET "\n");
  printf(WHT " W " RESET "\n");
  printf(BLA " K " RESET "\n");


  return 0;
}
