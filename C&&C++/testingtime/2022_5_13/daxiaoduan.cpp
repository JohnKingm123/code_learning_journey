#include <cstring>

#include <stdio.h>

using namespace std;



int main() {

  int   x = 12345;
  int   a = 0x38333231;
  char  m[16];
  int   b = 0x434241;
  char  n[12];

 

  const char  *s = "HelloShanghai123456789.";

  memcpy(n,s,sizeof(n));
  memcpy(m,s,sizeof(m));



  printf("%s****\n",n);
  printf("%s****\n",m);



  printf("\n");
  printf("m=%p\n",m);
  printf("a=%p\n",&a);
  printf("n=%p\n",n);
  printf("b=%p\n",&b);
  printf("x=%p\n",&x);
  


  return 0;

}