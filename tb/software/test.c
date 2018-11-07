#include "print.h"

int main()
{
   int n = 100, i = 3, count, c;
 
   if ( n >= 1 )
   {
      print_dec(2);
      print_chr('\n');
   }

   for ( count = 2 ; count <= n ;  )
   {
      for ( c = 2 ; c <= i - 1 ; c++ )
      {
         if ( i%c == 0 )
            break;
      }
	  if ( c == i )
      {
        print_dec(i);
	     print_chr('\n');
         count++;
      }
      i++;
     }

      return i;
}
