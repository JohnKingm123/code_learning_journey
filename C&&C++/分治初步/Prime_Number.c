//The Prime Number from n to m
#include<stdio.h>
int main ()
{
int n,m;
int mark=1;	//mark作为标识符
scanf("%d%d",&n,&m);

for(;n<=m;n++)
{
	for(int i=2;i<n/2;i++)
	{	
		if(n%i==0)
		{
			mark=0;
		break;
		}
	
	}
		if(mark!=0)
		{
		printf("%d\n",n);
		}
		
		mark =1;
				
	
}



return 0;
}