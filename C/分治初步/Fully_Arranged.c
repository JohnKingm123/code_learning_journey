#include<stdio.h>
void swap(char* a,char* b)
{
char t;
t = *a;
*a = *b;
*b = t;
}


int P(char a[],int x, int y)
{
	if(x==y)
	{
	printf("%s\n",a);
	}
	else
	{
		for(int i=x;i<=y;i++)
		{
		swap(&a[i],&a[x]);
		P(a,x+1,y);
		swap(&a[i],&a[x]);
		
		}
	
	}


return 0;
}


int main ()
{
char e[4]={'A','B','C','D'};
P(e,0,3);
return 0;
}
