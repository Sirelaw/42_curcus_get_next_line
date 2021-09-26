#include <stdio.h>

char	*using_static()
{
   static char *s;
   return (s);
}

int main()
{
   int i;
   i = 0;
   char *s = "This is a string";
   while (i < 5)
     {
       using_static();
       i++;
     }
   printf("%s\n", s);
   return (0);
}
