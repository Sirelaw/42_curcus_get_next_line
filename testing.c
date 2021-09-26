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
   while (i < 5)
     {
       using_static();
       i++;
     }
   printf("%s", using_static());
   return (0);
}
