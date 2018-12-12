#include "print.h"

int main()
{
      print_dec(2);

      volatile uint8_t * ptr = 0x1008;

      while(((*ptr) & 1) == 0);

      ptr = 0x1004;

      volatile uint8_t tmp = (*ptr); 
}
