#include<stdio.h>


int main (){

char m[] = "dcba1234";

int *p = (int *)m;

printf("%d %x\n",*(p+1),*(p+1));

return 0;
}