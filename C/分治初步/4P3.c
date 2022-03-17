//非递归算法算3C3
#include<stdio.h>
int main()
{
for(int i=1;i<5;i++)
{
	for(int j=1;j<5;j++)
	{
		for(int k=1;k<5;k++)
		{
			if(i==j||j==k||k==i)
			{
			continue;		
			}
			printf("%d%d%d",i,j,k);
		}
	}

}	
	
	
return 0;
}