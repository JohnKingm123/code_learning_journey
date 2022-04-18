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
char e[6]={'6','5','4','3','2',0};
P(e,0,4);
return 0;
}
