//引用符号使用 ‘&’
#include<stdio.h>
void exc(int& a,int& b)
{
int t;
t=a;
a=b;
b=t;

}



int main()
{




return 0;
}