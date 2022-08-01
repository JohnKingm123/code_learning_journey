#include <iostream> 
#include"stdlib.h"
using namespace std; 
const int inf=9999; 
const int N = 7; 
//--------------------------------------------------------------------------- 
void Prim(int n,int c[][N+1]) { 
 int lowcost[N+1]; //记录 c[j][closest]的最小权值
 int closest[N+1]; //V-S 中点 j 在 S 中的最邻接顶点
 bool s[N+1]; 
 s[1] = true; 
 //初始化 s[i],lowcost[i],closest[i] 
 for(int i=2; i<=n; i++) { 
 lowcost[i] = c[1][i]; 
 closest[i] = 1; 
 s[i] = false; 
 } 
 
 for(int i=1; i<n; i++) { 
 int min = inf; 
 int j = 1; 
 //找出 V-S 中使 lowcost 最小的顶点 j 
 for(int k=2; k<=n; k++) { 
 if((lowcost[k]<min)&&(!s[k])) { 
 min = lowcost[k]; 
 j = k; 
 } 
 } 
 cout<<j<<' '<<closest[j]<<endl; 
 s[j] = true; //将 j 添加到 S 中
 //将 j 添加到 S 中后，修改 closest 和 lowcost 的值
 for(int k=2; k<=n; k++) { 
 if((c[j][k]<lowcost[k] && (!s[k]))) { 
 lowcost[k] = c[j][k]; 
 closest[k] = j; 
 } 
 } 
 } 
} 
//--------------------------------------------------------------------------- 
int main() { 
    system("chcp 65001");

 int c[N+1][N+1] = { 
 {0,0,0,0,0,0,0,0}, 
 {0,9999,23,9999,9999,9999,28,36}, 
 {0,23,9999,20,9999,9999,9999,1}, 
 {0,9999,20,9999,15,9999,9999,4}, 
 {0,9999,9999,15,9999,3,9999,9}, 
 {0,9999,9999,9999,3,9999,17,16}, 
 {0,28,9999,9999,9999,17,9999,25},
 {0,36,1,4,9,16,25,9999} 
 }; 
 cout<<"连通带权图的矩阵为："<<endl; 
 for(int i=1; i<=N; i++) { 
 for(int j=1; j<=N; j++) printf("%6d",c[i][j]); 
 cout<<endl; 
 } 
 cout<<"Prim 算法最小生成树选边次序如下："<<endl; 
 Prim(N,c); 
 system("pause"); 
 return 0; 
} 
//--------------------------------------------------------------------------- 