#include<stdio.h>
  int main ()
  {
  char m[] = "Hello.";

  char *n  = "Shanghai";

 

  char *p;

  p = m;

  p[2] = 'x';

  puts(m);

  p = n;

p[2] = 'x';

  puts(n);
  
  
  getchar();
  getchar();
}