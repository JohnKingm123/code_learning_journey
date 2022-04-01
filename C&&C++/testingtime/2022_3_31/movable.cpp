#include <stdlib.h> 
#include <stdio.h> 
#include<iostream>
//--------------------------------------------------------------------------- 
//动态创建二维数组
template<typename T> 
T **creta2Darray(int n) { 
 T **p = new T *[n]; 
 for(int i=0;i<n;i++) { 
 p[i]=new int[n]; 
 for(int j=0;j<n;j++) p[i][j] = 0; 
 } 
 return p; 
} 
//--------------------------------------------------------------------------- 
//输出二维数组，屏蔽第一维
void disp2Darray(int **p,int n) { 
 for(int i=1;i<n;i++) { 
 for(int j=1;j<n;j++) printf("%8d",p[i][j]); 
 putchar('\n'); 
 } 
} 
//--------------------------------------------------------------------------- 
//动态规划法计算矩阵连乘的最优解
void MatrixChain(int *p,int n,int **m,int **s){ 
 for(int i=1;i<=n;i++) m[i][i] = 0; 
 for(int r=2;r<=n;r++){ //r 为当前计算的链长（子问题规模）
 for(int i=1;i<=n-r+1;i++){ //n-r+1 为最后一个 r 链的前边界
 int j = i+r-1; //计算前边界为 r，链长为 r 的链的后边界
 //将链 ij 划分为 A(i) * ( A[i+1:j] ) 
 m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j]; 
 s[i][j] = i; //记录断开点的索引
 for(int k = i+1 ; k<j;k++) { 
 //将链 ij 划分为( A[i:k] )* (A[k+1:j]) 
 int t = m[i][k] + m[k+1][j] + p[i-1] *p[k]*p[j]; 
 if(t<m[i][j]) { 
 m[i][j] = t; s[i][j] = k; 
 } 
 } 
 } 
 } 
} 
//--------------------------------------------------------------------------- 
//直接递归
int RecurMatrixChain(int i,int j,int **s,int *p) { 
 if(i==j) return 0; 
 int u = RecurMatrixChain(i,i,s,p)+RecurMatrixChain(i+1,j,s,p)+p[i-1]*p[i]*p[j]; 
 s[i][j] = i; 
 for(int k=i+1;k<j;k++) { 
 int t = RecurMatrixChain(i,k,s,p)+RecurMatrixChain(k+1,j,s,p)+p[i-1]*p[k]*p[j]; 
 if(t<u) { 
 u=t; 
 s[i][j]=k; 
 } 
 } 
 return u; 
} 
//--------------------------------------------------------------------------- 
//备忘录方法
int LookupChain(int i,int j,int **m,int **s,int *p) { 
 if(m[i][j]>0) { return m[i][j]; } 
 if(i==j) { return 0; } 
 int u = LookupChain(i,i,m,s,p) + LookupChain(i+1,j,m,s,p)+p[i-1]*p[i]*p[j]; 
 s[i][j]=i; 
 for(int k=i+1; k<j; k++) { 
 int t = LookupChain(i,k,m,s,p) + LookupChain(k+1,j,m,s,p) + p[i-1]*p[k]*p[j]; 
 if(t<u) { 
 u=t; 
 s[i][j] = k; 
 } 
 } 
 m[i][j] = u; 
 return u; 
} 
//--------------------------------------------------------------------------- 
int MemoizedMatrixChain(int n,int **m,int **s,int *p) { 
 for(int i=1;i<=n;i++) { 
 for(int j=1;j<=n;j++) m[i][j]=0; 
 } 
 return LookupChain(1,n,m,s,p); 
} 
//--------------------------------------------------------------------------- 
//构造最优解
void Traceback(int i,int j,int **s) { 
 if(i==j) return; 
 Traceback(i,s[i][j],s); 
 Traceback(s[i][j]+1,j,s); 
 printf("Multiply A %d,%d ",i,s[i][j]); 
 printf("and A %d,%d\n",(s[i][j]+1),j); 
} 
//--------------------------------------------------------------------------- 
//动态规划法
//--------------------------------------------------------------------------- 
void dyProg(int *p,int n,int **m,int **s) { 
 MatrixChain(p,n,m,s); 
 disp2Darray(m,n+1); 
 printf("\n"); 
 disp2Darray(s,n+1); 
 Traceback(1,n,s); 
} 
//--------------------------------------------------------------------------- 
//直接递归
//--------------------------------------------------------------------------- 
void recMat(int *p,int n,int **m,int **s) { 
 printf("\n 直接递归\n 矩阵的最少计算次数:%d\n",RecurMatrixChain(1,n,s,p)); 
 Traceback(1,n,s); 
} 
//--------------------------------------------------------------------------- 

//备忘录方法
//--------------------------------------------------------------------------- 
void memMat(int n,int **m,int **s,int *p) { 
 printf("\n 备忘录方法\n 矩阵的最少计算次数:%d\n",MemoizedMatrixChain(n,m,s,p)); 
 Traceback(1,n,s); 
} 
//--------------------------------------------------------------------------- 
int main(int argc, char* argv[]) 
{ 
 int p[] = {30,35,15,5,10,20,25}; 
 int n = sizeof(p)/sizeof(int)-1; 
 int **m = creta2Darray<int>(n+1); 
 int **s = creta2Darray<int>(n+1); 
 //动态规划法
 dyProg(p,n,m,s); 
 //直接递归
 recMat(p,n,m,s); 
 //备忘录方法
 memMat(n,m,s,p); 
 system("pause"); 
 return 0; 
} 
//--------------------------------------------------------------------------- 