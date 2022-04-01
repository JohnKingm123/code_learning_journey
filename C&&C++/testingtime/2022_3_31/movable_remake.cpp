#include <stdlib.h> 
#include <stdio.h> 
#include<iostream>

template<typename T> 
T **creta2Darray(int n) 
{ 
 T **p = new T *[n]; 
 for(int i=0;i<n;i++) 
 { 
 p[i]=new int[n]; 
 for(int j=0;j<n;j++) p[i][j] = 0; 
 } 
 return p; 
} //动态建立二维数组

void display(int **p,int n)
{
for(int i=1;i<n;i++)
{
    for(int j=1;j<n;j++)
    {printf("%8d",p[i][j]);}
    putchar('\n');
}
}//打印
//----------------------------------------------------------------------------------------
void MatrixChain(int *p,int n,int **m)
{ 
 for(int i=1;i<=n;i++) 
 {m[i][i] = 0;}//左下三角归零
 /*长度为r的连乘最小结果*/
 for(int r=2;r<=n;r++)
 {
    for(int i=1;i<=n-r+1;i++)//以i作为首元素开始，保证不1越界
    {
    int j = i+r-1;//j是r的后边界
    m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j]; //记录初值
    printf("raw:%d i:%d j:%d\n",m[i][j],i,j);
        for(int k = i+1 ; k<j;k++) 
        {  
        int t = m[i][k] + m[k+1][j] + p[i-1] *p[k]*p[j];//k作为游标[i+1,j-1]之间枚举，出现更小值就跟新当前m[i][j]
            printf("list:%d k:%d\n",t,k);
            if(t<m[i][j]) 
            { m[i][j] = t;} 
            
        } 
        puts(" ||newline|| \n");
    } 
 } 
} //动态规划

int main()
{
int p[] = {30,35,15,5,10,20,25}; 
int n = sizeof(p)/sizeof(int)-1; 
int **m = creta2Darray<int>(n+1); 
MatrixChain(p,n,m); 
//display(m,n+1); 

system("pause");
return 0;
}