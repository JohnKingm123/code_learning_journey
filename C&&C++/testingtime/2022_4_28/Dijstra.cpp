#include <iostream> 
#include "stdlib.h"
using namespace std; 
const int N = 5; 
const int M = 1000; 
//--------------------------------------------------------------------------- 
void Dijkstra(int n,int v,int dist[],int prev[],int c[][N+1]) { 
 bool s[N+1]; 
 for(int i=1; i<=n; i++) { 
 dist[i] = c[v][i]; //dist[i]从源到顶点 i 的最短特殊路径长度
 s[i] = false; 
 if(dist[i] == M) prev[i] = 0; //从源到顶点 i 的最短路径 i 的前一个顶点
 else prev[i] = v; 
 } 
 dist[v] = 0; 
 s[v] = true; 
 
 for(int i=1; i<n; i++) { 
 int temp = M; 
 int u = v;//上一顶点
 //取出 V-S 中具有最短特殊路径长度的顶点 u 
 for(int j=1; j<=n; j++) { 
 if((!s[j]) && (dist[j]<temp)) { 
 u = j; 
 temp = dist[j]; 
 } 
 } 
 s[u] = true; 
 //根据作出的贪心选择更新 Dist 值
 for(int j=1; j<=n; j++) { 
 if((!s[j]) && (c[u][j]<M)) { 
 int newdist = dist[u] + c[u][j]; 
 if(newdist < dist[j]) { 
 dist[j] = newdist; 
 prev[j] = u; 
 } 
 } 
 } 
 } 
} 
//输出最短路径 v 源点，i 终点
void Traceback(int v,int i,int prev[]) { 
 if(v == i) { cout<<i; return; } 
 Traceback(v,prev[i],prev); 
 cout<<"->"<<i; 
} 
//--------------------------------------------------------------------------- 
int main() { 
system("chcp 65001");

 int v = 1; //源点为 1 
 int dist[N+1],prev[N+1]; 
 int c[N+1][N+1] = { {0,0,0,0,0,0}, 
 {0,1000,10, 1000,30, 100}, 
 {0,1000,1000,50, 1000,1000}, 
 {0,1000,1000,1000,1000,10}, 
 {0,1000,1000,20, 1000,60}, 
 {0,1000,1000,1000,1000,1000}}; 
 cout<<"有向图权的矩阵为："<<endl; 
 for(int i=1; i<=N; i++) { 
 for(int j=1; j<=N; j++) cout<<c[i][j]<<" "; 
 cout<<endl; 
 } 
 Dijkstra(N,v,dist,prev,c); 
 for(int i=2; i<=N; i++) { 
 cout<<"源点 1 到点"<<i<<"的最短路径长度为:"<<dist[i]<<"，其路径为"; 
 Traceback(1,i,prev); 
 cout<<endl; 
 } 
 system("pause"); 
 return 0; 
} 
//--------------------------------------------------------------------------- 