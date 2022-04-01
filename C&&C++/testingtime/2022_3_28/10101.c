/*一个整数二进制数是否是10101排位，难点是边界条件1010、10、1、0,相邻两位不相同*/
#include<stdio.h>

int dif(int n)
{
if(n<2){return 1;}

while(n>1)
{    
if(n%2==n/2%2){return 0;}
n/=2;
}
return 1;
}

int main ()
{
int n;    
int booll;

scanf("%d",&n);

booll=dif(n);
printf("%d",booll);

return 0;    
}
