#include <iostream> 
using namespace std; 
//--------------------------------------------------------------------------- 
void Knapsack(int v[],int w[],int c,int n,int m[][10]) { 
 int jMax = min(w[n]-1,c); //背包剩余载重上限 范围[0~w[n]-1] 
 for(int j=0; j<=jMax;j++) m[n][j] = 0; 
 for(int j=w[n];j<=c; j++) m[n][j] = v[n]; //限制范围[w[n]~c] 
 for(int i=n-1; i>1; i--) { 
 jMax = min(w[i]-1,c); 
 for(int j=0; j<=jMax; j++) { //背包不同剩余载重 j<=jMax<c 
 m[i][j] = m[i+1][j]; //没产生任何效益
 } 
 for(int j=w[i]; j<=c; j++) { //背包不同剩余载重 j-wi >c 
 m[i][j] = max(m[i+1][j],m[i+1][j-w[i]]+v[i]); //效益值增长 vi 
 } 
 } 
 m[1][c] = m[2][c]; 
 if(c>=w[1]) m[1][c] = max(m[1][c],m[2][c-w[1]]+v[1]); 
} 
//--------------------------------------------------------------------------- 
//x[]数组存储对应物品 0-1 向量,0 不装入背包，1 表示装入背包
void Traceback(int m[][10],int w[],int c,int n,int x[]) { 
 for(int i=1; i<n; i++) { 
 if(m[i][c] == m[i+1][c]) x[i]=0; 
 else { 
 x[i]=1; 
 c-=w[i]; 
 } 
 } 
 x[n]=(m[n][c])?1:0; 
} 
//--------------------------------------------------------------------------- 
int main() { 
 const int N = 3; 
 int c = 6; 
 int w[]={0,4,3,2},v[]={0,5,2,1}; //下标从 1 开始
 int x[N+1]; 
 int m[10][10]; 
 printf("待装物品价值分别为："); 
 for(int i=1;i<=N;i++) printf("%4d",w[i]); puts(""); 
 printf("待装物品价值分别为"); 
 for(int i=1;i<=N;i++) printf("%4d",v[i]); puts(""); 
 Knapsack(v,w,c,N,m); 
 printf("背包能装的最大值为：%4d\n",m[1][c]); 
 Traceback(m,w,c,N,x); 
 printf("背包装下的物品编号为："); 
 for(int i=1;i<=N;i++) { if(x[i]==1) printf("%4d",i); } puts(""); 
 system("pause"); 
 return 0; 
} 
//--------------------------------------------------------------------------- 